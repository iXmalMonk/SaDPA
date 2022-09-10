#include<iostream>

#define CHAR_SIZE 16
#define SIZE 5
#define STUDENTS 10

struct Student
{
	float grade[SIZE];
	float number;
	char surname[CHAR_SIZE];
};

struct Data
{
	char subject[SIZE][CHAR_SIZE];
	Student student[STUDENTS];
};

void createDataFromTxt(Data &data, const char *filename)
{
	FILE* txt;

	if (fopen_s(&txt, filename, "rt") != 0) exit(1);

	for (int i = 0; i < SIZE; i++)
		fscanf_s(txt, "%s", data.subject[i], CHAR_SIZE);

	for (int i = 0; i < 10; i++)
	{
		fscanf_s(txt, "%s%f", data.student[i].surname, CHAR_SIZE, &data.student[i].number);
		for (int j = 0; j < SIZE; j++)
			fscanf_s(txt, "%f", &data.student[i].grade[j]);
	}
	
	fclose(txt);
}

void printData(Data data)
{
	printf("   Фамилия № зач. кн.\t");

	for (int i = 0; i < SIZE; i++)
		printf("%s\t", data.subject[i]);

	printf("\n");

	for (int i = 0; i < STUDENTS; i++)
	{
		printf("%10s %.2f\t", data.student[i].surname, data.student[i].number);
		for (int j = 0; j < SIZE; j++)
			printf("%.1f\t", data.student[i].grade[j]);
		printf("\n");
	}
}

int main()
{
	system("chcp 1251");
	system("cls");

	Data data;

	createDataFromTxt(data, "data.txt");

	printData(data);

	return 0;
}