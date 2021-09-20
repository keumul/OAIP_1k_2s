
// В приложении 2 приведен проект, в котором реализован проект с использованием двусвязного списка. На основе данного проекта
// разработать функции, которые предлагается создать в данном приложении.
// Дополнить проект, разработав функцию deleteList (удаление списка) и функцию countList (подсчет числа элементов списка). 
// В содержимом списка отразить информацию в соответствии со своим вариантом из лабораторной работы № 4. Создать интерфейс в виде меню.

// Государство.Наименование, столица, численность населения, площадь, фамилия президента.Выбор государства по названию.

//#include "stdafx.h"
#include "List.h"
#include <iostream>
using namespace std;
struct State
{
	char name[20]; //наименования
	char capital[20]; //столица
	int population; //численность населения
	int S; //площадь
	char president[123]; //фамилия президента
	State* next;
};
int n = 0;
void print(void* b) //Функция используется при выводе 
{
	State* a = (State*)b;
	cout << a->name << "  " << a->capital << " " << a->population << " " << a->S << " " << a->president << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice; int count = 0;
	State a1 = { "Лалалупсия", "Лала", 123 , 321,"Лалалупсинчик Ф.Ш." };
	State a2 = { "Шоколандия", "ВайтЧококо", 555 , 444,"Вилли Вонка" };
	State a3 = { "Бугагашенька", "Астрохандия", 253 , 987 ,"Бенджинберг" };
	bool rc;
	Object L1 = Create();
	L1.Insert(&a1);
	L1.Insert(&a2);
	L1.Insert(&a3);
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для вывода информации о государствах" << endl;
	cout << "2-для удаления одного из государств" << endl;
	cout << "3-для поиска гос-ва" << endl;
	cout << "4-для удаления всего списка" << endl;
	cout << "5-для подсчета числа элементов списка" << endl;
	cout << "0-для выхода" << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:  
		L1.PrintList(print); break;
		case 2: rc = L1.Delete(&a2);
			if (rc == true) cout << "Удален элемент, теперь список выглядит так:" << endl;
			else cout << "Видимо, пусто не густо.." << endl;
			L1.PrintList(print);
			break;
		case 4:
			rc = L1.Delete(&a1);
			rc = L1.Delete(&a2);
			rc = L1.Delete(&a3);
			if (rc == true) cout << "Удалены элементы." << endl;
			L1.PrintList(print);
			break;
		case 5:
			cout << "Число элементов списка: " << endl;
			cout << n;
			break;
		case 3: 
			Element * e = L1.Search(&a3);
			State* aa = (State*)e->Data;
			cout << "Найден элемент: " << aa->name << endl;
			break;
		
		//case 6: read();
		//	break;
		}
	} while (choice != 0);
	return 0;
}

bool Object::Insert(void* data) // Вставка в начало
{
	bool rc = 0;
	if (Head == NULL)
	{
		Head = new Element(NULL, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, data, Head));
		rc = true;
	}
	return rc;
}
//-----------------------------------------------------------
Element* Object::Search(void* data) // Найти заданный элемент
{
	Element* rc = Head;
	while ((rc != NULL) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*)) // Вывод
{
	int count = 0;
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Data);
		e = e->GetNext();
		count++;
	};
	n = count;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*), Element* e)
{
	f(e->Data);
}
//-----------------------------------------------------------
bool  Object::Delete(Element* e) // Удалить по ссылке
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}
//-----------------------------------------------------------
bool Object::Delete(void* data) // Удалить по значению
{
	return Delete(Search(data));
};
//-----------------------------------------------------------
Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}
//-----------------------------------------------------------
Object Create()
{
	return *(new Object());
}

//bool DeleteList() {
//	L1.PrintList();
//}