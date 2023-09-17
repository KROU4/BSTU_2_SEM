#include <iostream>
using namespace std;

// ����������� ��������� ����
struct Node {
    int data;
    Node* next;
};

// ����������� ��������� �������
struct Queue {
    Node* front;
    Node* rear;
};

// �������� ������ �������
Queue* createQueue() {
    Queue* queue = new Queue;
    queue->front = queue->rear = NULL;
    return queue;
}

// �������� �� ������� �������
bool isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// ���������� �������� � ����� �������
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

    cout << "������� " << value << " �������� � �������" << endl;
}

// �������� ������� �������� �� �������
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "������� �����" << endl;
        return;
    }

    Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    int value = temp->data;
    delete(temp);

    cout << "������� " << value << " ������ �� �������" << endl;
}

// ����� ����������� ������� �� �����
void display(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "������� �����" << endl;
        return;
    }

    Node* temp = queue->front;
    cout << "���������� �������: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// ����������� ������� �������
int size(Queue* queue) {
    int count = 0;
    Node* temp = queue->front;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// �������� ������� �������������� �������� �� �������
void removeNegative(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "������� �����" << endl;
        return;
    }

    Node* temp = queue->front;

    while (temp != NULL && temp->data >= 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "� ������� ��� ������������� ���������" << endl;
        return;
    }

    if (temp == queue->front) {
        queue->front = queue->front->next;
    }
    else {
        Node* prev = queue->front;
        while (prev->next != temp)  // ����� ����� �������� ")"
            prev = prev->next;

        if (temp == queue->rear) {
            queue->rear = prev;
        }

        prev->next = temp->next;
    }

    int value = temp->data;
    delete(temp);

    cout << "������� " << value << " ������ �� �������" << endl;
}

// �������� �������
int main() {
    setlocale(0, "rus");
    Queue* queue = createQueue();
    // ������ ������������� �������
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
