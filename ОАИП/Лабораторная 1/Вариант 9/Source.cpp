#include <iostream>
#include <Windows.h>
using namespace std;
void input(int size);
void find(char lastName[]);
typedef struct Students
{
    char fio[16];
    char group[3];
    char date[10];
    char facult[10];
    char special[10];
    char bal[5];
} STUD;
int number; FILE* f; errno_t err;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice[3]; char fio[16];
    do
    {
        cout << "\n1.���� ������ � ���������� � ������ � ����\n";
        cout << "2.����� �� �������\n";
        cout << "0.����� �� ���������\n\n";
        cout << "������� ����� ��������: ";
        cin >> choice[2];
        switch (choice[2])
        {
        case 1: cout << "������� ���������� ���������: ";
            cin >> number;
            input(number);  break;
        case 2: {  cout << "������� �������: ";
            cin >> fio;
            find(fio); break;
        }
        case 0: exit(0);  break;
        }
    } while (choice != 0);
}

void input(int size)
{
    STUD buf = { ' ', ' ', ' ', ' ', ' ', ' ' };
    if (!fopen_s(&f, "base.bin", "ab"))
    {
        for (int p = 0; p < size; p++)
        {
            cout << "�������: ";   cin >> buf.fio;
            cout << "������: ";   cin >> buf.group;
            cout << "���� �����������: "; cin >> buf.date;
            cout << "���������: "; cin >> buf.facult;
            cout << "�����a�������: "; cin >> buf.special;
            cout << "������� ���: "; cin >> buf.bal;
            fwrite(&buf, sizeof(buf), 1, f);
        }
        fclose(f);
    }
    else {
        cout << "������ �������� �����";
        return;
    }
}


void find(char lastName[16])
{

    bool flag = false;  STUD buf;
    if (!fopen_s(&f, "base.bin", "rb"))
    {
        while (!feof(f))
        {
            fread(&buf, sizeof(buf), 1, f);
            if (strcmp(lastName, buf.fio) == 0)   //��������� �����
            {
                cout << "\n�������: " << buf.fio << endl;
                cout << "������: " << buf.group << endl;
                cout << "���� �����������: " << buf.date << endl;
                cout << "���������: " << buf.facult << endl;
                cout << "�����a�������: " << buf.special << endl;
                cout << "������� ���: " << buf.bal << endl;
                flag = true; break;
            }
        }
        fclose(f);
        if (!flag) cout << "������ �� �������\n";
    }
    else
    {
        cout << "������ �������� �����";
        return;
    }
}