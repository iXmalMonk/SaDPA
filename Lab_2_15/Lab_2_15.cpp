#include <iostream>

using namespace std;

#define DEFAULT true
#define FOUR false
#define FIVE false
#define SIX false

struct Array
{
	int* data = NULL;
	int size = 0;
};

void initArray(Array& array)
{
	if (DEFAULT)
	{
		do
		{
			cout << "Size of array: ";
			cin >> array.size;
		} while (array.size <= 0);

		array.data = (int*)malloc(sizeof(int) * array.size);
	}

	if (FOUR)
	{
		array.size = 4;
		array.data = (int*)malloc(sizeof(int) * array.size);
		array.data[0] = 100;
		array.data[1] = 121;
		array.data[2] = 200;
		array.data[3] = 357;
	}

	if (FIVE)
	{
		array.size = 5;
		array.data = (int*)malloc(sizeof(int) * array.size);
		array.data[0] = 342;
		array.data[1] = 455;
		array.data[2] = 653;
		array.data[3] = 234;
		array.data[4] = 523;
	}

	if (SIX)
	{
		array.size = 6;
		array.data = (int*)malloc(sizeof(int) * array.size);
		array.data[0] = 456;
		array.data[1] = 298;
		array.data[2] = 4324;
		array.data[3] = 8456;
		array.data[4] = 37298;
		array.data[5] = 80024;
	}
}

void fillArray(Array& array)
{
	if (DEFAULT)
	{
		for (int i = 0; i < array.size; i++)
			do
			{
				cout << i + 1 << " = ";
				cin >> array.data[i];
			} while (array.data[i] < 100 or array.data[i] > 1000000000);
	}
}

void printArray(const Array& array)
{
	for (int i = 0; i < array.size; i++)
		cout << array.data[i] << " ";
	cout << "\n";
}

void deInitArray(Array& array)
{
	free(array.data);
	array.data = NULL;
	array.size = 0;
}

//O(N^3)
void findUniqueNumbersWorst(const Array& array)
{
	int counter = array.size;
	int* temp = (int*)malloc(sizeof(int) * array.size);
	
	for (int i = 0; i < array.size; i++)
		temp[i] = array.data[i];

	for (int i = 0; i < array.size - 1; i++)
	{
		bool flag = true;

		for (int j = i + 1; j < array.size; j++)
			if (temp[i] % 100 == temp[j] % 100 and temp[j] != 0 and temp[i] != 0)
			{
				if (flag)
				{
					counter -= 2;
					flag = false;
					temp[j] = 0;
				}
				else
				{
					counter--;
					temp[j] = 0;
				}
			}

		if (counter == 0) break;
	}

	cout << counter << "\n";
	free(temp);
}

//O(N^2)
void findUniqueNumbersBest(const Array& array)
{
	int counter = 0;

	for (int i = 0; i < array.size; i++)
	{
		bool flag = true;
		for (int j = 0; j < array.size; j++)
		{
			if (array.data[i] % 100 == array.data[j] % 100 and i != j)
			{
				flag = false;
				break;
			}
		}

		if (flag) counter++;
	}

	cout << counter << "\n";
}

int main()
{
	system("chcp 1251");
	system("cls");

	Array array;

	initArray(array);

	fillArray(array);
	printArray(array);

	//findUniqueNumbersWorst(array);
	findUniqueNumbersBest(array);
	printArray(array);

	deInitArray(array);

	return 0;
}