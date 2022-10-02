#include<iostream>

#define SIZE_STRING 1024
#define SIZE_WORD 16

struct Words {
	int size = 0;
	char** word = NULL;
};

void createStringFromTxt(char* string, const char* filename)
{
	FILE* txt;

	if (fopen_s(&txt, filename, "rt") != 0) exit(1);

	int i = 0;

	while (!feof(txt)) fscanf_s(txt, "%c", &string[i++], 1);

	string[--i] = '\0';

	fclose(txt);
}

void createWordsFromTxt(Words& words, const char* filename)
{
	FILE* txt;

	if (fopen_s(&txt, filename, "rt") != 0) exit(1);

	fscanf_s(txt, "%i", &words.size);

	words.word = (char**)malloc(sizeof(char*) * words.size);

	for (int i = 0; i < words.size; i++)
	{
		words.word[i] = (char*)malloc(sizeof(char) * SIZE_WORD);
		fscanf_s(txt, "%s", words.word[i], SIZE_WORD);
	}

	fclose(txt);
}

void deleteWords(Words& words)
{
	for (int i = 0; i < words.size; i++)
	{
		free(words.word[i]);
		words.word[i] = NULL;
	}

	free(words.word);

	words.word = NULL;

	words.size = 0;
}

void takeWord(char* string, char* tmp_word, int& pos)
{
	int j = 0;
	for (int i = pos; string[i] != '\n' and string[i] != '\0' and string[i] != ' '; i++) tmp_word[j++] = string[i];
	tmp_word[j] = '\0';
	pos += j + 1;
}

void replaceSomeWordsOnDotInString(char* string, Words words)
{
	int pos = 0;
	char tmp_word[SIZE_WORD];
	int second_pos = 0;

	for (int i = 0; string[i - 1] != '\0'; i = pos)
	{
		second_pos = i;
		takeWord(string, tmp_word, pos);
		for (int j = 0; j < words.size; j++)
			if (!strcmp(tmp_word, words.word[j])) while (string[second_pos] != ' ' and string[second_pos] != '\n' and string[second_pos] != '\0') string[second_pos++] = '.';
	}
}

void createTxtFromString(char* string,const char* filename)
{
	FILE* txt;

	if (fopen_s(&txt, filename, "wt") != 0) exit(1);

	int i = 0;

	while (string[i] != '\0') fprintf(txt, "%c", string[i++]);

	fclose(txt);
}

int main()
{
	system("chcp 1251");
	system("cls");

	Words words;
	char string[SIZE_STRING];

	createStringFromTxt(string, "string.txt");
	
	createWordsFromTxt(words, "words.txt");

	replaceSomeWordsOnDotInString(string, words);

	createTxtFromString(string, "string.txt");

	deleteWords(words);

	return 0;
}