#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Sanatorium {
    string Name;
    string Location;
    string TreatmentProfile;
    int TicketsCount;
};

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Sanatorium> sanatoriums;
    int ticketsCount;
    char choice;
    bool isNumber = false;

    cout << "������� ������ � ������� ���������� �������:" << endl;

    do {
        Sanatorium sanatorium;
        cout << "�������� ���������: ";
        cin >> sanatorium.Name;
        cout << "����� ������������: ";
        cin >> sanatorium.Location;
        cout << "�������� �������: ";
        cin >> sanatorium.TreatmentProfile;
        cout << "���������� �������: ";
        cin >> sanatorium.TicketsCount;

        sanatoriums.push_back(sanatorium);

        cout << "��� ����������� ���������� ������ ������� Y, ��� ������ - N: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    // ��������� ������ �� �������� �������� ����������
    sort(sanatoriums.begin(), sanatoriums.end(),
        [](const Sanatorium& sanatorium1, const Sanatorium& sanatorium2) {
            return sanatorium1.TreatmentProfile < sanatorium2.TreatmentProfile;
        });

    cout << endl << "������ ����������:" << endl;
    cout << "�������� ���������\t����� ������������\t�������� �������\t���������� �������" << endl;

    for (const auto& sanatorium : sanatoriums) {
        // ������� ������� � �������
        cout << sanatorium.Name << "\t\t\t" << sanatorium.Location << "\t\t\t"
            << sanatorium.TreatmentProfile << "\t\t\t" << sanatorium.TicketsCount << endl;
    }

    // ����������� ���������� �������
    do {
        cout << "������� ���������� �������, ����������� ��� ������ (�� ����� 5): ";
        cin >> ticketsCount;

        if (ticketsCount < 5)
            cout << "����������� ���������� ������� ������ ���� 5 ��� ������" << endl;
        else
            isNumber = true;
    } while (!isNumber);

    cout << endl << "��������� � ����������� ������� �� ����� " << ticketsCount << ":" << endl;
    cout << "�������� ���������\t����� ������������\t�������� �������\t���������� �������" << endl;

    for (const auto& sanatorium : sanatoriums) {
        // ����� � ����� �����������
        if (sanatorium.TicketsCount >= ticketsCount)
            cout << sanatorium.Name << "\t\t\t" << sanatorium.Location << "\t\t\t"
            << sanatorium.TreatmentProfile << "\t\t\t" << sanatorium.TicketsCount << endl;
    }

    return 0;
}