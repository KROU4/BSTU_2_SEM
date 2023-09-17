#include "Heap.h"
#include <iostream>
#include <iomanip>
using namespace std;

void AAA::Print()
{
    std::cout << x;
}
int AAA::GetPriority()
{
    return x;
}

namespace heap
{
    Heap Create(int maxsize, CMP(*f)(void*, void*))
    {
        return *(new Heap(maxsize, f));
    }

    int Heap::Left(int ix)
    {
        return (2 * ix + 1 >= Size) ? -1 : (2 * ix + 1);
    }

    int Heap::Right(int ix)
    {
        return (2 * ix + 2 >= Size) ? -1 : (2 * ix + 2);
    }

    int Heap::Parent(int ix)
    {
        return (ix + 1) / 2 - 1;
    }

    void Heap::Swap(int i, int j)
    {
        void* buf = Storage[i];
        Storage[i] = Storage[j];
        Storage[j] = buf;
    }

    void Heap::Heapify(int ix)
    {
        int l = Left(ix), r = Right(ix), irl = ix;
        if (l > 0)
        {
            if (isGreat(Storage[l], Storage[ix]))
                irl = l;

            if (r > 0 && isGreat(Storage[r], Storage[irl]))

                irl = r;

            if (irl != ix)
            {
                Swap(ix, irl);
                Heapify(irl);
            }
        }
    }

    void Heap::Insert(void* x)
    {
        int i;
        if (!isFull())
        {
            i = Size;
            Storage[i] = x;
            Size++;
            while (i > 0 && isLess(Storage[Parent(i)], Storage[i]))
            {
                Swap(Parent(i), i);
                i = Parent(i);
            }
        }
    }

    void* Heap::ExtractMax()
    {
        void* rc = NULL;
        if (!isEmpty())
        {
            rc = Storage[0];
            Storage[0] = Storage[Size - 1];
            Size--;
            Heapify(0);
        }
        Heapify(0);
        return rc;
    }

    void Heap::Scan(int i)
    {
        int probel = 20;
        std::cout << '\n';
        if (Size == 0)
            std::cout << "Куча пуста";
        for (int u = 0, y = 0, level = 1; u < Size; u++)

        {
            cout << setw(probel + 10) << setfill(' ');

            ((AAA*)Storage[u])->Print();
            if (u == y)
            {
                level++;
                cout << '\n';
                if (y == 0)
                    y = 2;
                else y = pow(2, level) - 2;
            }
            probel /= 2;
        }
        cout << '\n';
    }

    void Heap::DeleteHeap()
    {
        if (!isEmpty())
        {
            Size = 0;
            this->~Heap();
        }
    }


    void* Heap::ExtractMin()
    {
        void* rc = NULL;
        if (Size > 0)
        {
            int j = Size / 2;
            for (int i = Size / 2; i < Size; i++)

            {
                if (Compare(Storage[i], Storage[j]) == LESS)
                {
                    j = i;
                }
            }
            rc = Storage[j];
            Swap(j, Size - 1);
            Size--;
        }
        Heapify(0);
        return rc;
    }

    void* Heap::ExtractI(int i)
    {
        void* rc = NULL;
        if (Size > 0 && i >= 0 && i < Size)
        {
            rc = Storage[i];
            Swap(i, Size - 1);
            Size--;
        }
        Heapify(0);
        return rc;
    }

    void Heap::Union(Heap& h2)
    {
        while (!h2.isEmpty())
            Insert(h2.ExtractMax());
    }
}