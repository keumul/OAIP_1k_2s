// Скопировать из файла FILE1 в файл FILE2 все строки, в которых нет слов, совпадающих с первым словом. 
// Определить количество согласных букв в первой строке  файла FILE2.

#include <iostream>
#include <fstream>

using namespace std;

char first[256];
int arr[256], aa = 0;
int size1 = 0;

string sogl = "sdfцкнгзхфвghjklzxcvbnmqwrtpпрлджчсмт";

void search(char str[256], int size)
{
	int a = 0;
	for (int i = 0; i <= 37; i++)
	{
		for (int j = 0; j < ','; j++)
		{
			if (str[j] == sogl[i])
			{
				a++;
			}
		}
	}
	arr[aa] = a;
	aa++;
}

int word(char last[256], int size)
{
	int j = 0, ni = 0, flag = 0;
	
	for (int i = 0; i <= size; i++)
	{
		if ((last[i] == ' ') || (last[i] == '\0') || (last[i] == '\n'))
		{
			if (ni == size1)
			{
				return 1;
			}
			ni = 0, j = 0;
		}
		else
		{
			if (last[i] == first[j])
			{
				ni++;
			}
			j++;
		}
	}
	return 0;
}
int main()
{
	setlocale(LC_CTYPE, "Russian");

	ifstream f1("f1.txt");
	ofstream f2("f2.txt");

	if (!f1.is_open())
	{
		cout << "Файл не может быть открыт!\n";
	}
	f1 >> first;
	size1 = strlen(first);
	
	int size = sizeof(f1);
	char last[256];
	int sizei = 0, len = 0;
	do {
		f1.getline(last, 256);
		len = strlen(last);
		if (len > 0) 
		{
			if (word(last, len) != 1)
			{
				f2 << last << endl;
				search(last, len);
			}
		}
		sizei += len;
	} while (f1);

	cout << arr[aa - 1] << " cогласных букв в первой строке файла!" << endl;

	f1.close();
	f2.close();
}
