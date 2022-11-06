#include <iostream>

#define _SIZE 30

//const int _SIZE = 30;

void fillArray(int* array)
{
	for (int i = 0; i < _SIZE; i++)
		array[i] = i + 1;
}

void printArray(const int* array)
{
	for (int i = 0; i < _SIZE; i++)
		printf("%i ", array[i]);
	printf("\n");
}

int firstMethodFindNumber(const int* array, int number)
{
	for (int i = 0; i < _SIZE; i++)
		if (number == array[i]) return i;
	return -1;
}

int secondMethodFindNumber(const int* array, int number)
{
	if (_SIZE % 2 != 0 and array[_SIZE - 1] == number) return _SIZE - 1;

	for (int i = 0; i < _SIZE / 2; i++)
		if (number == array[i]) return i;
		else if (number == array[i + _SIZE / 2]) return i + _SIZE / 2;

	return -1;
}

int thirdMethodFindNumber(const int* array, int number)
{
	int left = 0;
	int right = _SIZE - 1;
	int middle;

	bool flag = false;

	while (left <= right and flag != true)
	{
		middle = (left + right) / 2;

		if (array[middle] == number) flag = true;
		if (array[middle] > number) right = middle - 1;
		else left = middle + 1;
	}

	if (flag) return middle;

	return -1;
}

int main()
{
	system("chcp 1251");
	system("cls");

	int array[_SIZE] = { 0 };

	fillArray(array);

	//printArray(array);

	int number = _SIZE;

	//if (firstMethodFindNumber(array, number) != -1)
	//	printf("1 - The number %i is at index %i", number, firstMethodFindNumber(array, number));
	//else
	//	printf("1 - The number %i not found", number);

	//if (secondMethodFindNumber(array, number) != -1)
	//	printf("2 - The number %i is at index %i", number, secondMethodFindNumber(array, number));
	//else
	//	printf("2 - The number %i not found", number);

	if (thirdMethodFindNumber(array, number) != -1)
		printf("3 - The number %i is at index %i", number, thirdMethodFindNumber(array, number));
	else
		printf("3 - The number %i not found", number);

	return 0;
}