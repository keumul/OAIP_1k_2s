//Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию.
//Скопировать в файл F2 только те строки из F1, которые заканчиваются символом «а».

//#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    FILE* A;
    FILE* B;
    char str[255];
    errno_t err;

    err = fopen_s(&A, "A.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        printf("Строка  %d : \n", i + 1);
        gets_s(str);
        fputs(str, A);
        fputs("\n", A);
    }
    fclose(A);
    fclose(A);
    err = fopen_s(&A, "A.txt", "r");
    err = fopen_s(&B, "B.txt", "w");

    while (fgets(str, 255, A) != NULL)
    {
        if (str[strlen(str) - 2] == 'a')
        {
            fputs(str, B);
        }
    }
    fclose(A);
    fclose(B);
}