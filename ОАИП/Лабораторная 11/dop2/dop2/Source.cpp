#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;
#define max 100
struct Tree          //������
{
	int key;         //����
	int number;    //����� - �� ����� 4 ����
	Tree* Left, * Right;
};

Tree* makeTree(Tree* Root, int& left, int& right, int quantity);       //�������� ������
Tree* list(int i, int s);       //�������� ������ ��������
Tree* insertElem(Tree* Root, int key, int s, int& left, int& right);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
void view(Tree* t, int level);    //����� ������ 
void delAll(Tree* t);             //������� ������
int key = 0;
//���������� ����
Tree* Root = NULL; 	//��������� �����
int sum = 0;
int quantity = 0;
void main()
{
	srand(time(0));
	setlocale(0, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int  choice, left_count = 0, right_count = 0;
	Tree* rc; int s, letter;
	for (;;)
	{
		cout << "1 -	�������� ������\n";
		cout << "2 -	���������� ��������\n";
		cout << "3 -	����� �� �����\n";
		cout << "4 -	�������� ��������\n";
		cout << "5 -	����� ������\n";
		cout << "6 -	������� ������\n";
		cout << "7 -	�����\n";
		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1: printf("������� ���������� ������:"); cin >> quantity; Root = makeTree(Root, left_count, right_count, quantity);	break;
		case 2:
			insertElem(Root, key++, 1 + rand() % 500, left_count, right_count); break;
		case 3:  cout << "\n������� ����: ";  cin >> key;
			rc = search(Root, key);
			if (rc != NULL)
			{
				cout << "��������� �����= ";
				cout << rc->number << endl;
			}break;
		case 4:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root != NULL)
		{
			cout << "������ ��������� �� 90 ����. �����" << endl;
			view(Root, 0);
		}
			  else cout << "������ ������\n"; break;
		case 6:  delAll(Root); Root = NULL; break;
		case 7:  exit(0);
		}
	}
}

Tree* makeTree(Tree* Root, int& left, int& right, int quantity)    //�������� ������
{
	if (Root == NULL)	// ���� ������ �� �������
	{
		key = 0;
		Root = list(key++, 1 + rand() % 500);	// ��������� ��������� �� ������
	}
	for (; quantity - 1 > 0; quantity--)        //���������� ���������
	{
		insertElem(Root, key++, 1 + rand() % 500, left, right);
	}
	return Root;
}

Tree* list(int i, int s)     //�������� ������ ��������
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->number = s;
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, int s, int& left, int& right)  //���������� ������ ��������
{
	Tree* Prev = NULL;	     // Prev - ������� ����� �������
	while (t)
	{
		Prev = t;
		if (t->Left)
		{
			if (t->Right)
			{
				t = t->Right;
			}
			else
			{
				t = list(key, s);
				Prev->Right = t;
				right++;
				return t;
			}
		}
		else
		{
			t = list(key, s);
			Prev->Left = t;
			left++;
			return t;
		}
	}
}

Tree* delet(Tree* Root, int key)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� ����� 
		else
			Prev_Del->Right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //����� �������� �� ����� 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < n->key)
			rc = search(n->Left, key);
		else
			if (key > n->key)
				rc = search(n->Right, key);
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}

void view(Tree* t, int level) //����� ������ 
{
	if (t == NULL)return;
	else
	{
		view(t->Left, ++level);
		for (int i = 0; i < level; i++)
			cout << "      ";
		int tm = t->key;
		cout << tm << ' ';
		cout << t->number << endl;
		level--;
	}
	view(t->Right, ++level);
}

void delAll(Tree* t) //������� ������
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}