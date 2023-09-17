#pragma once
#include <iostream>;
#include <fstream>
#include <string>
#include <malloc.h>
using namespace std;

struct comp {
	int Data;
	comp* next;
};

struct Stack1 {			//Стуктура элемента стека
	int data;
	//Указатель на вершину стека
	Stack1* Next;		//Указатель на следующий элемент
};

struct Stack2 {			//Стуктура элемента стека
	int data;
	//Указатель на вершину стека
	Stack2* Next;		//Указатель на следующий элемент
};



struct Stask3 {
	char Data;
	Stask3* next;
};

struct Stask4 {
	int num;
	int size;
	Stask4* next;
};



void push(comp** top, int D);
void delete_key(comp** top, int N);
void find(comp* top, int N);
void print(comp* top);
bool extract(comp** top);
void toFile(comp* top);
void fromFile(comp** top);
void clear(comp** top);
void Add1(Stack1** s1, int D);				//Добавить элемент в стек 1
void Add2(Stack2** s2, int D);
void Add3(comp** top, int x);//Добавить элемент в стек 2
void Show1(Stack1* s1);					//Вывести стек
void Show2(Stack2* s2);					//Вывести стек
void Show(comp** top);
void Showw(comp* top);
void taskVar3(comp** top);
void task3_1(Stask3* top, int n);
void task3_2(Stask3* top, int n);
void task3();
void task4();
void fun(int** arr, int x);
int menu();
int menu2();
