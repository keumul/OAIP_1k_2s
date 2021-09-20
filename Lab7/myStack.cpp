
#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void Push(Stack* Data, int value)
{
    Stack* element = new Stack; // выделение памяти для нового элемента
    element->numeric = value;
    element->next = Data->head; // перенос вершины на следующий элемент
    Data->head = element; // сдвиг вершины на позицию вперёд
}

void Print(Stack* Data)
{
    Stack* element = Data->head; // объявление указателя на вершину стека
    if (element == NULL)
    {
        cout << "Стек пуст. " << endl << endl;

        return;
    }
    cout << "Значения в стеке: ";
    for (element; element != NULL; element = element->next)
    {
        cout << element->numeric << ' ';
    }
    cout << endl << endl;
}

void Write_file(Stack* Data)
{
    int value;
    Stack* element = Data->head;
    ofstream enter("data.txt", ios::trunc);
    for (element; element != NULL; element = element->next)
    {
        value = element->numeric;
        enter << value << ' ';
    }
    enter.close();
    cout << endl;
    cout << "Запись прошла успешно!" << endl << endl;
}

void Read_file()
{
    char str[128];
    ifstream reading("data.txt");
    if (!reading)
    {
        cout << "Ошибка чтения файла. " << endl << endl;
        return;
    }
    while (!reading.eof())
    {
        reading.getline(str, 128);
        cout << "Значения в стеке: " << str << endl << endl;
    }
    reading.close();
}

void Clean(Stack* Data)
{
    Data->head = NULL;
}

void Even_numbers(Stack2* Data, int value) // чётные числа
{
    Stack2* element = new Stack2; // выделение памяти для нового элемента
    element->numeric = value;
    element->next = Data->head; // перенос вершины на следующий элемент
    Data->head = element; // сдвиг вершины на позицию вперёд
}

void Odd_numbers(Stack1* Data, int value) // нечётные числа
{
    Stack1* element = new Stack1; // выделение памяти для нового элемента
    element->numeric = value;
    element->next = Data->head; // перенос вершины на следующий элемент
    Data->head = element; // сдвиг вершины на позицию вперёд
}

void Print_even(Stack2* Data)
{
    Stack2* element = Data->head; // объявление указателя на вершину стека
    if (element == NULL)
    {
        cout << "Стек c чётными числами пуст. " << endl << endl;
        return;
    }
    cout << "Значения в стеке с чётными значениями: ";
    for (element; element != NULL; element = element->next)
    {
        cout << element->numeric << ' ';
    }
    cout << endl << endl;
}

void Print_odd(Stack1* Data)
{
    Stack1* element = Data->head; // объявление указателя на вершину стека
    if (element == NULL)
    {
        cout << "Стек с нечётными числами пуст. " << endl << endl;
        return;
    }
    cout << "Значения в стеке с нечётными значениями: ";
    for (element; element != NULL; element = element->next)
    {
        cout << element->numeric << ' ';
    }
    cout << endl << endl;
}

void Sorting(Stack* Data)
{
    int value = 0;
    Stack1* Data1 = new Stack1; // нечётные числа
    Stack2* Data2 = new Stack2; // чётные числа
    Stack* element = Data->head;
    Data1->head = NULL;
    Data2->head = NULL;

    for (element; element != NULL; element = element->next)
    {
        if (element->numeric % 2 == 0)
        {
            value = element->numeric;
            Even_numbers(Data2, value);
        }
        else
        {
            value = element->numeric;
            Odd_numbers(Data1, value);
        }

    }
    Print_even(Data2);
    cout << endl;
    Print_odd(Data1);
}



//using namespace std;
//void push(int x, Stack* myStk)   //Добавление элемента х в стек	
//{
//	Stack* e = new Stack;    //выделение памяти для нового элемента
//	e->data = x;             //запись элемента x в поле v 
//	e->next = myStk->head;   //перенос вершины на следующий элемент 
//	myStk->head = e;         //сдвиг вершины на позицию вперед
//}
//int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
//{
//	if (myStk->head == NULL)
//	{
//		cout << "Стек пуст!" << endl;
//		return -1;               //если стек пуст - возврат -1 
//	}
//	else
//	{
//		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
//		int a = myStk->head->data;   //запись числа из поля data в переменную a 
//		myStk->head = myStk->head->next; //перенос вершины
//		delete e;  //удаление временной переменной
//		return a; //возврат значения удаляемого элемента
//	}
//}
//void show(Stack* myStk)    //Вывод стека
//{
//	Stack* e = myStk->head;    //объявляется указатель на вершину стека
//	int a;
//	if (e == NULL)
//		cout << "Стек пуст!" << endl;
//	while (e != NULL)
//	{
//		a = e->data;          //запись значения в переменную a 
//		cout << a << " ";
//		e = e->next;
//	}
//	cout << endl;
//}
