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
        cerr << "���������� ������� ���� " << fileName << endl;
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
        cerr << "���������� ������� ���� " << fileName << endl;
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
        {"����", 20, "CS101"},
        {"�����", 22, "CS102"},
        {"���", 21, "CS103"}
    };

    string txt_file = "students.txt";
    string bin_file = "students.bin";

    // 1. ������� ��������� ����
    save_to_txt(students, txt_file);

    // 2. ������ ������ �� ���������� �����
    cout << "������ �� ���������� �����:" << endl;
    read_from_txt(txt_file);

    // 3. ���������� ����� ������� � ��������� � ��������� ����
    vector<Student> new_students = {
        {"���", 19, "CS104"},
        {"�����", 23, "CS105"}
    };
    save_to_txt(new_students, txt_file);

    // 4. ������� �������� ����
    save_to_bin(students, bin_file);

    // 5. ������ ������ �� ��������� �����
    cout << "������ �� ��������� �����:" << endl;
    read_from_bin(bin_file);

    // 6. ���������� ����� ������� � ��������� � �������� ����
    save_to_bin(new_students, bin_file);

    return 0;
}
