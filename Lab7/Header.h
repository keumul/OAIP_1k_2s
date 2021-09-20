#pragma once
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
