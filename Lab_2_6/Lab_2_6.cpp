#include <iostream>

using namespace std;

struct Data
{
	int* array = NULL;
	int n = 0;
};

void createData(Data& data)
{
	cout << "Кол-во чисел: ";
	cin >> data.n;

	data.array = (int*)malloc(sizeof(int) * data.n);

	cout << "Набор чисел: ";

	for (int i = 0; i < data.n; i++)
		cin >> data.array[i];
}

void printArray(const Data& data)
{
	for (int i = 0; i < data.n; i++)
		cout << data.array[i] << " ";
	cout << "\n";
}

void deleteData(Data& data)
{
	free(data.array);
	data.array = NULL;
	data.n = 0;
}

// O(N^3)
void firstMethod(Data& data)
{
	int* subsequence = NULL;
	int* temp_array = NULL;
	subsequence = (int*)malloc(sizeof(int) * data.n);
	temp_array = (int*)malloc(sizeof(int) * data.n);
	

	cout << "Введите последовательность перестановки: ";

	for (int i = 0; i < data.n; i++)
		cin >> subsequence[i];

	for (int i = 0; i < data.n; i++)
		temp_array[subsequence[i] - 1] = data.array[i];

	for (int i = 0; i < data.n; i++)
		data.array[i] = temp_array[i];

	free(subsequence);
	free(temp_array);
	subsequence = NULL;
	temp_array = NULL;
}

// O(N)
void secondMethod(Data& data)
{
	int subsequence = 0;
	int* temp_array = NULL;
	temp_array = (int*)malloc(sizeof(int) * data.n);

	cout << "Введите последовательность перестановки: ";

	for (int i = 0; i < data.n; i++)
	{
		cin >> subsequence;
		temp_array[subsequence - 1] = data.array[i];
	}

	int* temp = data.array;
	data.array = temp_array;

	free(temp);
}

int main()
{
	system("chcp 1251");
	system("cls");

	Data data;

	createData(data);
	printArray(data);
	//firstMethod(data);
	secondMethod(data);
	printArray(data);
	deleteData(data);
	return 0;
}