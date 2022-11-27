#include "HashTable.h"

int main()
{
	HashTable ht(10);

	ht.insert(34852, 1);
	ht.insert(56775, 2);
	ht.insert(63246, 3);
	ht.insert(65321, 4);
	ht.insert(99123, 5);
	ht.insert(42148, 6);
	ht.insert(45792, 7);
	ht.insert(61275, 8);
	ht.insert(99117, 9);

	ht.display();

	return 0;
}