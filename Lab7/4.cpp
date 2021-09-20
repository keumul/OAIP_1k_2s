//Разработать функцию, которая по одному стеку строит два новых: Stack1 из положительных элементов и Stack2 из отрицательных.

#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int value = 0;
    int amount = 0;
    Stack* Data = new Stack; // выделяем память для стека
    Data->head = NULL;
    int choice = 0;

    // int value = 0;
    Stack1* Data1 = new Stack1; 
    Stack2* Data2 = new Stack2;
    Stack* element = Data->head;
    Data1->head = NULL;
    Data2->head = NULL;
    do
    {
        cout << "1. Добавить числа в стек " << endl;
        cout << "2. Считывание стека " << endl;
        cout << "3. Запись стека в файл " << endl;
        cout << "4. Считывание из файла " << endl;
        cout << "5. Сортировка стека " << endl;
        cout << "6. Очистить стек " << endl;
        cout << "7. Выход " << endl << endl;
        cout << "Номер операции: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Количество чисел: ";
            cin >> amount;
            for (int i = 0; i < amount; i++)
            {
                cout << "Число: ";
                cin >> value;
                Push(Data, value);
            }
            cout << "Числа добавлены в стек. ";
            break;
        case 2: Print(Data);
            break;
        case 3: Write_file(Data);
            break;
        case 4: Read_file();
            break;
        case 5: Sorting(Data);
            break;
        case 6: Clean(Data);
            break;
        case 7: exit(0);
            break;
        default: cout << endl;
            cout << "Некорректный ввод!" << endl;
            cout << "Повторите ввод ещё раз. " << endl << endl;
            break;
        }
    } while (choice != 7);
    return 0;
}