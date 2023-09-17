#include <iostream>         // ���������� ���������� ��� ������ � �������� �����-������
#include <nlohmann/json.hpp> // ���������� ���������� ��� ������ � JSON
#include <fstream>          // ���������� ���������� ��� ������ � �������

using json = nlohmann::json; // ������� ��������� ��� ���� nlohmann::json ��� ��������

// ������� ��� ������ JSON-����� � ������ ��� ����������� �� �����
void read_json_file(const std::string& filename) {
    std::ifstream file(filename); // ��������� ���� ��� ������
    if (file.is_open()) {         // ���� ���� ������� ������
        json j;                   // ������� ������ JSON
        file >> j;                // ��������� ������ �� ����� � ������ JSON
        // ������� ��������� JSON ������ � �������� � 4 �������
        std::cout << "��������� JSON ������:\n" << j.dump(4) << std::endl;
    }
    else {
        // ������� ��������� �� ������, ���� ���� �� ������� �������
        std::cerr << "������: ���������� ������� ���� " << filename << std::endl;
    }
}

// ������� ��� ������ JSON-������� � ����
void write_json_file(const json& j, const std::string& filename) {
    std::ofstream file(filename); // ��������� ���� ��� ������
    if (file.is_open()) {         // ���� ���� ������� ������
        file << j.dump(4);        // ���������� JSON ������ � ���� � �������� � 4 �������
    }
    else {
        // ������� ��������� �� ������, ���� ���� �� ������� �������
        std::cerr << "������: ���������� ������� ���� " << filename << std::endl;
    }
}

int main() {
    setlocale(0, "rus");       // ������������� ����������� ��� ����������� ������ ���������
    int choice;                // ���������� ��� ������ �������� �������������
    std::string filename;      // ���������� ��� �������� ����� �����
    json person;               // JSON ������ ��� �������� ������ � ��������

    while (true) { // ����������� ���� ��� ������ �������� �������������
        std::cout << "�������� ��������:\n"
            << "1. ���� �����, ������� � ��������\n"
            << "2. ������ ������ � JSON ����\n"
            << "3. ������ JSON �����\n"
            << "4. ����� ������� ������\n"
            << "0. �����\n";
        std::cin >> choice; // ��������� ����� ������������

        switch (choice) { // ��������� � ����������� �� ������ ������������
        case 1: {
            std::string name, surname;
            int age;
            // ������ ���, ������� � ������� � ����������
            std::cout << "������� ���: ";
            std::cin >> name;
            std::cout << "������� �������: ";
            std::cin >> surname;
            std::cout << "������� �������: ";
            std::cin >> age;

            // ��������� ��������� ������ � JSON ������
            person["name"] = name;
            person["surname"] = surname;
            person["age"] = age;
            break;
        }
        case 2: {
            // ������ ��� ����� ��� ������ � �������� ������� ������ ������ � ����
            std::cout << "������� ��� ����� ��� ������: ";
            std::cin >> filename;
            write_json_file(person, filename);
            break;
        }
        case 3: {
            // ������ ��� ����� ��� ������ � �������� ������� ������ ������ �� �����
            std::cout << "������� ��� ����� ��� ������: ";
            std::cin >> filename;
            read_json_file(filename);
            break;
        }
        case 4: {
            // ������� ������� ������ �� JSON ������� �� ����� � �������� � 4 �������
            std::cout << "������� ������:\n" << person.dump(4) << std::endl;
            break;
        }
        case 0: // ��������� ������ ���������
            return 0;
        default: // ������� ��������� �� ������ ��� ������������ ������
            std::cerr << "�������� �����. ��������� �������." << std::endl;
        }
    }

    return 0;
}
