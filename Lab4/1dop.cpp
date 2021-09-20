//	Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля : ФИО студента, число экзаменов, полученные оценки.
//	Определить функции для обработки отдельного объекта(например, для проверки, сданы ли все экзамены на 4 и 5). Написать функцию для обработки массива структур.
//	В результате обработки требуется вычислить характеристику успеваемости студентов, то есть отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу
//	студентов, в процентах.

#include <iostream>
#include <string>
#include <clocale>

using namespace std;
int badRes = 0, goodRes = 0;
int goodmarks = 0, badmarks = 0;

struct STUD
{
	string NAME;
	int GROUP;
	int SES[5];
};

void put(STUD *st,int N)
{
	for (int i(0); i < N; ++i)
	{
		cout << "Введите фамилию студента: ";
		cin >> st[i].NAME;
		cout << "Введите оценки:";
		for (int j(0); j < 5; ++j)
		{
			cout << j + 1 << ":"; 
			cin >> st[i].SES[j];
		}
	}
}

void progress(STUD * st, int N)
{
	string da, net;
	
	for (int i = 0; i < N; i++) //i - текущий студент, N - кол-во учеников
	{
		for (int j = 0; j < 5; j++) //j - текущий предмет, 5 - всего предметов
		{
			if ((st[i].SES[j] == 4) || (st[i].SES[j] == 5))
			{
				goodRes++;
			}
			else
			{
				badRes++;
			}
		}
		if (goodRes == 5)
		{
			da = st[i].NAME;
		}
		else
			if (goodRes < 5)
			{
				net = st[i].NAME;
			}
		if (goodRes == 5)
		{
			cout << da << " сдал все экзамены на 4 и 5!" << endl;
			goodmarks++;
		}
		else if (goodRes < 5)
		{
			cout << net << " провалил некоторые экзамены :(" << endl;
			badmarks++;
		}
		goodRes = 0;
	}
}

void result(STUD *st,int N)
{
	cout << "Студент\t\tОценки\n";
	for (int i(0); i < N; ++i)
	{
		cout << st[i].NAME << "\t\t";
		for (int j(0); j < 5; ++j)
		{
			cout << st[i].SES[j];
			if (j != 4)cout << ",";
		}
		cout << endl;
	}
	cout << "Отношение числа студентов, сдавших все экзамены на 4 и 5 к общему числу студентов, в процентах: " << (goodmarks * (100 / (goodmarks+badmarks))) << endl;
}
                                                                                                                                                                   
int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE,"rus");
	int N;
	cout<<"Введите число студентов:";
	cin>>N;

	STUD *st=new STUD[N];
	put(st,N);
	progress(st,N);
	result(st, N);

	return 0;
}