#include<iostream>

#define CHAR_SIZE 16
#define SIZE 5
#define STUDENT 10

struct Student
{
	float grade[SIZE];
	float gpa;
	float number;
	char surname[CHAR_SIZE];
};

struct Data
{
	char subject[SIZE][CHAR_SIZE];
	Student student[STUDENT];
};

void createDataFromTxt(Data &data, const char *filename)
{
	FILE* txt;

	if (fopen_s(&txt, filename, "rt") != 0) exit(1);

	for (int i = 0; i < SIZE; i++)
		fscanf_s(txt, "%s", data.subject[i], CHAR_SIZE);

	for (int i = 0; i < STUDENT; i++)
	{
		fscanf_s(txt, "%s%f", data.student[i].surname, CHAR_SIZE, &data.student[i].number);
		for (int j = 0; j < SIZE; j++)
			fscanf_s(txt, "%f", &data.student[i].grade[j]);
	}
	
	fclose(txt);
}

// true - grades, false - GPA
void printData(Data data, bool mode)
{
	printf("   Фамилия № зач. кн.\t");

	if (mode)
		for (int i = 0; i < SIZE; i++)
			printf("%s\t", data.subject[i]);
	else
		printf("Средний балл");

	printf("\n");

	for (int i = 0; i < STUDENT; i++)
	{
		printf("%10s %.2f\t", data.student[i].surname, data.student[i].number);
		
		if (mode)
			for (int j = 0; j < SIZE; j++)
				printf("%.1f\t", data.student[i].grade[j]);
		else
			printf("%.1f\t", data.student[i].gpa);
		printf("\n");
	}

	printf("\n");
}

void findGPAforStudent(Data &data)
{
	for (int i = 0; i < STUDENT; i++)
	{
		double amount = 0;
		for (int j = 0; j < SIZE; j++)
			amount += data.student[i].grade[j];
		data.student[i].gpa = amount / SIZE;
	}
}

void sortDataBySurname(Data &data)
{
	for (int i = 0; i < STUDENT; i++)
		for (int j = i + 1; j < STUDENT; j++)
		{
			int n = 0;

			if (data.student[i].surname[n] == data.student[j].surname[n]) n++;

			if (data.student[i].surname[n] > data.student[j].surname[n])
			{
				Student temp = data.student[i];
				data.student[i] = data.student[j];
				data.student[j] = temp;
			}
		}
}

int main()
{
	system("chcp 1251");
	system("cls");

	Data data;

	createDataFromTxt(data, "data.txt");

	printData(data, true);

	findGPAforStudent(data);

	sortDataBySurname(data);

	printData(data, false);

	return 0;
}