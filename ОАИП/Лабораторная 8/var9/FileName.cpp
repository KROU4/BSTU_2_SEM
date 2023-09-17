#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class MyQueue {
public:
    MyQueue() : head(nullptr), tail(nullptr), _size(0) {}

    ~MyQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        _size++;
    }

    void pop() {
        if (_size > 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            _size--;
        }
    }

    int front() const {
        return head->value;
    }

    bool empty() const {
        return _size == 0;
    }

    int size() const {
        return _size;
    }

private:
    Node* head;
    Node* tail;
    int _size;
};

void printQueue(MyQueue& q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

void splitQueue(MyQueue& initial, MyQueue& queue1, MyQueue& queue2) {
    while (!initial.empty()) {
        int value = initial.front();
        initial.pop();

        if (value % 2 == 0) {
            queue1.push(value);
        }
        else {
            queue2.push(value);
        }
    }
}

int main() {
    setlocale(0, "rus");
    MyQueue myQueue, evenQueue, oddQueue;

    for (int i = 1; i <= 10; ++i) {
        myQueue.push(i);
    }

    std::cout << "Исходная очередь: ";
    printQueue(myQueue);

    // Восстанавливаем исходную очередь после вывода
    for (int i = 1; i <= 10; ++i) {
        myQueue.push(i);
    }

    splitQueue(myQueue, evenQueue, oddQueue);

    std::cout << "Очередь с четными элементами: ";
    printQueue(evenQueue);

    std::cout << "Очередь с нечетными элементами: ";
    printQueue(oddQueue);

    return 0;
}
