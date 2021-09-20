// Создать проект из нескольких файлов, демонстрирующий работу с очередью.В соответствии со своим вариантом выполнить задание из таблицы, 
// представленной ниже. Разработать меню и реализовать все операции с очередью через функции.Максимальный размер очереди ввести с клавиатуры.

// Создать очередь для символов и функции для ввода, вывода, удаления и определения размера очереди. Ввести символы с экрана в очередь. 
// В случае совпадения вводимого символа с первым элементом очереди вывести очередь и ее размер. 


#include<iostream> 
#include "queue.h"

using namespace std;
//struct Symbol
//{
//    string info;
//    Symbol* next;
//};
//void create(Symbol** begin, Symbol** end, string p); 
//void view(Symbol* begin);
//void delto(Symbol** begin, Symbol** p);

int main()
{
    setlocale(LC_CTYPE,"Russian");
    Symbol* begin = NULL, * end, * t;
    t = new Symbol;
    int size, choice;
    string p;
    string firs1;
    cout << "Введите:" << endl;
    cout << "1-для ввода новой очереди" << endl;
    cout << "2-для вывода очереди" << endl;
    cout << "3-для удаления записи" << endl;
    cout << "0-для выхода" << endl;
    cin >> choice;
    do
    {
        switch (choice)
        {
        case 1:  
            cout << "\nВведите размер очереди: "; cin >> size;
            cout << "Введите символ: "; cin >> p;
            t->info = p;        //первый элемент
            t->next = NULL;
            begin = end = t;
         
            for (int i = 1; i < size; i++) //создание очереди
            {
                cout << "Введите символ: ";
                cin >> p;
                create(&begin, &end, p);
                if (p == t->info) {
                    cout << "\nЭлементы очереди: \n";
                    if (begin == NULL)   //вывод на экран
                    {
                        cout << "Элементов нет." << endl;
                    }
                    else { view(begin); }
                    cout << "Размер очереди: " << size << endl;
                }
            }
            cout << "Что дальше?" << endl;
            cin >> choice;
            break;
        case 2:  
            cout << "\nЭлементы очереди: \n";
            if (begin == NULL)   //вывод на экран
                cout << "Элементов нет." << endl;
            else
                view(begin);
            cout << "Что дальше?" << endl;
            cin >> choice;
            break;
        case 3:  delto(&begin, &t); 
            cout << "Что дальше?" << endl;
            cin >> choice;
            break;}
    } while (choice != 0);
    return 0;}

//void create(Symbol** begin, Symbol** end, string p) //Формирование элементов очереди
//{
//    Symbol* t = new Symbol;
//    t->next = NULL;
//    if (*begin == NULL)
//        *begin = *end = t;
//    else
//    {
//        t->info = p;
//        (*end)->next = t;
//        *end = t;
//    }
//}
//void view(Symbol* begin) //Вывод элементов очереди 
//{
//    Symbol* t = begin;
//    if (t == NULL)
//    {
//        cout << "Очередь пуста\n";
//        return;
//    }
//    else
//        while (t != NULL)
//        {
//            cout << t->info << endl;
//            t = t->next;
//        }
//}
//
//void delto(Symbol** begin, Symbol** p)
//{
//    Symbol* t;
//    t = new Symbol;
//    while (*begin)
//    {
//        t = *begin;
//        *begin = (*begin)->next;
//        delete t;
//    }
//
//}
