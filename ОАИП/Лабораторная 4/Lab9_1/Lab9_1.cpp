#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void zad9_1() {
    string filename1 = "FILE1.txt";
    string filename2 = "FILE2.txt";
    int n1 = 2;
    int n2 = 5;
    ifstream file1(filename1);
    if (!file1.is_open()) {
        cout << "Ошибка открытия файла " << filename1 << endl;
    }
    ofstream file2(filename2);
    if (!file2.is_open()) {
        cout << "Ошибка открытия файла " << filename2 << endl;
    }
    string line;
    int line_num = 0;
    int word_count = 0;
    while (getline(file1, line)) {
        line_num++;
        if (line_num >= n1 && line_num <= n2 && line[0] == 'C') {
            file2 << line << endl;
            if (word_count == 0) {
                size_t pos = 0;
                while ((pos = line.find(" ", pos)) != string::npos) {
                    word_count++;
                    pos++;
                }
                word_count++;
            }
        }
    }
    file1.close();
    file2.close();
    cout << "Количество слов в первой строке файла " << filename2 << ": " << word_count << endl;
}

void zad9_2()
{
    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    ofstream file("text.txt");
    file << str;
    file.close();

    ifstream readFile("text.txt");
    if (readFile.is_open()) {
        int count = 1;
        int min_length = INT_MAX;
        int min_pos = -1;
        string word;
        while (readFile >> word) {
            int length = word.length();
            if (length < min_length) {
                min_length = length;
                min_pos = count;
            }
            cout << count << ". " << word << " - " << length << " символов" << endl;
            count++;
        }
        cout << "Слово с минимальной длиной - " << min_pos << "-е, " << "содержит " << min_length << " символов" << endl;
    }
    else {
        cout << "Ошибка открытия файла!";
    }
    readFile.close();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    zad9_2();
}