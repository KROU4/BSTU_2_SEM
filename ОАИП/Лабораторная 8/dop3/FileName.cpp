#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Item {
    char data;
    Item* next;
};

Item* head = nullptr;
Item* tail = nullptr;

bool isNull() {
    return (head == nullptr);
}

void insertToQueue(char x) {
    Item* p = new Item;
    p->data = x;
    p->next = nullptr;

    if (isNull()) {
        head = tail = p;
    }
    else {
        tail->next = p;
        tail = p;
    }
}

void processLine(string& line) {
    for (char ch : line) {
        if (isdigit(ch)) {
            insertToQueue(ch);
        }
    }
}

void printQueue(ofstream& out) {
    if (!isNull()) {
        Item* p = head;
        while (p != nullptr) {
            out << p->data;
            p = p->next;
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    ifstream inFile("f.txt");
    ofstream outFile("g.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Ошибка при открытии файла." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        processLine(line);

        outFile << line;
        printQueue(outFile);
        outFile << endl;
    }

    inFile.close();
    outFile.close();

    cout << "Файл успешно обработан." << endl;

    return 0;
}
