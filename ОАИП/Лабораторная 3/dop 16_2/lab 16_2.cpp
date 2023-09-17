#include <fstream>
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	char str[50];
	int k, i;
	ofstream file1("File3.txt");
	ifstream file2("File3.txt");
	ofstream file3("File4.txt");
	cout << "Введите строку" << endl;
	cin.getline(str, 50);
	file1 << str;
	file1.close();
	while (!file2.eof())
	{
		file2.getline(str, 50);
		cout << "Строка прочитанная из файла:\t" << str << endl;
		cout << "Четный числа записаны в файл\t";
		for (i = 0; str[i] != 0; i++)
			if (str[i] == '2' || str[i] == '4' || str[i] == '6' || str[i] == '8' || str[i] == '0')
				cout << str[i] << "\t";

	}
	file2.close();
	file3.close();
}