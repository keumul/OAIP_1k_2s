
#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void Push(Stack* Data, int value)
{
    Stack* element = new Stack; // ��������� ������ ��� ������ ��������
    element->numeric = value;
    element->next = Data->head; // ������� ������� �� ��������� �������
    Data->head = element; // ����� ������� �� ������� �����
}

void Print(Stack* Data)
{
    Stack* element = Data->head; // ���������� ��������� �� ������� �����
    if (element == NULL)
    {
        cout << "���� ����. " << endl << endl;

        return;
    }
    cout << "�������� � �����: ";
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
    cout << "������ ������ �������!" << endl << endl;
}

void Read_file()
{
    char str[128];
    ifstream reading("data.txt");
    if (!reading)
    {
        cout << "������ ������ �����. " << endl << endl;
        return;
    }
    while (!reading.eof())
    {
        reading.getline(str, 128);
        cout << "�������� � �����: " << str << endl << endl;
    }
    reading.close();
}

void Clean(Stack* Data)
{
    Data->head = NULL;
}

void Even_numbers(Stack2* Data, int value) // ������ �����
{
    Stack2* element = new Stack2; // ��������� ������ ��� ������ ��������
    element->numeric = value;
    element->next = Data->head; // ������� ������� �� ��������� �������
    Data->head = element; // ����� ������� �� ������� �����
}

void Odd_numbers(Stack1* Data, int value) // �������� �����
{
    Stack1* element = new Stack1; // ��������� ������ ��� ������ ��������
    element->numeric = value;
    element->next = Data->head; // ������� ������� �� ��������� �������
    Data->head = element; // ����� ������� �� ������� �����
}

void Print_even(Stack2* Data)
{
    Stack2* element = Data->head; // ���������� ��������� �� ������� �����
    if (element == NULL)
    {
        cout << "���� c ������� ������� ����. " << endl << endl;
        return;
    }
    cout << "�������� � ����� � ������� ����������: ";
    for (element; element != NULL; element = element->next)
    {
        cout << element->numeric << ' ';
    }
    cout << endl << endl;
}

void Print_odd(Stack1* Data)
{
    Stack1* element = Data->head; // ���������� ��������� �� ������� �����
    if (element == NULL)
    {
        cout << "���� � ��������� ������� ����. " << endl << endl;
        return;
    }
    cout << "�������� � ����� � ��������� ����������: ";
    for (element; element != NULL; element = element->next)
    {
        cout << element->numeric << ' ';
    }
    cout << endl << endl;
}

void Sorting(Stack* Data)
{
    int value = 0;
    Stack1* Data1 = new Stack1; // �������� �����
    Stack2* Data2 = new Stack2; // ������ �����
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
//void push(int x, Stack* myStk)   //���������� �������� � � ����	
//{
//	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
//	e->data = x;             //������ �������� x � ���� v 
//	e->next = myStk->head;   //������� ������� �� ��������� ������� 
//	myStk->head = e;         //����� ������� �� ������� ������
//}
//int pop(Stack* myStk)   //���������� (��������) �������� �� �����
//{
//	if (myStk->head == NULL)
//	{
//		cout << "���� ����!" << endl;
//		return -1;               //���� ���� ���� - ������� -1 
//	}
//	else
//	{
//		Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
//		int a = myStk->head->data;   //������ ����� �� ���� data � ���������� a 
//		myStk->head = myStk->head->next; //������� �������
//		delete e;  //�������� ��������� ����������
//		return a; //������� �������� ���������� ��������
//	}
//}
//void show(Stack* myStk)    //����� �����
//{
//	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
//	int a;
//	if (e == NULL)
//		cout << "���� ����!" << endl;
//	while (e != NULL)
//	{
//		a = e->data;          //������ �������� � ���������� a 
//		cout << a << " ";
//		e = e->next;
//	}
//	cout << endl;
//}
