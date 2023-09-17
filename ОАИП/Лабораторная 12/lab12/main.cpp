#include "Heap.h"//удаление максимального, удаление i-го и объединение двух куч
#include <iostream>
#include <fstream>
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)  // функция сравнения 2х элементов типа ААА
{
#define A1 ((AAA*)a1) 
#define A2 ((AAA*)a2)

    heap::CMP  rc = heap::EQUAL;     // объявляем переменную типа CMP, то есть результат сравнения двух структур (=двух элементов кучи)
    if (A1->x > A2->x)             // если значение первого элемента больше значения второго
        rc = heap::GREAT;             // записываем в переменную, что первый элемент больше второго
    else
        if (A2->x > A1->x)         // если второй элемент больше первого 
            rc = heap::LESS;      // записываем в переменную, что первый элемент меньше второго
    return rc;              //  возвращаем значение переменной
#undef A2  
#undef A1  
}
bool BuildHeap(char* FileName, heap::Heap& h)  // построение кучи из файла, char *FileName - имя файла, heap::Heap& h - куча, на которую берётся указатель
{
    bool rc = true;
    int n;
    ifstream inFile;
    inFile.open(FileName);
    if (!inFile)
    {
        cout << "Невозможно открыть файл" << endl;
        exit(1);
    }
    cout << "    Исходные данные" << endl;
    while (inFile >> n)
    {
        int* a = new int;
        *a = n;  // переписываем прочитанный элемент из буфера в выделенную память 
        h.Insert((void*)a);
        cout << *a << endl;
    }
    inFile.close();
    return rc;
}

void SaveHeap(heap::Heap& h, char* FileName)
{
    ofstream  outFile(FileName);
    if (!outFile)
    {
        std::cout << "Ошибка открытия выходного файла" << std::endl;
        return;
    }
    int* a;
    for (int u = 0; u < h.Size; u++)
    {
        a = (int*)h.Storage[u];
        outFile << *a;
        outFile << endl;
    }
    outFile.close();
}

void main()
{
    setlocale(LC_ALL, "rus");
    char buf[255];
    int k;
    heap::Heap h1 = heap::Create(30, cmpAAA), h2 = heap::Create(30, cmpAAA);

    int choise;
    AAA* a;
    for (;;)
    {
        cout << "1 - вывод кучи на экран" << endl;
        cout << "2 - добавление элемента" << endl;
        cout << "3 - удаление максимального" << endl;
        cout << "4 - очистить кучу" << endl;
        cout << "5 - сохранить в файл" << endl;
        cout << "6 - загрузить из файла" << endl;
        cout << "7 - извлечение минимального элемента" << endl;
        cout << "8 - удаление i-ого элемента" << endl;
        cout << "9 - объединения двух куч в одну" << endl;
        cout << "0 - выход" << endl;
        cout << "Что надо сделать?" << endl;
        cin >> choise;
        switch (choise)
        {
        case 0:  exit(0);
        case 1:  h1.Scan(0);
            break;
        case 2:
            a = new AAA;
            cout << "Введите элемент " << endl;
            cin >> k;
            a->x = k;
            h1.Insert(a);
            break;
        case 3:
            a = (AAA*)h1.ExtractMax();

            if (a != NULL)
                cout << "Максимальный элемент: " << a->x << endl;
            else cout << "Куча пуста." << endl;
            break;
        case 4:   h1.DeleteHeap();
            break;
        case 5:
            cout << "Введите имя файла" << endl;
            cin >> buf;
            SaveHeap(h1, buf);
            break;
        case 6:
            h1.DeleteHeap();
            cout << "Введите имя файла" << endl;
            cin >> buf;
            BuildHeap(buf, h1);
            break;
        case 7:
            a = (AAA*)h1.ExtractMin();

            if (a != NULL)
                cout << "Минимальный элемент: " << a->x << endl;
            else cout << "Куча пуста." << endl;
            break;
        case 8:
            cout << "Введите номер элемента " << endl;
            cin >> choise;
            a = (AAA*)h1.ExtractI(choise);

            if (a != NULL)
                cout << "Извлечённый элемент: " << a->x << endl;
            else cout << "Куча пуста." << endl;
            break;
        case 9:
            cout << "Введите имя файла" << endl;
            cin >> buf;
            h2.DeleteHeap();
            BuildHeap(buf, h2);
            h1.Union(h2);
            break;
        default:
            cout << endl << "Введена неверная команда!"; cout << endl;
        }
    }
}