//Ввести с клавиатуры строку символов, состоящую из букв, цифр, запятых, точек, знаков + и - , и записать ее в файл.Прочитать из 
//файла данные и посчитать и вывести количество запятых.

#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;
int a = 0;
void fromFile(ofstream& f, char* str) //Функция записи в файл
{

	f.open("f1.txt");

	if (f.fail())
	{
		cout << "\n Ошибка открытия файла1";
		exit(1);
	}

	f << str; //запись
	f.close();
}

void inFile(ifstream& f, char* pstr) //Функция чтения из файла
{
	char str[255];

	f.open("f1.txt");
	if (f.fail()) //проверка открытия файла
	{
		cout<< "\n Ошибка открытия файла2";
		exit(1);
	}

	f>> str; //чтение
	sizeof(f); //перемещаемся к 0-му байту относительно начала файла

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ',')
		{
			pstr[a] = str[i];
			a++;
		}
	}
	f.close();
	pstr[a] = '\0';

}
int main()
{
	setlocale(LC_CTYPE, "Russian");

	ifstream ifile;
	ofstream ofile;

	char str[255], pstr[255];

	cout<< "Str:"<< endl;
	cin>> str;


	fromFile(ofile, str);
	//ofile.close();

	//ifile.open("f1.txt");

	inFile(ifile, pstr);
	ifile.close();

	cout<< a;
}
