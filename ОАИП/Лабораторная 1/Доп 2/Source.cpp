#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int N = 3;

struct TRAIN
{
    string destination;
    int trainNumber;
    string departureTime;
};

//функция для сортировки поездов по алфавиту
void sort(TRAIN* trains, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (trains[j].destination > trains[j + 1].destination)
            {
                TRAIN temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Создаем массив объектов типа TRAIN 
    TRAIN trains[N];

    // Вводим данные о поездах с клавиатуры
    for (int i = 0; i < N; i++)
    {
        cout << "Введите название пункта назначения для поезда №" << i + 1 << ": ";
        cin >> trains[i].destination;
        cout << "Введите номер поезда №" << i + 1 << ": ";
        cin >> trains[i].trainNumber;
        cout << "Введите время отправления поезда №" << i + 1 << ": ";
        cin >> trains[i].departureTime;
        cout << endl;
    }

    // Сортируем поезда по алфавиту
    sort(trains, N);

    // Запрашиваем у пользователя время отправления
    string time;
    cout << "Введите время отправления: ";
    cin >> time;
    cout << endl;

    // Выводим информацию о поездах, которые отправляются после введенного времени
    bool isFound = false;
    cout << "Поезда, отправляющиеся после " << time << " ->" << endl;
    for (int i = 0; i < N; i++)
    {
        if (trains[i].departureTime > time)
        {
            cout << "Поезд №" << trains[i].trainNumber << " идет в " << trains[i].destination << " в " << trains[i].departureTime << endl;
            isFound = true;
        }
    }
    if (!isFound)
    {
        cout << "Поездов после " << time << " нет." << endl;
    }

    return 0;
}