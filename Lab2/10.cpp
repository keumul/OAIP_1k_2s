//Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию.
//Скопировать в файл F2 только строки из F1, которые не содержат цифр.

#include <iostream>

FILE* f;
using namespace std;

void wrt(const char a[256], int n)
{
	for (int i = 0; i <= n; i++)
	{
		fwrite(&a[i], 1, 1, f);
	}
	fwrite("\n", 1, 1, f);
}

void str(char a[256], int n)
{
	char in[11] = "0123456789";

	for (int i = n; i >= 0; i--)
	{
		for (int j = 0; j <= 10; j++)
			if (a[i] == in[j]) return;
	}
	wrt(a, n);
}

int main()
{
	setlocale(LC_CTYPE, "Russian");

	FILE* fp;

	errno_t err;
	err = fopen_s(&fp, "A.txt", "r");
	if (err != 0)
	{
		perror("Ошибка открытия a.txt");
		return 0;
	}

	errno_t err1;
	err1 = fopen_s(&f, "B.txt", "w");
	if (err1 != 0)
	{
		perror("Ошибка открытия a.txt");
		return 0;
	}

	char x, a[256];
	int n = -1;

	fseek(fp, 0L, SEEK_END);
	long fsize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	for (int i = 0; i <= fsize; i++)
	{
		fread((char*)&x, sizeof(char), 1, fp);
		if (x == '\n') {
			str(a, n);
			n = -1;
		}
		else {
			n++;
			a[n] = x;
		}
	}
	str(a, n);
}

