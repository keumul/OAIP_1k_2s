// Содержимое текстового файла f, разделенное на строки, переписать в текстовый файл g, перенося при этом в конец каждой строки все входящие в
// нее цифры (с сохранением исходного взаимного порядка, как среди цифр, так и среди остальных литер строки). Использовать очереди.


#include<iostream>
#include<fstream>

struct Elem { //очередь
	char ch; //буква
	Elem* next; //следующая
	Elem* back; //предыдущая
};

void Add(Elem*& first, char c) //добавление в конец
{
	Elem* n = new Elem; //создаём новый элемент
	n->ch = c;
	n->next = NULL;
	if (first == NULL) { //если список пуст
		first = n; //новый будет первым
		n->back = NULL;
	}
	else { //иначе ищем конец очереди
		Elem* t = first;
		while (t->next != NULL) t = t->next;
		t->next = n; //и добавляем в конец
		n->back = t;
	}
}

void Print(Elem* first, FILE* file) //печать в файл
{
	Elem* t = first;
	while (t != NULL) { //идём по списку
		fputc(t->ch, file); //печатаем букву
		t = t->next; //переходим на следующую
	}
	fputc('\n', file); //делаем перевод строки
}

void Clear(Elem*& first) //очистка списка
{
	Elem* t;
	while (first != NULL) {
		t = first;
		first = first->next;
		delete t;
	}
}

int main()
{
	FILE* in;
	fopen_s(&in, "f.txt", "r"); //входной файл

	FILE* out; 
	fopen_s(&out,"g.txt", "w"); //выходной
	if (in == NULL || out == NULL) { return -1; } //если не открылись - выходим
	while (!feof(in)) { //пока не кончится файл
		char t;
		int count = 0;
		Elem* first = NULL; //новый список
		while ((t = fgetc(in)) != '\n' && t != EOF) { //читаем посимвольно до конца строки или файла
			Add(first, t); //добавляем букву в список
			count++; //считаем количество
		}
		if (t == EOF && count == 0) { break; } //если файл кончился и ни одного символа нет - выходим
		Elem* tmp = first;
		int i = 0;
		while (i < count) { //обходим список
			i++;
			if ((tmp->ch >= '0') && (tmp->ch <= '9')) { //если цифра
				Elem* tmp1 = tmp; //находим конец списка
				while (tmp1->next != NULL)
					tmp1 = tmp1->next;
					tmp1->next = tmp;
					//кладём туда цифру и освобождаем исходную позицию
					if (tmp->back != NULL) { tmp->back->next = tmp->next; }
					else first = tmp->next;
					if (tmp->next != NULL) { tmp->next->back = tmp->back; }
					Elem* next = tmp->next; //сохраняем следующий для перехода
					tmp->next = NULL; //меняем ссылки у исходного
					tmp->back = tmp1;
					tmp = next; //переходим на следующий
				
			}
			else tmp = tmp->next; //если буква - просто пропускаем
		}
		Print(first, out); //печатаем строку в файл
		Clear(first); //очищаем список
	}
	fclose(in); //закрываем файлы
	fclose(out);
	//_getch();
	return 0;
}

