#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

// ������������ ��� ��������� ��
enum PCState {
    OFF,
    ON,
    SLEEP
};

// ������������ ��� ������ ������
enum RainbowColor {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    INDIGO,
    VIOLET
};

// ������������ ��� ������ ��������� �������
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

// ������������ ��� ���� ������
enum DayOfWeek {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

// ��������� ��� �������� ������������ ������
struct ListNode {
    int value;
    ListNode* next;
};

// ��������� ��� �������� ����������� ������
struct DoubleListNode {
    int value;
    DoubleListNode* prev;
    DoubleListNode* next;
};

// ������� ��� ������ ��������� ��
void printPCStates() {
    cout << "�������� ��������� ��:" << endl;
    cout << "1. ���" << endl;
    cout << "2. ����" << endl;
    cout << "3. ������ �����" << endl;
    int state;
    cin >> state;
    switch (state) {
    case 1:
        cout << "�� �������" << endl;
        break;
    case 2:
        cout << "�� ��������" << endl;
        break;
    case 3:
        cout << "�� � ������ ������" << endl;
        break;
    default:
        cout << "������������ ����." << endl;
        break;
    }
}

// ������� ��� ������ ������ ������
void printRainbowColors() {
    cout << "�������� ���� ������:" << endl;
    cout << "1. �������" << endl;
    cout << "2. ���������" << endl;
    cout << "3. ������" << endl;
    cout << "4. �������" << endl;
    cout << "5. �������" << endl;
    cout << "6. �����" << endl;
    cout << "7. ����������" << endl;
    int color;
    cin >> color;
    switch (color) {
    case 1:
        cout << "�������" << endl;
        break;
    case 2:
        cout << "���������" << endl;
        break;
    case 3:
        cout << "������" << endl;
        break;
    case 4:
        cout << "�������" << endl;
        break;
    case 5:
        cout << "�������" << endl;
        break;
    case 6:
        cout << "�����" << endl;
        break;
    case 7:        
        cout << "����������" << endl;
        break;
    default:
        cout << "������������ ����." << endl;
        break;
    }
}

// ������� ��� ������ �������� ������ ��������� �������
void printPlanetNames() {
    cout << "�������� �������:" << endl;
    cout << "1. ��������" << endl;
    cout << "2. ������" << endl;
    cout << "3. �����" << endl;
    cout << "4. ����" << endl;
    cout << "5. ������" << endl;
    cout << "6. ������" << endl;
    cout << "7. ����" << endl;
    cout << "8. ������" << endl;
    int planet;
    cin >> planet;
    switch (planet) {
    case 1:
        cout << "��������" << endl;
        break;
    case 2:
        cout << "������" << endl;
        break;
    case 3:
        cout << "�����" << endl;
        break;
    case 4:
        cout << "����" << endl;
        break;
    case 5:
        cout << "������" << endl;
        break;
    case 6:
        cout << "������" << endl;
        break;
    case 7:
        cout << "����" << endl;
        break;
    case 8:
        cout << "������" << endl;
        break;
    default:
        cout << "������������ ����." << endl;
        break;
    }
}

// ������� ��� ������ ���� ������
void printDaysOfWeek() {
    cout << "�������� ���� ������:" << endl;
    cout << "1. �����������" << endl;
    cout << "2. �������" << endl;
    cout << "3. �����" << endl;
    cout << "4. �������" << endl;
    cout << "5. �������" << endl;
    cout << "6. �������" << endl;
    cout << "7. �����������" << endl;
    int day;
    cin >> day;
    switch (day) {
    case 1:
        cout << "�����������" << endl;
        break;
    case 2:
        cout << "�������" << endl;
        break;
    case 3:
        cout << "�����" << endl;
        break;
    case 4:
        cout << "�������" << endl;
        break;
    case 5:
        cout << "�������" << endl;
        break;
    case 6:
        cout << "�������" << endl;
        break;
    case 7:
        cout << "�����������" << endl;
        break;
    default:
        cout << "������������ ����." << endl;
        break;
    }
}

// ������� ��� �������� ������������ ������
ListNode* createList() {
    int value;
    cout << "������� �������� ��������� �������� ������: ";
    cin >> value;
    ListNode* head = new ListNode{ value,nullptr };
    ListNode* curr = head;
    int n;
    cout << "������� ���������� ���������, ������� �� ������ �������� � ����� ������: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "������� �������� ��������: ";
        cin >> value;
        ListNode* node = new ListNode{ value, nullptr };
        curr->next = node;
        curr = node;
    }
    return head;
}

// ������� ��� ������ ������������ ������
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

// ������� ��� �������� ����������� ������
DoubleListNode* createDoubleList() {
    int value;
    cout << "������� �������� ��������� �������� ������: ";
    cin >> value;
    DoubleListNode* head = new DoubleListNode{ value, nullptr, nullptr };
    DoubleListNode* curr = head;
    int n;
    cout << "������� ���������� ���������, ������� �� ������ �������� � ������ ������: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "������� �������� ��������: ";
        cin >> value;
        DoubleListNode* node = new DoubleListNode{ value, nullptr, curr };
        curr->prev = node;
        curr = node;
    }
    return head;
}

// ������� ��� ������ ����������� ������
void printDoubleList(DoubleListNode* head) {
    DoubleListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

// ������� ��� ���������� ������������� �������� �������
void findMaxInVector() {
    vector<int> v;
    srand(time(nullptr));
    int n;
    cout << "������� ���������� ��������� �������: ";
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
    cout << "������������ ������� �������: " << max << endl;
}

// ������� ��� ���������� ������������ �������� ���� � ���������� ��� � ������
void findMinInDeque() {
    deque<int> dq;
    srand(time(nullptr));
    int n;
    cout << "������� ���������� ��������� ����: ";
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
    cout << "����������� ������� ����: " << min << endl;
}

// ������� ��� ���������� ����� ������������ � ������������� ��������� �������
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
    cout << "����������� ������� �������: " << min << endl;
    cout << "������������ ������� �������: " << max << endl;
    cout << "����� ������������ � ������������� ��������� �������: " << sum << endl;
}

// ������� ��� ���������� ����� ���� ��������� �������
void findSumInVector() {
    vector<int> v;
    srand(time(nullptr));
    int n;
    cout << "������� ���������� ��������� �������: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % 100);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    cout << "����� ���� ��������� �������: " << sum << endl;
}

// ������� ��� �������� n ��������� �� ����������� ������ � ���������� ����� �� � ������
void deleteNFromDoubleList() {
    DoubleListNode* head = createDoubleList();
    cout << "�������� ������: ";
    printDoubleList(head);
    int n;
    cout << "������� ���������� ���������, ������� �� ������ ������� �� ������: ";
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
    cout << "������� ���������� ���������, ������� �� ������ �������� � ������ ������: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        int value;
        cout << "������� �������� ��������: ";
        cin >> value;
        DoubleListNode* node = new DoubleListNode{ value, curr, nullptr };
        curr->prev = node;
        curr = node;
    }
    cout << "���������� ������: ";
    printDoubleList(head);
}

// ������� ��� ���������� ������������ ���� ��������� ����
void findProductInDeque() {
    deque<int> dq;
    srand(time(nullptr));
    int n;
    cout << "������� ���������� ��������� ����: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        dq.push_back(rand() % 10 + 1);
    }
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= dq[i];
    }
    cout << "������������ ���� ��������� ����: " << product << endl;
}

// ������� ��� �������� ���� ��������� ������������ ������ � ���������� n �����
void deleteAllAndAddNToList() {
    ListNode* head =
        createList();
    cout << "�������� ������: ";
    printList(head);
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    int n;
    cout << "������� ���������� ���������, ������� �� ������ �������� � ������: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "������� �������� ��������: ";
        cin >> value;
        ListNode* node = new ListNode{ value, nullptr };
        node->next = head;
        head = node;
    }
    cout << "���������� ������: ";
    printList(head);
}

// ������� �������
int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        cout << "�������� �������:" << endl;
        cout << "1. ��������� ��" << endl;
        cout << "2. ����� ������" << endl;
        cout << "3. �������� ������� ��������� �������" << endl;
        cout << "4. ��� ������" << endl;
        cout << "5. ���������� ��������� � ����� ������������ ������" << endl;
        cout << "6. ���������� ��������� � ������ ����������� ������" << endl;
        cout << "7. ���������� ������������� �������� �������" << endl;
        cout << "8. ���������� ������������ �������� ���� � ���������� ��� � ������" << endl;
        cout << "9. ���������� ����� ������������ � ������������� ��������� �������" << endl;
        cout << "10. ���������� ����� ���� ��������� �������" << endl;
        cout << "11. �������� n ��������� �� ����������� ������ � ���������� ����� �� � ������" << endl;
        cout << "12. ���������� ������������ ���� ��������� ����" << endl;
        cout << "13. �������� ���� ��������� ������������ ������ � ���������� n �����" << endl;
        cout << "0. �����" << endl;
        cout << "��� �����: ";
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
            cout << "����� �� ���������" << endl;
            break;
        default:
            cout << "������! ������������ �����." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}