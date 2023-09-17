#include <iostream>
using namespace std;

struct Item {
    int data;
    Item* next;
};

Item* head, * tail;

enum PriorityMode {
    MIN_LIFO,
    MAX_FIFO,
    MIN_LIFO_END,
    MIN_LIFO_START,
    MAX_FIFO_END
};

bool isNull() {
    return (head == NULL);
}

void deletFirst() {
    if (isNull())
        cout << "Очередь пуста" << endl;
    else {
        Item* p = head;
        head = head->next;
        delete p;
    }
}

void getFromHead() {
    if (isNull())
        cout << "Очередь пуста" << endl;
    else
        cout << "Начало = " << head->data << endl;
}

void insertToQueue(int x, PriorityMode mode) {
    Item* p = new Item;
    p->data = x;
    p->next = NULL;
    Item* v = new Item;
    Item* p1 = new Item;
    Item* p2 = new Item;
    int i = 0;
    bool condition;

    if (isNull()) {
        head = tail = p;
    }
    else {
        p2 = head;
        p1 = head;
        while (p1 != NULL) {
            switch (mode) {
            case MIN_LIFO:
                condition = x < p1->data;
                break;
            case MAX_FIFO:
                condition = x > p1->data;
                break;
            case MIN_LIFO_END:
                condition = x <= p1->data;
                break;
            case MIN_LIFO_START:
                condition = x < p1->data;
                break;
            case MAX_FIFO_END:
                condition = x >= p1->data;
                break;
            default:
                condition = false;
                break;
            }

            if (i == 1) {
                if (condition) {
                    v->data = x;
                    v->next = p1;
                    p2->next = v;
                    return;
                }
                p2 = p2->next;
            }
            else {
                if (condition) {
                    v->data = x;
                    v->next = p1;
                    head = v;
                    return;
                }
            }
            p1 = p1->next;
            i = 1;
        }
        if (p1 == NULL) {
            tail->next = p;
            tail = p;
        }
    }
}

void printQueue() {
    Item* p = new Item;
    if (isNull()) {
        cout << "Очередь пуста" << endl;
    }
    else {
        cout << "Очередь = ";
        p = head;
        while (!isNull()) {
            if (p != NULL) {
                cout << p->data << " ";
                cout << "->";
                p = p->next;
            }
            else {
                cout << "NULL" << endl;
                return;
            }
        }
    }
}

void clrQueue() {
    while (!isNull()) deletFirst();
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int choice = 1, z;
    head = NULL;
    tail = NULL;
    while (choice != 0) {
        cout << "1 - добавить элемент" << endl;
        cout << "2 - получить элемент с начала" << endl;
        cout << "3 - извлечь элемент с начала" << endl;
        cout << "4 - вывести элементы" << endl;
        cout << "5 - очистить очередь" << endl;
        cout << "0 - выход" << endl;
        cout << "Выберите действие  ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите элемент:  ";
            cin >> z;
            insertToQueue(z, PriorityMode::MIN_LIFO);
            printQueue();
            break;
        case 2:
            getFromHead();
            break;
        case 3:
            deletFirst();
            break;
        case 4:
            printQueue();
            break;
        case 5:
            clrQueue();
            break;
        }
    }
    return 0;
}
