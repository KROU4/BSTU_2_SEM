#include <iostream> 
#include<Windows.h>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Добавление элемента х в конец списка" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin >> c;
	} while (c < 0 || c > 5);
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.ignore(4096, '\n');
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
//addXEnd (int x) – функция добавление элемента x в конец списка.
void addXEnd(Address** phead, Address** plast, int x)
{
	Address* e = new Address();
	if (!e)
	{
		cerr << "Ошибка выделения памяти";
		return;
	}
	e->next = NULL;
	e->prev = *plast;
	e->name[0] = '\0'; // обнуляем поля, чтобы избежать ошибок
	e->city[0] = '\0';
	sprintf_s(e->city, CITY_SIZE - 1, "%d", x); // записываем x как строку в поле город
	if (*plast != NULL)
	{
		(*plast)->next = e;
	}
	*plast = e;
	if (*phead == NULL)
	{
		*phead = e;
	}
}
//-----------------------------------------------------------
int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2:
		{
			int x;
			cout << "Введите число: ";
			cin >> x;
			addXEnd(&head, &last, x);
		}
		break;

		case 3:  outputList(&head, &last);
			break;
		case 4:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}