// В соответствии со своим вариантом разработать программу с использованием односвязного списка по данным, представленным в 
// таблице ниже.Программа должна содержать меню с пунктами : добавление элемента, удаление элемента, поиск элемента, вывод
// списка в консольное окно, 
// запись списка в файл, считывание списка из файла.

// Создать список, содержащий элементы вещественного типа. Найти сумму элементов, каждый из которых меньше числа 9. 


#include <iostream>
#include <fstream>

using namespace std;

struct list
{
    float number;
    list* next;
};

void add(list*&, float); 
float del(list*&, float);
int empty(list*);
void output(list*); 
void menu(void); 
void sum9(list*);
void toFile(list*& p);
void fromFile(list*& p);

int howmuch = 0;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    list* first = NULL;
    int choice;
    float value;
    menu();    // вывести меню 
    cout << " ? ";
    cin >> choice;
    while (choice != 6)
    {
        switch (choice)
        {
        case 1:  	cout << "Введите число "; // добавить число в список
            cin >> value;
            add(first, value);
            output(first);
            break;
        case 2:   if (!empty(first)) // удалить число из списка
        {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
                output(first);
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;
        case 3:   sum9(first);	
            break;
        case 4:  toFile(first);
            break;
        case 5: fromFile(first);
            break;
        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cout << "?  ";
        cin >> choice;
    }
    cout << "Конец" << endl;
    return 0;
}

void menu(void)  //Вывод меню 
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Вычисление суммы элементов, каждый из которых меньше числа 9" << endl;
    cout << " 4 - Запись информации в файл" << endl;
    cout << " 5 - Чтение из файла" << endl;
    cout << " 6 - Выход" << endl;
}

void add(list*& p, float value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

float del(list*& p, float value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next; // отсоединить узел 
        delete temp; //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return value;
        }
    }
    return 0;
}

int empty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}



void output(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void sum9(list* p)
{

    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < 9)
            howmuch = howmuch + (p->number);
            p = p->next;
        }
        cout << "Сумма элементов, каждый из которых меньше числа 9: " << howmuch << endl;
    }
}

void toFile(list*& p)
{
    list* temp = p;
    list buf;
    ofstream file("text.txt");
    if (file.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        buf = *temp;
        file.write((char*)&buf, sizeof(list));
        temp = temp->next;
    }
    file.close();
    cout << "Список записан в файл text.txt\n";
}

void fromFile(list*& p) //Считывание из файла
{
    list buf, * first = nullptr;
    ifstream file("text.txt");
    if (file.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    file.read((char*)&buf, sizeof(list));
    while (!file.eof())
    {
        add(first, buf.number);
        cout << "-->" << buf.number;
        file.read((char*)&buf, sizeof(list));
    }
    cout << "-->NULL" << endl;
    file.close();
    p = first;
    cout << "\nСписок считан из файла text.txt\n";
}

