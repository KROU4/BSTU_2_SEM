#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int age;
    string group;
};

void save_to_txt(const vector<Student>& students, const string& fileName) {
    ofstream file(fileName, ios::app);

    for (const auto& student : students) {
        file << student.name << " " << student.age << " " << student.group << endl;
    }

    file.close();
}

void read_from_txt(const string& fileName) {
    ifstream file(fileName);
    Student temp;

    if (!file.is_open()) {
        cerr << "Невозможно открыть файл " << fileName << endl;
        return;
    }

    while (file >> temp.name >> temp.age >> temp.group) {
        cout << temp.name << " " << temp.age << " " << temp.group << endl;
    }

    file.close();
}

void save_to_bin(const vector<Student>& students, const string& fileName) {
    ofstream file(fileName, ios::binary | ios::app);

    for (const auto& student : students) {
        file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    file.close();
}

void read_from_bin(const string& fileName) {
    ifstream file(fileName, ios::binary);
    Student temp;

    if (!file.is_open()) {
        cerr << "Невозможно открыть файл " << fileName << endl;
        return;
    }

    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        cout << temp.name << " " << temp.age << " " << temp.group << endl;
    }

    file.close();
}

int main() {
    setlocale(0, "rus");
    vector<Student> students = {
        {"Джон", 20, "CS101"},
        {"Алиса", 22, "CS102"},
        {"Боб", 21, "CS103"}
    };

    string txt_file = "students.txt";
    string bin_file = "students.bin";

    // 1. Создать текстовый файл
    save_to_txt(students, txt_file);

    // 2. Чтение данных из текстового файла
    cout << "Чтение из текстового файла:" << endl;
    read_from_txt(txt_file);

    // 3. Добавление новых записей о студентах в текстовый файл
    vector<Student> new_students = {
        {"Ева", 19, "CS104"},
        {"Чарли", 23, "CS105"}
    };
    save_to_txt(new_students, txt_file);

    // 4. Создать двоичный файл
    save_to_bin(students, bin_file);

    // 5. Чтение данных из двоичного файла
    cout << "Чтение из двоичного файла:" << endl;
    read_from_bin(bin_file);

    // 6. Добавление новых записей о студентах в двоичный файл
    save_to_bin(new_students, bin_file);

    return 0;
}
