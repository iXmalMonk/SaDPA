#include <iostream>

using namespace std;

#define FULL_NAME_SIZE 32

struct Table
{
	char** full_name = NULL;
	int* number = NULL;
	int size = 0;
};

void createTable(Table& table)
{
	FILE* file;

	if (fopen_s(&file, "table.txt", "rt") != 0) exit(1);

	fscanf_s(file, "%i", &table.size);

	table.full_name = (char**)malloc(sizeof(char*) * table.size);
	table.number = (int*)malloc(sizeof(int) * table.size);

	for (int i = 0; i < table.size; i++)
	{
		table.full_name[i] = (char*)malloc(sizeof(char) * FULL_NAME_SIZE);
		int index = 0;

		for (int j = 0; j < 3; j++)
		{
			char temp[FULL_NAME_SIZE];
			fscanf_s(file, "%s", temp, FULL_NAME_SIZE);

			for (int k = 0; temp[k] != '\0'; k++)
				table.full_name[i][index++] = temp[k];

			if (j == 2) table.full_name[i][index++] = '\0';
			else table.full_name[i][index++] = ' ';
		}

		fscanf_s(file, "%i", &table.number[i]);
		//printf("%s %i\n", table.full_name[i], table.number[i]);
	}
}

void printTable(const Table& table)
{
	for (int i = 0; i < table.size; i++)
		printf("%s %i\n", table.full_name[i], table.number[i]);
	printf("\n");
}

void deleteTable(Table& table)
{
	for (int i = 0; i < table.size; i++)
		free(table.full_name[i]);

	free(table.full_name);

	free(table.number);

	table.size = 0;

	table.number = NULL;

	table.full_name = NULL;
}

// O(N^2)
void bubbleSortTable(Table& table)
{
	for (int i = 0; i < table.size; i++)
		for(int j = i; j < table.size - 1; j++)
			if (table.number[j] > table.number[j + 1])
			{
				int temp_int = table.number[j];
				table.number[j] = table.number[j + 1];
				table.number[j + 1] = temp_int;

				char* temp_char = table.full_name[j];
				table.full_name[j] = table.full_name[j + 1];
				table.full_name[j + 1] = temp_char;
			}
}

// O(N)
void shakerSortTable(Table& table)
{
	bool flag = true;
	int left = 1;
	int right = table.size - 1;

	do {
		flag = true;

		for (int i = left; i <= right; i++)
			if (table.number[i - 1] > table.number[i])
			{
				int temp_int = table.number[i];
				table.number[i] = table.number[i - 1];
				table.number[i - 1] = temp_int;

				char* temp_char = table.full_name[i];
				table.full_name[i] = table.full_name[i - 1];
				table.full_name[i - 1] = temp_char;
				flag = false;
			}

		right--;

		for (int i = right; i >= left; i--)
			if (table.number[i - 1] > table.number[i])
			{
				int temp_int = table.number[i];
				table.number[i] = table.number[i - 1];
				table.number[i - 1] = temp_int;

				char* temp_char = table.full_name[i];
				table.full_name[i] = table.full_name[i - 1];
				table.full_name[i - 1] = temp_char;
				flag = false;
			}

		left++;

	} while (flag == false);
}

int main()
{
	system("chcp 1251");
	system("cls");

	Table table;

	createTable(table);

	printTable(table);
	//bubbleSortTable(table);
	shakerSortTable(table);
	printTable(table);

	deleteTable(table);

	return 0;
}