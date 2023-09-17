#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int str;
	int arr[100], k = 0;
	ifstream fin("fileA.txt");
	if (!fin)
	{
		cout << "Error opening file" << endl;
		system("pause");
		return 1;
	}
	ofstream fout("fileB.txt");
	while (fin >> str)
	{
		bool flag = true;
		for (int i = 0; i < k; i++)
		{
			if (arr[i] == str)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			arr[k] = str;
			k++;
			fout << str << endl;
		}
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}