#include <iostream>

#define CHAR_SIZE 32

struct User {
	char surname[CHAR_SIZE];
	char np[CHAR_SIZE];
	char number[CHAR_SIZE];
};

struct Data {
	User* user = NULL;
	int size = 0;
};

void createDataFromTxt(Data& data, const char* filename)
{
	FILE* txt;

	if (fopen_s(&txt, filename, "rt") != 0) exit(1);

	fscanf_s(txt, "%i", &data.size);

	data.user = (User*)malloc(sizeof(User) * data.size);

	for (int i = 0; i < data.size; i++)
		fscanf_s(txt, "%s%*c%s%*c%s", data.user[i].surname, CHAR_SIZE, data.user[i].np, CHAR_SIZE, data.user[i].number, CHAR_SIZE);
}

void deleteData(Data& data)
{
	free(data.user);
	data.user = NULL;
	data.size = 0;
}

void sortDataBySurname(Data& data)
{
	for (int i = 0; i < data.size; i++)
		for (int j = i + 1; j < data.size; j++)
		{
			int n = 0;

			if (data.user[i].surname[n] == data.user[j].surname[n]) n++;

			if (data.user[i].surname[n] > data.user[j].surname[n])
			{
				User tmp = data.user[i];
				data.user[i] = data.user[j];
				data.user[j] = tmp;
			}
		}
}

void printData(Data data)
{
	for (int i = 0; i < data.size; i++)
		printf("%s %s %s\n", data.user[i].surname, data.user[i].np, data.user[i].number);
}

// O(N)
void findNumberBySurnameBest(Data data, char* surname)
{
	for (int i = 0; i < data.size; i++)
		if (!strcmp(surname, data.user[i].surname))
		{
			printf("%s\n", data.user[i].number);
			return;
		}

	printf("Not found\n");
}

// O(NlogN) + 1 byte
void findNumberBySurnameMedium(Data data, char* surname)
{
	for (int i = 0; i < data.size; i++)
	{
		bool flag = true;

		for (int j = 0; surname[j] != '\0' and flag; j++)
			if (surname[j] != data.user[i].surname[j]) flag = false;

		if (flag)
		{
			printf("%s\n", data.user[i].number);
			return;
		}
	}

	printf("Not found\n");
}

// O(N^2) + size * 4 byte
void findNumberBySurnameWorst(Data data, char* surname)
{
	int* index = NULL;
	index = (int*)malloc(sizeof(int) * data.size);

	for (int i = 0; i < data.size; i++)
	{
		index[i] = -1;
		for (int j = 0; surname[j] != '\0'; j++)
		{
			if (data.user[i].surname[j] == surname[j]) index[i] = i;
			else index[i] = -1;
		}
	}

	for (int i = 0; i < data.size; i++)
		if (index[i] > -1)
		{
			printf("%s\n", data.user[i].number);
			return;
		}

	printf("Not found\n");

	free(index);
	index = NULL;
}

void selectSearchMethod(Data data, char* surname)
{
	int n = 0;
	
	do {
		printf("\n1 - Best\n2 - Medium\n3 - Worst\n\nN: ");
		scanf_s("%i", &n);
	} while (n <= 0 or n >= 4);

	switch (n)
	{
	case 1:
		findNumberBySurnameBest(data, surname);
		break;
	case 2:
		findNumberBySurnameMedium(data, surname);
		break;
	case 3:
		findNumberBySurnameWorst(data, surname);
		break;
	}
}

int main()
{
	system("chcp 1251");
	system("cls");

	Data data;
	char surname[CHAR_SIZE];

	createDataFromTxt(data, "Lab_2_7.txt");

	printData(data);

	sortDataBySurname(data);

	printf("\n");

	printData(data);

	printf("\nSurname: ");

	scanf_s("%s", surname, CHAR_SIZE);

	selectSearchMethod(data, surname);

	deleteData(data);

	return 0;
}