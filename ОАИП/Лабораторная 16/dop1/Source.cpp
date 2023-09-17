#include<iostream>

using namespace std;
struct ListNode
{
	char letter;
	int number;
	ListNode* next;

};

unsigned char HashFunction(char* str, int MAX_TABLE_SIZE)
{
	unsigned char h = 0;
	while (*str)
		h += *str++;
	return h % MAX_TABLE_SIZE;
}

void hashtab_init(ListNode* hashtab[], int MAX_TABLE_SIZE)
{
	for (int i = 0; i < MAX_TABLE_SIZE; i++)
	{
		hashtab[i] = nullptr;
		
	}

}
void add_element(ListNode* hashtab[], char* str1, int counter, char symbol, int MAX_TABLE_SIZE)
{
	ListNode* node = new ListNode;
	int index = HashFunction(str1, MAX_TABLE_SIZE);
	if (node != NULL)
	{
		node->letter = symbol;
		node->number = counter;
		node->next = hashtab[index];
		hashtab[index] = node;

	}

}

void out(ListNode** hashtab, int MAX_TABLE_SIZE)
{
	int index = 0, counter = 0;
	struct ListNode* node;

	for (; index < MAX_TABLE_SIZE; index++)
	{
		for (node = hashtab[index]; node != NULL; node = node->next)
		{
			if (node != NULL)

			{
				cout << endl;
				cout << node->letter <<"-->";
				cout << node->number << endl;
			}

		}

	}
}
void findLetter(ListNode** hashtab, int MAX_TABLE_SIZE, char fleter)
{
	int index = 0;
	struct ListNode* node;

	for (; index < MAX_TABLE_SIZE; index++)
	{
		for (node = hashtab[index]; node != NULL; node = node->next)
		{
			if (node != NULL)
				if (node->letter == fleter)
				{
					cout << endl;
					cout << "Найдена буква ";
					cout << node->letter << endl;
					cout << "Количество её вхождений в строку составило:" << node->number << endl;
					return;
				}

		}

	}
	cout << "Данной буквы нет в хеш-таблице" << endl;
}

int main()
{
	int size = 10, counter = 0;
	char strV[100];
	setlocale(LC_ALL, "ru");
	ListNode** hashtab = new ListNode * [size];
	short int choice = 0;
	hashtab_init(hashtab, size);
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - поиск буквы в таблице" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2:
		{
			char symbol;
			cout << "Введите строку:";
			cin >> strV;
			for (int i = 0; strV[i] != '\0'; i++)
			{
				bool uniqueSymbol = true; 
				if (i > 0)
					for (int k = (i - 1); k >= 0; k--)
						if (strV[k] == strV[i])
							uniqueSymbol = false;

				if (uniqueSymbol)
				{
					
					for (int j = 0; j < strlen(strV); j++)
						if (strV[i] == strV[j])

							counter++;
					symbol = strV[i];
					add_element(hashtab, strV, counter, symbol, size);
					counter = 0;
				}
				

			}
			
			
		} break;

		case 1:
		{
			out(hashtab, size);

		} break;



		
		case 3:
		{
			char fleter;
			cout << "Введите букву, которую необходимо найти в хеш-таблице:";
			cin >> fleter;
			findLetter(hashtab, size, fleter);


		}   break;

		}


	}
	return 0;
}