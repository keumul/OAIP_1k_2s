// Создать очередь с вещественными числами, и заполнить ее с клавиатуры. Выполнить циклический сдвиг 
// элементов в очереди так, чтобы в ее начале был расположен наибольший элемент.

#include <cstdlib>
#include <iostream>
using namespace std;

struct Node {
    int value;
    struct Node* next;
};

Node* newElem(int, Node*&);
void print(const Node*);
void r_shift(Node*&);
void del(Node*&);

int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "Russian");

    Node* head = NULL;
    int n, k=0, i, v, max=0, b, bmax;
    cout << "Количество элементов очереди: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        b = i + 1;
        cout << "Введите " << b << " элемент: ";
        cin >> v;
        if (v > max) 
        { 
            max = v; 
            bmax = b;
        }
          
        newElem(v, head);
    }
    cout << "Очередь: ";
    print(head);

    k = n - bmax;
    for (i = 0; i <= k; i++)
        r_shift(head);
    cout << "Очередь после циклического сдвига: ";
    print(head);
    del(head);
    system("PAUSE");
    return 0;
}

Node* newElem(int val, Node*& first) {
    Node* p, * t;
    p = new Node[1];
    p->next = NULL;
    p->value = val;
    if (first == NULL)
        first = p;
    else
    {
        t = first;
        while (t->next != NULL)
            t = t->next;
        t->next = p;
    }
    return p;
}

void print(const Node* first)
{
    const Node* p;
    p = first;
    while (p != NULL)
    {
        cout << p->value << "  ";
        p = p->next;
    }
    cout << endl;
}

void del(Node*& first)
{
    Node* p, * t;
    p = first;
    while (p != NULL)
    {
        t = p->next;
        delete p;
        p = t;
    }
}

void r_shift(Node*& first)
{
    Node* t=0, * p;
    if (first == NULL);
    else if (first->next == NULL);
    else
    {
        p = first;
        while (p->next != NULL)
        {
            t = p;
            p = p->next;
        }
        t->next = NULL;
        p->next = first;
        first = p;
    }
}


//#include<iostream> 
//using namespace std;
//struct node
//{
//    int elem;
//    node* sled;
//};
//void postroenie(node **phead);
//void vivod(node **phead);
//node* poisk(int);
//
//void main() {
//    setlocale(LC_CTYPE, "Russian");
//    int el, el1;
//    node* phead = NULL, * end, * t;
//    //    t = new Number;
//    //    int p, size;
//    //    cout << "\nEnter size queue=";  cin >> size;
//    //    cout << "Enter number= ";       cin >> p;
//    //    t->info = p;    
//    //    t->next = NULL;
//    //    begin = end = t;
//    postroenie(&phead);
//    vivod(&phead); 
//}
//void postroenie(node** phead) {
//    int el;
//    struct node* t;
//
//    // Вначале сформируем заглавное звено.
//    *phead = new (node);
//    t = *phead; (*t).sled = NULL;
//    cout << "Вводите элементы кольца (0, чтобы выйти):  "; cin >> el;
//    while (el != 0)
//    {
//        (*t).sled = new (node); t = (*t).sled; (*t).elem = el;
//        cin >> el;
//    }
//    (*t).sled = (*(*phead)).sled;
//
//}
//void vivod(node** phead)
//{
//    struct node* t;
//    t = (**phead).sled; cout << "Кольцо: ";
//    if (t != NULL)
//    {
//        cout << (*t).elem; 
//        t = (*t).sled;
//        while (t != (**phead).sled)
//        {
//            cout << (*t).elem;
//            t = (*t).sled;
//        }
//    }
//    else cout << "пусто!\n";
//}

//void create(Number** begin, Number** end, int p); //формирование элементов очереди
//void view(Number* begin); //функция вывода элементов очереди 
//Number* maxElem(Number* begin); //функция определения минимального элемента 
//void DeltoMax(Number** begin, Number** p); 
//void AddMax(Number**end, Number**p);
//int main()
//{
//    Number* begin = NULL, * end, * t;
//    t = new Number;
//    int p, size;
//    cout << "\nEnter size queue=";  cin >> size;
//    cout << "Enter number= ";       cin >> p;
//    t->info = p;    
//    t->next = NULL;
//    begin = end = t;
//    for (int i = 1; i < size; i++) 
//    {
//        cout << "Enter number= ";    
//        cin >> p;
//        create(&begin, &end, p);
//    }
//    cout << "\nelements of queue: \n";
//    if (begin == NULL)
//        cout << "No elements" << endl;
//    else
//        view(begin);
//    t = maxElem(begin);
//    cout << "maximum=" << t->info << endl;
//    DeltoMax(&begin, &t);  
//   // AddMax(&end,&t);
//    cout << "\nnew Queue:\n";
//    view(begin);
//    return 0;
//}
//void create(Number** begin, Number** end, int p) 
//{
//    Number* t = new Number;
//    t->next = NULL;
//    if (*begin == NULL)
//        *begin = *end = t;
//    else
//    {
//        t->info = p;
//        (*end)->next = t;
//        *end = t;
//    }
//}
//void view(Number* begin) //Вывод элементов очереди 
//{
//    Number* t = begin;
//    if (t == NULL)
//    {
//        cout << "Number is empty\n";
//        return;
//    }
//    else
//        while (t != NULL)
//        {
//            cout << t->info << endl;
//            t = t->next;
//        }
//}
//Number* maxElem(Number* begin) 
//{
//    Number* t = begin, * mn=0
//        ;
//    int max;
//    if (t == NULL)
//    {
//        cout << "Number is empty\n"; return 0;
//    }
//    else
//    {
//        max = t->info;
//        while (t != NULL)
//        {
//            if (t->info > max)
//            {
//                max = t->info;
//                mn = t;
//            }
//            t = t->next;
//        }
//    }
//    return mn;
//}
////void AddMax(Number** end, Number** p)
////{
////    Number* t;
////    t = new Number;
////    while (*end != *p)
////    {
////        t = *end;
////        *end = (*end)->next;
////    }
////}
//void DeltoMax(Number** begin, Number** p)
//{
//    Number* t;
//    t = new Number;
//    while (*begin != *p)
//    {
//        t = *begin;
//        *begin = (*begin)->next;
//        delete t;
//    }
//}

//#include <string>
//#include <cstdlib>
//#include <cstdio>
//
//struct STACK
//{
//    int a;
//    STACK* next;
//};
//STACK* top = NULL;
//
//void push(int c, STACK** b)
//{
//    STACK* temp = new STACK;
//    temp->a = c;
//    temp->next = (*b);
//    (*b) = temp;
//}
//int pop(STACK** t)
//{
//    if ((*t) != NULL)
//    {
//        STACK* temp = (*t);
//        int a = (*t)->a;
//        (*t) = (*t)->next;
//        delete temp;
//        return a;
//    }
//    else
//        return 0;
//}
//
//struct QUEUE
//{
//    char a;
//    QUEUE* next;
//};
//
//QUEUE* head = NULL, * tail = NULL;
//
//void push_back(char c, QUEUE** b)
//{
//    if ((*b) != NULL)
//    {
//        QUEUE* temp = new QUEUE;
//        temp->a = c;
//        temp->next = NULL;
//        (*b)->next = temp;
//        (*b) = temp;
//    }
//    else
//    {
//        (*b) = new QUEUE;
//        (*b)->a = c;
//        (*b)->next = NULL;
//        head = (*b);
//    }
//}
//char pop_front(QUEUE** t)
//{
//    if ((*t) != NULL)
//    {
//        QUEUE* temp = (*t);
//        char a = (*t)->a;
//        (*t) = (*t)->next;
//        delete temp;
//        return a;
//    }
//    else
//        return 0;
//}
//
//int main()
//{
//    char c[200], str[10];
//    gets_s(c);                          
//    int a, k = 0;
//    for (int i = 0; i < strlen(c); i++)
//    {
//        if (c[i] == '-' && c[i + 1] >= '0' && c[i + 1] <= '9' && k == 0) k = 1;
//        else
//            if (c[i] >= '0' && c[i] <= '9') k = 1;
//            else
//                if (c[i] == ' ' && k == 1)
//                {
//                    k = 0;
//                    strncpy_s(str, c, i + 1);
//                    strcpy_s(c, &(c[i + 1]));
//                    i = -1;
//                    a = atoi(str);
//                    push(a, &top);
//                }
//                else
//                {
//                    if (c[i] != ' ') push_back(c[i], &tail);
//                    strcpy_s(c, &(c[i + 1]));
//                    i = -1;
//                }
//
//    }
//    if (k == 1)
//    {
//        a = atoi(c);
//        push(a, &top);
//    }
//
//    while (head != NULL)
//        printf("%c ", pop_front(&head));
//
//    while (top != NULL)
//        printf("%d ", pop(&top));
//
//    return 0;
//}


//#include<iostream>
//#include <cstdlib>
//using namespace std;
//
//struct node {
//	int item;
//	node* next;
//	node(int x,node* t)
//	{
//		item = x; next = t;
//	}
//};
//
//typedef node* link;
//int main(int argc, char* argv[])
//{
//	int i, N = atoi(argv[1]), M = atoi(argv[2]);
//	link t = new node(1, 0);
//	t->next = t;
//	link x = t;
//	for (i = 2; i <= N; i++)
//		x = (x->next = new node(1, t));
//	while (x != x->next)
//	{
//		for (i = 1; i < M; i++)
//			x = x->next;
//		x->next = x->next->next;
//	}
//	cout << x->item << endl;
//}
//










//struct list
//{
//	int field; // поле данных
//	struct list* ptr; // указатель на следующий элемент
//};
//struct list* init(int a) // а- значение первого узла
//{
//	struct list* lst;
//	// выделение памяти под корень списка
//	lst = (struct list*)malloc(sizeof(struct list));
//	lst->field = a;
//	lst->ptr = lst; // указатель на сам корневой узел
//	return(lst);
//}
//struct Number
//{
//    int info;
//    Number* next;
//};
//
//void create(Number** begin, Number** end, int p); 
//void view(Number* begin, int max); 
//int main()
//{
//    Number* begin = NULL, * end, * t;
//    t = new Number;
//    int p, size, max=0;
//    cout << "\nEnter size queue="; 
//    cin >> size;
//    cout << "Enter number= ";       
//    cin >> p;
//    t->info = p; 
//    t->next = NULL;
//    begin = end = t;
//    for (int i = 1; i < size; i++)
//    {
//        cout << "Enter number= ";    
//        cin >> p;
//        if (p > max) { max = p; }
//        create(&begin, &end, p);
//    }
//    cout << "\nelements of queue: \n";
//    if (begin == NULL)   
//        cout << "No elements" << endl;
//    else
//        view(begin, max);
//    return 0;
//}
//void create(Number** begin, Number** end, int p)
//{
//    Number* t = new Number;
//    t->next = NULL;
//    if (*begin == NULL)
//        *begin = *end = t;
//    else
//    {
//        t->info = p;
//        (*end)->next = t;
//        *end = t;
//    }
//}
//void view(Number* begin, int max) 
//{
//    
//    Number* t = begin;
//    Number* n;
//    if (t == NULL)
//    {
//        cout << "Number is empty\n";
//        return;
//    }
//    else
//        while (t!=NULL)
//        {
//            t = t->next;
//            t->next = begin;
//        }
//    n = begin;
//    int count = 1;
//    while(count<=max)
//    { 
//        n = n->next;
//        count++;
//    }
//    begin = n->next;
//    n->next = NULL;
//
//}
