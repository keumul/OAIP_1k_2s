// Скопировать в файл FILE2 только те строки из FILE1,  которые начинаются с буквы «А». Подсчитать количество слов в FILE2.

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    ifstream in("f1.txt");
    ofstream out("f2.txt");

    if (!in.is_open())
    {
        cout << "Error";
        exit(EXIT_FAILURE);
    }
    string str;

    while (in >> str)
    {
        if (str[0] == 'A')
            out << str <<endl;
    }

    in.close();
    out.close();

    in.open("f2.txt");

    int count = 0;
    while (in >> str)
        count++;

    cout << "Количество слов в FILE2: " << count << endl;

    in.close();

    cin.get();
    return 0;
}