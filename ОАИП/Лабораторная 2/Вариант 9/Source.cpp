#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <locale.h>

using namespace std;

// Перечисление дней следования
enum Days {
  Monday = 1,
  Tuesday = 2,
  Wednesday = 3,
  Thursday = 4,
  Friday = 5,
  Saturday = 6,
  Sunday = 7
};

// Структура для хранения данных
struct Train
{
  int number; // Номер поезда
  string destination; // Пункт назначения
  Days days; // Дни следования
  int arrivalTime; // Время прибытия (часы, минуты)
  int departureTime; // Время отправления (часы, минуты)
};

// Функция вывода содержимого структуры
void PrintTrainInfo(Train train)
{
  cout << "Номер поезда: " << train.number << endl;
  cout << "Пункт назначения: " << train.destination << endl;
  cout << "Дни следования: ";
  if (train.days & Monday)
    cout << "Пн ";
  if (train.days & Tuesday)
    cout << "Вт ";
  if (train.days & Wednesday)
    cout << "Ср ";
  if (train.days & Thursday)
    cout << "Чт ";
  if (train.days & Friday)
    cout << "Пт ";
  if (train.days & Saturday)
    cout << "Сб ";
  if (train.days & Sunday)
    cout << "Вс ";
  cout << endl;
  cout << "Время прибытия: " << train.arrivalTime / 100 << ":" << train.arrivalTime % 100 << endl;
  cout << "Время отправления: " << train.departureTime / 100 << ":" << train.departureTime % 100 << endl;
}

// Функция ввода структуры с клавиатуры
Train InputTrainInfo()
{
  Train train;
  int days;
  cout << "Введите номер поезда: ";
  cin >> train.number;
  cout << "Введите пункт назначения: ";
  cin >> train.destination;
  cout << "Укажите дни следования (Пн 1, Вт 2, Ср 4, Чт 8, Пт 16, Сб 32, Вс 64): ";
  cin >> days;
  train.days = (Days)days;
  cout << "Введите время прибытия (ччмм): ";
  cin >> train.arrivalTime;
  cout << "Введите время отправления (ччмм): ";
  cin >> train.departureTime;
  return train;
}

// Функция для вывода меню программы
void ShowMenu()
{
  cout << "Выберите действие:" << endl;
  cout << "1. Добавить рейс." << endl;
  cout << "2. Вывести рейсы." << endl;
  cout << "3. Удалить рейс." << endl;
  cout << "4. Найти рейс по пункту назначения." << endl;
  cout << "0. Выход." << endl;
  cout << "Ваш выбор: ";
}

// Функция для поиска рейса по пункту назначения
void FindTrainByDestination(Train trains[], int size, string destination)
{
  for (int i = 0; i < size; ++i)
  {
    if (trains[i].destination == destination)
    {
      PrintTrainInfo(trains[i]);
      cout << endl;
    }
  }
}

// Функция удаления рейса
void DeleteTrain(Train trains[], int& size, int number)
{
  for (int i = 0; i < size; ++i)
  {
    if (trains[i].number == number)
    {
      for (int j = i; j < size - 1; ++j)
      {
        trains[j] = trains[j + 1];
      }
      size--;
      cout << "Рейс удален." << endl;
      return;
    }
  }
  cout << "Рейс не найден." << endl;
}

int main()
{
  setlocale(LC_ALL, "RUS");
  Train trains[100];
  int size = 0;
  while (true)
  {
    ShowMenu();
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 0:
      return 0;
    case 1:
      trains[size] = InputTrainInfo();
      size++;
      cout << "Рейс добавлен." << endl;
      break;
    case 2:
      for (int i = 0; i < size; ++i)
      {
        PrintTrainInfo(trains[i]);
        cout << endl;
      }
      break;
    case 3:
      int number;
      cout << "Введите номер рейса: ";
      cin >> number;
      DeleteTrain(trains, size, number);
      break;
    case 4:
      string destination;
      cout << "Введите пункт назначения: ";
      cin >> destination;
      FindTrainByDestination(trains, size, destination);
      break;
    }
    _getch();
    system("cls");
  }
  return 0;
}
