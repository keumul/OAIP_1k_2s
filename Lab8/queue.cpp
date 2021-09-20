
#include "queue.h"
#include <iostream>
using namespace std;

void create(Symbol** begin, Symbol** end, string p) //������������ ��������� �������
{
    Symbol* t = new Symbol;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}
void view(Symbol* begin) //����� ��������� ������� 
{
    Symbol* t = begin;
    if (t == NULL)
    {
        cout << "������� �����\n";
        return;
    }
    else
        while (t != NULL)
        {
            cout << t->info << endl;
            t = t->next;
        }
}

void delto(Symbol** begin, Symbol** p)
{
    Symbol* t;
    t = new Symbol;
    while (*begin)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }

}