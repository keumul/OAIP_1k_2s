
// Разработать программу с использованием перечислений и битовых полей для работы с данными из таблицы, приведенной ниже.
// Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов.Интерфейс пользователя осуществить в виде меню.

// Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). Выборка по году рождения. 
// Дату рождения организовать с помощью битового поля, пол - с помощью перечисления.


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


union Citizen
{
    char name[80];
    char adress[40];
    char gender[15];
    struct
    {
        unsigned short day : 5;   
        unsigned short month : 4; 
        unsigned short year : 7; 
    }bday;
}person[SiZE];

struct CITIZEN {
    string nname;
    string aadress;
    string ggender;
}pperson[SiZE];

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
    cout << "Пол: ";
    cin.getline(person[i].gender, 15);
    pperson[i].ggender = person[i].gender;

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
            cout << "Пол: " << pperson[i].ggender << endl;
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
            cout << "Пол: " << pperson[i].ggender << endl;
            cout << "Дата рождения: ";
            cout << person[i].bday.day << ".";
            cout << person[i].bday.month << ".";
            cout << person[i].bday.year << endl;
        }
    }
}