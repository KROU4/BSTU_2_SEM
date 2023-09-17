#include <iostream>
#include <fstream>
using namespace std;
struct list
{
    int number;
    list* next;
};

/*прототипы функций*/
void insert(list*&, int);
float del(list*&, int);
int IsEmpty(list*);
void printList(list*);
void menu(void);
void arifm(list*);
void toFile(list*& p);
void fromFile(list*& p);
void find(list*);

int main() {

    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice = 0;
    int value;
    menu();
    while (choice != 8)
    {
        cout << "Ваш выбор: ";
        cin >> choice;
        switch (choice)
        {
            /*для добавления числа*/
        case 1:  	cout << "Введите число ";
            cin >> value;
            insert(first, value);
            break;
            /*для вывода листа*/
        case 2:
            printList(first);
            break;
            /* для удаления*/
        case 3:   if (!IsEmpty(first)) /*проверка*/
        {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
                printList(first);
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;
            /* для суммы*/
        case 4:   arifm(first); /*вычисление суммы*/
            break;
            /* для записи в файл*/
        case 5: toFile(first);
            break;
            /* для чтения из файла*/
        case 6: fromFile(first);
            break;
            /* для поиска*/
        case 7: find(first);
            break;

        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
    }
    cout << "Конец" << endl;
    return 0;
}

void menu(void) {
    \

        cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Вывод числа" << endl;
    cout << " 3 - Удаление числа" << endl;
    cout << " 4 - Вычисление суммы" << endl;
    cout << " 5 - Запись в файл" << endl;
    cout << " 6 - Вывод из файла" << endl;
    cout << " 7 - Поиск элемента" << endl;
    cout << " 8 - Выход" << endl;
}
/* -> доступ по указателю*/
void insert(list*& p, int value) { /*Добавление числа value в список */

    list* newP = new list;
    if (newP != NULL)     /*Проверка на место */
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

float del(list*& p, int value) {

    list* previous, * current, * temp;
    if (value == p->number)     /*удаление предыдущего р, чтобы удалить первый р*/
    {
        temp = p;
        p = p->next;
        delete temp;
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value) /*выполняется пока не найдем введенное значение*/
        {
            previous = current;
            current = current->next;
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;     /*переадресация*/
            free(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p) {/*Пустой ли*/

    return p == NULL;
}

void printList(list* p)  /*Вывод списка*/
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "\t" << p->number;
            p = p->next;
        }
        cout << "\tNULL" << endl;
    }
}

void arifm(list* p) {/* Подсчет суммы*/

    int sm = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number >= -99 && p->number <= -10)
            {
                sm += (p->number);
            }
            p = p->next;
        }
        cout << "Сумма отрицательных двузначных = " << sm << endl;
    }
}

void toFile(list*& p)
{
    list* temp = p;
    ofstream file1("text.txt");
    if (file1.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        int nn = temp->number;
        file1 << nn << "\n";        /*запись*/
        temp = temp->next;
    }
    file1.close();      /*закрываем файл*/
    cout << "Список записан в файл text.txt\n";
}

void fromFile(list*& p)
{
    char buf[10];

    ifstream file1("text.txt");     /* открываем файл для чтения*/

    if (file1.fail())           /*если файл не открыт*/
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (!file1.eof())
    {
        file1.getline(buf, 10);         /*считываем строчку со значением*/
        if (strlen(buf))        /*если длина > 0, то */
            insert(p, atoi(buf));       /*добавляем в список*/
        cout << "\t" << buf;
    }
    cout << "\tNULL" << endl;
    file1.close();
}

void find(list* p) { /*поиск элементов*/

    bool isFind = false;
    int element;
    cout << "Введите элемент" << endl;
    cin >> element;
    list* find = p;
    while (find)
    {
        if (find->number == element)
        {
            isFind = true;
            printf("Элемент найден\n");
            break;
        }
        find = find->next;
    }
    if (!isFind)
        printf("Элемент не найден\n");
}
