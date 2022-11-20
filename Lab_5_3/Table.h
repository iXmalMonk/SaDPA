#ifndef _TABLE_H
#define _TABLE_H

#define SIZE 16

struct Table
{
	char** words = NULL;
	int** line_number = NULL;
	int* size_line_number = NULL;
	int* id = NULL;
	int size;
};

void createTable(Table& table, const char* filename);
void deleteTable(Table& table);

#endif
