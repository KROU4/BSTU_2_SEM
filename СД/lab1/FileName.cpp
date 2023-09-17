#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

// Перечисление для состояний ПК
enum PCState {
    OFF,
    ON,
    SLEEP
};

// Перечисление для цветов радуги
enum RainbowColor {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    INDIGO,
    VIOLET
};

// Перечисление для планет Солнечной системы
enum SolarSystemPlanet {
    MERCURY,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE
};

// Перечисление для дней недели
enum DayOfWeek {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

// Структура для элемента односвязного списка
struct ListNode {
    int value;
    ListNode* next;
};

// Структура для элемента двусвязного списка
struct DoubleListNode {
    int value;
    DoubleListNode* prev;
    DoubleListNode* next;
};

// Функция для вывода состояний ПК
void printPCStates() {
    cout << "Выберите состояние ПК:" << endl;
    cout << "1. Вкл" << endl;
    cout << "2. Выкл" << endl;
    cout << "3. Спящий режим" << endl;
    int state;
    cin >> state;
    switch (state) {
    case 1:
        cout << "ПК включен" << endl;
        break;
    case 2:
        cout << "ПК выключен" << endl;
        break;
    case 3:
        cout << "ПК в спящем режиме" << endl;
        break;
    default:
        cout << "Некорректный ввод." << endl;
        break;
    }
}

// Функция для вывода цветов радуги
void printRainbowColors() {
    cout << "Выберите цвет радуги:" << endl;
    cout << "1. Красный" << endl;
    cout << "2. Оранжевый" << endl;
    cout << "3. Желтый" << endl;
    cout << "4. Зеленый" << endl;
    cout << "5. Голубой" << endl;
    cout << "6. Синий" << endl;
    cout << "7. Фиолетовый" << endl;
    int color;
    cin >> color;
    switch (color) {
    case 1:
        cout << "Красный" << endl;
        break;
    case 2:
        cout << "Оранжевый" << endl;
        break;
    case 3:
        cout << "Желтый" << endl;
        break;
    case 4:
        cout << "Зеленый" << endl;
        break;
    case 5:
        cout << "Голубой" << endl;
        break;
    case 6:
        cout << "Синий" << endl;
        break;
    case 7:        
        cout << "Фиолетовый" << endl;
        break;
    default:
        cout << "Некорректный ввод." << endl;
        break;
    }
}

// Функция для вывода названий планет Солнечной системы
void printPlanetNames() {
    cout << "Выберите планету:" << endl;
    cout << "1. Меркурий" << endl;
    cout << "2. Венера" << endl;
    cout << "3. Земля" << endl;
    cout << "4. Марс" << endl;
    cout << "5. Юпитер" << endl;
    cout << "6. Сатурн" << endl;
    cout << "7. Уран" << endl;
    cout << "8. Нептун" << endl;
    int planet;
    cin >> planet;
    switch (planet) {
    case 1:
        cout << "Меркурий" << endl;
        break;
    case 2:
        cout << "Венера" << endl;
        break;
    case 3:
        cout << "Земля" << endl;
        break;
    case 4:
        cout << "Марс" << endl;
        break;
    case 5:
        cout << "Юпитер" << endl;
        break;
    case 6:
        cout << "Сатурн" << endl;
        break;
    case 7:
        cout << "Уран" << endl;
        break;
    case 8:
        cout << "Нептун" << endl;
        break;
    default:
        cout << "Некорректный ввод." << endl;
        break;
    }
}

// Функция для вывода дней недели
void printDaysOfWeek() {
    cout << "Выберите день недели:" << endl;
    cout << "1. Понедельник" << endl;
    cout << "2. Вторник" << endl;
    cout << "3. Среда" << endl;
    cout << "4. Четверг" << endl;
    cout << "5. Пятница" << endl;
    cout << "6. Суббота" << endl;
    cout << "7. Воскресенье" << endl;
    int day;
    cin >> day;
    switch (day) {
    case 1:
        cout << "Понедельник" << endl;
        break;
    case 2:
        cout << "Вторник" << endl;
        break;
    case 3:
        cout << "Среда" << endl;
        break;
    case 4:
        cout << "Четверг" << endl;
        break;
    case 5:
        cout << "Пятница" << endl;
        break;
    case 6:
        cout << "Суббота" << endl;
        break;
    case 7:
        cout << "Воскресенье" << endl;
        break;
    default:
        cout << "Некорректный ввод." << endl;
        break;
    }
}

// Функция для создания односвязного списка
ListNode* createList() {
    int value;
    cout << "Введите значение головного элемента списка: ";
    cin >> value;
    ListNode* head = new ListNode{ value,nullptr };
    ListNode* curr = head;
    int n;
    cout << "Введите количество элементов, которые вы хотите добавить в конец списка: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введите значение элемента: ";
        cin >> value;
        ListNode* node = new ListNode{ value, nullptr };
        curr->next = node;
        curr = node;
    }
    return head;
}

// Функция для вывода односвязного списка
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Функция для создания двусвязного списка
DoubleListNode* createDoubleList() {
    int value;
    cout << "Введите значение головного элемента списка: ";
    cin >> value;
    DoubleListNode* head = new DoubleListNode{ value, nullptr, nullptr };
    DoubleListNode* curr = head;
    int n;
    cout << "Введите количество элементов, которые вы хотите добавить в начало списка: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введите значение элемента: ";
        cin >> value;
        DoubleListNode* node = new DoubleListNode{ value, nullptr, curr };
        curr->prev = node;
        curr = node;
    }
    return head;
}

// Функция для вывода двусвязного списка
void printDoubleList(DoubleListNode* head) {
    DoubleListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Функция для нахождения максимального элемента вектора
void findMaxInVector() {
    vector<int> v;
    srand(time(nullptr));
    int n;
    cout << "Введите количество элементов вектора: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % 100);
    }
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    cout << "Максимальный элемент вектора: " << max << endl;
}

// Функция для нахождения минимального элемента дэка и добавления его в начало
void findMinInDeque() {
    deque<int> dq;
    srand(time(nullptr));
    int n;
    cout << "Введите количество элементов дэка: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        dq.push_back(rand() % 100);
    }
    int min = dq[0];
    for (int i = 1; i < n; i++) {
        if (dq[i] < min) {
            min = dq[i];
        }
    }
    dq.push_front(min);
    cout << "Минимальный элемент дэка: " << min << endl;
}

// Функция для нахождения суммы минимального и максимального элементов массива
void findSumMinMaxInArray() {
    int arr[10];
    srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    int min = arr[0];
        int max = arr[0];
        for (int i = 1; i < 10; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    int sum = min + max;
    cout << "Минимальный элемент массива: " << min << endl;
    cout << "Максимальный элемент массива: " << max << endl;
    cout << "Сумма минимального и максимального элементов массива: " << sum << endl;
}

// Функция для нахождения суммы всех элементов вектора
void findSumInVector() {
    vector<int> v;
    srand(time(nullptr));
    int n;
    cout << "Введите количество элементов вектора: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % 100);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    cout << "Сумма всех элементов вектора: " << sum << endl;
}

// Функция для удаления n элементов из двусвязного списка и добавления таких же в начало
void deleteNFromDoubleList() {
    DoubleListNode* head = createDoubleList();
    cout << "Исходный список: ";
    printDoubleList(head);
    int n;
    cout << "Введите количество элементов, которые вы хотите удалить из списка: ";
    cin >> n;
    DoubleListNode* curr = head;
    for (int i = 0; i < n && curr != nullptr; i++) {
        DoubleListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    head = curr;
    curr = head;
    int m;
    cout << "Введите количество элементов, которые вы хотите добавить в начало списка: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        int value;
        cout << "Введите значение элемента: ";
        cin >> value;
        DoubleListNode* node = new DoubleListNode{ value, curr, nullptr };
        curr->prev = node;
        curr = node;
    }
    cout << "Измененный список: ";
    printDoubleList(head);
}

// Функция для нахождения произведения всех элементов дэка
void findProductInDeque() {
    deque<int> dq;
    srand(time(nullptr));
    int n;
    cout << "Введите количество элементов дэка: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        dq.push_back(rand() % 10 + 1);
    }
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= dq[i];
    }
    cout << "Произведение всех элементов дэка: " << product << endl;
}

// Функция для удаления всех элементов односвязного списка и добавления n новых
void deleteAllAndAddNToList() {
    ListNode* head =
        createList();
    cout << "Исходный список: ";
    printList(head);
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    int n;
    cout << "Введите количество элементов, которые вы хотите добавить в список: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Введите значение элемента: ";
        cin >> value;
        ListNode* node = new ListNode{ value, nullptr };
        node->next = head;
        head = node;
    }
    cout << "Измененный список: ";
    printList(head);
}

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        cout << "Выберите задание:" << endl;
        cout << "1. Состояние ПК" << endl;
        cout << "2. Цвета радуги" << endl;
        cout << "3. Название планеты Солнечной системы" << endl;
        cout << "4. Дни недели" << endl;
        cout << "5. Добавление элементов в конец односвязного списка" << endl;
        cout << "6. Добавление элементов в начало двусвязного списка" << endl;
        cout << "7. Нахождение максимального элемента вектора" << endl;
        cout << "8. Нахождение минимального элемента дэка и добавление его в начало" << endl;
        cout << "9. Нахождение суммы минимального и максимального элементов массива" << endl;
        cout << "10. Нахождение суммы всех элементов вектора" << endl;
        cout << "11. Удаление n элементов из двусвязного списка и добавление таких же в начало" << endl;
        cout << "12. Нахождение произведения всех элементов дэка" << endl;
        cout << "13. Удаление всех элементов односвязного списка и добавление n новых" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:
            printPCStates();
            break;
        case 2:
            printRainbowColors();
            break;
        case 3:
            printPlanetNames();
            break;
        case 4:
            printDaysOfWeek();
            break;
        case 5:
            createList();
            break;
        case 6:
            createDoubleList();
            break;
        case 7:
            findMaxInVector();
            break;
        case 8:
            findMinInDeque();
            break;
        case 9:
            findSumMinMaxInArray();
            break;
        case 10:
            findSumInVector();
            break;
        case 11:
            deleteNFromDoubleList();
            break;
        case 12:
            findProductInDeque();
            break;
        case 13:
            deleteAllAndAddNToList();
            break;
        case 0:
            cout << "Выход из программы" << endl;
            break;
        default:
            cout << "Ошибка! Некорректный выбор." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}