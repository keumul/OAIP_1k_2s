#pragma once
//struct Stack
//{
//	int data;             //�������������� �������
//	Stack* head;		 //������� ����� 
//	Stack* next;		 //��������� �� ��������� �������
//};
struct Stack
{
    int numeric;
    Stack* head, * next;
};

struct Stack1
{
    int numeric;
    Stack1* head, * next;
};

struct Stack2
{
    int numeric;
    Stack2* head, * next;
};

void Push(Stack* Data, int value), 
     Print(Stack* Data), 
     Write_file(Stack* Data), 
     Read_file(), Clean(Stack* Data), 
     Even_numbers(Stack2* Data, int value), 
     Odd_numbers(Stack1* Data, int value);
void Print_even(Stack2* Data), Print_odd(Stack1* Data);
void Sorting(Stack* Data);

//int value = 0;
//Stack1* Data1 = new Stack1; // �������� �����
//Stack2* Data2 = new Stack2; // ������ �����
//Stack* element = Data->head;
//Data1->head = NULL;
//Data2->head = NULL;
//
//void show(Stack* myStk);         //��������
//int pop(Stack* myStk);           //��������
//void push(int x, Stack* myStk);  //��������
