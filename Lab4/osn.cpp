// Государство. Наименование, столица, численность населения, площадь, фамилия президента. Выбор государства по названию.

// Определить структурированный тип, разработать меню для работы с массивом структур.
// В программу должны войти функции:
//  -ввод элементов структуры с клавиатуры; +
//  -вывод элементов структуры в консольное окно; +
//  -удаление заданной структурированной переменной; +
//  -поиск информации; +
//  -запись информации в файл; 
//  -чтение данных из файла.

#include <windows.h>
#include <iostream>  
#include <string>
#include <cstring>
#include <fstream>

# define str_len 30                               
# define size 30  

using namespace std;

void enter_new();
void del();
void out();
void search();
void write(); 
void read();

struct State
{
	char name[str_len]; //наименования
	char capital[20]; //столица
	int population; //численность населения
	int S; //площадь
    char president[123]; //фамилия президента
};
struct State list_of_state[size];
struct State bad;
int current_size = 0; int choice;
char str[500];

int number; FILE* fAin, *fAout; errno_t err;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи(ей)" << endl;
	cout << "3-для удаления записи" << endl;
	cout << "4-для поиска информации о гос-ве" << endl;
	cout << "5-запись информации в файл" << endl;
	cout << "6-чтение данных из файла" << endl;
	cout << "0-для выхода" << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:  enter_new();  break;
		case 2:  out();	break;
		case 3:  del();	break;
		case 4: search(); break;
		case 5: write(); break;
	    case 6: read(); break;
		}
	} while (choice != 0);
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Наименование гос-ва:  " << endl;
		cin >> list_of_state[current_size].name;
		cout << "Столица: " << endl;
		cin >> list_of_state[current_size].capital;
		cout << "Численность населения:  " << endl;
		cin >> list_of_state[current_size].population;
		cout << "Площадь: " << endl;
		cin >> list_of_state[current_size].S;
		cout << "Фамилия президента:  " << endl;
		cin >> list_of_state[current_size].president;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_state[de1] = list_of_state[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list_of_state[i] = bad;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << "Наименование гос-ва: ";
		cout << list_of_state[n - 1].name << endl;
		cout << "Столица: ";
		cout << list_of_state[n - 1].capital << endl;
		cout << "Численность населения: ";
		cout << list_of_state[n - 1].population << endl;
		cout << "Площадь: ";
		cout << list_of_state[n - 1].S << endl;
		cout << "Численность населения: ";
		cout << list_of_state[n - 1].president << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Наименование гос-ва: ";
			cout << list_of_state[i].name << endl;
			cout << "Столица: ";
			cout << list_of_state[i].capital << endl;
			cout << "Численность населения: ";
			cout << list_of_state[i].population << endl;
			cout << "Площадь: ";
			cout << list_of_state[i].S << endl;
			cout << "Численность населения: ";
			cout << list_of_state[i].president << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}


void search()
{
	string name, num;
	cout << "Введите название гос-ва, чтобы узнать о нем всю информацию: ";
	cin >> name;
	
		for (int i = 0; i < current_size; i++)
		{
			if (list_of_state[i].name == name)
			{
				cout << "Наименование гос-ва: ";
				cout << list_of_state[i].name << endl;
				cout << "Столица: ";
				cout << list_of_state[i].capital << endl;
				cout << "Численность населения: ";
				cout << list_of_state[i].population << endl;
				cout << "Площадь: ";
				cout << list_of_state[i].S << endl;
				cout << "Фамилия президента: ";
				cout << list_of_state[i].president << endl;

			}
		}
	
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void write()
{
	ofstream fAout("A.txt");
	if (fAout.is_open())
	{
		int sw, n;
		cout << "1-вывод 1 строки" << endl;
		cout << "2-вывод всех строк" << endl;
		cin >> sw;
		if (sw == 1)
		{
			cout << "Номер выводимой строки " << endl;  cin >> n;  cout << endl;
			fAout << "Наименование гос-ва: ";
			fAout << list_of_state[n - 1].name << endl;
			fAout << "Столица: ";
			fAout << list_of_state[n - 1].capital << endl;
			fAout << "Численность населения: ";
			fAout << list_of_state[n - 1].population << endl;
			fAout << "Площадь: ";
			fAout << list_of_state[n - 1].S << endl;
			fAout << "Фамилия президента: ";
			fAout << list_of_state[n - 1].president << endl;
		}
		if (sw == 2)
		{
			for (int i = 0; i < current_size; i++)
			{
				fAout << "Наименование гос-ва: ";
				fAout << list_of_state[i].name << endl;
				fAout << "Столица: ";
				fAout << list_of_state[i].capital << endl;
				fAout << "Численность населения: ";
				fAout << list_of_state[i].population << endl;
				fAout << "Площадь: ";
				fAout << list_of_state[i].S << endl;
				fAout << "Фамилия президента: ";
				fAout << list_of_state[i].president << endl;
			}
		}
		cout << "Что дальше?" << endl;
		cin >> choice;

		fAout << endl;

	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}
void read()
{
	

	ifstream fAin("A.txt");
	if (fAin.is_open())
	{
		while (true)
		{
			fAin.getline(str, sizeof(str));
			if (fAin.eof() != 0) break;
			cout << str << endl;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();
}