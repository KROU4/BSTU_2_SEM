#include "stdafx.h"

int main()
{
	setlocale(LC_ALL, "rus");
	comp* top = NULL;
	Stack1* s1 = NULL;			//указатель на вершину стека - NULL
	int N = 3;
	Stack2* s2 = NULL;
	int* temp = new int[N];
	cout << _msize(temp);

	bool work = true;
	float n;
	while (work)
	{
		switch (menu())
		{
		case 1:
			cout << "Введите число: ";
			cin >> n;
			push(&top, n);
			break;
		case 2:
			cout << "Введите число, которое нужно удалить: ";
			cin >> n;
			delete_key(&top, n);
			break;
		case 3:
			cout << "Введите число, которое нужно найти: ";
			cin >> n;
			find(top, n);
			break;
		case 4:
			print(top);
			break;
		case 5:
			extract(&top);
			break;
		case 6:
			toFile(top);
			break;
		case 7:
			fromFile(&top);
			break;
		case 8:
			clear(&top);
			break;
		case 9:
			while (work) {
				switch (menu2()) {
				case 1:
					cout << "Введите число: ";
					cin >> n;
					Add1(&s1, n);
					break;						//Добавить элемент в стек
				case 2:
					cout << "Введите число: ";
					cin >> n;
					Add2(&s2, n);
					break;                           //Добавить элемент в стек
				case 3: Show1(s1); break;
				case 4: Show2(s2); break;
				case 5: Show(&top); break;									//Вывести стек
				case 6: Showw(top); break;
				case 7:work = false;
					break;;
				}										//Конец
			};
			break;
		case 10:
			taskVar3(&top);
			break;
		case 11:
			task3();
			break;
		case 12:
			task4();
			break;
		case(0):
			work = false;
			break;
		default:
			break;
		}
	}

	return 0;
}