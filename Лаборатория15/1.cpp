// В соответствии со своим вариантом разработать проект для условия из таблицы, представленной ниже. Построить хеш-таблицы разного размера с коллизиями. 
// Для вариантов с 1 по 8 вычисление хеш - функции произвести по методу универсального хеширования.Для вариантов с 9 по 16 при вычислении хеш - функции использовать
// алгоритм на основе исключающего ИЛИ для поля строки данных. Исследовать время поиска информации.

//Жильцы. Реализовать хеш-таблицу со следующими полями: № квартиры, жильцы. Ключ — номер квартиры.


//#include <iostream>
//#include <fstream>
//using namespace std;
//
//typedef char T;  // тип элементов
//typedef int hashTableIndex; // индекс в хеш-таблице
//#define compEQ(a,b) (a == b)
//typedef struct Node_ {
//    T data;// данные, хранящиеся в вершине
//    struct Node_* next; // следующая вершина
//} Node;
//
//Node** hashTable;
//int hashTableSize;
//hashTableIndex myhash(T data);
//Node* insertNode(T data);
//void deleteNode(T data);
//Node* findNode(T data);
//
//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    int i, maxnum=0;
//    char* a=0;
//   // char a[20];
//    int choice=10;
//    for (;;)
//    {
//        cout << "1.Создание хеш-таблицы" << endl;
//        cout << "2.Вывод хеш-таблицы" << endl;
//        cout << "3.Поиск информации" << endl;
//        cout << "4.Очистка хеш-таблицы" << endl;
//        cout << "0.Выход" << endl;
//        cin >> choice;
//        switch (choice) {
//        case 1:
//        {
//            cout << "Введите количество жильцов: "; cin >> maxnum;
//            cout << "Введите размер дома (размер хеш-таблицы): ";
//            cin >> hashTableSize;
//            a = new char[maxnum];
//            hashTable = new Node * [hashTableSize];
//            for (i = 0; i < hashTableSize; i++)
//                hashTable[i] = NULL;
//            for (i = 0; i < maxnum; i++)
//            {
//                a[i] = 'a'+rand() % 26;
//                a[maxnum] = '\0';
//            }
//            for (i = 0; i < maxnum; i++) {
//                insertNode(a[i]);
//            }
//        }
//        break;
//        case 2:
//        {
//            cout << "Рандомно сгенерированные люди, которые берутся за основу: " << endl;
//            for (i = 0; i < maxnum; i++) {
//                cout << a[i];
//                if (i < maxnum - 1) cout << "\t";
//            }
//            cout << endl;
//            cout << "Хеш-таблица: " << endl;
//            for (i = 0; i < hashTableSize; i++) {
//                cout << i << "  :  ";
//                Node* Temp = hashTable[i];
//                while (Temp) {
//                    cout << Temp->data << " -> ";
//                    Temp = Temp->next;
//                }
//                cout << endl;
//            }
//        }
//        break;
//        case 3:
//        {
//            int sear = 0;
//            cout << "Введите номер элемента хеш-таблица (см.массив): "; cin >> sear;
//            cout << endl;
//            // поиск элементов массива по хеш-таблице
//            for (i = 0; i < maxnum; i++) {
//                if (i == sear)
//                {
//                    cout << "Найденный элемент:" << a[i-1] << endl;
//               }
//            }
//            break;
//        }
//        case 4:
//        {
//            // очистка хеш-таблицы
//            for (i = maxnum - 1; i >= 0; i--) {
//                deleteNode(a[i]);
//            }
//        }
//        case 0:
//        {
//            exit(0);
//        }}
//    }
//    return 0;
//}
//
//
//// хеш-функция размещения вершины
////алгоритм на основе исключающего ИЛИ для поля строки данных
//hashTableIndex myhash(T data) {
//    return fmod(data^13,hashTableSize);
//    //return (data % hashTableSize); то, что было изначально
//}
//
//
//// функция поиска местоположения и вставки вершины в таблицу
//Node* insertNode(T data) {
//    Node* p, * p0;
//    hashTableIndex bucket;
//    // вставка вершины в начало списка
//    bucket = myhash(data);
//    if ((p = new Node) == 0) {
//        fprintf(stderr, "Нехватка памяти (insertNode)\n");
//        exit(1);
//    }
//    p0 = hashTable[bucket];
//    hashTable[bucket] = p;
//    p->next = p0;
//    p->data = data;
//    return p;
//}
//
////функция удаления вершины из таблицы
//void deleteNode(T data) {
//    Node* p0, * p;
//    hashTableIndex bucket;
//    p0 = 0;
//    bucket = myhash(data);
//    p = hashTable[bucket];
//    while (p && !compEQ(p->data, data)) {
//        p0 = p;
//        p = p->next;
//    }
//    if (!p) return;
//    if (p0)
//        p0->next = p->next;
//    else
//        hashTable[bucket] = p->next;
//    free(p);
//}
//
//// функция поиска вершины со значением data
//Node* findNode(T data) {
//    Node* p;
//    p = hashTable[myhash(data)];
//    while (p && !compEQ(p->data, data))
//    p = p->next;
//    cout << p << endl;
//    return p;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------ДОП 1----------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// В текстовом файле содержатся целые числа. Построить хеш-таблицу из чисел файла. Осуществить поиск введенного целого числа в хеш-таблице. 
// Сравнить результаты количества сравнений при различном наборе данных в файле.

//#include <iostream>
//#include <fstream>
//
//using namespace std;
//typedef int T; // тип элементов
//typedef int hashTableIndex; // индекс в хеш-таблице
//#define compEQ(a, b) (a == b)
//
//typedef struct Node_ {
//    T data;// данные, хранящиеся в вершине
//    struct Node_* next; // следующая вершина
//} Node;
//
//Node** hashTable;
//int hashTableSize;
//hashTableIndex myhash(T data);
//Node* insertNode(T data);
//void deleteNode(T data);
//Node* findNode(T data);
//
//int main() {
//    setlocale(LC_CTYPE, "RU");
//    int i, *a=0, maxnum=0;
//    int choice = 10;
//        for (;;)
//        {
//            cout << "1.Генерация рандомных чисел и запись их в файл" << endl;
//            cout << "2.Создание хеш-таблицы на основе данных из файла" << endl;
//            cout << "3.Поиск информации" << endl;
//            cout << "4.Очистка хеш-таблицы" << endl;
//            cout << "0.Выход" << endl;
//            cin >> choice;
//            switch (choice) {
//            case 1:
//            {
//                cout << "Введите количество элементов maxnum : ";
//                cin >> maxnum;
//                cout << "Введите размер хеш-таблицы HashTableSize : ";
//                cin >> hashTableSize;
//                a = new int[maxnum];
//                hashTable = new Node * [hashTableSize];
//                for (i = 0; i < hashTableSize; i++)
//                    hashTable[i] = NULL;
//                // генерация массива
//                for (i = 0; i < maxnum; i++)
//                    a[i] = rand()%100;
//                // заполнение хеш-таблицы элементами массив
//                for (i = 0; i < maxnum; i++) {
//                    insertNode(a[i]);
//                }
//                // вывод элементов массива в файл List. txt
//                ofstream out("List.txt");
//                for (i = 0; i < maxnum; i++) {
//                    out << a[i];
//                    if (i < maxnum - 1) out << "\t";
//                }
//
//                out.close();
//                // сохранение хеш-таблицы в файл HashTable. txt
//                out.open("HashTable.txt");
//                for (i = 0; i < hashTableSize; i++) {
//                    out << i;
//                    Node* Temp = hashTable[i];
//                    while (Temp) {
//                        out << Temp->data;
//                        Temp = Temp->next;
//                    }
//                }
//                out.close();
//            }
//            break;
//            case 2:
//            {
//                // вывод элементов массива в файл List. txt
//                ofstream out("List.txt");
//                for (i = 0; i < maxnum; i++) {
//                    cout << a[i];
//                    if (i < maxnum - 1) cout << "\t";
//                }
//                out.close();
//                
//                // сохранение хеш-таблицы в файл HashTable. txt
//                out.open("HashTable.txt");
//                for (i = 0; i < hashTableSize; i++) {
//                    cout << i << " : ";
//                    Node* Temp = hashTable[i];
//                    while (Temp) {
//                        cout << Temp->data << " -> ";
//                        Temp = Temp->next;
//                    }
//                    cout << endl;
//                }out.close();
//            }
//            break;
//            case 3:
//            {
//                int sear = 0, howmuch = 0;
//                cout << "Введите номер элемента хеш-таблица (см.массив): "; cin >> sear;
//                cout << endl;
//                // поиск элементов массива по хеш-таблице
//                for (i = 0; i < maxnum; i++) {
//                    if (i == sear)
//                    {
//                        cout << "Найденный элемент:" << a[i-1] << endl;
//                    }
//                    howmuch++;
//                }
//                cout << "Количество сравнений:" << howmuch << endl;
//                break;
//            }
//            case 4:
//            {
//                // очистка хеш-таблицы
//                for (i = maxnum - 1; i >= 0; i--) {
//                    deleteNode(a[i]);
//                }
//            }
//            case 0:
//            {
//                exit(0);
//            }}
//        }
//        return 0;
//    
//
//// поиск элементов массива по хеш-таблице
//for (i = maxnum - 1; i >= 0; i--) {
//    findNode(a[i]);
//}
//
//
//// очистка хеш-таблицы
//for (i = maxnum - 1; i >= 0; i--) {
//    deleteNode(a[i]);
//}
//
//system("pause");
//return 0;
//}
//
//// хеш-функция размещения вершины
//hashTableIndex myhash(T data) {
//    return (data % hashTableSize);
//}
//
//// функция поиска местоположения и вставки вершины в таблицу
//Node* insertNode(T data) {
//    Node* p, * p0;
//    hashTableIndex bucket;
//    // вставка вершины в начало списка
//    bucket = myhash(data);
//    if ((p = new Node) == 0) {
//        fprintf(stderr, "Нехватка памяти (insertNode)\n");
//        exit(1);
//    }
//    p0 = hashTable[bucket];
//    hashTable[bucket] = p;
//    p->next = p0;
//    p->data = data;
//    return p;
//}
//
//// функция удаления вершины из таблицы
//
//void deleteNode(T data) {
//    Node* p0, * p;
//    hashTableIndex bucket;
//    p0 = 0;
//    bucket = myhash(data);
//    p = hashTable[bucket];
//    while (p && !compEQ(p->data, data)) {
//        p0 = p;
//        p = p->next;
//    }
//    if (!p) return;
//    if (p0)
//        p0->next = p->next;
//    else
//        hashTable[bucket] = p->next;
//    free(p);
//}
//
//// функция поиска вершины со значением data
//Node* findNode(T data) {
//    Node* p;
//    p = hashTable[myhash(data)];
//    while (p && !compEQ(p->data, data))
//        p = p->next;
//    return p;
//}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------2ДОП------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Составить хеш-таблицу, содержащую буквы и количество их вхождений во введенной строке. Вывести таблицу на экран. Осуществить поиск введенной 
// буквы в хеш-таблице.

//#include <iostream>
//#include <fstream>
//using namespace std;
//
//typedef char T;  // тип элементов
//typedef int hashTableIndex; // индекс в хеш-таблице
//#define compEQ(a,b) (a == b)
//typedef struct Node_ {
//    T data;// данные, хранящиеся в вершине
//    struct Node_* next; // следующая вершина
//} Node;
//
//Node** hashTable;
//int hashTableSize;
//hashTableIndex myhash(T data);
//Node* insertNode(T data);
//void deleteNode(T data);
//Node* findNode(T data);
//
//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    int i, maxnum=0;
//    char* a=0;
//   // char a[20];
//    int choice=10;
//    for (;;)
//    {
//        cout << "1.Создание хеш-таблицы" << endl;
//        cout << "2.Вывод хеш-таблицы" << endl;
//        cout << "3.Поиск информации по ключу" << endl;
//        cout << "4.Поиск информации по букве" << endl;
//        cout << "5.Удаление хеш-таблицы" << endl;
//        cout << "0.Выход" << endl;
//        cin >> choice;
//        switch (choice) {
//        case 1:
//        {
//            cout << "Введите количество элементов: "; cin >> maxnum;
//            cout << "Введите размер хеш-таблицы: ";
//            cin >> hashTableSize;
//            a = new char[maxnum];
//            hashTable = new Node * [hashTableSize];
//            for (i = 0; i < hashTableSize; i++)
//                hashTable[i] = NULL;
//            for (i = 0; i < maxnum; i++)
//            {
//                a[i] = 'a'+rand() % 26;
//                a[maxnum] = '\0';
//            }
//            for (i = 0; i < maxnum; i++) {
//                insertNode(a[i]);
//            }
//        }
//        break;
//        case 2:
//        {
//            int how = 0, other=0;
//            cout << "Рандомно сгенерированные элементы, которые берутся за основу: " << endl;
//            for (i = 0; i < maxnum; i++) {
//                cout << a[i];
//                for (int j = maxnum; j > 0; j--) {
//                    if (a[j] == a[i]) {
//                        how++;
//                    }
//                }
//                if (i < maxnum - 1) cout;
//                cout << " - " << how << endl;
//                how = 0;
//            }
//            
//            cout << endl;
//            cout << "Хеш-таблица: " << endl;
//            for (i = 0; i < hashTableSize; i++) {
//                cout << i << "  :  ";
//                Node* Temp = hashTable[i];
//                while (Temp) {
//                    cout << Temp->data << " -> ";
//                    Temp = Temp->next;
//                }
//                cout << endl;
//            }
//        }
//        break;
//        case 3:
//        {
//            int sear = 0;
//            cout << "Введите номер элемента хеш-таблица (см.массив): "; cin >> sear;
//            cout << endl;
//            // поиск элементов массива по хеш-таблице
//            for (i = 0; i < maxnum; i++) {
//                if (i == sear)
//                {
//                    cout << "Найденный элемент:" << a[i-1] << endl;
//               }
//            }
//            break;
//        }
//        case 4: {
//            char sear[5];
//            cout << "Введите букву: "; cin >> sear[0];
//            cout << endl;
//            // поиск элементов массива по хеш-таблице
//            for (i = 0; i < maxnum; i++) {
//                if (a[i] == sear[0])
//                {
//                    cout << "Найденный элемент находится по ключом:" << i + 1 << endl;
//                }
//            }
//            break;
//        }
//        case 5:
//        {
//            // очистка хеш-таблицы
//            for (i = maxnum - 1; i >= 0; i--) {
//                deleteNode(a[i]);
//            }
//        }
//        case 0:
//        {
//            exit(0);
//        }}
//    }
//    return 0;
//}
//
//
//// хеш-функция размещения вершины
////алгоритм на основе исключающего ИЛИ для поля строки данных
//hashTableIndex myhash(T data) {
//    return fmod(data^13,hashTableSize);
//    //return (data % hashTableSize); то, что было изначально
//}
//
//
//// функция поиска местоположения и вставки вершины в таблицу
//Node* insertNode(T data) {
//    Node* p, * p0;
//    hashTableIndex bucket;
//    // вставка вершины в начало списка
//    bucket = myhash(data);
//    if ((p = new Node) == 0) {
//        fprintf(stderr, "Нехватка памяти (insertNode)\n");
//        exit(1);
//    }
//    p0 = hashTable[bucket];
//    hashTable[bucket] = p;
//    p->next = p0;
//    p->data = data;
//    return p;
//}
//
////функция удаления вершины из таблицы
//void deleteNode(T data) {
//    Node* p0, * p;
//    hashTableIndex bucket;
//    p0 = 0;
//    bucket = myhash(data);
//    p = hashTable[bucket];
//    while (p && !compEQ(p->data, data)) {
//        p0 = p;
//        p = p->next;
//    }
//    if (!p) return;
//    if (p0)
//        p0->next = p->next;
//    else
//        hashTable[bucket] = p->next;
//    free(p);
//}
//
//// функция поиска вершины со значением data
//Node* findNode(T data) {
//    Node* p;
//    p = hashTable[myhash(data)];
//    while (p && !compEQ(p->data, data))
//    p = p->next;
//    cout << p << endl;
//    return p;
//}
//


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------3ДОП------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Построить хеш - таблицу из слов произвольного текстового файла, задав ее размерность с экрана.Вывести построенную таблицу 
//слов на экран.Осуществить поиск введенного слова.Выполнить программу для различных размерностей таблицы и сравните количество 
//сравнений.Удалить все слова, начинающиеся на указанную букву, выведите таблицу.

#include <iostream>
#include <fstream>

using namespace std;
typedef char T; // тип элементов
typedef int hashTableIndex; // индекс в хеш-таблице
#define compEQ(a, b) (a == b)

typedef struct Node_ {
    T data;// данные, хранящиеся в вершине
    struct Node_* next; // следующая вершина
} Node;

Node** hashTable;
int hashTableSize;
hashTableIndex myhash(T data);
Node* insertNode(T data);
void deleteNode(T data);
Node* findNode(T data);

int main() {
    setlocale(LC_CTYPE, "RU");
    int i, maxnum = 0;
    char* a = 0;
    int choice = 10;
    for (;;)
    {
        cout << "1.Генерация рандомных чисел и запись их в файл" << endl;
        cout << "2.Создание хеш-таблицы на основе данных из файла" << endl;
        cout << "3.Поиск информации" << endl;
        cout << "4.Удаление всех слов, начинающихся на указанную букву" << endl;
        cout << "0.Выход" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            cout << "Введите количество элементов maxnum : ";
            cin >> maxnum;
            cout << "Введите размер хеш-таблицы HashTableSize : ";
            cin >> hashTableSize;
            a = new char[maxnum];
            hashTable = new Node * [hashTableSize];
            for (i = 0; i < hashTableSize; i++)
                hashTable[i] = NULL;
            // генерация массива
            for (i = 0; i < maxnum; i++)
            {
                a[i] = 'a' + rand() % 26;
                a[maxnum] = '\0';
            }
            // заполнение хеш-таблицы элементами массив
            for (i = 0; i < maxnum; i++) {
                insertNode(a[i]);
            }
            // вывод элементов массива в файл List. txt
            ofstream out("List.txt");
            for (i = 0; i < maxnum; i++) {
                out << a[i];
                if (i < maxnum - 1) out << "\t";
            }

            out.close();
            // сохранение хеш-таблицы в файл HashTable. txt
            out.open("HashTable.txt");
            for (i = 0; i < hashTableSize; i++) {
                out << i;
                Node* Temp = hashTable[i];
                while (Temp) {
                    out << Temp->data;
                    Temp = Temp->next;
                }
            }
            out.close();
        }
        break;
        case 2:
        {
            // вывод элементов массива в файл List. txt
            ofstream out("List.txt");
            for (i = 0; i < maxnum; i++) {
                cout << a[i];
                if (i < maxnum - 1) cout << "\t";
            }
            out.close();
            cout << endl;
            // сохранение хеш-таблицы в файл HashTable. txt
            out.open("HashTable.txt");
            for (i = 0; i < hashTableSize; i++) {
                cout << i << " : ";
                Node* Temp = hashTable[i];
                while (Temp) {
                    cout << Temp->data << " -> ";
                    Temp = Temp->next;
                }
                cout << endl;
            }out.close();
        }
        break;
        case 3:
        {
            int sear = 0;
            cout << "Введите номер элемента хеш-таблица (см.массив): "; cin >> sear;
            cout << endl;
            // поиск элементов массива по хеш-таблице
            for (i = 0; i < maxnum; i++) {
                if (i == sear)
                {
                    cout << "Найденный элемент:" << a[i - 1] << endl;
                }
            }
            break;
        }
        case 4:
        {
            char what;
            cout << "Введите 1ую букву слова, которое хотите удалить." << endl;
            cout << "Если слово состоит из 1 буквы - оно удаляется полностью: "; cin >> what;
            char* b;
                    b = new char[maxnum];
                    hashTable = new Node * [hashTableSize];
                    for (i = 0; i < hashTableSize; i++)
                        hashTable[i] = NULL;
                    // генерация массива
                    for (i = 0; i < maxnum; i++)
                    {
                        if (a[i] != what) {
                            b[i] = a[i];
                        }
                    }
                    // заполнение хеш-таблицы элементами массив
                    for (i = 0; i < maxnum; i++) {
                        insertNode(b[i]);
                    }
                    // вывод элементов массива в файл List. txt
                    ofstream out("List.txt");
                    for (i = 0; i < maxnum; i++) {
                        out << b[i];
                        if (i < maxnum - 1) out << "\t";
                    }

                    out.close();
                    // сохранение хеш-таблицы в файл HashTable. txt
                    out.open("HashTable.txt");
                    for (i = 0; i < hashTableSize; i++) {
                        out << i;
                        Node* Temp = hashTable[i];
                        while (Temp) {
                            out << Temp->data;
                            Temp = Temp->next;
                        }
                    }
                    out.close();

                    cout << "Слово удалено." << endl;
                }
        break;
        case 0:
        {
            exit(0);
        }
        }
    }
    return 0;


    // поиск элементов массива по хеш-таблице
    for (i = maxnum - 1; i >= 0; i--) {
        findNode(a[i]);
    }


    // очистка хеш-таблицы
    for (i = maxnum - 1; i >= 0; i--) {
        deleteNode(a[i]);
    }

    system("pause");
    return 0;
}

// хеш-функция размещения вершины
hashTableIndex myhash(T data) {
    return (data % hashTableSize);
}

// функция поиска местоположения и вставки вершины в таблицу
Node* insertNode(T data) {
    Node* p, * p0;
    hashTableIndex bucket;
    // вставка вершины в начало списка
    bucket = myhash(data);
    if ((p = new Node) == 0) {
        fprintf(stderr, "Нехватка памяти (insertNode)\n");
        exit(1);
    }
    p0 = hashTable[bucket];
    hashTable[bucket] = p;
    p->next = p0;
    p->data = data;
    return p;
}

// функция удаления вершины из таблицы

void deleteNode(T data) {
    Node* p0, * p;
    hashTableIndex bucket;
    p0 = 0;
    bucket = myhash(data);
    p = hashTable[bucket];
    while (p && !compEQ(p->data, data)) {
        p0 = p;
        p = p->next;
    }
    if (!p) return;
    if (p0)
        p0->next = p->next;
    else
        hashTable[bucket] = p->next;
    free(p);
}

// функция поиска вершины со значением data
Node* findNode(T data) {
    Node* p;
    p = hashTable[myhash(data)];
    while (p && !compEQ(p->data, data))
        p = p->next;
    return p;
}