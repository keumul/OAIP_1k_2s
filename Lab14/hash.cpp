//#include "stdafx.h"
#include "Hash.h"
#include <iostream>

//int HashFunction(int key, int size, int p)//Хеш-функция
//{
//	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
//	return (p + key) % size;
//}

//---------------------------МОДУЛЬНОЕ ХЭШИРОВАНИЕ-----------------------------------//

//int HashFunction(int key, int size, int p)//Хеш-функция
//{
//	return key % 5;
//}

//---------------------------МУЛЬТИПЛИКАТИВНОЕ ХЭШИРОВАНИЕ---------------------------//
//int HashFunction(int key, int size, int p) //Хеш-функция
//{
//	int n = 13; double A = 0.6180339887499;
//	int h = n * fmod(key * A, 1) +p;
//	return h;
//}


//----Изменить функцию вычисления хеш для решения коллизии на линейную функцию,  которая--// 
//----строится на основе формулы: h(key, i) = (h'(key) + i)×mod  hashTableSize.-----------//

//inline int HashFunction(int key, int size, int p) //Хеш-функция
//{
//	int h = fmod(key + 13, size) + p;
//	return h;
//}

//------Изменить функцию вычисления хеш для решения коллизии на функцию, которая----------//
//------строится на основе формулы : h(key, i) = (h1(key) + i∙h2(key))×mod hashTableSize,-//
//------где  h1(key) = key×mod hashTableSize, h2(key) = 1 + (key×mod hashTableSize).------//

int HashFunction(int key, int size, int p) //Хеш-функция
{
	int n = 13; double A = 0.6180339887499;
	int h1 = fmod(key, size) + p;
	int h2 = 1 + fmod(key, size) + p;
	int h = fmod(h1+n*h2,size) + p;
	return h;
}

//-------------------------------
int Next_hash(int hash, int size, int p)
{
	//1ый метод
	//return (hash + 5 * p + 3 * p * p) % size;
	
	//модульный метод
	//return hash % 5;
	
	//мультипликативный метод
	//return 13 * fmod(hash*0.6180339887499, 1) + p;

	//2й доп
	//return fmod(hash + 13, size) + p;

	//3й доп
	return fmod(fmod(hash, size) + 13 * (1 + fmod(hash, size)), size) + p;
}
//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d)
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0);
			i != size && !b;  j = Next_hash(j, size, ++i))
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}
//-------------------------------
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				f((this->data)[i]);
	}
}