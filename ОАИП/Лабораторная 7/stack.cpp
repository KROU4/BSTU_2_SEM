#include "stdafx.h"

int main()
{
	setlocale(LC_ALL, "rus");
	comp* top = NULL;
	Stack1* s1 = NULL;			//��������� �� ������� ����� - NULL
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
			cout << "������� �����: ";
			cin >> n;
			push(&top, n);
			break;
		case 2:
			cout << "������� �����, ������� ����� �������: ";
			cin >> n;
			delete_key(&top, n);
			break;
		case 3:
			cout << "������� �����, ������� ����� �����: ";
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
					cout << "������� �����: ";
					cin >> n;
					Add1(&s1, n);
					break;						//�������� ������� � ����
				case 2:
					cout << "������� �����: ";
					cin >> n;
					Add2(&s2, n);
					break;                           //�������� ������� � ����
				case 3: Show1(s1); break;
				case 4: Show2(s2); break;
				case 5: Show(&top); break;									//������� ����
				case 6: Showw(top); break;
				case 7:work = false;
					break;;
				}										//�����
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