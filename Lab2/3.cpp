//Дан файл вещественных чисел, содержащий элементы квадратной матрицы по строкам, причем начальный элемент файла содержит значение
//количества столбцов матрицы. Создать новый файл той же структуры, содержащий k-ую строку исходной матрицы.

#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE* A, * B;
	size_t fSizeOfA;
	long endPos;
	errno_t err;

	err = fopen_s(&A, "A.txt", "w"); 
	if (err != 0) 
	{
		perror("ошибка открытия a.txt");
		return;
	}

	cout << "Введите размер матрицы:" << endl; 
	int n; cin >> n;

	fprintf(A, "%d\t", n);
	int* massiv = new int[n * n];

	cout << "Введите элементы массива: " << endl;
	for (int g = 0, u = 0; g < n; g++) 
	{
		for (int i = 0; i < n; i++, u++) 
		{
			cin >> massiv[u];
			fprintf(A, "%d\t", massiv[u]);
		}
	}

	for (int g = 0, u = 0; g < n; g++) 
	{
		for (int i = 0; i < n; i++, u++) 
		{
			cout << massiv[u];
		}
		cout << endl;
	}
	
	delete[] massiv;
	fclose(A);


	err = fopen_s(&A, "A.txt", "r");
	if (err != 0) 
	{
		perror("ошибка открытия a.txt");
		return;
	}

	//определяем размер
	fseek(A, 0L, SEEK_END); 
	endPos = ftell(A);
	fseek(A, 0L, SEEK_SET); 

	if (!fopen_s(&B, "B.txt", "w")) 
	{ 
		int x;
		fscanf_s(A, "%d", &x); //узнаем размер массива
		
		int** arr = new int* [x];
		for (int i = 0; i < x; i++)
			arr[i] = new int[x];
		for (int u = 0; u < x; u++) //считывание данных из файлов в массив
			for (int i = 0; i < x; i++) 
			{
				fscanf_s(A, "%d", &(arr[u][i]));
			}

		cout << "Итоговая матрица: " << endl;
		for (int g = 0; g < x; g++) 
		{
			for (int i = 0; i < x; i++) 
			{
				cout << arr[g][i] << " ";
			}
			cout << endl;
		}

		cout << "Введите k-й столбец(он появится в файле В): " << endl;
		int k; cin >> k;

		for (int i = 0; i < x; i++) 
		{ 
			fprintf_s(B, "%d ", arr[i][k]);
		}
		fclose(A);
		fclose(B);

		delete[] arr;

		cout << "Файл был успешно создан" << std::endl;
	}
	else {
		cout << "Ошибка создания файла" << std::endl;
		return;
	}
	system("pause");
}

