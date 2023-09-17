#include "Header.h"
#include <cstdlib>
int main() {
	setlocale(LC_ALL, "ru");
	int choice;
	unordered_map <string, string> m;
	fillTable(m);
	do {
		cout << "\n1 - вывод всех ключевых слов" << endl;
		cout << "2 - поиск ключевого слова" << endl;
		cout << "3 - изменить подсказку для ключевого слова или добавить новое" << endl;
		cout << "0 - выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: print(m); break;
		case 2: {
			string c;
			cout << "\nВведите ключевое слово: ";
			cin >> c;
			findEl(m, c); break;
		}
		case 3: {
			string help;
			cout << "\nВведите подсказку: ";
			cin >> help;
			string keyWord;
			cout << "\nКакое ключевое слово заменить?  ";
			cin >> keyWord;
			changeHelp(m, help, keyWord);
		}
		case 0: break;
		}
	} while (choice);
}