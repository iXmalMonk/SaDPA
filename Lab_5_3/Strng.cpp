#include <iostream>
#include <fstream>
#include <string>
#include "Table.h"
#include "Strng.h"

using namespace std;

void createStrng(Strng& strng, const char* filename)
{
	string temp;
	ifstream in;
	in.open(filename);

	getline(in, temp);

	strng.size = int(stoi(temp));

	strng.strng = new string[strng.size];


	int i = 0;
	if (in.is_open())
	{
		while (getline(in, temp))
		{
			//cout << temp << "\n";
			strng.strng[i++] = temp;
			cout << strng.strng[i - 1] << "\n";
		}
		in.close();
	}
}

void deleteStrng(Strng& strng)
{
	delete[] strng.strng;
	strng.size = 0;
}

int theNumberOfOccurrencesOfTheWord(Strng strng, int si, Table table, int ti)
{
	//string s = "éöó àààááá qwe àààááá";
	//string w = "àààááá";
	
	string w = table.words[ti - 1];

	int counter = 0;
	bool flag = true;

	while (flag)
	{
		int tmp = strng.strng[si].find(table.words[ti - 1]);
		if (tmp != -1)
		{
			strng.strng[si].erase(strng.strng[si].find(table.words[ti - 1]), w.size() + 1);
			counter++;
		}
		else flag = false;
	}

	return counter;
}