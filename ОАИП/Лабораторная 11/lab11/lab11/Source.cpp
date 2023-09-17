#include <iostream>
#include <windows.h>
#include<conio.h>  
using namespace std;
#define max 100
struct Tree          //дерево
{
	int key;         //ключ
	int number;    //текст - не более 4 букв
	Tree* left, * right;
};
Tree* Root = NULL;
int sum = 0;
int d = 0;
Tree* makeTree(Tree* Root, int& left, int& right);       //Создание дерева
Tree* list(int i, int s);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key, int s, int& left, int& right);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
int count(Tree* t, int k);  //Подсчет количества слов
void delAll(Tree* t);//Очистка дерева

int wrtreelast1(Tree* t);
void wrtree(Tree* t);
void wrtree1(Tree* t);
void wrtree2(Tree* t);
int Depth(Tree* t);
bool IsBalanced(Tree* t);

void main()
{
	setlocale(0, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int key, choice, left_count = 0, right_count = 0;
	Tree* rc; int s, letter, k = 0;
	for (;;)
	{
		cout << "\n1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск по ключу\n";
		cout << "4 -	удаление элемента\n";
		cout << "5 -	вывод дерева\n";
		cout << "6 -	количество ключей с определённым значением\n";
		cout << "7 -	очистка дерева\n";
		cout << "8 -	проверка сбалансированности дерева\n";
		cout << "9 -	вывод правых узлов дерева\n";
		cout << "10 -	прямой обход\n";
		cout << "11 -	симметричный обход\n";
		cout << "12 -	обратный обход\n";
		cout << "13 -	выход\n";
		cout << "Ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root, left_count, right_count);	break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			cout << "Введите число: "; cin >> s;
			insertElem(Root, key, s, left_count, right_count); break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
			rc = search(Root, key);
			if (rc != NULL)
			{
				cout << "Найденное число= ";
				cout << rc->number << endl;
			}break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root != NULL)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 6:
			sum = 0;
			cout << "Введите значение k:"; cin >> k;
			count(Root, k);
			cout << "\nКоличеств узлов со значением k = " << sum << endl; break;
		case 7:  delAll(Root); Root = NULL; break;
		case 8:  if (IsBalanced(Root) != 1)
			cout << "Это сбалансированное дерево" << endl;
			  else cout << "Это не сбалансированное дерево" << endl; break;
		case 9:  cout << "Количества узлов правой ветви дерева: " << wrtreelast1(Root) - 1; break;
		case 10:  wrtree(Root); break;
		case 11:  wrtree1(Root); break;
		case 12:  wrtree2(Root); break;
		case 13:  exit(0);
		}

	}
}
Tree* makeTree(Tree* Root, int& left, int& right)    //Создание дерева
{
	int key; int s;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;
		cout << "Введите число корня: "; cin >> s;
		Root = list(key, s);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "\nВведите ключ: ";  cin >> key;
		if (key < 0) break;       //признак выхода (ключ < 0)   
		cout << "Введите число: ";  cin >> s;
		insertElem(Root, key, s, left, right);
	}
	return Root;
}
Tree* list(int i, int s)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->number = s;
	t->left = t->right = NULL;
	return t;
}
Tree* insertElem(Tree* t, int key, int s, int& left, int& right)  //Добавление нового элемента
{
	Tree* Prev = NULL;	     // Prev - элемент перед текущим
	int find = 0;  // признак поиска  
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->key) t = t->left;
			else t = t->right;
	}

	if (!find)
	{
		t = list(key, s);
		if (key < Prev->key)
		{
			Prev->left = t;
			left++;
		}
		else
		{
			Prev->right = t;
			right++;
		}
	}
	return t;
}
Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->right == NULL) // поиск элемента R для замены
		R = Del->left;
	else
		if (Del->left == NULL)
			R = Del->right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->left;
			while (R->right != NULL)
			{
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->right = Del->right;
			else
			{
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->left = R; // на левую ветвь 
		else
			Prev_Del->right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}
Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < n->key)
			rc = search(n->left, key);
		else
			if (key > n->key)
				rc = search(n->right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}
int count(Tree* t, int k)
{
	if (t == NULL) { return NULL; }
	if (t->right == NULL && t->left == NULL)
	{
		if (t->number == k)
		{
			sum += 1;
		}
		return 1;
	}
	else
	{
		return (count(t->right, k) + count(t->left, k));
	}
}
void view(Tree* t, int level) //Вывод дерева 
{
	if (t == NULL)return;
	else
	{
		view(t->left, ++level);
		for (int i = 0; i < level; i++)
			cout << "      ";
		int tm = t->key;
		cout << tm << ' ';
		cout << t->number << endl;
		level--;
	}
	view(t->right, ++level);
}
void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->left);
		delAll(t->right);
		delete t;
	}
}



int wrtreelast1(Tree* t)
{

	if (t == NULL) return d;
	d++;
	wrtreelast1(t->left);
	return d;
}
void wrtree(Tree* t) // прямой обход
{
	if (t == NULL) return;
	cout << t->key << '-' << t->number << " ";
	wrtree(t->left);
	wrtree(t->right);

}
void wrtree1(Tree* t)// симметричный обход
{
	if (t == NULL) return;

	wrtree(t->left);
	cout << t->key << '-' << t->number << " ";
	wrtree(t->right);

}
void wrtree2(Tree* t) // обратный обход
{
	if (t == NULL) return;

	wrtree(t->left);
	wrtree(t->right);
	cout << t->key << '-' << t->number << " ";
}
int Depth(Tree* t)
{
	if (t != NULL)
	{
		int A = Depth(t->left);
		int B = Depth(t->right);
		if (A > B) return A + 1;
		else return B + 1;
	}
	else return 0;
}
bool IsBalanced(Tree* t) // проверка сбалансированности дерева
{
	int l, r;
	if (t == NULL) return true;
	else
	{
		if (IsBalanced(t->left) && IsBalanced(t->right))
		{
			l = Depth(t->left);
			r = Depth(t->right);
			if (l - r == 1 || r - l == 1 || l == r)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}
