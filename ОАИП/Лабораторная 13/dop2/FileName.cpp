// вариант 12
#include<iostream>
#define N 10
using namespace std;
void scanf_array(int* arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		scanf_s("%d", &arr[i]);
}

void bubblesort(int* arr, int size)
{

	int i, j, t;
	for (i = 1; i < size; i++)
		for (j = size - 1; j >= i; j--)
			if (arr[j - 1] < arr[j])
			{
				t = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = t;
			}

}

void selectSort(int A[], int size)
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++)
			if (A[j] > A[k])
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c;
	}
}


void print_array(int* arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int A[N];
	int B[N];
	int size = 0;
	int max_index_of_array;
	int i = 2;
	cout << "Введите элементы массива" << endl;
	scanf_array(A, N);
	for (; i < N; i += 2)
		B[size++] = A[i];

	cout << "Массив:"; print_array(B, size);
	cout << endl;
	bubblesort(B, size);
	cout << "Сортировка пузырьком:"; print_array(B, size);
	cout << endl;
	selectSort(B, size);
	cout << "Сортировка простой вставкой:"; print_array(B, size);
	cout << endl;
	return 0;
}