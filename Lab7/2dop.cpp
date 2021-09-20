// Создать стек с целочисленным информационным полем. Заполнить его длинами строк, считанных из файла. Распечатать на экране содержимое стека. 
// Указать номер и длину последней самой короткой строки файла.

#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdio>

using namespace std;
struct s
{
    int ind;
    s* next;
};
void cr(s** begin, int n)
{
    s* i = new s;
    i->ind = n;
    i->next = *begin;
    *begin = i;
}
void v(s* begin)
{
    s* i = begin;
    if (begin == NULL)
    {
        cout << "Список пуст";
        return;
    }
    int numb = 0;
    while (i != NULL)
    {
        cout << numb + 1 << ") " << i->ind << endl;
        i = i->next;
        numb++;
    }
}
void f(s** begin)
{
    s* i;
    while (*begin != NULL)
    {
        i = *begin;
        *begin = (*begin)->next;
        delete i;
    }
}
int main()
{
    setlocale(LC_CTYPE, "Russian");
    s* begin = NULL;
    ifstream in("A.txt");
    
    char str[255];
    int n = 0, z = 0, min = 99;

    while (!in.eof())
    {
        in.getline(str, 255);
        n = strlen(str);
        cr(&begin, n);
      //  if (in.eof()) { break; }
    }

    in.clear();
    in.seekg(0);
    while (!in.eof())
    {
        in >> str;
        if (strlen(str) < min) min = strlen(str);
    }
    // in.clear();
    in.seekg(0);
    int size = 0;
    while (!in.eof())
    {
        size++;
        in >> str;
        if (strlen(str) == min)
        {
            cout << "Самая короткая строка из файла содержит всего " << strlen(str) << " символа." << endl;
        }
    }

    cout << "Она находится под номером " << size - 1 << endl;
    cout << "Вот список длин строк, считанных из файла: " << endl;
    in.close();
    v(begin);
    cout << endl;

    f(&begin);
    return 0;
}
