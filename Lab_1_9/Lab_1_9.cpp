#include <iostream>

#define CHAR_SIZE 1024

void createDataFromTxt(char data[], const char* filename)
{
	FILE* txt;

	int i = 0;

	if (fopen_s(&txt, filename, "rt") != 0) exit(1);

	while (!feof(txt)) fscanf_s(txt, "%c", &data[i++], 1);

	data[--i] = '\0';

	printf("%s", data);
	printf("\n");

	fclose(txt);
}

void copyString(char data[], char tmp[], int position_data)
{
	int j = 0;
	for (int i = position_data; data[i] != '\n' and data[i] != '\0'; i++) tmp[j++] = data[i];
	tmp[j] = '\0';
}

void findWordInData(char data[], char word[])
{
	char tmp[CHAR_SIZE];
	
	int position_data = 0, string = 0;

	char* pointer = NULL;

	for (int i = 0; data[i] != '\0'; i++)
	{
		if (data[i] == '\n' or data[i + 1] == '\0')
		{
			copyString(data, tmp, position_data);
			position_data = i + 1;
			pointer = strstr(tmp, word);
			if (pointer and string <= 5)
			{
				printf("%s\n", tmp);
				string++;
			}
			pointer = NULL;
		}
		if (string >= 5) break;
	}
}

int main()
{
	system("chcp 1251");
	system("cls");

	char data[CHAR_SIZE];
	char word[CHAR_SIZE];

	createDataFromTxt(data, "data.txt");

	printf("\n");

	scanf_s("%s", &word, CHAR_SIZE);

	printf("\n");

	findWordInData(data, word);

	return 0;
}