
#include <iostream>
#include <windows.h>
using namespace std;
#define max 100

long long numbers[10] = { 375336939934,375549295069,375444917218,375854392135,375336549932,375339873325, 375843209832,375867485923,375323413245,375339495069 };
const char* names[10] = { "Александр","Екатерина","Дмитрий","Жанна","Андрей","Елена","Виктор","Елизавета","Евгений","Мария" };
const char* surnames[10] = { "Ковалёв","Астапкина","Бруй","Андреева","Степанов","Большова","Суднов","Кочевнова","Пляскевич","Терехова" };
int tarifs[10] = { 1,3,2,3,2,1,2,3,2,2 };

struct User
{
	long long number;
	char name[max];
	char surname[max];
	int tarif;
	User* Left, * Right;
};

User* makeUser(User* Root);       //Создание дерева
User* list(int i, char* s, char* l, int d); //Создание нового элемента
User* insertElem(User* t, int number, char* name, char* surname, int tarif); //Добавление нового элемента
User* search(User* n, int number);   //Поиск элемента по номеру 
User* delet(User* Root, int number); //Удаление элемента по номеру
void view(User* t, int level);    //Вывод дерева 
void delAll(User* t);             //Очистка дерева
int checkpopT(User* t);
User* fill(User* t);
User* inserеFILL(User* t, int number, const char* name, const char* surname, int tarif);
User* listFILL(int i, const char* s, const char* l, int d);
void printTARIFS();
User* Root = NULL; 	//указатель корня
int  a[] = { 0,0,0 };

void main()
{
	setlocale(0, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int number, choice, Left_count = 0, Right_count = 0;
	User* rc; int s, letter;
	for (;;)
	{
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск по номеру\n";
		cout << "4 -	удаление элемента\n";
		cout << "5 -	вывод дерева\n";
		cout << "6 -	очистка дерева\n";
		cout << "7 -	вывод названий тарифов\n";
		cout << "8 -	определение самого популярного тарифа\n";
		cout << "9 -	заполнение дерева\n";
		cout << "10 -	выход\n";
		cout << "Ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeUser(Root);	break;
		case 2:  int tarif; char name[max], surname[max];
			cout << "Введите номер: "; cin >> number;
			cin.ignore();
			cout << "Введите имя "; cin.getline(name, max);
			cout << "Введите фамилию:"; cin.getline(surname, max);
			cout << "Введите номер тарифа:"; cin >> tarif;
			insertElem(Root, number, name, surname, tarif); break;
		case 3:  cout << "\nВведите номер: ";  cin >> number;
			rc = search(Root, number);
			if (rc != NULL)
			{
				cout << "Найденная запись: ";
				cout << rc->number << "-" << rc->name << "-" << rc->surname << "-" << rc->tarif << endl;
			}break;
		case 4:  cout << "\nВведите удаляемый номер: "; cin >> number;
			Root = delet(Root, number);  break;
		case 5:  if (Root != NULL)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 6:  delAll(Root); Root = NULL; break;
		case 7:  printTARIFS(); break;
		case 8: for (int i = 0; i < 3; i++) a[i] = 0; checkpopT(Root);
			if (a[0] > a[1] && a[0] > a[2])
			{
				printf("Самый популярный тариф - Безлимит\n");
			}
			else if (a[1] > a[2])
			{
				printf("Самый популярный тариф - Путешествия\n");
			}
			else if (a[0] == a[1])
			{
				printf("Самый популярные тарифы - Путешествия и Безлимитный\n");
			}
			else if (a[0] == a[2])
			{
				printf("Самый популярные тарифы - Безлимит и Молодёжный\n");
			}
			else if (a[1] == a[2])
			{
				printf("Самый популярные тарифы - Путешествия и Молодёжный\n");
			}
			else if (a[1] == a[2] == a[0])
			{
				printf("Самый тарифы равно популярны\n");
			}
			else
			{
				printf("Самый популярный тариф - Молодёжный\n");
			}
			break;
		case 9:  Root = fill(Root); break;
		case 10:  exit(0);
		}
	}
}

User* makeUser(User* Root)    //Создание дерева
{
	int number, tarif; char name[max], surname[max];
	cout << "Конец ввода - отрицательный номер\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите номер: "; cin >> number;
		if (number < 0) return Root;
		cin.ignore();
		cout << "Введите имя: "; cin.getline(name, max);
		cout << "Введите фамилию: "; cin.getline(surname, max);
		cout << "Введите номер тарифа: "; cin >> tarif;
		Root = list(number, name, surname, tarif);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "Введите номер: "; cin >> number;
		if (number < 0) return Root;
		cin.ignore();
		cout << "Введите имя: "; cin.getline(name, max);
		cout << "Введите фамилию: "; cin.getline(surname, max);
		cout << "Введите номер тарифа: "; cin >> tarif;
		insertElem(Root, number, name, surname, tarif);
	}
	return Root;
}

User* list(int i, char* s, char* l, int d)     //Создание нового элемента
{
	User* t = new User[sizeof(User)];
	t->number = i;
	strcpy_s(t->name, s);
	strcpy_s(t->surname, l);
	t->tarif = d;
	t->Left = t->Right = NULL;
	return t;
}

User* insertElem(User* t, int number, char* name, char* surname, int tarif)  //Добавление нового элемента
{
	User* Prev = NULL;	     // Prev - элемент перед текущим
	int find = 0;  // признак поиска  
	while (t && !find)
	{
		Prev = t;
		if (number == t->number)
			find = 1;	   //номера должны быть уникальны
		else
			if (number < t->number) t = t->Left;
			else t = t->Right;
	}

	if (!find)
	{
		t = list(number, name, surname, tarif);
		if (number < Prev->number)
		{
			Prev->Left = t;
		}
		else
		{
			Prev->Right = t;
		}
	}
	return t;
}

User* delet(User* Root, int number)  //Удаление элемента по номеру
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	User* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->number != number)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->number > number)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого номера");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->number < Prev_Del->number)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->number;
	cout << "\nУдален элемент с номером" << tmp << endl;
	delete Del;
	return Root;
}

User* search(User* n, int number)  //Поиск элемента по номеру 
{
	User* rc = n;
	if (rc != NULL)
	{
		if (number < n->number)
			rc = search(n->Left, number);
		else
			if (number > n->number)
				rc = search(n->Right, number);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}

void view(User* t, int level) //Вывод дерева 
{
	if (t == NULL)return;
	else
	{
		view(t->Left, ++level);
		for (int i = 0; i < level; i++)
			cout << "                      ";
		cout << t->number << "-" << t->name << "-" << t->surname << "-" << t->tarif << endl;
		level--;
	}
	view(t->Right, ++level);
}

void delAll(User* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

int checkpopT(User* t)
{
	if (t == NULL) { return NULL; }
	if (t->tarif == 1)
	{
		a[0]++;
		return(checkpopT(t->Right) + checkpopT(t->Left));
	}
	else if (t->tarif == 2)
	{
		a[1]++;
		return(checkpopT(t->Right) + checkpopT(t->Left));
	}
	else if (t->tarif == 3)
	{
		a[2]++;
		return(checkpopT(t->Right) + checkpopT(t->Left));
	}

}

User* fill(User* Root)
{
	for (int i = 0; i < 10; i++)
	{
		if (Root == NULL)	// если дерево не создано
		{
			Root = listFILL(numbers[i], names[i], surnames[i], tarifs[i]);	// установка указателя на корень
		}
		else
		{
			inserеFILL(Root, numbers[i], names[i], surnames[i], tarifs[i]);
		}
	}
	return Root;
}

User* inserеFILL(User* t, int number, const char* name, const char* surname, int tarif)  //Добавление нового элемента
{
	User* Prev = NULL;	     // Prev - элемент перед текущим
	int find = 0;  // признак поиска  
	while (t && !find)
	{
		Prev = t;
		if (number == t->number)
			find = 1;	   //номера должны быть уникальны
		else
			if (number < t->number) t = t->Left;
			else t = t->Right;
	}

	if (!find)
	{
		t = listFILL(number, name, surname, tarif);
		if (number < Prev->number)
		{
			Prev->Left = t;
		}
		else
		{
			Prev->Right = t;
		}
	}
	return t;
}

User* listFILL(int i, const char* s, const char* l, int d)     //Создание нового элемента
{
	User* t = new User[sizeof(User)];
	t->number = i;
	strcpy_s(t->name, s);
	strcpy_s(t->surname, l);
	t->tarif = d;
	t->Left = t->Right = NULL;
	return t;
}

void printTARIFS()
{
	printf("Список тарифов:\n1.Безлимит.\n2.Путешествия.\n3.Молодёжный.\n");
}