// В соответствии со своим вариантом разработать программу с использованием структуры в виде объединения, для работы с данными из 
// таблицы, приведенной ниже. Реализовать функции ввода с клавиатуры, вывода на экран и поиска. 

// Клиенты банка. Ф.И.О., тип счета (срочный, льготный и т. д.), номер счета, сумма на счете, дата последнего изменения.
// Выбор по номеру счета.

#include <iostream>
#include <windows.h>
using namespace std;
const int SiZE = 15;
void init_list(),
enter(),
input(int i),
display(),
search();

int menu();

union Bank
{
    char name[80];
    char type[15];
    int number;
    int money;

    struct
    {
        unsigned short day : 5; 
        unsigned short month : 4; 
        unsigned short year : 7; 
    }editday;

}person[SiZE];

struct BANK
{
    string nname;
    string ttype;
    int nnumber;
    int mmoney;
}pperson[SiZE];

//struct bday d; //объявляем переменную этого типа с битовыми полями

int main()
{

    setlocale(LC_ALL, "Russian");
    init_list();
    char choice;
    for (;;)
    {
        choice = menu();
        switch (choice)
        {
        case 'A': enter();
            break;
        case 'B': display();
            break;
        case 'C': search();
            break;
        case 'D': return 0;
        }
    }
    return 0;
}
void init_list()
{
    int t;
    for (t = 0; t < SiZE; t++) *person[t].name = '\0';
}
int menu()
{
    char ch;
    do
    {
        cout << "A. Ввести данные\n";
        cout << "B. Отобразить данные\n";
        cout << "C. Поиск информации\n";
        cout << "D. Выйти из программы\n";
        cout << "Выберите команду: ";
        cin >> ch;
    } while (!strchr("abcdef", tolower(ch)));
    return ch;
}
void enter()
{
    int i;
    for (i = 0; i < SiZE; i++)
        if (!*person[i].name) break;
    input(i);
}

void input(int i)
{
    int j = 0;

    getchar();
    cout << "Ф.И.О: ";
    cin.getline(person[i].name, 40);
    pperson[i].nname = person[i].name;
    cout << "Тип счета (срочный, льготный и т. д.): ";
    cin.getline(person[i].type, 40);
    pperson[i].ttype = person[i].type;
 
    cout << "Номер счета: ";
    cin >> person[i].number;
    pperson[i].nnumber = person[i].number;
    cout << "Сумма на счете: ";
    cin >> person[i].money;
    pperson[i].mmoney = person[i].money;
    cout << "Дата последнего изменения: ";
    cout << "Введите день (1-31):" << '\t'; cin >> j; person[i].editday.day = j;
    cout << "Введите месяц (1-12):" << '\t'; cin >> j; person[i].editday.month = j;
    cout << "Введите год (00-99) :" << '\t'; cin >> j; person[i].editday.year = j;

    cout << endl;
}

void display()
{

    int i;
    for (i = 0; i < SiZE; i++)
    {
        if (*person[i].name)
        {
            cout << "Ф.И.О: " << pperson[i].nname << endl;
            cout << "Тип счета: " << pperson[i].ttype << endl;
            cout << "Сумма на счете: " << pperson[i].mmoney << endl;
            cout << "Номер счета: " << pperson[i].nnumber << endl;
            cout << "Дата последнего изменения: ";
            cout << person[i].editday.day << ".";
            cout << person[i].editday.month << ".";
            cout << person[i].editday.year << endl;
        }
    }
}

void search()
{
    int numb, num;
    cout << "Введите номер счёта: ";
    cin >> numb;
    for (int i = 0; i < SiZE; i++)
    {
        if (pperson[i].nnumber == numb)
        {
            cout << "Ф.И.О: " << pperson[i].nname << endl;
            cout << "Тип счета: " << pperson[i].ttype << endl;
            cout << "Сумма на счете: " << pperson[i].mmoney << endl;
            cout << "Номер счета: " << pperson[i].nnumber << endl;
            cout << "Дата последнего изменения: ";
            cout << person[i].editday.day << ".";
            cout << person[i].editday.month << ".";
            cout << person[i].editday.year << endl;
        }
    }
}
