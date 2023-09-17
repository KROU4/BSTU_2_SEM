#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void dop3_1()
{
	int k, num = 0, counter = 0;
	cout << "Введите, с какой строки копировать:\n";
	cin >> k;
	int k1 = k + 3;
	string str;
	ifstream a("a3_1.txt");
	ofstream b("b3_1.txt");
	k--;
	k1--;
	int size;
	while (getline(a, str))
	{
		if (num >= k && num <= k1)
		{
			b << str << '\n';
			size = str.size();
			for (int j = 0; j < size; j++)
			{
				if (str[j] == 'a' || str[j] == 'A' || str[j] == 'o' || str[j] == 'O' || str[j] == 'e' || str[j] == 'E' || str[j] == 'y' || str[j] == 'Y' || str[j] == 'u' || str[j] == 'U' || str[j] == 'i' || str[j] == 'I') counter++;
			}
		}
		num++;
	}
	cout << "В строках с k до k+3 содержится " << counter << " гласных букв.\n";
}

void dop3_2()
{
	string str;
	cout << "Введите строку: ";
	getline(cin, str);
	ofstream outfile("string.txt");
	outfile << str;
	outfile.close();
	ifstream infile("string.txt");
	string word;
	ofstream outfile2("words.txt");
	while (infile >> word)
	{
		outfile2 << word << endl;
		cout << word << endl;
	}
	infile.close();
	outfile2.close();
}

void dop13_1() {
	setlocale(LC_CTYPE, "RUSSIAN");
	ofstream file1("File1_13_1.txt");
	ifstream file2("File1_13_1.txt");
	ofstream file3("File2_13_1.txt");
	ifstream file4("File2_13_1.txt");
	file1 << "Жизнь очень хорошая\nкартина очень ноль\nжизнь красивая и мифическая\nптицы\nЛеший чудовище\nочень\nжизнь\n";
	file1.close();
	char str[256];
	int wrd = 0;
	while (!file2.eof()) {
		file2.getline(str, 256);
		wrd = 1;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == ' ') {
				wrd++;
			}
		}
		if (wrd > 1) {
			file3 << str;
			file3 << '\n';
		}
	}

	file2.close();
	file3.close();
	int max = 0, neps = 0, word = 0, answer = 0;
	while (!file4.eof())
	{
		file4.getline(str, 256);
		for (int l = 0; l < strlen(str); l++)
		{
			if (str[l] == 'и' || str[l] == 'а' || str[l] == 'о' || str[l] == 'у' ||
				str[l] == 'е' || str[l] == 'ё' || str[l] == 'ю' || str[l] == 'я' ||
				str[l] == 'э' || str[l] == 'ы')

				neps++;

			if (str[l] == ' ')
			{
				word++;
				if (neps > max)
				{
					max = neps;
					answer = word;
				}

			}
		}
	}
	cout << "Число с наибольшим количеством гласных под номером: " << answer << endl;
	file4.close();
}

void dop13_2()
{
	setlocale(LC_ALL, "rus");
		char str[50];
		int k, i, l = 0,c=0,u=0;
		ofstream file1("File3_13_2.txt");
		ifstream file2("File3_13_2.txt");
		ofstream file3("File4_13_2.txt");
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

void dop16_1()
{
	setlocale(LC_ALL, "rus");
		char str[256];
		int k, j = 1, l = 1,c=0;
		
		ofstream file1("File1_16_1.txt");
		ifstream file2("File1_16_1.txt");
		ofstream file3("File2_16_1.txt");
		ifstream file4("File2_16_1.txt");
		file1 << "Жизнь очень хорошая\nкартина очень красивая\nпогода такая пасмурная\nптицы прилетают весной\nЛеший-мифическое чудовище\nочень кра23сиво\nлань\n";
		file1.close();
		while (!file2.eof())
		{
			file2.getline(str, 256);
			if (j == 1 || j == 2 || j == 6)
				file3 << str << "\n";
			j++;
			
		}
		file2.close();
		file3.close();
		while (!file4.eof())
		{
			file4.getline(str, 256);
			if ( l== 3)
			cout << str << endl;
			l++;
			for (int i = 0; i<strlen(str); i++)
				if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
				{
					c++;
				}
		}
		cout << c << endl;
}

void dop16_2()
{
	char str[50];
	int k, i;
	ofstream file1("File3_16_2.txt");
	ifstream file2("File3_16_2.txt");
	ofstream file3("File4_16_2.txt");
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

int main()
{
	setlocale(LC_ALL, "ru");
	dop16_2();
}