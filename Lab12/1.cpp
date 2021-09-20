
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

//// Добавить к проекту  функции смешанного и нисходящего обхода дерева с выводом  на консоль, проверки сбалансированности дерева и функцию в соответствии с вариантом из
//// таблицы, представленной в лабораторной работе № 11,
//// изменив ее так, чтобы функция соответствовала проекту данной лабораторной работы.
//
//struct Tree
//{
//	int key;
//	string str;
//	struct Tree* left;
//	struct Tree* right;
//};
//Tree* root = NULL;
//
//Tree* CreateTree(Tree* root);
//Tree* CreateEl(int k, string str);
//Tree* AddEl(Tree* root);
//Tree* DeleteEl(Tree* root, int key);
//void PrintTree(Tree* root, int depth);
//void PrintTree2(Tree* root, int depth);
//void DeleteTree(Tree* root);
//int chetn(Tree* root, int key);
//int isBalanced(Tree* root);
//int height(Tree* node);
//int maxInt(int a, int b);
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	int choice = 0;
//	do
//	{
//		cout << "1 - добавление нового элемента\n";
//		cout << "2 - удаление элемента\n";
//		cout << "3 - вывод дерева в нисходящем порядке\n";
//		cout << "4 - вывод дерева в смешанном порядке\n";
//		cout << "5 - количество узлов с четными ключами\n";
//		cout << "6 - проверка на сбалансированномть\n";
//		cout << "7 - очистка дерева\n";
//		cout << "0 - выход\n";
//		cout << "\nНомер операции > "; cin >> choice;
//
//		switch (choice)
//		{
//
//		case 1: {
//			if (root == NULL)
//				root = CreateTree(root);
//			else AddEl(root);
//			break;
//		}
//
//		case 2: {
//			int key;
//			cout << "Ключ > "; cin >> key;
//			DeleteEl(root, key);
//			break;
//		}
//
//		case 3: {
//			PrintTree(root, 0);
//			cout << endl << endl;
//			break;
//		}
//
//		case 4: {
//			PrintTree2(root, 0);
//			cout << endl << endl;
//			break;
//		}
//
//		case 6: {
//			int r = isBalanced(root->right), l = isBalanced(root->left);
//			if (isBalanced(root->right) == 1 || isBalanced(root->left) == 1)
//				cout << "\nДерево  сбалансировано!\n";
//			else
//				cout << "\nДерево не сбалансировано!\n";
//		}
//
//		case 7: {
//			DeleteTree(root);
//			cout << endl << endl;
//			root = NULL;
//			break;
//		}
//
//		case 5: {
//			cout << "Количество узлов с четными ключами > " << chetn(root, root->key)-1 << endl;
//			break;
//		}
//
//		case 0: {
//			break;
//		}
//		}
//	} while (choice != 0);
//
//}
//
//Tree* CreateTree(Tree* root)
//{
//	int key;
//	string str;
//	if (root == NULL)
//	{
//		cout << "Ключ корня > "; cin >> key;
//		cout << "Строка корня > "; cin >> str;
//		root = CreateEl(key, str);
//		cout << "\nКорень дерева создан!\n\n";
//	}
//	return root;
//}
//
//Tree* CreateEl(int k, string str)
//{
//	Tree* interm = new Tree[sizeof(Tree)];
//	interm->key = k;
//	interm->str = str;
//	interm->left = interm->right = NULL;
//	return interm;
//}
//
//Tree* AddEl(Tree* root)
//{
//	int key; string str;
//	cout << "Ключ элемента > "; cin >> key;
//	if (key == root->key)
//	{
//		cout << "Ключ должнен быть уникальным, измените значение!\n";
//		cout << "Ключ элемента > "; cin >> key;
//	}
//	cout << "Строка элемента > "; cin >> str; cout << endl << "Элемент добавлен!\n";
//	Tree* prev = root; // из-за ошибки "Потенциально неинициализируемая переменная"
//	while (root)
//	{
//		prev = root;
//		if (key < root->key)
//			root = root->left;
//		else root = root->right;
//	}
//	root = CreateEl(key, str);
//	if (key < prev->key)
//		prev->left = root;
//	else
//		prev->right = root;
//	return root;
//}
//
//Tree* DeleteEl(Tree* root, int key)
//{
//	Tree* d, * prevd, * r, * prevr;
//	d = root; prevd = NULL;
//	while (d != NULL && d->key != key)
//	{
//		prevd = d;
//		if (d->key > key)
//			d = d->left;
//		else
//			d = d->right;
//	}
//
//	if (d == NULL)
//	{
//		cout << "Элемент не найден!";
//		return root;
//	}
//
//	if (d->right == NULL)
//		r = d->left;
//	else if (d->left == NULL)
//		r = d->right;
//	else {
//		prevr = d;
//		r = d->left;
//		while (r->right != NULL)
//		{
//			prevr = r;
//			r = r->right;
//		}
//
//		if (prevr == d)
//			r->right = d->right;
//		else {
//			r->right = d->right;
//			prevr->right = r->left;
//			r->left = prevr;
//		}
//	}
//
//	if (d == root)
//		root = r;
//	else {
//		if (d->key < prevd->key)
//			prevd->left = r;
//		else
//			prevd->right = r;
//	}
//
//	int Dkey = d->key;
//	cout << "Удален элемент с ключом " << Dkey << "\n";
//	d = NULL;
//	return root;
//}
//int how = 0;
//void PrintTree(Tree* root, int depth)
//{
//	if (root)
//	{
//		// смешанный обход - слева направ0
//		PrintTree(root->right, depth);
//		how++;
//		cout << root->key << ' ';
//		how++;
//		PrintTree(root->left, depth);
//		how++;
//	}
//}
//
//void PrintTree2(Tree* root, int depth)
//{
//	if (root)
//	{
//		// нисходящий обход - сверху вниз
//		PrintTree2(root->left, depth);
//		PrintTree2(root->right, depth);
//		cout << root->key << ' ';
//	}
//}
//
//void DeleteTree(Tree* root)
//{
//	if (root != NULL)
//	{
//		DeleteTree(root->left);
//		DeleteTree(root->right);
//		root = NULL;
//	}
//}
//
////количество узлов с четными ключами
//int depth = 0;
//int chetn(Tree* root, int key)
//{
//	if (root != NULL)
//	{
//		
//		if (chetn(root->left, key) % 2 == 0 || chetn(root->right, key) % 2 == 0 || root->key%2==0 )
//		{
//			++depth;
//		}
//	}
//	return depth;
//}
//
//int maxInt(int a, int b)
//{
//	return (a >= b) ? a : b;
//}
//
//int height(Tree* node)
//{
//	if (node == NULL)
//		return 0;
//
//	return 1 + maxInt(height(node->left), height(node->right));
//}
//
//int isBalanced(Tree* root)
//{
//	int lh;
//	int rh;
//
//	if (root == NULL)
//		return 1;
//
//	lh = height(root->left);
//	rh = height(root->right);
//
//	if (abs(lh - rh) == 0 && isBalanced(root->left) && isBalanced(root->right))
//		return 1;
//
//	return 0;
//}


// Изучить работу с красно-черными деревьями. Реализовать основные операции над красно-черным деревом. В красно-черном дереве найти путь 
// от корня к некоторому листу, содержащий минимальное количество красных вершин.

#include <iostream>

enum COLOR { RED, BLACK };

struct node
{
    node(int const rhs) : data(rhs) {}
    COLOR color = RED;
    int data;
    node* left = nullptr, * right = nullptr, * parent = nullptr;
};

// дерево
node* root = nullptr;

// поиск деда
node* grandparent(node* rhs)
{
    node* ret = nullptr;
    if (rhs && rhs->parent)
    {
        ret = rhs->parent->parent;
    }

    return ret;
}

// поиск дяди
node* uncle(node* rhs)
{
    node* ret = nullptr;
    if (node const* gp = grandparent(rhs))
    {
        ret = (gp->left == rhs->parent ? gp->right : gp->left);
    }

    return ret;
}

// левый поворот
void rotate_left(node* rhs)
{
    node* pivot = rhs->right;

    pivot->parent = rhs->parent;
    if (rhs->parent != nullptr)
    {
        if (rhs->parent->left == rhs)
        {
            rhs->parent->left = pivot;
        }
        else
        {
            rhs->parent->right = pivot;
        }
    }
    else
    {
        root = pivot;
    }

    rhs->right = pivot->left;
    if (pivot->left != nullptr)
    {
        pivot->left->parent = rhs;
    }

    rhs->parent = pivot;
    pivot->left = rhs;
}

// правый поворот
void rotate_right(node* rhs)
{
    node* pivot = rhs->left;

    pivot->parent = rhs->parent;
    if (rhs->parent != nullptr)
    {
        if (rhs->parent->left == rhs)
        {
            rhs->parent->left = pivot;
        }
        else
        {
            rhs->parent->right = pivot;
        }
    }
    else
    {
        root = pivot;
    }

    rhs->left = pivot->right;
    if (pivot->right != nullptr)
    {
        pivot->right->parent = rhs;
    }

    rhs->parent = pivot;
    pivot->right = rhs;
}


void push_case1(node*);
void push_case2(node*);
void push_case3(node*);
void push_case4(node*);
void push_case5(node*);

// вставка
node* push(node*& root, int const data)
{
    node** pcur = &root;
    node* parent = nullptr;
    while (*pcur)
    {
        parent = *pcur;
        if (data < (*pcur)->data)
        {
            pcur = &(*pcur)->left;
        }
        else if (data > (*pcur)->data)
        {
            pcur = &(*pcur)->right;
        }
        else
        {
            break;
        }
    }
    if (nullptr == *pcur)
    {
        *pcur = new node(data);
        (*pcur)->parent = parent;

        push_case1(*pcur);
    }
    return 0;
}

void push_case1(node* rhs)
{
    if (rhs->parent == nullptr)
    {
        rhs->color = BLACK;
    }
    else
    {
        push_case2(rhs);
    }
}

void push_case2(node* n)
{
    if (n->parent->color == BLACK)
    {
        return; /* Tree is still valid */
    }
    else
    {
        push_case3(n);
    }
}

void push_case3(node* n)
{
    node* u = uncle(n), * g = nullptr;

    if ((u != nullptr) && (u->color == RED))
    {
        // && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
        n->parent->color = BLACK;
        u->color = BLACK;
        g = grandparent(n);
        g->color = RED;
        push_case1(g);
    }
    else
    {
        push_case4(n);
    }
}

void push_case4(node* n)
{
    node* g = grandparent(n);

    if ((n == n->parent->right) && (n->parent == g->left))
    {
        rotate_left(n->parent);
        n = n->left;
    }
    else if ((n == n->parent->left) && (n->parent == g->right))
    {
        rotate_right(n->parent);
        n = n->right;
    }
    push_case5(n);
}

void push_case5(node* n)
{
    node* g = grandparent(n);

    n->parent->color = BLACK;
    g->color = RED;
    if ((n == n->parent->left) && (n->parent == g->left))
    {
        rotate_right(g);
    }
    else
    { /* (n == n->parent->right) && (n->parent == g->right) */
        rotate_left(g);
    }
}

// поиск
node* find(int const data)
{
    node* ret = root;
    while (ret)
    {
        if (data < ret->data)
        {
            ret = ret->left;
        }
        else if (data > ret->data)
        {
            ret = ret->right;
        }
        else
        {
            break;
        }
    }

    return ret;
}

void DeleteTree(node* root)
{
    if (root)
    {
       root->data = NULL;
       root->left = NULL;
       root->right = NULL;
    }
}

int lft = 0, rght = 0, how=0;
// печать дерева
void print(node* root, int indent = 0)
{
    
    if (root)
    {
        how = 0;
        print(root->right, indent + 1);
        for (int i = 0; i < indent; ++i)
        {
            std::cout << ".";
            how++;
        }
        std::cout << root->data << std::endl;
        print(root->left, indent + 1);
        if (how == 2 && root->left)
        {
            lft++;
       }
        if (how == 2 && root->right)
        {
            rght++;
        }
    }
}
void putt(node* root, int indent = 0)
{
    if (root)
    {
        if (lft > rght) {
            print(root->right, indent + 1);
        }
        for (int i = 0; i < indent; ++i)
        {
            std::cout << ".";
        }
        std::cout << root->data << std::endl;
        if (lft < rght) {
            print(root->left, indent + 1);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    	int choice = 0;
        int key = 0;
    	do
    	{
    		cout << "1 - добавление нового элемента\n";
    		cout << "2 - вывод дерева \n";
            cout << "3 - очистка дерева\n";
    		cout << "4 - поиск элемента дерева\n";
            cout << "5 - путь от корня к некоторому листу, содержащий минимальное количество красных вершин\n";
    		cout << "0 - выход\n";
    		cout << "\nНомер операции > "; cin >> choice;
    
    		switch (choice)
    		{
    		case 1: {
                
                string str;
                cout << "Введите ключ > "; cin >> key;
                cout << "Строка корня > "; cin >> str;
                push(root, key);
    			break;
    		}
    
    		case 2: {
                print(root);
                cout << endl << endl;
    			break;
    		}
    
    		case 3: {
                DeleteTree(root);
    			break;
    		}
    
    		case 4: {

                string str;
                cout << "Введите элемент, который хотите найти >"; cin >> key;
                if (node* found = find(key))
                {
                    std::cout << "\nfound: " << found->data << std::endl;
                }
    			cout << endl << endl; 
    			break;
    		}
    
    		case 5: {
                putt(root);
                cout << endl << endl;
    		}
    
    		case 0: {
    			break;
    		}
    		}
    	} while (choice != 0);
}


// Оператор мобильной связи организовал базу данных абонентов, содержащую сведения о телефонах, их владельцах и используемых тарифах, в виде бинарного дерева.
// Разработать программу, которая обеспечивает начальное формирование базы данных в виде бинарного дерева; производит вывод всей базы данных; поиск владельца по
// номеру телефона; выводит наиболее востребованный тариф(по наибольшему числу абонентов).

//struct Database
//{
//	int number;
//	string name;
//	int tarif;
//	struct Database* left;
//	struct Database* right;
//};
//
//Database* root = NULL;
//
//void pushAbonent(Database** t, int Number, int Tarif, string Name);
//void printAbonent(Database* t);
//void searchAbonent(Database* t, int Number);
//void mostPopularTarif(Database* t);
//
//
//int AmountOfFirst = 0, AmountOfSecond = 0, AmountOfThird = 0, counter = 0;
//int main()
//{
//	int choice = 0;
//	setlocale(LC_ALL, "rus");
//	do
//	{
//		cout << "1 - добавление нового элемента\n";
//		cout << "2 - вывод базы даных\n";
//		cout << "3 - поиск владельца по номеру телефона\n";
//		cout << "4 - вывод наиболее востребованного тарифа\n";
//		cout << "0 - выход\n";
//		cout << "\nНомер операции > "; cin >> choice;
//
//		switch (choice) {
//		case 1: {
//			int Amount, Number, Tarif;
//			string Name;
//			cout << "\nВведите Номер Клиента:\n";
//			cin >> Number;
//			cout << "\nВведите Имя Клиента:\n";
//			cin.ignore();
//			getline(cin, Name);
//			cout << "\nВыберите Тариф:\n1. Первый\n2. Второй\n3. Третий\n";
//			cin >> Tarif;
//			pushAbonent(&root, Number, Tarif, Name);
//			cout << "\nДобавлен успешно!\n\n";
//			break;
//		}
//		case 2: {
//			cout << "\nДерево Клиентов\n";
//			printAbonent(root);
//			break;
//		}
//		case 3: {
//			int Number;
//			cout << "\nВведите Номер Клиента\n";
//			cin >> Number;
//			searchAbonent(root, Number);
//			break;
//		}
//		case 4: {
//			int max;
//			mostPopularTarif(root);
//			if (AmountOfFirst >= AmountOfSecond >= AmountOfThird)
//				max = AmountOfFirst;
//			else if (AmountOfFirst < AmountOfSecond > AmountOfThird)
//				max = AmountOfSecond;
//			else max = AmountOfThird;
//			cout << "\nСамый популярный Тариф:\t";
//			if (max == AmountOfFirst)
//				cout << "Первый\n";
//			else if (max == AmountOfSecond)
//				cout << "Второй\n";
//			else cout << "Третий\n";
//			AmountOfFirst = 0;
//			AmountOfSecond = 0;
//			AmountOfThird = 0;
//			break;
//		}
//		case 0: break;
//		default: {
//			cout << "\nНеверный Выбор\n";
//			break;
//		}
//		}
//	} while (choice != 0);
//}
//
//void pushAbonent(Database** t, int Number, int Tarif, string Name) {
//	if ((*t) == NULL) {
//		(*t) = new Database();
//		(*t)->name = Name;
//		(*t)->number = Number;
//		(*t)->tarif = Tarif;
//		return;
//	}
//	if (Number > (*t)->number)
//		pushAbonent(&(*t)->left, Number, Tarif, Name);
//	else
//		pushAbonent(&(*t)->right, Number, Tarif, Name);
//}
//
//void printAbonent(Database* t) {
//	if (t) {
//		cout << "\nИмя:\t" << t->name;
//		cout << "\nНомер:\t" << t->number;
//		cout << "\nТариф:\t";
//		if (t->tarif == 1)
//			cout << "Первый\n";
//		else if (t->tarif == 2)
//			cout << "Второй\n";
//		else cout << "Третий\n";
//		printAbonent(t->left);
//		printAbonent(t->right);
//	}
//}
//
//void searchAbonent(Database* t, int Number) {
//	if (t) {
//		if (t->number == Number) {
//			cout << "\nИмя:\t" << t->name;
//			cout << "\nНомер:\t" << t->number;
//			cout << "\nТариф:\t";
//			if (t->tarif == 1)
//				cout << "Первый\n";
//			else if (t->tarif == 2)
//				cout << "Второй\n";
//			else cout << "Третий\n";
//			return;
//		}
//		searchAbonent(t->left, Number);
//		searchAbonent(t->right, Number);
//	}
//}
//
//void mostPopularTarif(Database* t) {
//	if (t) {
//		if (t->tarif == 1)
//			AmountOfFirst++;
//		if (t->tarif == 2)
//			AmountOfSecond++;
//		if (t->tarif == 3)
//			AmountOfThird++;
//		mostPopularTarif(t->left);
//		mostPopularTarif(t->right);
//	}
//}

// Дано N чисел, N > 0. Создать дерево из N вершин, в котором каждая левая дочерняя вершина является листом, а правая дочерняя вершина является внутренней.
// Для каждой внутренней вершины вначале создавать левую дочернюю вершину, а затем правую(если она существует); 
// каждой создаваемой вершине присваивать очередное значение из исходного набора.

//
//struct El
//{
//	int data;
//	El* left;
//	El* right;
//};
//
// El* root = NULL;
//
// El* CreateEl(int data)
//{
//	El* interm = new El[sizeof(El)];
//	interm->data = data;
//	interm->left = interm->right = NULL;
//	return interm;
//}
//
//void printT(El* p, int level)
//{
//	if (p)
//	{
//		printT(p->left, level + 1);
//		for (int i = 0; i < level; i++) 
//			cout << "   ";
//		cout << p->data << endl;
//		printT(p->right, level + 1);
//	}
//}
//
//El* f(El* rt, int n, int count)
//{
//	static int loop = 0, data = 0;
//	loop++; data++;
//
//	if (loop<= n)
//	{
//		if (root == NULL && count == 0)
//		{
//			root = CreateEl(data);
//			++count;
//			f(root, n, count);
//			return root;
//		}
//		else if (count == 1)
//		{
//			rt->left = CreateEl(data);
//			++count;
//			f(rt, n, count);
//		}
//		else if (count == 2)
//		{
//			--count;
//			rt->right = CreateEl(data);
//			f(rt->right, n, count);
//		}
//	}
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	int n = 0;
//	cout << "Введите число N (количество вершин) > "; cin >> n;
//	root = f(root, n, 0);
//	printT(root, 0);
//}