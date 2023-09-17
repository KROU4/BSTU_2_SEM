#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TABLE_SIZE = 100;

struct Passport {
    string name;
    int number;
};

class HashTable {
private:
    Passport* table[TABLE_SIZE];
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    int hash(int key) {
        return key ^ (key >> 1);
    }

    void insert(Passport* passport) {
        int index = hash(passport->number) % TABLE_SIZE;
        int originalIndex = index;

        while (table[index] != nullptr) {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                cout << "Хеш-таблица заполнена!" << endl;
                return;
            }
        }

        table[index] = passport;
    }

    Passport* search(int key) {
        int index = hash(key) % TABLE_SIZE;
        int originalIndex = index;

        while (table[index] != nullptr && table[index]->number != key) {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                return nullptr;
            }
        }

        return table[index];
    }

    void printAllNumbers() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                cout << table[i]->number << endl;
            }
        }
    }
};

int main() {
    setlocale(0, "rus");
    srand(time(nullptr));

    HashTable hashTable;

    for (int i = 0; i < 20; i++) {
        Passport* passport = new Passport();
        passport->number = rand() % 1000000;
        passport->name = "Имя" + to_string(i);
        hashTable.insert(passport);
    }

    cout << "Список существующих номеров паспорта: " << endl;
    hashTable.printAllNumbers();

    cout << "Введите номер паспорта для поиска: ";
    int searchNumber;
    cin >> searchNumber;

    Passport* result = hashTable.search(searchNumber);

    if (result != nullptr) {
        cout << "Найден паспорт с номером: " << result->number << " и именем: " << result->name << endl;
    }
    else {
        cout << "Паспорт не найден!" << endl;
    }

    return 0;
}
