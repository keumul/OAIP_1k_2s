// В соответствии со своим вариантом разработать программу с использованием структуры в виде объединения, для работы с данными из 
// таблицы, приведенной ниже. Реализовать функции ввода с клавиатуры, вывода на экран и поиска. 

//Записная книжка.Ф.И.О, дата рождения, адрес, телефон, место работы или учебы, должность. Поиск по фамилии.

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

union NBOOK
{
    char name[80];
    char work[15];
    char speciality[40];
    char adress[40];
    int number;

    struct
    {
        unsigned short day : 5;   //5 бит для дня
        unsigned short month : 4; //4 для месяца
        unsigned short year : 7;  //7 для года от 0 до 99
    }bday;

}person[SiZE];

struct NOTEBOOK
{
    string nname;
    string wwork;
    string spec;
    string aadress;
    int nnumber;
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
    cout << "Адрес: ";
    cin.getline(person[i].adress, 40);
    pperson[i].aadress = person[i].adress;
    cout << "Место работы: ";
    cin.getline(person[i].work, 15);
    pperson[i].wwork = person[i].work;
    cout << "Должность: ";
    cin.getline(person[i].speciality, 40);
    pperson[i].spec = person[i].speciality;
    cout << "Рабочий номер телефона: ";
    cin >> person[i].number;
    pperson[i].nnumber = person[i].number;
    cout << "Дата рождения: ";
    cout << "Введите день (1-31):" << '\t'; cin >> j; person[i].bday.day = j;
    cout << "Введите месяц (1-12):" << '\t'; cin >> j; person[i].bday.month = j;
    cout << "Введите год (00-99) :" << '\t'; cin >> j; person[i].bday.year = j;

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
            cout << "Адрес: " << pperson[i].aadress << endl;
            cout << "Место работы: " << pperson[i].wwork << endl;
            cout << "Должность: " << pperson[i].spec << endl;
            cout << "Рабочий номер телефона: " << pperson[i].nnumber << endl;
            cout << "Дата рождения: ";
            cout << person[i].bday.day << ".";
            cout << person[i].bday.month << ".";
            cout << person[i].bday.year << endl;
        }
    }
}

void search()
{
    string name, num;
    cout << "Введите фамилию: ";
    cin >> name;
    for (int i = 0; i < SiZE; i++)
    {
        if (pperson[i].nname == name)
        {
            cout << "Ф.И.О: " << pperson[i].nname << endl;
            cout << "Адрес: " << pperson[i].aadress << endl;
            cout << "Место работы: " << pperson[i].wwork << endl;
            cout << "Должность: " << pperson[i].spec << endl;
            cout << "Рабочий номер телефона: " << pperson[i].nnumber << endl;
            cout << "Дата рождения: ";
            cout << person[i].bday.day << ".";
            cout << person[i].bday.month << ".";
            cout << person[i].bday.year << endl;
        }
    }
}