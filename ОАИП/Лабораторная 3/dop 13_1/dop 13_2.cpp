#include <fstream>
#include <iostream>
using namespace std;
void main()
{

	setlocale(LC_ALL, "rus");
	char str[50];
	int k, i, l = 0,c=0,u=0;
	ofstream file1("File3.txt");
	ifstream file2("File3.txt");
	ofstream file3("File4.txt");
	cout << "Введите строку" << endl;
	cin.getline(str, 50);
	file1 << str << "\n";
	file1.close();
	while (!file2.eof())
	{
	file2.getline(str, 50);
		cout << "Строка прочитанная из файла:\t" << str << endl;
		for (i = 0; str[i] != 0; i++)
			if (str[i] == '(' || str[i] == ')')
			{
				l++;
			}
		for (i = 0; str[i] != 0; i++)
		if (str[i] == '[' || str[i] == ']')
		{
			c++;
		}
		for (i = 0; str[i] != 0; i++)
		if (str[i] == '{' || str[i] == '}')
		{
			u++;
		}
	 }
	cout << "Количество круглых скобок=" << l << endl;
	cout << "Количество квадратных скобок=" << c << endl;
	cout << "Коичество фигурных скобок=" << u << endl;
	file2.close();
	file3.close();
}