
// Разработать программу с использованием перечислений и битовых полей для работы с данными из таблицы, приведенной ниже.
// Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов. Интерфейс пользователя осуществить в виде меню.

// Студенты. Ф.И.О., дата поступления, специальность, группа, факультет, средний балл. Выбор по среднему баллу.
// Дату поступления реализовать с помощью битового поля, факультет - с помощью перечисления.


#include <iostream>
#include <windows.h>
using namespace std;
const int SiZE = 15;
void init_list(),
enter(),
input(int i),
display(),
clean(),
search();

int menu();
enum Faculty
{
    FacultyofGeneralMedicine=1,
    FacultyofMedicalDiagnostics,
    FacultofMentalHealthMedicine,
    FacultyofPediatrics,
    FacultyofInternationalStudents
};

struct STUDENT
{
    char name[80];
    char group[15];
    char specialty[40];
    int marks;
    Faculty faculty1;

    struct
    {
        unsigned short day : 5;   //5 бит для дня
        unsigned short month : 4; //4 для месяца
        unsigned short year : 7;  //7 для года от 0 до 99
    }admission;
}person[SiZE];
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
        case 'C': clean();
            break;
        case 'D': search();
            break;
        case 'F': return 0;
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
        cout << "C. Удалить данные\n";
        cout << "D. Поиск информации\n";
        cout << "E. Выйти из программы\n";
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
    cout << "Группа: ";
    cin.getline(person[i].group, 15);
    cout << "Специальность: ";
    cin.getline(person[i].specialty, 40);
    cout << "Факультет: ";
    cin.getline(person[i].specialty, 40);
    cout << "Факультет: " << endl;
    cout << "\t 1) лечебный факультет " << endl;
    cout << "\t 2) медико-диагностический факультет " << endl;
    cout << "\t 3) медико-психологический факультет " << endl;
    cout << "\t 4) педиатрический факультет" << endl;
    cout << "\t 5) факультет иностранных учащихся " << endl;

    int ENTER;
    cin >> ENTER;
    person[i].faculty1 = Faculty(ENTER);

    cout << "Срений балл: ";
    cin >> person[i].marks;
    cout << "День поступления: ";
    cout << "Введите день (1-31):" << '\t'; cin >> j; person[i].admission.day = j;
    cout << "Введите месяц (1-12):" << '\t'; cin >> j; person[i].admission.month = j;
    cout << "Введите год (00-99) :" << '\t'; cin >> j; person[i].admission.year = j;
    cout << endl;
}

void display()
{

    int i;
    for (i = 0; i < SiZE; i++)
    {
        if (*person[i].name)
        {
            cout << "Ф.И.О: " << person[i].name << endl;
            cout << "Группа: " << person[i].group << endl;
            cout << "Факультет: " << person[i].faculty1 << endl;
            cout << "Специальность: " << person[i].specialty << endl;
            cout << "Средний балл: " << person[i].marks << endl;
            cout << "Дата поступления: ";
            cout << person[i].admission.day << ".";
            cout << person[i].admission.month << ".";
            cout << person[i].admission.year << endl;
        }
    }
}
void clean()
{
    int i;
    for (i = 0; i < SiZE; i++)
    {
        *person[i].name = '\0';
        *person[i].group = '\0';
        *person[i].specialty = '\0';

        person[i].marks = '\0';
        person[i].admission.day = '\0';
        person[i].admission.month = '\0';
        person[i].admission.year = '\0';
    }
}
void search()
{
    int srd, num;
    cout << "Введите средний балл: ";
    cin >> srd;
    for (int i = 0; i < SiZE; i++)
    {
        if (person[i].marks == srd)
        {
            cout << "Ф.И.О: " << person[i].name << endl;
            cout << "Группа: " << person[i].group << endl;
            cout << "Специальность: " << person[i].specialty << endl;
            cout << "Факультет: " << person[i].faculty1 << endl;
            cout << "Оценки: " << person[i].marks << endl;
            cout << "Дата рождения: ";
            cout << person[i].admission.day << ".";
            cout << person[i].admission.month << ".";
            cout << person[i].admission.year << endl;
        }
    }
}