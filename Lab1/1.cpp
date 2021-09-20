



#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

// 2x + x^3 – 7, e^x + 2x
// приближение e = 0,001
double f1(double x)
{
    return(2 * x + pow(x, 3) - 7);
}

double f2(double x)
{
    return(exp(x) + 2 * x);
}

double j(double a, double b, double (*f)(double))
{
    int x = 0;
    double e = 0.001;
    while (abs(a - b) > 2 * e)
    {
        x = (a + b) / 2;
        if (f(a) * f(x) <= 0)
        {
            b = x;
        }
        else a = x;
        return(x);
    } 
}
void lab1()
{
    setlocale(LC_CTYPE, "Russian");
    double a = 0, b = 0;
    cout << "Введите a и b: "; cin >> a >> b;
    cout<<"Решение 1го уравнения: "<< j(a, b, f1) << endl;
    cout<<"Решение 2го уравнения: "<< j(a, b, f2) << endl;
}

//x2 + 4x – 2, sin(x) + 0,1
//приближение e = 0,001

double f3(double x)
{
    return(pow(x,2) + 4*x - 2);
}

double f4(double x)
{
    return(sin(x)+0.1);
}

double l(double a, double b, double (*l)(double))
{
    int x = 0;
    double e = 0.001;
    while (abs(a - b) > 2 * e)
    {
        x = (a + b) / 2;
        if (l(a) * l(x) <= 0)
        {
            b = x;
        }
        else a = x;
        return(x);
    }
}
void lab2()
{
    setlocale(LC_CTYPE, "Russian");
    double a = 0, b = 0;
    cout << "Введите a и b: "; cin >> a >> b;
    cout << "Решение 1го уравнения: " << l(a, b, f3) << endl;
    cout << "Решение 2го уравнения: " << l(a, b, f4) << endl;
}


//x3 + x – 3, cos3(x)
//приближение e = 0,001
double f5(double x)
{
    return(pow(x,3)+x-3);
}

double f6(double x)
{
    return(cos(3*x));
}

double p(double a, double b, double (*p)(double))
{
    int x = 0;
    double e = 0.001;
    while (abs(a - b) > 2 * e)
    {
        x = (a + b) / 2;
        if (p(a) * p(x) <= 0)
        {
            b = x;
        }
        else a = x;
        return(x);
    }
}
void lab3()
{
    setlocale(LC_CTYPE, "Russian");
    double a = 0, b = 0;
    cout << "Введите a и b: "; cin >> a >> b;
    cout << "Решение 1го уравнения: " << p(a, b, f5) << endl;
    cout << "Решение 2го уравнения: " << p(a, b, f6) << endl;
}


//x3 + 2x – 1, ex - 2
double f7(double x)
{
    return(2 * x + pow(x, 3) - 1);
}

double f8(double x)
{
    return(exp(x) - 2);
}

double h(double a, double b, double (*h)(double))
{
    int x = 0;
    double e = 0.001;
    while (abs(a - b) > 2 * e)
    {
        x = (a + b) / 2;
        if (h(a) * h(x) <= 0)
        {
            b = x;
        }
        else a = x;
        return(x);
    }
}
void lab4()
{
    setlocale(LC_CTYPE, "Russian");
    double a = 0, b = 0;
    cout << "Введите a и b: "; cin >> a >> b;
    //cout << a << b << endl;
    cout << "Решение 1го уравнения: " << h(a, b, f7) << endl;
    cout << "Решение 2го уравнения: " << h(a, b, f8) << endl;
}


//Написать функцию, проверяющую есть ли отрицательные элементы в заданном одномерном массиве размерностью n.Удалить из массива все отрицательные элементы, удаленный элемент заполняется нулем и переносится в конец массива.

//int w(/*double *a,*/ int n, ...)
//{
//        int* a = &n;
//        cout << "Введите массив: " << endl;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> *(a+i);
//        }
//        cout << endl;
//   
//        for (int i = 0; i < n; i++)
//        {
//            cout << *(a+i) << "\t";
//        }
//        cout << endl;
//    
//    int* k = &n;
//    //нахождение отрицательныx элементов
//    int kol = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (*(k + i) < 0)
//        {
//            kol++;
//        }
//    }
//    if (kol > 0)
//    {
//        cout << "Отрицательные элементы ЕСТЬ, их кол-во: " << kol << endl;
//    }
//    else
//    {
//        cout << "Отрицательные элементы отсутствуют." << endl;
//    }
//
//    //перенесение отрицательных элементов в конец и замена 0
//    int neminus = 0, otvet=0;
//    for (int i = 0; i < n; i++)
//    { 
//        if (*(k+i) >= 0) 
//        {
//            *(k+neminus++) = *(k+i);
//        }
//    }
//    while (neminus < n)
//    {
//        
//        *(k+neminus++) = 0;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        otvet = *(k + i);
//        cout << *(k+i) << " ";
//    }
//    return otvet;
//}
//    void lab5()
//    {
//        int n = 0; double* a = 0;
//        setlocale(LC_CTYPE, "Russian");
//        int(*wf)( int n, ...);
//        wf = w;
//        cout<<w(n,...)<<endl;
//        //cout <<w(3,2,1,2) << endl;
//    }

int w(int n, int a, ...)
{
    int* b = &a;

    for (int i = 0; i < n; i++)
    {
        cout << *(b + i) << "\t";
    }
    cout << endl;

    int* k = &n;
    //нахождение отрицательныx элементов
    int kol = 0;
    for (int i = 0; i <= n; i++)
    {
        if (*(k + i) < 0)
        {
            kol++;
        }
    }
    if (kol > 0)
    {
        cout << "Отрицательные элементы ЕСТЬ, их кол-во: " << kol << endl;
    }
    else
    {
        cout << "Отрицательные элементы отсутствуют." << endl;
    }

    //перенесение отрицательных элементов в конец и замена 0
    int neminus = 0, otvet = 0;
    for (int i = 0; i <= n; i++)
    {
        if (*(k + i) >= 0)
        {
            *(k + neminus++) = *(k + i);
        }
    }
    while (neminus < n)
    {

        *(k + neminus++) = 0;
    }
    
    for (int i = 1; i < n; i++)
    {
        otvet = *(k + i);
        cout << *(k + i) << " ";
    }
    return otvet;

}
void lab5()
{
    int n = 0; double* a = 0;
    setlocale(LC_CTYPE, "Russian");
    int(*wf)(int n, int a ...);
    wf = w;
    cout << w(4, -2, 3, -4, 1) << endl;
   //cout << w(5, 2, -1, 3, -2, 5) << endl;
   // cout << w(3, -5, -2, 3) << endl;
}


   // Написать функцию mn с переменным числом параметров, которая находит минимальное из чисел типа int или из чисел типа double, тип параметров определяется с помощью первого параметра функции.
    double g(double n, ...)
    {
        double* p = &n;
        double min = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || min > * (p + i))
            {
                min = *(p + i);
            }
        }
        return min;
    }

    void lab6()
    {
        setlocale(LC_CTYPE, "Russian");
        double(*fg)(double n, ...);
        cout << "Написать функцию mn с переменным числом параметров, которая находит минимальное из чисел типа int или из чисел типа double, тип параметров определяется с помощью первого параметра функции" << endl;
        cout << "1: (4, 0, 6, 9, -2) = " << g(4, 0, 6, 9, -2) << "; 2: (6.0, -150.50, -3.3, 3.7, -10.45, 4.34, 1.3) = " << g(6.0, -150.50, -3.3, 3.7, -10.45, 4.34, 1.3) << "; 3: (7.0, -160.5, 161.27, 3.7, -9.45, 4.314, 12.3, 7.9) = " << g(7.0, -160.5, 161.27, 3.7, -9.45, 4.314, 12.3, 7.9) << endl;
    }

    //Написать функцию as с переменным числом параметров, которая находит сумму чисел типа int по формуле: S=a1*a2+a2*a3+a3*a4+. . . . .
    int q(int n, ...)
    {
        int* p = &n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += *(p + i) * *(p + i + 1);
        }
        return sum;
    }
    void lab7()
    {
        setlocale(LC_CTYPE,"Russian");
        int (*fq)(int n, ...);
        cout << "Написать функцию as с переменным числом параметров, которая находит сумму чисел типа int по формуле: S=a1*a2+a2*a3+a3*a4+. ." <<endl;
        fq = q;
        cout << "1: (4, 2, 4, 2, 4) = " << fq(4, 2, 4, 2, 4) << "; 2: (6, 2, 3, 4, 3, 2, 1) = " << fq(6, 2, 3, 4, 3, 2, 1) << "; 3: (3, 8, 9, 10) = " << fq(3, 8, 9, 10) << endl;
    }

    //Написать функцию kvadr с переменным числом параметров, которая определяет количество чисел, являющихся точными квадратами (2, 4, 9, 16,…) типа int.
    int P(int n, ...)
    {
        int* p = &n;
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (floor(sqrt(*(p + i))) == sqrt(*(p + i)))
            {
                count += 1;
            }
            else count += 0;
        }
        return count;
    }
    int lab8()
    {
        setlocale(LC_CTYPE, "Russian");
        srand(time(NULL));
        int(*fP)(int n, ...);
        cout << "Написать функцию kvadr с переменным числом параметров, которая определяет количество чисел, являющихся точными квадратами (2, 4, 9, 16,…) типа int: " << endl;
        fP = P;
        cout << "1: (4, 4, 28, 16, 18) = " << fP(4, 4, 28, 16, 18) << "; 2: (6, 12, 16, 26, 169, 256) = " << fP(6, 12, 16, 26, 169, 256) << "; 3: (6, 128, 9, 16, 48, 130, 1) = " << fP(6, 128, 9, 16, 48, 130, 1) << endl;
        return 0;
    }
    

   void main()
   {
    lab8();
   }
