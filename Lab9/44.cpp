// N человек располагаются по кругу. Начав отсчет от первого, удаляют каждого k-го, смыкая круг после удаления. Определить порядок 
// удаления людей из круга. Использовать линейный список.

#include <iostream>
#include <cstdlib>
using namespace std;
struct node {
	int item; node* next;
	node(int x, node* t)
	{
		item = x; next = t;
	}
};
typedef node* link;
int main()
{
	setlocale(LC_CTYPE,"Russian");
	int i, N, M;
	cout << "Введите кол-во узлов в связном спике" << endl; cin >> N;
	cout << "Введите число, через которое будем удалять узлы списка" << endl; cin >> M;
	link t = new node(1, 0);
	t->next = t;
	link x = t;
	for (i = 2; i <= N; i++)
		x = (x->next = new node(i, t));
	cout << "" << endl;
	x = t;
	do {
		cout << x->item << " " << endl;
		x = x->next;
	} while (x != t);

	while (x != x->next)
	{
		for (i = 0; i < M; i++)
		{
			x = x->next;
			x->next = x->next->next;
		}
	}
	cout << "Оставшийся элемент: " << x->item << endl;
}