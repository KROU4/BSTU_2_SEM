#include <ctime>             
#include <stdlib.h>
#include <iostream>
using namespace std;
int* sort1(int m[], int lm)
{
	int k, i, j;
	for (i = 0; i < lm - 1; i++)
	{
		for (j = i + 1, k = i; j < lm; j++)
			if (m[j] < m[k])
				k = j;
		int c = m[k];
		m[k] = m[i];
		m[i] = c;
	}
	return m;
}
//------------------------------
int* sort2(int m[], int lm)
{
	int buf;
	bool sort;
	for (int g = lm / 2; g > 0; g /= 2)
		do
		{
			sort = false;
			for (int i = 0, j = g; j < lm; i++, j++)
				if (m[i] > m[j])
				{
					sort = true;
					buf = m[i];
					m[i] = m[j];
					m[j] = buf;
				}
		} while (sort);
		return m;
}
//------------------------------
void insOrd(int m[], int sm, int em, int e)
{

	int buf;
	int i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}
int* merge(int m[], int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
	return m;
}
int* sort3(int m[], int lm, int sm)
{
	if (lm > 1)
	{
		sort3(m, lm / 2, sm);
		sort3(m, lm - lm / 2, sm + lm / 2);
		merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
	return m;
}

//----------------------------
int getRandKey(int reg = 0)
{
	if (reg > 0)
		srand((unsigned)time(NULL));
	int rmin = 0;
	int rmax = 100000;
	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}
//------------------------------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int t = 0;
	const int N = 30000;
	int k[N], f[N];
	clock_t  t1, t2;
	getRandKey(1);
	for (int i = 0; i < N; i++)
		f[i] = getRandKey(0);
	for (int n = 10000; n <= N; n += 10000)
	{
		cout << "n = " << n << endl;
		cout << "SortVybor ";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sort1(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << "SortShell   ";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sort2(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << "SortSliyaniem   ";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sort3(k, n, t);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl << endl;
	}
	return 0;
}
