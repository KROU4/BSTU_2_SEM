//13 variant
#include<iostream>
#define N 10
using namespace std;
void scanf_array(int* arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		scanf_s("%d", &arr[i]);
}

int get_max_index_of_array(int* arr, int size)
{
	int max_index = 0;
	int i;

	for (i = 0; i < size; ++i)
		if (arr[i] > arr[max_index])
			max_index = i;

	return max_index;
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

int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] > brd);
		while (A[++i] < brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};



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
	int i;
	int first, last;
	cout << "Введите элементы массива" << endl;
	scanf_array(A, N);

	max_index_of_array = get_max_index_of_array(A, N);
	if (max_index_of_array % 2 == 0)
	{
		i = max_index_of_array + 2;
	}
	else
	{
		i = max_index_of_array + 1;
	}

	for (; i < N; i += 2)
		B[size++] = A[i];

	cout << "Массив:"; print_array(B, size);
	cout << endl;
	bubblesort(B, size);
	cout << "Сортировка пузырьком:"; print_array(B, size);
	cout << endl;
	first = max_index_of_array + 1;
	last = size - 1;
	sortHoar(B, first, last);
	cout << "Сортировка Хаора:"; print_array(B, size);
	return 0;
}