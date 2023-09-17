#include <iostream>
using namespace std;

struct Element                   // Ёлемент списка 
{
    Element* Prev;                // указатель на предыдущий элемент 
    Element* Next;                // указатель на следующий элемент 
    void* Data;                  // данные  

    Element(Element* prev, void* data, Element* next)
    {
        Prev = prev;
        Data = data;
        Next = next;
    }

    Element* GetNext()            // получить следующий
    {
        return Next;
    }

    Element* GetPrev()            // получить предыдущий  
    {
        return Prev;
    }
};

//-----------------------------------------------------------
struct Object                     // Ѕлок управлени€ списком 
{
    Element* Head;                 // указатель на начало списка

    Object()
    {
        Head = NULL;
    }

    Element* GetFirst()            // получить первый элемент списка
    {
        return Head;
    }

    Element* GetLast();            // получить последний элемент списка
    Element* Search(void* data);   // найти  первый элемент по данным 
    bool Insert(void* data);       // добавить элемент в начало
    bool InsertAtEnd(void* data);  // добавить элемент в конец 
    bool Delete(Element* e);       // удалить по адресу элемента 
    bool Delete(void* data);       // удалить первый по данным
    bool DeleteList();		        // очистить список 
    void PrintList(void(*f)(void*));
    void PrintList(void(*f)(void*), Element*);
    int CountList();
    void BubbleSort(int(*compare)(void*, void*));
    void QuickSort(int(*compare)(void*, void*));
    bool DeleteDouble();
};

Object Create();                   // создать список

int CompareInt(void* a, void* b) {
    int* pa = (int*)a;
    int* pb = (int*)b;
    return (*pa < *pb) ? -1 : (*pa > *pb) ? 1 : 0;
}

void PrintInt(void* data) {
    int* p = (int*)data;
    cout << *p << " ";
}

void InputInt(Object& list) {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int* p = new int;
        cout << "Enter element #" << i + 1 << ": ";
        cin >> *p;
        list.InsertAtEnd(p);
    }
}

int main()
{
    Object list = Create();
    InputInt(list);
    cout << "Original list: ";
    list.PrintList(PrintInt);
    cout << endl;

    // Insert at end
    int x = 100;
    list.InsertAtEnd(&x);
    cout << "List after inserting " << x << " at end: ";
    list.PrintList(PrintInt);
    cout << endl;

    // Get size
    cout << "Size of list: " << list.CountList() << endl;

    // Sort using bubble sort
    list.BubbleSort(CompareInt);
    cout << "List after sorting using bubble sort: ";
    list.PrintList(PrintInt);
    cout << endl;

    // Sort using quick sort
    list.QuickSort(CompareInt);
    cout << "List after sorting using quick sort: ";
    list.PrintList(PrintInt);
    cout << endl;

    // Delete duplicates
    list.DeleteDouble();
    cout << "List after deleting duplicates: ";
    list.PrintList(PrintInt);
    cout << endl;

    // Delete element by value
    int value = 5;
    list.Delete(&value);
    cout << "List after deleting element with value " << value << ": ";
    list.PrintList(PrintInt);
    cout << endl;

    // Delete element by pointer
    Element* e2 = list.Search(&x);
    list.Delete(e2);
    cout << "List after deleting element with value " << x << ": ";
    list.PrintList(PrintInt);
    cout << endl;

    // Clear list
    list.DeleteList();
    cout << "List after deleting all elements: ";
    list.PrintList(PrintInt);
    cout << endl;

    return 0;
}

//-----------------------------------------------------------
Element* Object::GetLast() // получить последний элемент списка
{
    Element* e = Head;
    Element* rc = e;
    while (e != NULL)
    {
        rc = e;
        e = e->GetNext();
    }
    return rc;
}

//-----------------------------------------------------------
Element* Object::Search(void* data) // найти первый элемент по данным
{
    Element* rc = Head;
    while ((rc != NULL) && (rc->Data != data))
        rc = rc->Next;
    return rc;
}

//-----------------------------------------------------------
bool Object::Insert(void* data) // добавить элемент в начало
{
    bool rc = false;
    if (Head == NULL)
    {
        Head = new Element(NULL, data, Head);
        rc = true;
    }
    else
    {
        Head = (Head->Prev = new Element(NULL, data, Head));
        rc = true;
    }
    return rc;
}

//-----------------------------------------------------------
bool Object::InsertAtEnd(void* data) // добавить элемент в конец
{
    bool rc = false;
    if (Head == NULL)
    {
        Head = new Element(NULL, data, Head);
        rc = true;
    }
    else
    {
        Element* last = GetLast();
        last->Next = new Element(last, data, NULL);
        rc = true;
    }
    return rc;
}

//-----------------------------------------------------------
bool Object::Delete(Element* e) // удалить по адресу элемента
{
    bool rc = false;
    if (rc = (e != NULL))
    {
        if (e->Next != NULL)
            e->Next->Prev = e->Prev;

        if (e->Prev != NULL)
            e->Prev->Next = e->Next;
        else
            Head = e->Next;
        delete e;
    }
    return rc;

}

//-----------------------------------------------------------
bool Object::Delete(void* data) // удалить первый по данным
{
    return Delete(Search(data));
}

//-----------------------------------------------------------
bool Object::DeleteList() // очистить список
{
    while (Head != NULL)
    {
        Element* e = Head;
        Head = Head->Next;
        delete e;
    }
    return true;
}

//-----------------------------------------------------------
void Object::PrintList(void(f)(void))
{
    Element* e = Head;
    while (e != NULL)
    {
        f(e->Data);
        e = e->GetNext();
    }
}

//-----------------------------------------------------------
void Object::PrintList(void(f)(void), Element* e)
{
    f(e->Data);
}

//-----------------------------------------------------------
int Object::CountList()
{
    int count = 0;
    Element* e = Head;
    while (e != NULL)
    {
        count++;
        e = e->Next;
    }
    return count;
}

//-----------------------------------------------------------
void Object::BubbleSort(int(compare)(void, void*))
{
    int n = CountList();
    if (n <= 1) return;
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        Element* e1 = Head;
        Element* e2 = e1->Next;
        for (int i = 1; i < n; i++)
        {
            if (compare(e1->Data, e2->Data) > 0)
            {
                void* tmp = e1->Data;
                e1->Data = e2->Data;
                e2->Data = tmp;
                swapped = true;
            }
            e1 = e1->Next;
            e2 = e2->Next;
        }
    }
}

//-----------------------------------------------------------
void QuickSortRecursive(Element* head, Element* tail, int(compare)(void, void*))
{
    if (head == NULL || tail == NULL || head == tail) return;
    Element* left = head;
    Element* right = tail;
    Element* pivot = head;

    while (left != right)
    {
        while (compare(left->Data, pivot->Data) <= 0 && left != tail)
        {
            left = left->Next;
        }

        while (compare(right->Data, pivot->Data) > 0)
        {
            right = right->Prev;
        }

        if (left != right)
        {
            void* tmp = left->Data;
            left->Data = right->Data;
            right->Data = tmp;
        }
    }

    if (compare(pivot->Data, right->Data) > 0)
    {
        void* tmp = pivot->Data;
        pivot->Data = right->Data;
        right->Data = tmp;
    }

    QuickSortRecursive(head, right->Prev, compare);
    QuickSortRecursive(right->Next, tail, compare);

}

void Object::QuickSort(int(compare)(void, void*))
{
    QuickSortRecursive(Head, GetLast(), compare);
}

bool Object::DeleteDouble()
{
    bool rc = false;
    Element* e1 = Head;
    while (e1 != NULL)
    {
        Element* e2 = e1->Next;
        while (e2 != NULL)
        {
            if (e1->Data == e2->Data)
            {
                Element* tmp = e2;
                e2 = e2->Next;
                Delete(tmp);
                rc = true;
            }
            else
            {
                e2 = e2->Next;
            }
        }
        e1 = e1->Next;
    }
    return rc;
}

Object Create() // создать список
{
    return *(new Object());
}