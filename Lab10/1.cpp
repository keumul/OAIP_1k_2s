////--------1ДОП---------1ДОП--------1ДОП---------1ДОП----------1ДОП------------1ДОП------------1ДОП---------1ДОП-----------------------------------------------//
//
//// Ввести цифру А, записать в файл все возможные числа, состоящие из цифр, не превышающих или равных A.Количество цифр в числах должно быть равно А.
//// Примечание: использовать дополнительный массив.
//
//#include <iostream>
//#include <fstream>
//#include <cmath>
//
//using namespace std;
//
//int i, c, b = 0;
//int fun(int smth, int max, int* Array) {
//    if (!b) 
//    {
//        while (i < max) 
//        {
//            i++;
//            b++;
//        }
//    }
//    if (i <= smth) 
//    {
//        Array[c] = i;
//        ++i;
//        c++;
//        fun(smth, max, Array);
//    }
//    else {
//    return c;
//    }
//}
//
//int main(int argc, char* argv[])
//{
//    setlocale(LC_CTYPE, "Russian");
//    ofstream f("t.txt");
//    int A = 0;
//    cout << "Введите А: "; cin >> A;
//    cout << endl;
//    int* Arr = new int[A];
//    int counter = 1;
//    while (counter < A) 
//    {
//        counter = counter * 10;
//    }
//    counter = counter / 10;
//    int count = fun(A, counter, Arr);
//    for (int i = 0; i < count; i++) 
//    {
//        f << Arr[i] << endl;
//    }
//    f.close();
//    return 0;
//}
//
//
////--------2ДОП---------2ДОП--------2ДОП---------2ДОП----------2ДОП------------2ДОП------------2ДОП---------2ДОП-----------------------------------------------//
//
//
//// Дано n различных натуральных чисел (n = 5). Напечатать все перестановки этих чисел
//
////#include <iostream>
////using namespace std;
////const int n = 5;
////int a[n];
////
////void perm(int k) {
////    int i, j, t, p;
////    for (i = 0; i < n - k; i++) {
////        if (k < n - 2) {perm(k + 1);} // рекурсивный вызов
////        else { 
////            for (p = 0; p < n; p++) cout << " " << a[p];
////            cout << endl; }
////        // циклический сдвиг
////        t = a[k];
////        for (j = k + 1; j < n; j++) a[j - 1] = a[j];
////        a[j - 1] = t;
////    }
////}
////
////int main(void)
////{
////    int i;
////    for (i = 0; i < n; i++) a[i] = i + 1;
////    perm(0);
////    return 0;
////}
//
////--------3ДОП---------3ДОП--------3ДОП---------3ДОП----------3ДОП------------3ДОП------------3ДОП-----------3ДОП-----------3ДОП-------------3ДОП----------3ДОП-------------//
//
//// По заданному числу n определить символ, который стоит на n - ом месте последовательности, получившейся после шага c номером 26.
#include <iostream>
using namespace std;
int n = 0, k = 0, search;
void func(int num)
{
	if (num > 0) func(num - 1); k++;
	if (n == k) { search = num; }
	cout << num << " ";
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите n-ое место последовательности: "; cin >> n;
	cout << endl;
	cout << "Последовательность: "<< endl; 
	func(26); cin.get();
	cout << endl;
	cout << "Символ, который стоит на "<<n<<" месте последовательности: " << search << endl;
	return 0;
}
