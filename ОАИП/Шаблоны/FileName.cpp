#include <iostream>

// Определение структуры "Node", которая представляет узел в связном списке.
// Это шаблонная структура, поэтому она может хранить данные любого типа T.
template <typename T>
struct Node {
    T data; // Данные, хранящиеся в узле
    Node* next; // Указатель на следующий узел в списке
};

// Определение шаблонного класса "LinkedList".
// Это связанный список, который может хранить элементы любого типа T.
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Указатель на начало списка
    Node<T>* tail; // Указатель на конец списка

public:
    // Конструктор класса. Инициализирует head и tail как nullptr, т.е. список пуст.
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Деструктор класса. Удаляет все узлы в списке, чтобы избежать утечки памяти.
    ~LinkedList() {
        Node<T>* current = head; // Начинаем с начала списка
        while (current != nullptr) { // Пока не пройдем весь список
            Node<T>* next = current->next; // Сохраняем указатель на следующий узел
            delete current; // Удаляем текущий узел
            current = next; // Переходим к следующему узлу
        }
    }

    // Функция для добавления нового элемента в конец списка
    void add(T data) {
        Node<T>* node = new Node<T>{ data, nullptr }; // Создаем новый узел с данными

        if (head == nullptr) { // Если список пуст
            head = tail = node; // Новый узел становится единственным в списке
        }
        else { // Если в списке уже есть элементы
            tail->next = node; // Добавляем новый узел в конец списка
            tail = node; // Обновляем указатель на конец списка
        }
    }

    // Функция для печати всех элементов списка
    void print() {
        Node<T>* current = head; // Начинаем с начала списка
        while (current != nullptr) { // Пока не пройдем весь список
            std::cout << current->data << " "; // Печатаем данные текущего узла
            current = current->next; // Переходим к следующему узлу
        }
        std::cout << std::endl; // Печатаем новую строку после всех элементов списка
    }
};

int main() {
    setlocale(0, "rus"); // Установка локали для поддержки русского языка
    // Создаем список целых чисел
    LinkedList<int> intList; // Создаем новый список для целых чисел
    intList.add(5); // Добавляем числа в список
    intList.add(10);
    intList.add(15);
    std::cout << "Список целых чисел: ";
    intList.print(); // Печатаем все элементы списка

    // Создаем список вещественных чисел
    LinkedList<double> doubleList; // Создаем новый список для вещественных чисел
    doubleList.add(5.5); // Добавляем числа в список
    doubleList.add(10.1);
    doubleList.add(15.2);
    std::cout << "Список вещественных чисел: ";
    doubleList.print(); // Печатаем все элементы списка

    // Создаем список строк
    LinkedList<std::string> stringList; // Создаем новый список для строк
    stringList.add("Hello"); // Добавляем строки в список
    stringList.add("World");
    stringList.add("!");
    std::cout << "Список строк: ";
    stringList.print(); // Печатаем все элементы списка

    return 0; // Конец функции main. Программа успешно завершена.
}

