#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>

using namespace std;

#include <stdio.h>
#include <Windows.h>

int nScreenWidth = 120;			// Размер экрана консоли X (колонки)
int nScreenHeight = 40;			// Размер экрана консоли Y (строки)
int nMapWidth = 16;				// Мировые измерения
int nMapHeight = 16;

float fPlayerX = 14.7f;			// Стартовая позиция игрока
float fPlayerY = 5.09f;
float fPlayerA = 0.0f;			// Стартовое вращение игрокa
float fFOV = 3.14159f / 4.0f;	// Поле зрения
float fDepth = 16.0f;			// Максимальное расстояние рендеринга
float fSpeed = 5.0f;			// Скорость ходьбы

int main()
{
	// Создание экранного буфера
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	// Создаем карту мирового пространства # = блок стены, . = пустота
	wstring map;
	map += L"#########.......";
	map += L"#...............";
	map += L"#.......########";
	map += L"#..............#";
	map += L"#......##......#";
	map += L"#......##......#";
	map += L"#..............#";
	map += L"###............#";
	map += L"##.............#";
	map += L"#......####..###";
	map += L"#......#.......#";
	map += L"#......#.......#";
	map += L"#..............#";
	map += L"#......#########";
	map += L"#..............#";
	map += L"################";

	auto tp1 = chrono::system_clock::now();
	auto tp2 = chrono::system_clock::now();

	while (1)
	{
		// Нам понадобится разница во времени на кадр для расчета модификации
		// скорости движения, чтобы обеспечить последовательное движение, так как трассировка лучей является недетерминированным
		tp2 = chrono::system_clock::now();
		chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();


		// Вращение рукоятки в направлении против часовой стрелки
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
			fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;

		// Обработка вращения по часовой стрелке
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
			fPlayerA += (fSpeed * 0.75f) * fElapsedTime;

		// Обработка движения вперед и столкновений
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000)
		{
			fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;;
			fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;;
			if (map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#')
			{
				fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;;
				fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;;
			}
		}

		// Обработка движения назад и столкновений
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000)
		{
			fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;;
			fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;;
			if (map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#')
			{
				fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;;
				fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;;
			}
		}

		for (int x = 0; x < nScreenWidth; x++)
		{
			// Для каждого столбца вычислите угол проецирования луча в мировое пространство
			float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;

			// Найдите расстояние до стены
			float fStepSize = 0.1f;		  // Увеличение размера для приведения лучей, уменьшение для увеличения										
			float fDistanceToWall = 0.0f; // разрешение

			bool bHitWall = false;		// Устанавливается, когда луч попадает в блок стены
			bool bBoundary = false;		// Устанавливается, когда луч попадает на границу между двумя стеновыми блоками

			float fEyeX = sinf(fRayAngle); // Единичный вектор для луча в пространстве игрока
			float fEyeY = cosf(fRayAngle);

			// Инкрементально бросаем луч от игрока, вдоль угла луча, проверяя на пересечения с блоком
			while (!bHitWall && fDistanceToWall < fDepth)
			{
				fDistanceToWall += fStepSize;
				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

				// Проверяем, не выходит ли луч за пределы границ
				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
				{
					bHitWall = true;			// Просто установите расстояние на максимальную глубину
					fDistanceToWall = fDepth;
				}
				else
				{
					// Луч находится в границах, поэтому проверяем, является ли ячейка луча блоком стены.
					if (map.c_str()[nTestX * nMapWidth + nTestY] == '#')
					{
						// Луч ударился о стену
						bHitWall = true;

						// Чтобы выделить границы плитки, проведите луч от каждого угла плитки к игроку. 
						// Чем больше этот луч совпадает совпадает с лучом рендеринга, тем ближе мы к границе плитки. 
						// Границе, которую мы будем затенять, чтобы добавить детали к стенам.
						vector<pair<float, float>> p;

						// Протестируйте каждый угол плитки, сохранив расстояние до него от
						// игрока, и вычисленное точечное произведение двух лучей
						for (int tx = 0; tx < 2; tx++)
							for (int ty = 0; ty < 2; ty++)
							{
								// Угол от угла до глаза
								float vy = (float)nTestY + ty - fPlayerY;
								float vx = (float)nTestX + tx - fPlayerX;
								float d = sqrt(vx * vx + vy * vy);
								float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
								p.push_back(make_pair(d, dot));
							}

						// Сортировка пар от ближайшей к наиболее удаленной
						sort(p.begin(), p.end(), [](const pair<float, float>& left, const pair<float, float>& right) {return left.first < right.first; });

						// Первые два/три - самые близкие (мы никогда не увидим всех четырех)
						float fBound = 0.01;
						if (acos(p.at(0).second) < fBound) bBoundary = true;
						if (acos(p.at(1).second) < fBound) bBoundary = true;
						if (acos(p.at(2).second) < fBound) bBoundary = true;
					}
				}
			}

			// Вычислить расстояние до потолка и пола
			int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
			int nFloor = nScreenHeight - nCeiling;

			// Шейдер стен на основе расстояния
			short nShade = ' ';
			if (fDistanceToWall <= fDepth / 4.0f)			nShade = 0x2588;	// Очень близко	
			else if (fDistanceToWall < fDepth / 3.0f)		nShade = 0x2593;
			else if (fDistanceToWall < fDepth / 2.0f)		nShade = 0x2592;
			else if (fDistanceToWall < fDepth)				nShade = 0x2591;
			else											nShade = ' ';		// Слишком далеко

			if (bBoundary)		nShade = ' '; // Затемнить

			for (int y = 0; y < nScreenHeight; y++)
			{
				// Каждая строка
				if (y <= nCeiling)
					screen[y * nScreenWidth + x] = ' ';
				else if (y > nCeiling && y <= nFloor)
					screen[y * nScreenWidth + x] = nShade;
				else // Пол
				{
					// Затенение пола в зависимости от расстояния
					float b = 1.0f - (((float)y - nScreenHeight / 2.0f) / ((float)nScreenHeight / 2.0f));
					if (b < 0.25)		nShade = '#';
					else if (b < 0.5)	nShade = 'x';
					else if (b < 0.75)	nShade = '.';
					else if (b < 0.9)	nShade = '-';
					else				nShade = ' ';
					screen[y * nScreenWidth + x] = nShade;
				}
			}
		}

		// Отображение статистики
		swprintf_s(screen, 40, L"X=%3.2f, Y=%3.2f, A=%3.2f FPS=%3.2f ", fPlayerX, fPlayerY, fPlayerA, 1.0f / fElapsedTime);

		// Отображение карты
		for (int nx = 0; nx < nMapWidth; nx++)
			for (int ny = 0; ny < nMapWidth; ny++)
			{
				screen[(ny + 1) * nScreenWidth + nx] = map[ny * nMapWidth + nx];
			}
		screen[((int)fPlayerX + 1) * nScreenWidth + (int)fPlayerY] = 'P';

		// Рамка дисплея
		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}

	return 0;
}
