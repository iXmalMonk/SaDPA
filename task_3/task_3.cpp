#include<iostream>

using namespace std;

#define SIZE 100

void fillArrayRandomly(int* array, int start, int stop)
{
	for (int i = 0; i < SIZE; i++)
		array[i] = rand() % (stop - start + 1) + start;
}

void printArray(int* array)
{
	for (int i = 0; i < SIZE; i++)
		cout << array[i] << " ";
	cout << "\n";
}

void swap(int& a, int& b)
{
	int c = b;
	b = a;
	a = c;
}

void sortBubble(int* array)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE - 1; j++)
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
}

void sortShaker(int* array)
{
	bool flag = true;
	int left = 1;
	int right = SIZE - 1;

	do {
		flag = true;

		for (int i = left; i <= right; i++)
			if (array[i - 1] > array[i])
			{
				swap(array[i - 1], array[i]);
				flag = false;
			}

		right--;

		for(int i = right; i >= left; i--)
			if (array[i - 1] > array[i])
			{
				swap(array[i - 1], array[i]);
				flag = false;
			}

		left++;

	} while (flag == false);
}

int main()
{
	system("chcp 1251");
	system("cls");

	double start = clock();

	srand(1);

	int array[SIZE];

	fillArrayRandomly(array, 5, 10);
	//printArray(array);
	//sortBubble(array); // +-0.005 1000 // +-0.731 10000 // +-67.536 100000
	//sortShaker(array); // +-0.004 1000 // +-0.511 10000 // +-43.964 100000
	//printArray(array);

	double duration = (clock() - start) / double(CLOCKS_PER_SEC);
	cout << duration << "\n";

	return 0;
}