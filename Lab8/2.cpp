
//-----------------------------4ЧАСТИ------------------------------------//

#include<iostream>
using namespace std;

struct Symb
{
	int data;
	Symb* next, *prev;
};
Symb* head,* tail, *end;
bool Nulll(void)
{
	return (head == NULL);
}
int z = 0;

//--------------- СНЯТИЕ С МЛАДШИХ АДРЕСОВ ---------------------

//void del()
//{
//	if (Nulll())
//	{cout << "Пусто - не густо.." << endl;}
//	else {
//		Symb* p = head;
//		head = head->next;
//		delete p;
//	}
//}

//--------------- СНЯТИЕ СО СТАРШИХ АДРЕСОВ ---------------------

void del()
{
	Symb* temp, *t;
	if (Nulll())
	{cout << "Пусто - не густо.." << endl;}
	else
	{
		for (temp = head; temp->next->next; temp = temp->next);
		{ temp->next = NULL; }
	}
}


void fromHead()
{
	if (Nulll())
	{cout << "Пусто - не густо.." << endl;}
	else {
		cout << "Начало: " << head->data << endl; 
	}
}

void addToQueue(int x)
{
	Symb* p = new Symb;
	p->data = x;
	p->next = NULL;

	Symb* v = new Symb;
	Symb* p1 = new Symb;
	Symb* p2 = new Symb;

	int i = 0;

	if (Nulll())
	{
		head = tail = p;
	}
	else {
		p2 = head; p1 = head;
		while (p1 != NULL)
		{
			if (i == 1)
			{
				if (x <= p1->data)
				{
					v->data = x;
					v->next = p1;
					p2->next = v;
					return;
				}
				p2 = p2->next;
			}
			else {

//------------------------------Приоритет: МАКСИМАЛЬНОЕ значение числового параметра--------------------------------------
				if (x >= p1->data) 

//------------------------------Приоритет: МИНИМАЛЬНОЕ значение числового параметра---------------------------------------
				//if(x<=p1->data)
				
				{
					v->data = x;
					v->next = p1;
					head = v;
					return;
				}
			}
			p1 = p1->next;
			i = 1;
		}
		if (p1 == NULL)
		{
			tail->next = p;
			tail = p;
		}
	}
}

void print()
{
	Symb* p = new Symb;
	if(Nulll())
	{cout << "Пусто - не густо.. " << endl;}
	else {
		cout << "Очередь: ";
		p = head;
		while (!Nulll())
		{
			if (p != NULL)
			{
				cout << p->data << " ";
				cout << "->";
				p = p->next;
			}
			else {
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

void clear()
{
	while (!Nulll()) {del();}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 1, choice = 1; 
	head = NULL;
	tail = NULL;
	while (choice != 0)
	{
		cout << "1 - добавить элемент" << endl;
		cout << "2 - получить элемент" << endl;
		cout << "3 - извлечь элемент" << endl;
		cout << "4 - вывести элементы" << endl;
		cout << "5 - очистить очередь" << endl;
		cout << "0 - выход" << endl;
		cout << "Выберите действие  ";  cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент:  "; cin >> z;
			addToQueue(z); print();  break;
		case 2: fromHead(); break;
		case 3: del();
			break;
		case 4: print();  break;
		case 5: clear();    break;
		}
	}
	return 0;
}

