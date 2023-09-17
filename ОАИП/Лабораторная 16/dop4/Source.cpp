#include "Hash_Twin_Chain.h"
#include <iostream>
#include<fstream>
#include<tchar.h>
using namespace std;
struct AAA
{
	int key;
	int mas;
	AAA(int k, int z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = 0;
	}
};
//-------------------------------
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "¬ведите размер хеш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	hashTC::Object H2 = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - —читывание из файла" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	 ifstream fl;
			int str;
			int k;
			fl.open("file.txt");
			while (!fl.eof())
			{

				AAA* a = new AAA;
				fl >> str;
				a->key = str;
				a->mas = str;	
				H2.insert(a);
			}
			cout << "ƒанные считались" << endl;
			fl.close();
		}
			  break;
		case 1:
		{
			
			H2.Scan();
		}
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			b->key = k;
			H2.deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			c->key = k;
			if (H2.search(c) == NULL)
				cout << "Ёлемент не найден" << endl;
			else
			{
				cout << "ѕервый элемент с данным ключом" << endl;
				AAA_print(H2.search(c));
				cout << endl;
				
			}
			break;
		
		}
	}
	return 0;
}

