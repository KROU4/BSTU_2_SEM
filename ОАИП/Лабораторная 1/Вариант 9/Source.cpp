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
        cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
        cout << "2.Поиск по фамилии\n";
        cout << "0.Выход из программы\n\n";
        cout << "Введите номер операции: ";
        cin >> choice[2];
        switch (choice[2])
        {
        case 1: cout << "Введите количество студентов: ";
            cin >> number;
            input(number);  break;
        case 2: {  cout << "Введите фамилию: ";
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
            cout << "Фамилия: ";   cin >> buf.fio;
            cout << "Группа: ";   cin >> buf.group;
            cout << "Дата поступления: "; cin >> buf.date;
            cout << "Факультет: "; cin >> buf.facult;
            cout << "Специaльность: "; cin >> buf.special;
            cout << "Средний бал: "; cin >> buf.bal;
            fwrite(&buf, sizeof(buf), 1, f);
        }
        fclose(f);
    }
    else {
        cout << "Ошибка открытия файла";
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
            if (strcmp(lastName, buf.fio) == 0)   //сравнение строк
            {
                cout << "\nФамилия: " << buf.fio << endl;
                cout << "Группа: " << buf.group << endl;
                cout << "Дата поступления: " << buf.date << endl;
                cout << "Факультет: " << buf.facult << endl;
                cout << "Специaльность: " << buf.special << endl;
                cout << "Средний бал: " << buf.bal << endl;
                flag = true; break;
            }
        }
        fclose(f);
        if (!flag) cout << "Ничего не найдено\n";
    }
    else
    {
        cout << "Ошибка открытия файла";
        return;
    }
}