
#include <iostream>
#include <windows.h>
using namespace std;
#define max 100

long long numbers[10] = { 375336939934,375549295069,375444917218,375854392135,375336549932,375339873325, 375843209832,375867485923,375323413245,375339495069 };
const char* names[10] = { "���������","���������","�������","�����","������","�����","������","���������","�������","�����" };
const char* surnames[10] = { "������","���������","����","��������","��������","��������","������","���������","���������","��������" };
int tarifs[10] = { 1,3,2,3,2,1,2,3,2,2 };

struct User
{
	long long number;
	char name[max];
	char surname[max];
	int tarif;
	User* Left, * Right;
};

User* makeUser(User* Root);       //�������� ������
User* list(int i, char* s, char* l, int d); //�������� ������ ��������
User* insertElem(User* t, int number, char* name, char* surname, int tarif); //���������� ������ ��������
User* search(User* n, int number);   //����� �������� �� ������ 
User* delet(User* Root, int number); //�������� �������� �� ������
void view(User* t, int level);    //����� ������ 
void delAll(User* t);             //������� ������
int checkpopT(User* t);
User* fill(User* t);
User* inser�FILL(User* t, int number, const char* name, const char* surname, int tarif);
User* listFILL(int i, const char* s, const char* l, int d);
void printTARIFS();
User* Root = NULL; 	//��������� �����
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
		cout << "1 -	�������� ������\n";
		cout << "2 -	���������� ��������\n";
		cout << "3 -	����� �� ������\n";
		cout << "4 -	�������� ��������\n";
		cout << "5 -	����� ������\n";
		cout << "6 -	������� ������\n";
		cout << "7 -	����� �������� �������\n";
		cout << "8 -	����������� ������ ����������� ������\n";
		cout << "9 -	���������� ������\n";
		cout << "10 -	�����\n";
		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeUser(Root);	break;
		case 2:  int tarif; char name[max], surname[max];
			cout << "������� �����: "; cin >> number;
			cin.ignore();
			cout << "������� ��� "; cin.getline(name, max);
			cout << "������� �������:"; cin.getline(surname, max);
			cout << "������� ����� ������:"; cin >> tarif;
			insertElem(Root, number, name, surname, tarif); break;
		case 3:  cout << "\n������� �����: ";  cin >> number;
			rc = search(Root, number);
			if (rc != NULL)
			{
				cout << "��������� ������: ";
				cout << rc->number << "-" << rc->name << "-" << rc->surname << "-" << rc->tarif << endl;
			}break;
		case 4:  cout << "\n������� ��������� �����: "; cin >> number;
			Root = delet(Root, number);  break;
		case 5:  if (Root != NULL)
		{
			cout << "������ ��������� �� 90 ����. �����" << endl;
			view(Root, 0);
		}
			  else cout << "������ ������\n"; break;
		case 6:  delAll(Root); Root = NULL; break;
		case 7:  printTARIFS(); break;
		case 8: for (int i = 0; i < 3; i++) a[i] = 0; checkpopT(Root);
			if (a[0] > a[1] && a[0] > a[2])
			{
				printf("����� ���������� ����� - ��������\n");
			}
			else if (a[1] > a[2])
			{
				printf("����� ���������� ����� - �����������\n");
			}
			else if (a[0] == a[1])
			{
				printf("����� ���������� ������ - ����������� � �����������\n");
			}
			else if (a[0] == a[2])
			{
				printf("����� ���������� ������ - �������� � ���������\n");
			}
			else if (a[1] == a[2])
			{
				printf("����� ���������� ������ - ����������� � ���������\n");
			}
			else if (a[1] == a[2] == a[0])
			{
				printf("����� ������ ����� ���������\n");
			}
			else
			{
				printf("����� ���������� ����� - ���������\n");
			}
			break;
		case 9:  Root = fill(Root); break;
		case 10:  exit(0);
		}
	}
}

User* makeUser(User* Root)    //�������� ������
{
	int number, tarif; char name[max], surname[max];
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL)	// ���� ������ �� �������
	{
		cout << "������� �����: "; cin >> number;
		if (number < 0) return Root;
		cin.ignore();
		cout << "������� ���: "; cin.getline(name, max);
		cout << "������� �������: "; cin.getline(surname, max);
		cout << "������� ����� ������: "; cin >> tarif;
		Root = list(number, name, surname, tarif);	// ��������� ��������� �� ������
	}
	while (1)                //���������� ���������
	{
		cout << "������� �����: "; cin >> number;
		if (number < 0) return Root;
		cin.ignore();
		cout << "������� ���: "; cin.getline(name, max);
		cout << "������� �������: "; cin.getline(surname, max);
		cout << "������� ����� ������: "; cin >> tarif;
		insertElem(Root, number, name, surname, tarif);
	}
	return Root;
}

User* list(int i, char* s, char* l, int d)     //�������� ������ ��������
{
	User* t = new User[sizeof(User)];
	t->number = i;
	strcpy_s(t->name, s);
	strcpy_s(t->surname, l);
	t->tarif = d;
	t->Left = t->Right = NULL;
	return t;
}

User* insertElem(User* t, int number, char* name, char* surname, int tarif)  //���������� ������ ��������
{
	User* Prev = NULL;	     // Prev - ������� ����� �������
	int find = 0;  // ������� ������  
	while (t && !find)
	{
		Prev = t;
		if (number == t->number)
			find = 1;	   //������ ������ ���� ���������
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

User* delet(User* Root, int number)  //�������� �������� �� ������
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	User* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->number != number)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->number > number)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ ������");
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
		if (Del->number < Prev_Del->number)
			Prev_Del->Left = R; // �� ����� ����� 
		else
			Prev_Del->Right = R;	// �� ������ �����
	int tmp = Del->number;
	cout << "\n������ ������� � �������" << tmp << endl;
	delete Del;
	return Root;
}

User* search(User* n, int number)  //����� �������� �� ������ 
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
		cout << "��� ������ ��������\n";
	return rc;
}

void view(User* t, int level) //����� ������ 
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

void delAll(User* t) //������� ������
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
		if (Root == NULL)	// ���� ������ �� �������
		{
			Root = listFILL(numbers[i], names[i], surnames[i], tarifs[i]);	// ��������� ��������� �� ������
		}
		else
		{
			inser�FILL(Root, numbers[i], names[i], surnames[i], tarifs[i]);
		}
	}
	return Root;
}

User* inser�FILL(User* t, int number, const char* name, const char* surname, int tarif)  //���������� ������ ��������
{
	User* Prev = NULL;	     // Prev - ������� ����� �������
	int find = 0;  // ������� ������  
	while (t && !find)
	{
		Prev = t;
		if (number == t->number)
			find = 1;	   //������ ������ ���� ���������
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

User* listFILL(int i, const char* s, const char* l, int d)     //�������� ������ ��������
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
	printf("������ �������:\n1.��������.\n2.�����������.\n3.���������.\n");
}