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

    cout << "Введите данные о наличии санаторных путевок:" << endl;

    do {
        Sanatorium sanatorium;
        cout << "Название санатория: ";
        cin >> sanatorium.Name;
        cout << "Место расположения: ";
        cin >> sanatorium.Location;
        cout << "Лечебный профиль: ";
        cin >> sanatorium.TreatmentProfile;
        cout << "Количество путевок: ";
        cin >> sanatorium.TicketsCount;

        sanatoriums.push_back(sanatorium);

        cout << "Для продолжения добавления данных нажмите Y, для выхода - N: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    // Сортируем данные по лечебным профилям санаториев
    sort(sanatoriums.begin(), sanatoriums.end(),
        [](const Sanatorium& sanatorium1, const Sanatorium& sanatorium2) {
            return sanatorium1.TreatmentProfile < sanatorium2.TreatmentProfile;
        });

    cout << endl << "Список санаториев:" << endl;
    cout << "Название санатория\tМесто расположения\tЛечебный профиль\tКоличество путевок" << endl;

    for (const auto& sanatorium : sanatoriums) {
        // Выводим таблицу с данными
        cout << sanatorium.Name << "\t\t\t" << sanatorium.Location << "\t\t\t"
            << sanatorium.TreatmentProfile << "\t\t\t" << sanatorium.TicketsCount << endl;
    }

    // Запрашиваем количество путевок
    do {
        cout << "Введите количество путевок, необходимое для поиска (не менее 5): ";
        cin >> ticketsCount;

        if (ticketsCount < 5)
            cout << "Минимальное количество путевок должно быть 5 или больше" << endl;
        else
            isNumber = true;
    } while (!isNumber);

    cout << endl << "Санатории с количеством путевок не менее " << ticketsCount << ":" << endl;
    cout << "Название санатория\tМесто расположения\tЛечебный профиль\tКоличество путевок" << endl;

    for (const auto& sanatorium : sanatoriums) {
        // Поиск и вывод результатов
        if (sanatorium.TicketsCount >= ticketsCount)
            cout << sanatorium.Name << "\t\t\t" << sanatorium.Location << "\t\t\t"
            << sanatorium.TreatmentProfile << "\t\t\t" << sanatorium.TicketsCount << endl;
    }

    return 0;
}