#include<iostream>

#define CHAR_SIZE 256

void createDataFromTxt(char data[], const char* filename)
{
	FILE* txt;

	int i = 0;

	if (fopen_s(&txt, filename, "rt") != 0) exit(1);

	while (!feof(txt)) fscanf_s(txt, "%c", &data[i++], 1);
	data[--i] = '\0';

	fclose(txt);
}

void encryption(char data[], int cipher[])
{
	int n = 0, m = 0, k = 0;

	for (int i = 0; data[i] != '\0'; i++)
	{
		if (32 <= int(data[i]) <= 242)
		{
			m = (3 * k - 1) % 99;
			cipher[n++] = ((243 - int(data[i]) + m) % 211) + 32;
			if (n % 8 == 0) k++; // 8 if 32bit or 4 if 64bit
		}
	}
}

void printAfterEncryption(int cipher[])
{
	for (int i = 0; cipher[i] != 0; i++) printf("%c", char(cipher[i]));
}

int main()
{
	system("chcp 1251");
	system("cls");

	char data[CHAR_SIZE];
	int cipher[CHAR_SIZE] = { 0 };

	createDataFromTxt(data, "data.txt");

	encryption(data, cipher);

	printf("%s\n", data);

	printAfterEncryption(cipher);

	return 0;
}