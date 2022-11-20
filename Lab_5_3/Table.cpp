#include <iostream>
#include "Table.h"

void createTable(Table& table, const char* filename)
{
	FILE* file;
	if (fopen_s(&file, filename, "rt") != 0) exit(1);

	fscanf_s(file, "%i", &table.size);

	table.words = (char**)malloc(sizeof(char*) * table.size);
	table.line_number = (int**)malloc(sizeof(int*) * table.size);
	table.size_line_number = (int*)malloc(sizeof(int) * table.size);
	table.id = (int*)malloc(sizeof(int) * table.size);

	for (int i = 0; i < table.size; i++)
	{
		// id
		fscanf_s(file, "%i", &table.id[i]);
		printf("%i ", table.id[i]);

		// word
		table.words[i] = (char*)malloc(sizeof(char) * SIZE);
		fscanf_s(file, "%s", table.words[i], SIZE);
		printf("%s ", table.words[i]);

		// size_line_number && line_number
		fscanf_s(file, "%i", &table.size_line_number[i]);
		table.line_number[i] = (int*)malloc(sizeof(int) * table.size_line_number[i]);

		for (int j = 0; j < table.size_line_number[i]; j++)
		{
			fscanf_s(file, "%i", &table.line_number[i][j]);
			printf("%i ", table.line_number[i][j]);
		}

		printf("\n");
	}

	fclose(file);
}

void deleteTable(Table& table)
{
	for (int i = 0; i < table.size; i++)
	{
		free(table.words[i]);
		free(table.line_number[i]);
	}

	free(table.words);
	free(table.line_number);
	free(table.size_line_number);
	free(table.id);

	table.words = NULL;
	table.line_number = NULL;
	table.size_line_number = NULL;
	table.id = NULL;
	table.size = 0;
}