#include "stdafx.h"

string A = "A.txt";
char str[100];
int numOfnumber;
int z = 0, m = 0;
int* arr = new int[0];
int* arr2 = new int[0];
int* arr3 = new int[0];

void push(comp** top, int D)
{
	comp* q = new comp();
	q->Data = D;
	if (top == NULL)
	{
		*top = q;
	}
	else
	{
		q->next = *top;
		*top = q;
	}
}

void delete_key(comp** top, int N)
{
	comp* q = *top;
	comp* prev = NULL;
	while (q != NULL)
	{
		if (q->Data == N)
		{
			if (q == *top)
			{

				*top = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
			else
			{
				prev->next = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
		}
		prev = q;
		q = q->next;
	}
}

void find(comp* top, int N)
{
	comp* q = top;
	comp* prev = NULL;
	cout << "Переменных со значением: " << N << endl;
	while (q != NULL)
	{
		if (q->Data == N) cout << q->Data << endl;
		prev = q;
		q = q->next;
	}
}

void print(comp* top)
{
	comp* q = top;
	while (q)
	{
		cout << q->Data << " --> ";
		q = q->next;
	}
	cout << "NULL" << endl;
}

bool extract(comp** top)
{
	comp* q = *top;
	if (q != NULL)
	{
		*top = q->next;
		free(q);
	}
	else return 0;

	return 1;
}

void toFile(comp* top)
{
	numOfnumber = 0;
	ofstream fAout(A);
	if (fAout.is_open())
	{
		if (top == NULL)
		{
			fAout << "Список пуст" << endl;
		}
		else
		{
			while (top != NULL)
			{
				fAout << top->Data << endl;
				numOfnumber++;
				top = top->next;
			}
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}

void fromFile(comp** top)
{
	int* arr = new int[numOfnumber], n;
	ifstream fAin(A);
	if (fAin.is_open())
	{
		clear(top);
		for (int i = 0; i < numOfnumber; i++)
		{
			fAin.getline(str, sizeof(str));
			arr[i] = atoi(str);
		}
		for (int i = numOfnumber - 1; i >= 0; i--)
		{
			push(top, arr[i]);
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();
	delete[] arr;
}

void taskVar2(comp** top)
{
	cout << "Разработать функцию, которая удаляет из стека первый отрицательный элемент, если такой есть." << endl;
	comp* q = *top;
	comp* prev = NULL;
	while (q != NULL)
	{
		if (q->Data % 2 == 0)
		{

		}
		prev = q;
		q = q->next;
	}
}

void taskVar3(comp** top)
{
	cout << "Разработать функцию, которая удаляет первый положительный элемент, если такой есть." << endl;
	comp* q = *top;
	comp* prev = NULL;
	while (q != NULL)
	{
		if (q->Data > 0)
		{
			if (q == *top)
			{

				*top = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
			else
			{
				prev->next = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
		}
		prev = q;
		q = q->next;
	}
}

void task3_1(Stask3* top, int n)
{
	Stask3* q = top;
	for (int i = 0; i < n; i++)
	{
		if (i >= n / 2) cout << q->Data;
		q = q->next;
	}
}

void task3_2(Stask3* top, int n)
{
	Stask3* q = top;
	for (int i = 0; i < n / 2; i++)
	{
		cout << q->Data;
		q = q->next;
	}
}

void task3()
{
	cout << "Дана величина a строкового типа из четного количества символов. Получить и напечатать величину b, состоящую из симво-лов первой половины величины a, записанных в обратном порядке, после которых идут символы второй половины величи-ны a, также записанные в обратном порядке (например, при а = “привет” b должно быть равно «ирптев»)" << endl;
	Stask3* top = NULL;
	int n;
	cout << "Введите кол-во символов(чётное): ";
	cin >> n;
	char* arr = new char[n];
	cout << "Введите слово: ";
	cin >> arr;

	for (int i = 0; i < n; i++)
	{
		Stask3* q = new Stask3();
		q->Data = arr[i];
		if (top == NULL)
		{
			top = q;
		}
		else
		{
			q->next = top;
			top = q;
		}
	}
	task3_1(top, n);
	task3_2(top, n);
}

void task4()
{
	cout << "Создать стек с целочисленным информационным полем. Заполнить его длинами строк, считанных из файла. Распечатаьть на экране содержимое стека. Указать номер и длину последней самой короткой строки файла" << endl;
	Stask4* top = NULL;
	const int sizeArr = 7;
	string arr[sizeArr] = { "123456", "123", "1234567890123" , "12345678" , "123" , "1234" , "1234567" };

	ifstream fAin(A);
	ofstream fAout(A);

	if (fAout.is_open())
	{
		for (int i = 0; i < sizeArr; i++)
		{
			cout << i + 1 << ") " << arr[i] << endl;
			fAout << arr[i] << "\n";
		}
	}
	fAout.close();

	if (fAin.is_open())
	{
		for (int i = 0; i < sizeArr; i++)
		{
			fAin.getline(str, sizeof(str));
			Stask4* q = new Stask4();
			q->num = i;
			q->size = strlen(str);
			if (top == NULL)
			{
				top = q;
			}
			else
			{
				q->next = top;
				top = q;
			}
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();

	Stask4* q = top;
	int min, size;
	min = q->num;
	size = q->size;
	while (q != NULL)
	{
		if (q->size < size)
		{
			min = q->num;
			size = q->size;
		}
		q = q->next;
	}

	cout << "Номер строки = " << min + 1 << " и её размер = " << size << endl;
}

void fun(int*& arr, int x)
{
	int* temp = new int[_msize(arr) / 4 + 1];
	for (size_t i = 0; i < _msize(arr) / 4; i++)
	{
		temp[i] = arr[i];
	}
	temp[_msize(arr) / 4] = x;
	delete[]arr;
	arr = temp;
}

void clear(comp** top)
{
	while (extract(top));
}

void Add1(Stack1** s1, int D) {	//Добавление элементов в стек 1
	Stack1* a = new Stack1();



	fun(arr, D);
	a->data = D;
	if (s1 == NULL)
	{
		*s1 = a;
	}
	else
	{
		a->Next = *s1;
		*s1 = a;
	}

}

void Add2(Stack2** s2, int D) {	//Добавление элементов в стек 2
	Stack2* u = new Stack2();

	fun(arr2, D);
	u->data = D;
	if (s2 == NULL)
	{
		*s2 = u;
	}
	else
	{
		u->Next = *s2;
		*s2 = u;
	}

}

void Add3(comp** top, int x)
{
	comp* u = new comp();
	u->Data = x;
	if (top == NULL)
	{
		*top = u;
	}
	else
	{
		u->next = *top;
		*top = u;
	}
}

void Show1(Stack1* s1) {	//Вывод стека 1 на экран
	Stack1* a = s1;
	while (a)
	{
		cout << a->data << " --> ";
		a = a->Next;
	}
	cout << "NULL" << endl;
}

void Show2(Stack2* s2) {	//Вывод стека 2 на экран
	Stack2* u = s2;
	while (u)
	{
		cout << u->data << " --> ";
		u = u->Next;
	}
	cout << "NULL" << endl;
}



void Showw(comp* top) {	//Вывод стека 2 на экран
	for (size_t i = 0; i < _msize(arr3) / 4; i++)
	{
		Add3(&top, arr3[i]);
	}
	comp* u = top;
	while (u)
	{
		cout << u->Data << " --> ";
		u = u->next;
	}
	cout << "NULL" << endl;
}
void Show(comp** top) {	//Вычисление элементов стека Stack
	comp* q = new comp();
	Stack2* hz = new Stack2();
	int z = 0;

	for (int i = 0; i < _msize(arr) / 4; i++)
	{
		for (int k = 0; k < _msize(arr2) / 4; k++) {
			if (arr[i] == arr2[k]) break;
			if (k == _msize(arr2) / 4 - 1) fun(arr3, arr[i]);

		}

	}
	for (int i = 0; i < _msize(arr2) / 4; i++)
	{
		for (int k = 0; k < _msize(arr) / 4; k++) {
			if (arr2[i] == arr[k]) break;
			if (k == _msize(arr) / 4 - 1) fun(arr3, arr2[i]);

		}

	}


}


int menu()
{
	int n;
	cout << endl;
	cout << " 1. Добавление числа" << endl;
	cout << " 2. Удаление числа" << endl;
	cout << " 3. Поиск числа" << endl;
	cout << " 4. Вывод стека в консольное окно" << endl;
	cout << " 5. Извлечение числа" << endl;
	cout << " 6. Запись стека в файл" << endl;
	cout << " 7. Считывание стека из файла" << endl;
	cout << " 8. Очистка стека" << endl;
	cout << " 9. Задание" << endl;
	cout << " 10. Задание" << endl;
	cout << " 11. Дополнительное 1" << endl;
	cout << " 12. Дополнительное 2" << endl;
	cout << " 0. Выход" << endl;
	cout << "(Введите выбор) ";
	cin >> n;
	cout << endl;
	return n;
}

int menu2()
{
	int n;
	cout << "\n\nРазработать функцию, которая формирует стек Stack,\n включив в него по одному разу элементы, которые входят в один из стеков Stack1 и Stack2,\n но не входят в другой. Выберите команду:" << endl;
	cout << "1 - Добавление в Stack1" << endl;
	cout << "2 - Добавление в Stack2" << endl;
	cout << "3 - Вывод Stack1" << endl;
	cout << "4 - Вывод Stack2" << endl;
	cout << "5 - Создание Stack" << endl;
	cout << "6 - Вывод Stack" << endl;
	cout << "7 - Выход" << endl;
	cin >> n;
	cout << endl;
	return n;
}