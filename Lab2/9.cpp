// Компоненты файла fileA –  целые отличные от нуля числа : х, y1, ... yn.
// Вывести на экран два члена этой последовательности, среднее арифметическое 
// которых ближе всего к х.

#include <iostream>
#include <stdio.h>  
#include <string>
#include <cstdlib>

using namespace std;

int pint(char a[256], int n) {
	int x = 0;
	int t = 1;

	for (int i = n; i >= 0; i--)
	{
		char ch = a[i];
		x = x + (atoi(&ch)) * t;
		t = t * 10;
	}
	return x;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");

	FILE* A;
	errno_t err;
	err = fopen_s(&A, "A.txt", "r");
	if (err != 0)
	{
		perror("Ошибка открытия a.txt");
		return 0;
	}

	char xh;
	int jn = 0;

	fseek(A, 0L, SEEK_END);
	long fsize = ftell(A);
	fseek(A, 0L, SEEK_SET);

	int* y = new int[fsize];
	int n = 256;

	char* arr = new char[n];
	int k = -1;

	for (int i = 0; i <= fsize; i++) {
		fread((char*)&xh, sizeof(char), 1, A);
		if (xh == ' ')
		{
			y[jn] = pint(arr, k);
			jn++;
			k = -1;
		}
		else
		{
			k++;
			arr[k] = xh;
		}
	}

	y[jn] = pint(arr, k - 1);
	for (int i = 0; i <= jn; i++) {
		cout << y[i] << ' ';
	}
	cout << endl;

	int ni = -1, nj = -1;
	int x = y[0];
	int arifm = abs((y[1] + y[2]) / 2 - x);

	for (int i = 1; i <= jn; i++)
	{
		for (int j = i + 1; j <= jn - 1; j++)
		{
			if (abs((y[i] + y[j]) / 2 - x) <= arifm)
			{
				ni = i;
				nj = j;
				arifm = abs((y[i] + y[j]) / 2 - x);
			}
		}
	}
	cout << y[ni] << ' ' << y[nj];
}


