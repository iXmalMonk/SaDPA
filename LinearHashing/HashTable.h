#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <iostream>

using namespace std;

class HashTable
{
private:
	struct Data
	{
		int key;
		int value;
	};

	Data** data;
	int size;
	int count;

	int hash(int key);
public:
	HashTable(int size);
	~HashTable();

	//

	void insert(int key, int value);
	int get(int key);
	void remove(int key);
	void display();
};

#endif 