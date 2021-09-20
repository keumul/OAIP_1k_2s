//Скопировать из файла FILE1 в файл FILE2 все строки, которые содержат цифры. Подсчитать
//количество строк, которые начинаются на букву «А» в файле FILE2.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "Russian");
    char num[] = "0123456789";
    int n = 100;
    char** str = new char* [n];

    for (int i = 0; i < n; i++)
    {
        str[i] = new char[300];
    }

    ifstream ifs("f1.txt");
    if (!ifs.is_open()) 
    {
        cout << "Файл не может быть открыт!\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            ifs.getline(str[i], 300);
        }
    }

    ofstream f("f2.txt");
    cout << "Cтроки,которые содержат цифры:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (strlen(str[i]) >= 1) 
        {
            for (int q = 0; q < 300; q++) 
            {
                for (int z = 0; z < 10; z++) 
                {
                    if (str[i][q] == num[z])
                    {
                        cout << str[i] << endl;
                        f << str[i] << endl;
                        i++;
                    }
                }
            }
        }
    }
    int kolvo_strok = 0;
    cout << "Кол-во строк, начинающихся на А, в файле f2:" << endl;
    if (*str[0] == 'A' || *str[0] == 'a') 
    {
        kolvo_strok++;
    }
    cout << kolvo_strok << endl;
    f << kolvo_strok << endl;

    //system("pause");
}
