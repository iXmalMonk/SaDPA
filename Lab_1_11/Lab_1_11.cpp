#include<iostream>

#define CHAR_SIZE 256

void createDataFromTxt(char data[], const char* filename)
{
	FILE* txt;

	if (fopen_s(&txt, filename, "rt") != 0) exit(1);

	fscanf_s(txt, "%s", data, 256);
}

int main()
{
	system("chcp 1251");
	system("cls");

	char data[CHAR_SIZE];

	createDataFromTxt(data, "data.txt");

	printf("%s", data);

	return 0;
}