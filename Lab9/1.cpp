// Дополнить программу функцией в соответствии со своим вариантом из таблицы, представленной ниже. 
// deleteX(int x) – функция удаления первого встречающегося элемента с заданным значением x.

#include<iostream>
#include<fstream>
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct KATE
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	int age;
	KATE* next;
	KATE* prev;
};
int menu(void)
{
	setlocale(LC_CTYPE, "Russian");
	char s[80]; int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление первого встречающегося элемента с заданным значением x" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Выход" << endl;
	cout << endl;
	do {
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c>5);
	return c;
}

void insert(KATE* e, KATE** phead, KATE** plast)
{
	KATE* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	} else 
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

KATE* setElement()
{
	KATE* temp = new KATE();
	if (!temp)
	{
		cerr << "Ошибочка вышла :|";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "";
	cout << "Введите возраст: ";
	cin >> temp->age; cout << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(KATE** phead, KATE** plast)      //Вывод списка на экран
{
	KATE* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << ' ' << t->age << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], KATE** phead)    // Поиск имени в списке
{
	KATE* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << ' ' << t->age << endl;
}
//-----------------------------------------------------------
void delet(int age, KATE** phead, KATE** plast)  // Удаление имени 
{
	struct KATE* t = *phead;
	while (t)
	{
		if (age == t->age)  break;
		t = t->next;
	}
	if (!t)
		cerr << "Возраст не найден" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}


//-----------------------------------------------------------
int main(void)
{
	KATE* head = NULL;
	KATE* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  
			int delx;
			cout << "Введите возраст(х): ";
			cin >> delx; cout << endl;
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(delx, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			  break;
		case 5:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}