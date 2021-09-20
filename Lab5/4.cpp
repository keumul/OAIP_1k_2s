// В соответствии со своим вариантом разработать программу с использованием структуры в виде объединения, для работы с данными из 
// таблицы, приведенной ниже. Реализовать функции ввода с клавиатуры, вывода на экран и поиска. 

//Преподаватели. Фамилия преподавателя, название экзамена, дата экзамена. Выбор по фамилии.


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

union Teacher
{
    char name[80];
    char exam[15];

    struct
    {
        unsigned short day : 5;
        unsigned short month : 4;
        unsigned short year : 7;  
    }examday;

}person[SiZE];

struct TEACHER
{
    string nname;
    string eexam;

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
    cout << "Фамилия преподавателя: ";
    cin.getline(person[i].name, 40);
    pperson[i].nname = person[i].name;
    cout << "Название экзамена: ";
    cin.getline(person[i].exam, 40);
    pperson[i].eexam = person[i].exam;

    cout << "Дата экзамена: ";
    cout << "Введите день (1-31):" << '\t'; cin >> j; person[i].examday.day = j;
    cout << "Введите месяц (1-12):" << '\t'; cin >> j; person[i].examday.month = j;
    cout << "Введите год (00-99) :" << '\t'; cin >> j; person[i].examday.year = j;

    cout << endl;
}

void display()
{

    int i;
    for (i = 0; i < SiZE; i++)
    {
        if (*person[i].name)
        {
            cout << "Фамилия преподавателя: " << pperson[i].nname << endl;
            cout << "Название экзамена: " << pperson[i].eexam << endl;
            
            cout << "Дата экзамена: ";
            cout << person[i].examday.day << ".";
            cout << person[i].examday.month << ".";
            cout << person[i].examday.year << endl;
        }
    }
}

void search()
{
    string name, num;
    cout << "Введите фамилию преподавателя: ";
    cin >> name;
    for (int i = 0; i < SiZE; i++)
    {
        if (pperson[i].nname == name)
        {
            cout << "Фамилия преподавателя: " << pperson[i].nname << endl;
            cout << "Название экзамена: " << pperson[i].eexam << endl;
            cout << "Дата экзамена: ";
            cout << person[i]. examday.day << ".";
            cout << person[i].examday.month << ".";
            cout << person[i].examday.year << endl;
        }
    }
}