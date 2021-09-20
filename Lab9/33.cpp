// Каждый элемент списка студентов содержит фамилию, имя, отчество, год рождения, курс, номер группы, оценки по пяти предметам. Упорядочить студентов по
// курсу, причем студенты одного курса должны располагаться в алфавитном порядке. Найти средний балл каждой группы по каждому предмету. Определить самого
// старшего студента и самого младшего студентов. Для каждой группы найти лучшего с точки зрения успеваемости студента.


#include <iostream>
#include <fstream>

using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct STUDENT
{
	int mark;
	char name[NAME_SIZE];
	char surname[NAME_SIZE];
	char otchestvo[NAME_SIZE];
	int byear; int kurs; int groupnumber;
	int math; int lit; int physic; int biology; int chemistry;
	STUDENT* next;
	STUDENT* prev;
};

int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод информации о студенте" << endl;
	cout << "2. Средний балл каждой группы по каждому предмету" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Самый старший студент :)" << endl;
	cout << "5. Самый младший студент :)" << endl;
	cout << "6. Лучший по успеваемости студент" << endl;
	cout << "7. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 7);
	return c;
}

void insert(STUDENT* e, STUDENT** phead, STUDENT** plast) //Добавление в конец списка
{
	STUDENT* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
		//return;
	}
}

STUDENT* setElement()// Создание элемента и ввод его значений с клавиатуры 
{
	STUDENT* temp = new  STUDENT();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}

	int sum_sub = 0;

	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();

	cout << "Введите фамилию: ";
	cin.getline(temp->surname, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();

	cout << "Введите отчество: ";
	cin.getline(temp->otchestvo, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();

	cout << "Введите год рождения: ";
	cin >> temp->byear;
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();

	cout << "Введите курс: ";
	cin >> temp->kurs;
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();

	cout << "Введите номер группы: ";
	cin >> temp->groupnumber;
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();

	cout << "Оценки: " << endl;
	cout << "-математика: "; cin >> temp->math;
	sum_sub += temp->math;
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();
	cout << "-литература: "; cin >> temp->lit;
	sum_sub += temp->lit;
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();
	cout << "-физика: "; cin >> temp->physic;
	sum_sub += temp->physic;
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();
	cout << "-биология: "; cin >> temp->biology;
	sum_sub += temp->biology;
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();
	cout << "-химия: "; cin >> temp->chemistry;
	sum_sub += temp->chemistry;
	cin.ignore(cin.rdbuf()->in_avail()); cin.clear();

	temp->mark = sum_sub/5;

	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(STUDENT** phead, STUDENT** plast) //Вывод списка на экран
{
	STUDENT* t = *phead;
	if (t == NULL)
	{
		cout << "Пусто - не густо.." << endl;
	}
	else {
		for (int i = 1; i <= 5; i++)
		{
			while (t) {

				if ((t->kurs) == i)
				{
					//for (int j = 'a'; j < 'z'; j++) {
						cout << t->name << ' ';
					//	break;
				//	}
					cout<< t->surname << ' ' << t->otchestvo << ' ' << t->byear << ' ' << t->kurs << " курс" << ' ' << t->groupnumber << " группа" << endl;
					cout << "Оценки:" << endl;
					cout << "-математика: " << t->math << endl;
					cout << "-литература: " << t->lit << endl;
					cout << "-физика: " << t->physic << endl;
					cout << "-биология: " << t->biology << endl;
					cout << "-химия: " << t->chemistry << endl;
				}
				t = t->next;
			}
			if (t == NULL) { t = *phead; }
		}
	}
	cout << "" << endl;
}

void find( STUDENT** phead)
{
	STUDENT* t = *phead;
	int maxst = 2020, count = 0, count1 = 0;

	if (t == NULL)
	{
		cout << "Пусто - не густо.." << endl;
	}
	else {
		
		while (t)
		{
			if ((t->byear) <= maxst)
			{
				maxst = t->byear;
			}
			t = t->next;

			if (t == NULL) { t = *phead; }
			if (t->byear == maxst)
			{
				cout << "Студент " << t->name << " является самым старшим студентом" << endl;
				break;
			}
		}
	}
	cout << "" << endl;
}
void find1(STUDENT** phead)
{
	STUDENT* t = *phead;
	int minst = 0, count = 0, count1 = 0;
	if (t == NULL)
	{
		cout << "Пусто - не густо.." << endl;
	}
	else {
		while (t) {
			if ((t->byear) > minst)
			{
				minst = (t->byear);
			}
			t = t->next;

			if (t == NULL) { t = *phead; }
			if (t->byear == minst)
			{
				cout << "Студент " << t->name << " является самым младшим студентом" << endl;
				break;
			}
		}
	}
	cout << "" << endl;
}
void srball( STUDENT** phead, STUDENT** plast)
{
	struct STUDENT* t = *phead;

	int predsrb=0, srb = 0, predmath=0, predlit = 0, predphys = 0, predbio = 0, predchem = 0;
	if (t == NULL)
	{
		cout << "Пусто - не густо.." << endl;
	}
	else {
		for (int i = 1; i <= 10; i++)
		{
			while (t) {

				if ((t->groupnumber) == i)
				{
					predmath += (t->math);
					predlit += (t->lit);
					predphys += (t->physic);
					predbio += (t->biology);
					predchem += (t->chemistry);
					predsrb++;
				}
				t = t->next;
			}
			if (t == NULL) { t = *phead; }
			if (predsrb > 0)
			{
				cout << i << " группа: " << endl;
				cout << "Средний балл студентов " << t->groupnumber << endl;
				cout << "-по математике: " << predmath / predsrb << endl;
				cout << "-по литературе: " << predlit / predsrb << endl;
				cout << "-по физике: " << predphys / predsrb << endl;
				cout << "-по биологии: " << predbio / predsrb << endl;
				cout << "-по химии: " << predchem / predsrb << endl;
				predmath = 0, predlit = 0, predphys = 0, predbio = 0, predchem = 0, predsrb = 0;
			}
		}
	}
	cout << "" << endl;
}
void best(STUDENT** phead, STUDENT** plast)
{
	struct STUDENT* t = *phead;
	//item* host = p;
	int max_mark = t->mark;
	STUDENT* better = t;
	if (t == NULL)
	{
		cout << "Пусто - не густо.." << endl;
	}
	else {
		for (int i = 0; i < 10; i++)
		{
			if (t == NULL) { t = *phead; }
			if (max_mark < t->mark)
			{
				max_mark = t->mark;
				better = t;
			}
			
			t = t->next;
		}
		cout << "Cамая хорошая успеваемость у студента :" << better->name << " " << better->surname << " " << better->otchestvo << endl;
	}
}

int main(void)
{
	STUDENT* head = NULL;
	STUDENT* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2:
			srball(&head, &last);
			break;
		case 3:  
			outputList(&head, &last);
			break;
		case 4:
			find( &head);
			break;
		case 5:
			find1(&head);
			break;
		case 6:
			best(&head, &last);
			break;
		case 7:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}

