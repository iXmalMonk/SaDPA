#include "HashTable.h"

HashTable::HashTable(int size)
{
	this->count = 0;
	this->size = size;
	this->data = new Data * [this->size];

	for (int i = 0; i < this->size; i++)
		this->data[i] = nullptr;
}

HashTable::~HashTable()
{
	for (int i = 0; i < this->size; i++)
		if (this->data[i] != nullptr)
		{
			delete this->data[i];
			this->data[i] = nullptr;
		}

	this->count = 0;
	this->size = 0;
	delete[] this->data;
	this->data = nullptr;
}

int HashTable::hash(int key)
{
	return key % this->size;
}

void HashTable::insert(int key, int value)
{
	if (this->count == this->size)
	{
		cout << "Hash table is full\n";
		return;
	}

	int hashIndex = hash(key);

	while (data[hashIndex] != nullptr)
		hashIndex = (hashIndex + 1) % this->size;

	this->data[hashIndex] = new Data;
	this->data[hashIndex]->key = key;
	this->data[hashIndex]->value = value;

	this->count++;
}

int HashTable::get(int key)
{
	if (this->count == 0)
	{
		cout << "Hash table is empty\n";
		return INT_MIN;
	}

	int hashIndex = hash(key);
	int temporary = hashIndex;

	while (true)
	{
		if (this->data[hashIndex] == nullptr)
			hashIndex = (hashIndex + 1) % this->size;
		else if (this->data[hashIndex]->key != key)
			hashIndex = (hashIndex + 1) % this->size;
		else
			break;

		if (hashIndex == temporary)
		{
			temporary = -1;
			break;
		}
	}

	if (temporary == -1)
	{
		cout << "Key not found\n";
		return INT_MIN;
	}
	else
		return this->data[hashIndex]->value;
}

void HashTable::remove(int key)
{
	if (this->count == 0)
	{
		cout << "Hash table is empty\n";
		return;
	}

	int hashIndex = hash(key);
	int temporary = hashIndex;

	while (true)
	{
		if (this->data[hashIndex] == nullptr)
			hashIndex = (hashIndex + 1) % this->size;
		else if (this->data[hashIndex]->key != key)
			hashIndex = (hashIndex + 1) % this->size;
		else
			break;

		if (hashIndex == temporary)
		{
			temporary = -1;
			break;
		}
	}

	if (temporary == -1)
		cout << "Key not found\n";
	else
	{
		delete this->data[hashIndex];
		this->data[hashIndex] = nullptr;
		this->count--;
	}
}

void HashTable::display()
{
	for (int i = 0; i < this->size; i++)
		if (this->data[i] != nullptr)
			cout << "HT [" << i << "] key: " << this->data[i]->key << " value: " << this->data[i]->value << endl;
}
