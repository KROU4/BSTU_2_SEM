#include <iostream>
using namespace std;

struct Item {
    double data;
    Item* next;
};

Item* head = nullptr;
Item* tail = nullptr;

bool isNull() {
    return (head == nullptr);
}

void insertToQueue(double x) {
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

void printQueue() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
    }
    else {
        cout << "Очередь = ";
        Item* p = head;
        while (p != nullptr) {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
}

void shiftToMax() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    Item* max_item = head;
    Item* current = head;

    while (current != nullptr) {
        if (current->data > max_item->data) {
            max_item = current;
        }
        current = current->next;
    }

    while (head != max_item) {
        Item* tmp = head;
        head = head->next;
        tail->next = tmp;
        tail = tmp;
        tail->next = nullptr;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы очереди:" << endl;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        insertToQueue(x);
    }

    cout << "Исходная очередь:" << endl;
    printQueue();

    shiftToMax();

    cout << "Очередь после циклического сдвига:" << endl;
    printQueue();

    return 0;
}
