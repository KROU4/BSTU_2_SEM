#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int n;
	cout << "Введите кол-во символов: ";
	cin >> n;

	ofstream F1;
	F1.open("F1.txt", ios::out);
	F1 << "Первая строка" << endl;
	F1 << "Вторая строка в котороый больше чем " << n << " символов" << endl;
	F1 << "Третья строка" << endl;
	F1 << "Четвертая строка в которой больше чем  " << n << " символов" << endl;
	F1.close();

	ifstream F1_in;
	F1_in.open("F1.txt", ios::in);

	ofstream F2;
	F2.open("F2.txt", ios::out);
	string line;
	while (getline(F1_in, line))
	{
		if (line.length() > n)
			F2 << line << endl;
	}
	F1_in.close();
	F2.close();

	return 0;
}