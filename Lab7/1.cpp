// Создать проект, демонстрирующий работу со стеком, организованным на основе списка, в соответствии со своим вариантом для данных из таблицы ниже. 
// Все операции со стеком реализовать через функции. Дополнить проект функциями очистки стека clear(), сохранения в файл и считывания из файла.
// Проект должен содержать три части : главная функция, файл с функциями работы со стеком и заголовочный файл. Создать интерфейс в виде меню.

//Разработать функцию, которая по одному стеку Stack строит 2 новых: Stack1 из четных элементов, Stack2 из нечетных.


#include <iostream>
#include "myStack.h"
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
    Stack1* Data1 = new Stack1; // нечётные числа
    Stack2* Data2 = new Stack2; // чётные числа
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
//using namespace std;
////int _tmain(int argc, char* argv[])
//int main() 
//{
//	setlocale(LC_ALL, "Rus");
//	int choice;
//	Stack* myStk = new Stack; //выделение памяти для стека
//	myStk->head = NULL;       //инициализация первого элемента	
//	for (;;)
//	{
//		cout << "Выберите команду:" << endl;
//		cout << "1 - Добавление элемента в стек" << endl;
//		cout << "2 - Удаление элемента из стека" << endl;
//		cout << "3 - Вывод стека" << endl;
//		cout << "4 - Сохранение в файл" << endl;
//		cout << "5 - Считывание из файла" << endl;
//		cout << "6 - Выход" << endl;
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "Введите элемент: " << endl;
//			cin >> choice;
//			push(choice, myStk);
//			break;
//		case 2: choice = pop(myStk);
//			if (choice != -1)
//				cout << "Извлеченный элемент: " << choice << endl;
//			break;
//		case 3: cout << "Весь стек: " << endl;
//			show(myStk);
//			break;
//		case 4: cout << "Удаление содержисого стек: " << endl;
//			show(myStk);
//			break;
//		case 6: return 0;
//			break;
//		}
//	}
//	return 0;
//}
//
