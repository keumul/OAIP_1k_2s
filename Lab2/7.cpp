// Компоненты файла fileA –  целые числа, значения которых повторяются. Получить файл fileB, образованный из fileA числами,
// которые встречаются в A ровно 2 раза.

#include <iostream>
#include <stdio.h>  
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    FILE* A, *B;
    
    int random, pr=1, read=1, num;

    errno_t err, err1;
    err = fopen_s(&A, "A.txt", "r");
    if (err != 0)
    {
        perror("Ошибка открытия a.txt");
        return 0;
    }
   
    for (int i = 1; i < 10; i++)
    {
        random = 1 + rand() % 3;
        for (int j = 0; j < random; j++)
        {
            char arr[2] = { char(i + '0'), '\0' };
            fputs(arr, A);
            fputs("\n", A);
        }
    }
    fclose(A);
    fopen_s(&A, "A.txt", "r");

    err1 = fopen_s(&B, "B.txt", "w");
    if (err1 != 0)
    {
        perror("Ошибка открытия a.txt");
        return 0;
    }


    int mass[9] = { 0,0,0,0,0,0,0,0,0};
    
   
    int k = 1;
    while (read == 1) {
        read = fscanf_s(A, "%d", &num);
        if (read != 1) {
            continue;
        }
        if (num != pr) {
            k++;
        }
        if (num == k) {
            mass[num - 1]++;
        }
        pr = num;
    }
    fclose(A);

    for (int j = 0; j < 9; j++) {
        if (mass[j] == 2)
        {
            char arr[2] = { char((j + 1) + '0'), '\0' };
            fputs(arr, B);
            fputs("\n", B);
        }
    }
    fclose(B);
}
