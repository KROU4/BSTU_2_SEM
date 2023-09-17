#include <iostream>
using namespace std;

// Определение структуры узла
struct Node {
    int data;
    Node* next;
};

// Определение структуры очереди
struct Queue {
    Node* front;
    Node* rear;
};

// Создание пустой очереди
Queue* createQueue() {
    Queue* queue = new Queue;
    queue->front = queue->rear = NULL;
    return queue;
}

// Проверка на пустоту очереди
bool isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Добавление элемента в конец очереди
void enqueue(Queue* queue, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    cout << "Элемент " << value << " добавлен в очередь" << endl;
}

// Удаление первого элемента из очереди
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Очередь пуста" << endl;
        return;
    }

    Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    int value = temp->data;
    delete(temp);

    cout << "Элемент " << value << " удален из очереди" << endl;
}

// Вывод содержимого очереди на экран
void display(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Очередь пуста" << endl;
        return;
    }

    Node* temp = queue->front;
    cout << "Содержимое очереди: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Определение размера очереди
int size(Queue* queue) {
    int count = 0;
    Node* temp = queue->front;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Удаление первого отрицательного элемента из очереди
void removeNegative(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Очередь пуста" << endl;
        return;
    }

    Node* temp = queue->front;

    while (temp != NULL && temp->data >= 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "В очереди нет отрицательных элементов" << endl;
        return;
    }

    if (temp == queue->front) {
        queue->front = queue->front->next;
    }
    else {
        Node* prev = queue->front;
        while (prev->next != temp)  // здесь нужно добавить ")"
            prev = prev->next;

        if (temp == queue->rear) {
            queue->rear = prev;
        }

        prev->next = temp->next;
    }

    int value = temp->data;
    delete(temp);

    cout << "Элемент " << value << " удален из очереди" << endl;
}

// Основная функция
int main() {
    setlocale(0, "rus");
    Queue* queue = createQueue();
    // Пример использования функций
    enqueue(queue, 10);
    enqueue(queue, -5);
    enqueue(queue, 20);
    enqueue(queue, -15);
    display(queue);
    removeNegative(queue);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);

    return 0;
}
