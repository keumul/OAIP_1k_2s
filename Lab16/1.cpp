﻿// В соответствии со своим вариантом написать программу сортировок массивов указанными в таблице методами. Исходные массивы заполняются случайными числами. 
// Определить зависимость времени выполнения алгоритмов от количества элементов для каждого из алгоритмов. Выполнить моделирование для массивов различных размеров.
// Произвести сравнение эффективности алгоритмов (построить график в приложении Excel).

// Ввести массив А. В массив В скопировать элементы массива А, имеющие четный индекс. Массив В отсортировать по возрастанию, используя 
// алгоритмы сортировок: «пузырек», сортировка выбором.
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//void main() {
//	setlocale(LC_CTYPE, "RU");
//	const int size = 10;
//	int A[size], * B;
//	B = new int[size];
//	int i = 0;
//	cout << "Рандомно сгенерированный массив А:" << endl;
//	for (i = 0; i < size; i++) {
//		A[i] = rand() % 20;
//		cout << A[i] << "\t";
//	}cout << endl;
//	cout << "Массив B, содержащий элементы массива А, имеющие четный индекс:" << endl;
//	int how = 0;
//	for (i = 0; i < size; i++) {
//		if (i % 2 == 0) {
//			B[i] = A[i];
//			cout << B[i] << "\t";
//
//		}
//	}cout << endl;
//
//	cout << "Сортировка методом пузырька:\n";
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i; j < size; j++)
//		{
//			if (B[i] > B[j]) swap(B[i], B[j]);
//		}
//	}
//	for (int i = 0; i < size; i++)
//	{
//		if (B[i] >= 0) {
//			cout << B[i] << " ";
//		}
//	}
//	cout << endl;
//
//	cout << "Сортировка методом выбора:\n";
//	for (int start = 0; start < size; ++start)
//	{
//		int smallest = start;
//		for (int current = start + 1; current < size; ++current)
//		{
//			if (B[current] < B[smallest])
//				smallest = current;
//		}
//		swap(B[start], B[smallest]);
//	}
//	for (int i = 0; i < size; ++i) 
//	{
//		if (B[i] > 0) 
//		{
//			cout << B[i] << ' ';
//		}
//	}
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////ДОП1/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Ввести массивы А и В. В массив С перенести элементы массива А с четным значением и элементы массива В с нечетным значением. 
// Массив С отсортировать по возрастанию, используя алгоритмы сортировок: «пузырек», сортировка выбором.

//#include <iostream>
//#include <cstdlib>
//#include <conio.h>
//#include <cstdio>
//using namespace std;
//
//void main()
//{
//    setlocale(LC_ALL, "rus");
//    int a[5], b[6], c[11];
//    int q = 0;
//    int* p = a; int* r = b; int* s = c;
//    int i, j, k, tmp;
//
//    cout << "Массив A[5]: " << endl;
//    for (int i = 0; i < 5; i++) {
//        *p = rand() % 40;
//        cout<<*p<<"\t"; 
//        p++;
//    }
//    cout << endl;
//
//    cout << "Массив B[6]: " << endl;
//    for (int i = 0; i < 6; i++) {
//        *r = rand() % 40;
//        cout << *r << "\t";
//        r++;
//    }
//    cout << endl;
//
//    p = a;
//    r = b;
//    for (i = 0; i < 5; i++) {
//        if (a[i] % 2 == 0)
//        {
//            *s = a[i];
//            cout << *s << "\t";
//            s++;
//        }
//    }
//    for (i = 0; i < 6; i++) {
//        if (b[i] % 2 != 0) {
//            *s = b[i];
//            cout << *s << "\t";
//            s++;
//        }
//    }
//    s = c;
//    int size = 11;
//    cout << endl;
//    cout << "Сортировка методом пузырька:\n";
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i; j < size; j++)
//		{
//			if (c[i] > c[j]) swap(c[i], c[j]);
//		}
//	}
//	for (int i = 0; i < size; i++)
//	{
//		if (c[i] >= 0) {
//			cout << c[i] << " ";
//		}
//	}
//	cout << endl;
//
//	cout << "Сортировка методом выбора:\n";
//	for (int start = 0; start < size; ++start)
//	{
//		int smallest = start;
//		for (int current = start + 1; current < size; ++current)
//		{
//			if (s[current] < s[smallest])
//				smallest = current;
//		}
//		swap(s[start], s[smallest]);
//	}
//	for (int i = 0; i < size; ++i) 
//	{
//		if (c[i] > 0) 
//		{
//			cout << c[i] << ' ';
//		}
//	}
//  
//    _getch();
//}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////ДОП2/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Ввести массивы А и В.В массив С перенести четные элементы массива А и нечетные элемента массива В.Массив С отсортировать по убыванию, 
// используя алгоритмы сортировок : «пузырек», сортировка Хоара.

//#include <iostream>
//#include <cstdlib>
//#include <conio.h>
//#include <cstdio>
//using namespace std;
//void qs(int* c, int first, int last);
//void main()
//{
//    setlocale(LC_ALL, "rus");
//    int a[5], b[6], c[11];
//    int q = 0;
//    int* p = a; int* r = b; int* s = c;
//    int i, j, k, tmp;
//
//    cout << "Массив A[5]: " << endl;
//    for (int i = 0; i < 5; i++) {
//        *p = rand() % 40;
//        cout << *p << "\t";
//        p++;
//    }
//    cout << endl;
//
//    cout << "Массив B[6]: " << endl;
//    for (int i = 0; i < 6; i++) {
//        *r = rand() % 40;
//        cout << *r << "\t";
//        r++;
//    }
//    cout << endl;
//
//    p = a;
//    r = b;
//    for (i = 0; i < 5; i++) {
//        if (a[i] % 2 == 0)
//        {
//            *s = a[i];
//            cout << *s << "\t";
//            s++;
//        }
//    }
//    for (i = 0; i < 6; i++) {
//        if (b[i] % 2 != 0) {
//            *s = b[i];
//            cout << *s << "\t";
//            s++;
//        }
//    }
//    s = c;
//    int size = 11;
//    cout << endl;
//    cout << "Сортировка методом пузырька:\n";
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = i; j < size; j++)
//        {
//            if (c[i] < c[j]) swap(c[i], c[j]);
//        }
//    }
//    for (int i = 0; i < size; i++)
//    {
//        if (c[i] >= 0) {
//            cout << c[i] << " ";
//        }
//    }
//    cout << endl;
//
//    cout << "Сортировка методом Хоара:\n";
//    
//    qs(c, 0, size - 1);
//    	for (int i = 0; i < size; i++)
//    	{
//    		if (c[i] >= 0) {
//    			cout << c[i] << " ";
//    		}
//    	}
//    _getch();
//}
//void qs(int* c, int first, int last)
//{
//    int i = first, j = last, x =c[(first + last) / 2];
//
//    do {
//        while (c[i] < x) i++;
//        while (c[j] > x) j--;
//
//        if (i <= j) {
//            if (c[i] < c[j]) swap(c[i], c[j]);
//            i++;
//            j--;
//        }
//    } while (i <= j);
//
//    if (i < last)
//        qs(c, i, last);
//    if (first < j)
//        qs(c, first, j);
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////ДОП3/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Ввести массив А, в массив В перенести все элементы массива А, стоящие правее максимального элемента и имеющие нечетный индекс.Массив В 
// отсортировать по убыванию, используя алгоритмы сортировок : «пузырек», сортировка Хоара.

#include <iostream>
#include <cstdlib>
using namespace std;
void qs(int* B, int first, int last);
int A[10];
int *B = new int[10];
void main() {
	setlocale(LC_CTYPE, "RU");
	const int size = 10;
	int i = 0;
	cout << "Рандомно сгенерированный массив А:" << endl;
	for (i = 0; i < size; i++) {
		A[i] = rand() % 30;
		cout << A[i] << "\t";
	}cout << endl;
	cout << "Массив B, содержащий элементы массива А, стоящие правее максимального элемента и имеющие нечетный индекс:" << endl;
	int how = 0, max = 0, imax = 0;
	for (i = 0; i < size; i++) {
		if (A[i] > max) {
			max = A[i];
			imax = i;
		}
	}
	for (i = imax; i < size; i++) {
		if (i % 2 != 0) {
			B[i] = A[i];
			cout << B[i] << "\t";
		}
	}cout << endl;

	cout << "Сортировка методом пузырька:\n";
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (B[i] < B[j]) swap(B[i], B[j]);
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (B[i] >= 0) {
			cout << B[i] << " ";
		}
	}
	cout << endl;
	cout << "Сортировка методом Хоара:\n";
	qs(B, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		if (B[i] >= 0) {
			cout << B[i] << " ";
		}
	}
	cout << endl;
}

void qs(int* B, int first, int last)
{
	int i = first, j = last, x = B[(first + last) / 2];

	do {
		while (B[i] < x) i++;
		while (B[j] > x) j--;

		if (i <= j) {
			if (B[i] < B[j]) swap(B[i], B[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		qs(B, i, last);
	if (first < j)
		qs(B, first, j);
}
	