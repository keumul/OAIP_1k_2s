// Дана величина a строкового типа из четного количества символов. Получить и напечатать величину b, состоящую из символов первой половины величины a, 
// записанных в обратном порядке, после которых идут символы второй половины величины a, также записанные в обратном порядке (например, при а = “привет” 
// b должно быть равно «ипртев»)

#include <iostream>
#include <fstream>
using namespace std;

struct Stack
{
    char symb;
    Stack* head, * next;
};

struct Stack1
{
    char symb;
    Stack1* head, * next;
};

void Push(Stack*& Data, char value1), Print(Stack* Data, int count);

int main()
{
    setlocale(LC_ALL, "Russian");
    char value1 = 0, value2 = 0;
    char amount[255];
    Stack* Data = new Stack; // выделяем память для стека
    Data->head = NULL;
    
    cout << "Введите слово (четное кол-во букв): ";
    cin >> amount;

    int n = strlen(amount), k = 0;
    for (int i = 0; i < n/2; i++)
    {
        Push(Data, amount[i]);
        k++;
    }
    Print(Data, k);
    k = 0;
    for (int i = n/2; i < n; i++)
    {
        Push(Data, amount[i]);
        k++;
    }
   
    Print(Data,k);
    cout << "\nБуквы добавлены в стек, получилось слово :) ";
}
void Push(Stack*& Data, char value1)
{
    Stack* element = new Stack; // выделение памяти для нового элемента
    element->symb = value1;
    element->next = Data->head; // перенос вершины на следующий элемент
    Data->head = element; // сдвиг вершины на позицию вперёl
}

void Print(Stack* Data, int count)
{
    Stack* element = Data->head; // объявление указателя на вершину стека
    if (element == NULL)
    {
        cout << "Стек пуст. " << endl << endl;

        return;
    }
    for (element; element != NULL; element = element->next)
    {
        cout << element->symb;
        count--;
        if (count == 0) return;
        
    }
    cout << endl << endl;
}
