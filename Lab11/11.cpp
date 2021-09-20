﻿// Разработать программу работы с бинарным деревом, в которую включить основные функции манипуляции данными и функцию в соответствии со своим вариантом 
// из таблицы, представленной ниже.
// Дан указатель p1 на корень непустого дерева. Написать функцию определения количества узлов с четными ключами.

//9: Дан указатель p1 на корень непустого дерева и число k. Написать функцию вывода количества вершин дерева, значение которых равно k.


#include <iostream>
using namespace std;
struct Tree  //дерево
{
	int key; //ключ
	char text[5]; //текст - не более 4 букв
	Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i, char* s);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key, char* s);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
int count(Tree* t, char letter);  //Подсчет количества слов
void delAll(Tree* t);             //Очистка дерева
Tree* vershinyk(Tree* t, int key);
int c = 0, k = 0, srarifm=0, sr=0, lev=0;
Tree* kol = 0;
Tree* Root = NULL; 	//указатель корня

void main()
{
	setlocale(0, "Russian");
	int key = 0, choice, n;
	Tree* rc; char s[5], letter;
	Tree* ver, * kol = 0;
	for (;;)
	{
		cout << "1 - создание дерева\n";
		cout << "2 - добавление элемента\n";
		cout << "3 - поиск по ключу\n";
		cout << "4 - удаление элемента\n";
		cout << "5 - вывод дерева\n";
		cout << "6 - подсчет количества букв\n";
		cout << "7 - 12В: определение количества узлов с четными ключами\n";
		cout << "8 - 14В: среднеe арифметическоe всех элементов дерева (в нашем случае ключей)\n"; 
		cout << "9 - 5В: вывод количества вершин дерева, являющихся левыми дочерними вершинами (корень дерева не учитывать)\n";
		cout << "10 - 16В: функция вывода суммы значений всех листьев данного дерева\n";
		cout << "11 - очистка дерева\n";
		cout << "12 - выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			cout << "Введите слово: "; cin >> s;
			insertElem(Root, key, s); break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
			rc = search(Root, key);
			cout << "Найденное слово= ";
			puts(rc->text); break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 6:  cout << "\nВведите букву: "; cin >> letter;
			n = count(Root, letter);
			cout << "Количество слов, начинающихся с буквы " << letter;
			cout << " равно " << n << endl; break;
		case 7:  
			cout << "Количество узлов с четными ключами равно " << c << endl; break;
		case 8:
			cout << "Среднее арифметическоe всех элементов дерева (в нашем случае ключей): " << (srarifm+1)/(sr-1) << endl;
			break;
		case 9:
			cout << "Kоличествo вершин дерева, являющихся левыми дочерними вершинами (корень дерева не учитывать): " << (lev-1) << endl;
			break;
		case 10:
			cout << "Сумма значений всех листьев данного дерева: " << srarifm << endl; break;
		
		case 11:  delAll(Root); break;
		case 12:  exit(0);
		}
	}
}

Tree* makeTree(Tree* Root)    //Создание дерева
{
	int key; char s[5];
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;
		srarifm += key; 
		sr++;
		if (key % 2 == 0) { c++; }
		cout << "Введите слово корня: "; cin >> s;
		Root = list(key, s);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "\nВведите ключ: "; cin >> key;
		srarifm += key; 
		sr++; lev++;
		if (key % 2 == 0) { c++; }
		if (key < 0) break; //признак выхода (ключ < 0)   
		cout << "Введите слово: ";  cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}

Tree* list(int i, char* s)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < 5; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, char* s)  //Добавление нового элемента
{
	Tree* Prev = new Tree[sizeof(Tree)]; // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key, s);           //создается новый узел 
		if (key < Prev->key)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}

int count(Tree* t, char letter) //Подсчет количества слов
{
	if (t)
	{
		count(t->Right, letter);
		if (*(t->text) == letter)
			c++;
		count(t->Left, letter);
	}
	return c;
}

void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
		cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1);	//вывод левого поддерева
	}
}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

//
//#include <iostream>
//#include<conio.h>  
//using namespace std;
//struct Node
//{
//	int data;             //Информационное поле
//	Node* left, * right;   //Указатели на левую и правую ветви дерева
//};
//Node* tree = nullptr;
//
//void insert(int a, Node** t)  //Добавление элемента a 
//{
//	if ((*t) == NULL)              //если дерева нет, то создается элемент
//	{
//		(*t) = new Node;
//		(*t)->data = a;
//		(*t)->left = (*t)->right = NULL;
//		return;
//	}
//	if (a > (*t)->data)  //дерево есть, если а больше текущего
//		insert(a, &(*t)->right);  //то элемент помещается вправо
//	else
//		insert(a, &(*t)->left);   //иначе - влево
//}
//
//void print(Node* t, int u)    //Вывод на экран
//{
//	if (t == NULL)  return;
//	else
//	{
//		print(t->left, ++u);     //левое поддерево
//		for (int i = 0; i < u; ++i)
//			cout << "|";
//		cout << t->data << endl;
//		u--;
//	}
//	print(t->right, ++u);          // правое поддерево
//}
//
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int count, temp;
//	cout << "Введите количество элементов  "; 
//	cin >> count;
//	for (int i = 0; i < count; ++i)
//	{
//		cout << "Введите число  ";	
//		cin >> temp;
//		insert(temp, &tree);
//	}
//	cout << "ваше дерево\n";
//	print(tree, 0);
//	_getch();
//}
//
