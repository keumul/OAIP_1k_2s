
// � ���������� 2 �������� ������, � ������� ���������� ������ � �������������� ����������� ������. �� ������ ������� �������
// ����������� �������, ������� ������������ ������� � ������ ����������.
// ��������� ������, ���������� ������� deleteList (�������� ������) � ������� countList (������� ����� ��������� ������). 
// � ���������� ������ �������� ���������� � ������������ �� ����� ��������� �� ������������ ������ � 4. ������� ��������� � ���� ����.

// �����������.������������, �������, ����������� ���������, �������, ������� ����������.����� ����������� �� ��������.

//#include "stdafx.h"
#include "List.h"
#include <iostream>
using namespace std;
struct State
{
	char name[20]; //������������
	char capital[20]; //�������
	int population; //����������� ���������
	int S; //�������
	char president[123]; //������� ����������
	State* next;
};
int n = 0;
void print(void* b) //������� ������������ ��� ������ 
{
	State* a = (State*)b;
	cout << a->name << "  " << a->capital << " " << a->population << " " << a->S << " " << a->president << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice; int count = 0;
	State a1 = { "����������", "����", 123 , 321,"������������� �.�." };
	State a2 = { "����������", "����������", 555 , 444,"����� �����" };
	State a3 = { "������������", "�����������", 253 , 987 ,"�����������" };
	bool rc;
	Object L1 = Create();
	L1.Insert(&a1);
	L1.Insert(&a2);
	L1.Insert(&a3);
	setlocale(LC_CTYPE, "Russian");
	cout << "�������:" << endl;
	cout << "1-��� ������ ���������� � ������������" << endl;
	cout << "2-��� �������� ������ �� ����������" << endl;
	cout << "3-��� ������ ���-��" << endl;
	cout << "4-��� �������� ����� ������" << endl;
	cout << "5-��� �������� ����� ��������� ������" << endl;
	cout << "0-��� ������" << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:  
		L1.PrintList(print); break;
		case 2: rc = L1.Delete(&a2);
			if (rc == true) cout << "������ �������, ������ ������ �������� ���:" << endl;
			else cout << "������, ����� �� �����.." << endl;
			L1.PrintList(print);
			break;
		case 4:
			rc = L1.Delete(&a1);
			rc = L1.Delete(&a2);
			rc = L1.Delete(&a3);
			if (rc == true) cout << "������� ��������." << endl;
			L1.PrintList(print);
			break;
		case 5:
			cout << "����� ��������� ������: " << endl;
			cout << n;
			break;
		case 3: 
			Element * e = L1.Search(&a3);
			State* aa = (State*)e->Data;
			cout << "������ �������: " << aa->name << endl;
			break;
		
		//case 6: read();
		//	break;
		}
	} while (choice != 0);
	return 0;
}

bool Object::Insert(void* data) // ������� � ������
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
Element* Object::Search(void* data) // ����� �������� �������
{
	Element* rc = Head;
	while ((rc != NULL) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*)) // �����
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
bool  Object::Delete(Element* e) // ������� �� ������
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
bool Object::Delete(void* data) // ������� �� ��������
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