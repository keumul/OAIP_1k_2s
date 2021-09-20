
// Разработать программу с использованием перечислений и битовых полей для работы с данными из таблицы, приведенной ниже.
// Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов. Интерфейс пользователя осуществить в виде меню.

// Склад. Наименование товара, цена, количество, процент торговой надбавки (5, 7, 11, 20, 25, 30). Выбор по цене. 
// Процент торговой надбавки реализовать с помощью перечисления.



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
enum Percent
{
    five=1,
    seven,
    eleven,
    twenty, 
    twentyfive,
    thirty
};

struct STORE
{
    char name[80];
    double price;
    int lot;
    Percent percent1;
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
    cout << "Наименование товара: ";
    cin.getline(person[i].name, 40);
    cout << "Стоимость: ";
    cin>>person[i].price;
    cout << "Количество: ";
    cin >> person[i].lot;
    cout << "Процент торговой надбавки: "<< endl;
    cout << "\t 1) 5% " << endl;
    cout << "\t 2) 7% " << endl;
    cout << "\t 3) 11% " << endl; 
    cout << "\t 4) 20% " << endl;
    cout << "\t 5) 25% " << endl;
    cout << "\t 6) 30% " << endl;
    int ENTER;
    cin >> ENTER;
    person[i].percent1 = Percent(ENTER);
   
}

void display()
{

    int i;
    for (i = 0; i < SiZE; i++)
    {
        if (*person[i].name)
        {
            cout << "Наименование товара: " << person[i].name << endl;
            cout << "Стоимость: " << person[i].price << endl;
            cout << "Количество: " << person[i].lot << endl;
            cout << "Процент торговой надбавки: " << person[i].percent1 << endl;
        }
    }
}
void clean()
{
    int i;
    for (i = 0; i < SiZE; i++)
    {
        *person[i].name = '\0';
        person[i].price = '\0';
        person[i].lot = '\0';
    }
}
void search()
{
    double money, num;
    cout << "Введите цену: ";
    cin >> money;
    for (int i = 0; i < SiZE; i++)
    {
        if (person[i].price == money)
        {
            cout << "Наименование товара: " << person[i].name << endl;
            cout << "Стоимость: " << person[i].price << endl;
            cout << "Количество: " << person[i].lot << endl;
            cout << "Процент торговой надбавки: " << person[i].percent1 << endl;
        }
    }
}