#include <iostream>

// ����������� ��������� "Node", ������� ������������ ���� � ������� ������.
// ��� ��������� ���������, ������� ��� ����� ������� ������ ������ ���� T.
template <typename T>
struct Node {
    T data; // ������, ���������� � ����
    Node* next; // ��������� �� ��������� ���� � ������
};

// ����������� ���������� ������ "LinkedList".
// ��� ��������� ������, ������� ����� ������� �������� ������ ���� T.
template <typename T>
class LinkedList {
private:
    Node<T>* head; // ��������� �� ������ ������
    Node<T>* tail; // ��������� �� ����� ������

public:
    // ����������� ������. �������������� head � tail ��� nullptr, �.�. ������ ����.
    LinkedList() : head(nullptr), tail(nullptr) {}

    // ���������� ������. ������� ��� ���� � ������, ����� �������� ������ ������.
    ~LinkedList() {
        Node<T>* current = head; // �������� � ������ ������
        while (current != nullptr) { // ���� �� ������� ���� ������
            Node<T>* next = current->next; // ��������� ��������� �� ��������� ����
            delete current; // ������� ������� ����
            current = next; // ��������� � ���������� ����
        }
    }

    // ������� ��� ���������� ������ �������� � ����� ������
    void add(T data) {
        Node<T>* node = new Node<T>{ data, nullptr }; // ������� ����� ���� � �������

        if (head == nullptr) { // ���� ������ ����
            head = tail = node; // ����� ���� ���������� ������������ � ������
        }
        else { // ���� � ������ ��� ���� ��������
            tail->next = node; // ��������� ����� ���� � ����� ������
            tail = node; // ��������� ��������� �� ����� ������
        }
    }

    // ������� ��� ������ ���� ��������� ������
    void print() {
        Node<T>* current = head; // �������� � ������ ������
        while (current != nullptr) { // ���� �� ������� ���� ������
            std::cout << current->data << " "; // �������� ������ �������� ����
            current = current->next; // ��������� � ���������� ����
        }
        std::cout << std::endl; // �������� ����� ������ ����� ���� ��������� ������
    }
};

int main() {
    setlocale(0, "rus"); // ��������� ������ ��� ��������� �������� �����
    // ������� ������ ����� �����
    LinkedList<int> intList; // ������� ����� ������ ��� ����� �����
    intList.add(5); // ��������� ����� � ������
    intList.add(10);
    intList.add(15);
    std::cout << "������ ����� �����: ";
    intList.print(); // �������� ��� �������� ������

    // ������� ������ ������������ �����
    LinkedList<double> doubleList; // ������� ����� ������ ��� ������������ �����
    doubleList.add(5.5); // ��������� ����� � ������
    doubleList.add(10.1);
    doubleList.add(15.2);
    std::cout << "������ ������������ �����: ";
    doubleList.print(); // �������� ��� �������� ������

    // ������� ������ �����
    LinkedList<std::string> stringList; // ������� ����� ������ ��� �����
    stringList.add("Hello"); // ��������� ������ � ������
    stringList.add("World");
    stringList.add("!");
    std::cout << "������ �����: ";
    stringList.print(); // �������� ��� �������� ������

    return 0; // ����� ������� main. ��������� ������� ���������.
}

