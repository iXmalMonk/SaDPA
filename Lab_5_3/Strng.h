#ifndef _STRNG_H
#define _STRNG_H

#include <iostream>
#include <string>

using namespace std;

struct Strng
{
	string* strng;
	int size = 0;
};

void createStrng(Strng& strng, const char* filename);
void deleteStrng(Strng& strng);

int theNumberOfOccurrencesOfTheWord(Strng strng, int si, Table table, int ti);

#endif
