// Ввести с клавиатуры строку символов, состоящую из цифр и скобок, и записать ее в файл. 
// Прочитать из файла данные, посчитать и вывести количество скобок различного вида.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
char s[256];
int nm;
ofstream f2("F2.txt");

void writef(ofstream& f, char str[256])
{
	f.open("F1.txt");
	if (f.fail())  //проверка открытия файла
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f << str;
	f.close();
}
void readf(ifstream& ff)
{
	ff.open("F1.txt");
	if (!ff.is_open())
	{
		cout << "Ошибка открытия F1.txt" << endl;
	}
	ff.getline(s, 256);
}
void number(char str[256])
{
	char pstr[256];
	int i = 0, j = 0;
	int how = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ')' || str[i] == '(' || str[i]=='[' || str[i] == ']' || str[i] == '{' || str[i] == '}')
		{
			how++;
		}
		i++;
	}
	cout <<"Количество скобок различного вида: " <<how;
	f2 << how;
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	ofstream f;

	char str[256];
	cin.getline(str, 256);

	writef(f, str);
	ifstream ff;
	readf(ff);
	nm = sizeof(s);
	number(str);

}
