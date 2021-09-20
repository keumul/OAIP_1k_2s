//Даны три файла целых чисел одинакового размера с именами NameA, NameB и NameC.Создать новый файл с именем NameD, в который записать 
//минимальные элементы исходных файлов с одним и тем же номером : min(A0, B0, C0), min(A1, B1, C1), min(A2, B2, C2), ...

#include <iostream>
#include <stdio.h>

using namespace std;

void main()
{
    FILE* pA, * pB, * pC, * pD;

    fopen_s(&pA, "A.txt", "r");
    fopen_s(&pB, "B.txt", "r");
    fopen_s(&pC, "C.txt", "r");
    
    fopen_s(&pD, "D.txt", "w");
    
    int a, b, c, d;

    fseek(pA, 0, SEEK_SET);
    fseek(pB, 0, SEEK_SET);
    fseek(pC, 0, SEEK_SET);
    fseek(pD, 0, SEEK_SET);
   
    for (int i = 0; i <= 7; i++)
    {
        fscanf_s(pA, "%d", &a);
        fscanf_s(pB, "%d", &b);
        fscanf_s(pC, "%d", &c);
        fscanf_s(pD, "%d", &d);

        if (a < b && a < c) 
        { 
            fprintf(pD, "%d ", a); 
        }
        if (b < c && b < a)
        {
            fprintf(pD, "%d ", b);
        }
        if (c < b && c < a) 
        { 
            fprintf(pD, "%d ", c); 
        }
        if (a < b && a == c)
        {
            fprintf(pD, "%d ", a);
        }
        if (a < c && a == b)
        {
            fprintf(pD, "%d ", a);
        }
        if (b < a && b == c)
        {
            fprintf(pD, "%d ", b);
        }

        fseek(pA, 1, 1);
        fseek(pB, 1, 1);
        fseek(pC, 1, 1);
        fseek(pD, 1, 1);
    }

    fclose(pA);
    fclose(pB);
    fclose(pC);
    fclose(pD);
    return;
}
