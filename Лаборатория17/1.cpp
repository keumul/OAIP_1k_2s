// В соответствии со своим вариантом написать программу для сортировок массивов указанными в таблице методами. Исходные массивы 
// заполняются случайными числами. Определить зависимость времени выполнения алгоритмов от количества элементов для каждого из
// алгоритмов.Выполнить моделирование для массивов размером 1000, 2000, 3000, 4000, 5000 (в зависимости от быстродействия компьютера
// размеры массивов можно увеличивать). Произвести сравнение эффективности алгоритмов(построить график в приложении Excel).

// Сортировка Хоара, пирамидальная сортировка, сортировка выбором

//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//void qs(int* B, int first, int last);
//void printArray(int B[], int size);
//void heapSort(int B[], int size);
//void heapify(int B[], int size, int i);
//
//void main() {
//	setlocale(LC_CTYPE, "RU");
//	int size = 0;
//	cout << "Размер массива = "; cin >> size;
//	cout << endl;
//	int* B;
//	B = new int[size];
//	int i = 0;
//	cout << "Рандомно сгенерированный массив:" << endl;
//	for (i = 0; i < size; i++) {
//		B[i] = rand() % 100;
//		cout << B[i] << ' ';
//	}cout << endl;
//
//	cout << endl;
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
//	cout << endl;
//	cout << endl;
//	cout << "Сортировка методом Хоара:\n";
//	qs(B, 0, size - 1);
//	for (int i = 0; i < size; i++)
//	{
//		if (B[i] >= 0) {
//			cout << B[i] << " ";
//		}
//	}
//	cout << endl;
//	cout << endl;
//	cout << "Сортировка пирамидальным методом:\n";
//	heapSort(B, size);
//	printArray(B, size);
//}
//
//	
//	void qs(int* B, int first, int last)
//	{
//		int i = first, j = last, x = B[(first + last) / 2];
//	
//		do {
//			while (B[i] < x) i++;
//			while (B[j] > x) j--;
//	
//			if (i <= j) {
//				if (B[i] < B[j]) swap(B[i], B[j]);
//				i++;
//				j--;
//			}
//		} while (i <= j);
//	
//		if (i < last)
//			qs(B, i, last);
//		if (first < j)
//			qs(B, first, j);
//	}
//
//	void heapify(int B[], int size, int i)
//	{
//		int largest = i;
//		// Инициализируем наибольший элемент как корень
//		int l = 2 * i + 1; // левый = 2*i + 1
//		int r = 2 * i + 2; // правый = 2*i + 2
//
//	 // Если левый дочерний элемент больше корня
//		if (l < size && B[l] > B[largest])
//			largest = l;
//
//		// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
//		if (r < size && B[r] > B[largest])
//			largest = r;
//
//		// Если самый большой элемент не корень
//		if (largest != i)
//		{
//			swap(B[i], B[largest]);
//
//			// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
//			heapify(B, size, largest);
//		}
//	}
//
//	// Основная функция, выполняющая пирамидальную сортировку
//	void heapSort(int B[], int size)
//	{
//		// Построение кучи (перегруппируем массив)
//		for (int i = size / 2 - 1; i >= 0; i--)
//			heapify(B, size, i);
//
//		// Один за другим извлекаем элементы из кучи
//		for (int i = size - 1; i >= 0; i--)
//		{
//			// Перемещаем текущий корень в конец
//			swap(B[0], B[i]);
//
//			// вызываем процедуру heapify на уменьшенной куче
//			heapify(B, i, 0);
//		}
//	}
//
//	/* Вспомогательная функция для вывода на экран массива размера n*/
//	void printArray(int B[], int size)
//	{
//		for (int i = 0; i < size; ++i)
//			cout << B[i] << " ";
//		cout << "\n";
//	}
//


	//----------------------------------------------------ДОП1----------------------------------------------------------------------------
	//Дан массив из 10 элементов.Первые 4 элемента упорядочить по возрастанию, последние 4 по убыванию.
//#include <iostream>
//#include <cstdlib>
//	using namespace std;
//
//	void main() {
//		setlocale(LC_CTYPE, "RU");
//		int size = 10;
//		int* B;
//		B = new int[size];
//		int i = 0;
//		cout << "Рандомно сгенерированный массив:" << endl;
//		for (i = 0; i < size; i++) {
//			B[i] = rand() % 100;
//			cout << B[i] << ' ';
//		}cout << endl;
//
//		cout << endl;
//		cout << "Первые 4 элемента упорядочены по возрастанию, последние 4 по убывани:\n";
//		for (int start = 0; start < 5; ++start)
//		{
//			int smallest = start;
//			for (int current = start + 1; current < size; ++current)
//			{
//				if (B[current] < B[smallest])
//					smallest = current;
//			}
//			swap(B[start], B[smallest]);
//		}
//
//		for (int start = 6; start < size; ++start)
//		{
//			int smallest = start;
//			for (int current = start + 1; current < size; ++current)
//			{
//				if (B[current] > B[smallest])
//					smallest = current;
//			}
//			swap(B[start], B[smallest]);
//		}
//		for (int i = 0; i < size; ++i)
//		{
//			if (B[i] > 0)
//			{
//				cout << B[i] << ' ';
//			}
//		}
//		cout << endl;
//	}
//
//

	//----------------------------------------------------ДОП2----------------------------------------------------------------------------
	// Дан массив из 15 целых чисел на отрезке [-5; 5]. Упорядочить массив, удалив повторяющиеся элементы.

//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//void main() {
//	setlocale(LC_CTYPE, "RU");
//    
//    int m = 15;
//    int s1 = 0, s2 = 0;
//    
//    int* arr = new int[m]; 
//    int* brr = new int[m];
//
//    for (int i = 0; i < m; i++)
//    {
//        arr[i] = -5 + rand() % (5 + 5 + 1);
//        cout << arr[i] << " ";
//    }
//    cout << "\n"; 
//    
//    cout << "Упорядоченный массив с удаленными повторяющимися элементами: " << endl;
//    int CurIndex = 0;
//    bool Found;
//    for (int i = 0; i < 20; i++)
//    {
//        Found = false;
//        for (int j = 0; j < CurIndex; j++)
//            if (brr[j] == arr[i])
//            {
//                Found = true;
//                break;
//            }
//        if (!Found)
//            brr[CurIndex++] = arr[i];
//    }
//    // Создаём динамический массив с размерностью равной кол-ву уникальных элементов исходного и переписываем в него элементы из временного массива
//    int* DimFinal = new int[CurIndex];
//    for (int i = 0; i < CurIndex; i++)
//    {
//        DimFinal[i] = brr[i];
//    }
//
//    for (int start = 0; start < CurIndex; ++start)
//    {
//        int smallest = start;
//        for (int current = start + 1; current < CurIndex; ++current)
//        {
//            if (DimFinal[current] < DimFinal[smallest])
//                smallest = current;
//        }
//        swap(DimFinal[start], DimFinal[smallest]);
//    }
//    for (int i = 0; i < CurIndex; ++i)
//    {
//        if (DimFinal[i] > -10 && DimFinal[i] < 10)
//        {
//            cout << DimFinal[i] << ' ';
//        }
//    }
//    cout << endl;
//}





//----------------------------------------------------ДОП3----------------------------------------------------------------------------
// Дан массив целых чисел, количество элементов которого надо ввести с клавиатуры. Найти максимальный элемент массива и его номер, при 
// условии, что все элементы различны. Найти минимальный элемент массива.

#include <iostream>
#include <cstdlib>
using namespace std;

void main() {
    setlocale(LC_CTYPE, "RU");

    int m = 0;
    int s1 = 0, s2 = 0;
    cout << "Размер массива = "; cin >> m;
    cout << endl;
    int* arr = new int[m];
    int* brr = new int[m];

    for (int i = 0; i < m; i++)
    {
        arr[i] = rand() % 25;
        cout << arr[i] << " ";
    }
    cout << "\n";

    cout << "Упорядоченный массив с удаленными повторяющимися элементами: " << endl;
    int CurIndex = 0;
    bool Found;
    for (int i = 0; i < 20; i++)
    {
        Found = false;
        for (int j = 0; j < CurIndex; j++)
            if (brr[j] == arr[i])
            {
                Found = true;
                break;
            }
        if (!Found)
            brr[CurIndex++] = arr[i];
    }
    // Создаём динамический массив с размерностью равной кол-ву уникальных элементов исходного и переписываем в него элементы из временного массива
    int* DimFinal = new int[CurIndex];
    for (int i = 0; i < CurIndex; i++)
    {
            DimFinal[i] = brr[i];
    }

    //сортировка выбором
    for (int start = 0; start < CurIndex; ++start)
    {
        int smallest = start;
        for (int current = start + 1; current < CurIndex; ++current)
        {
            if (DimFinal[current] < DimFinal[smallest])
                smallest = current;
        }
        swap(DimFinal[start], DimFinal[smallest]);
    }

    for (int i = 0; i < CurIndex; ++i)
    {
        if (DimFinal[i] > -10 && DimFinal[i] < 10)
        {
            cout << DimFinal[i] << ' ';
        }
    }
    cout << endl;

    //максимальный и минимальный элементы массива
    int max = 0,imax=0, min = 0;
    //1 способ (с учетом сортировки):
    for (int i = 0; i < CurIndex; ++i)
    {
        if (DimFinal[i] > -10 && DimFinal[i] < 10)
        {
            if (DimFinal[i] > max) {
                max = DimFinal[i];
                imax = i;
            }
            if (DimFinal[i] < min) {
                min = DimFinal[i];
            }
        }
    }
    cout << "Максимальный элемент массива = " << max << " (находится под № "<<imax+1<<" в массиве)"<< endl;
    cout << "Минимальный элемент массива = " << min << endl;
    cout << endl;
}