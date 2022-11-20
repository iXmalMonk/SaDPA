#ifndef _TREE_H
#define _TREE_H

#include "Table.h"

struct Tree
{
	char word[SIZE];
	int id;
	Tree* left, * right;
};

struct T
{
	Tree* tree = NULL;
	int size = 0;
};

//Tree* treeN(T& t, int id);

Tree* treeNew(T& t, int id);

Tree* treeInsert(T& t, Tree* tree, int id);

//void treeTakeIds(Tree* tree, int id, int* temp);

Tree* treeRemove(T& t, Tree* tree, int id);

/*
 * NOT NULL - FOUNDED / NULL - NOT FOUNDED
 */
Tree* treeSearch(Tree* tree, int id);

void treePrint(Tree* tree);

//void treeDelete(Tree* tree);

Tree* treeDel(T& t, Tree* tree);

#endif
