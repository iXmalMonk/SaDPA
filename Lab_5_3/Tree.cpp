#include <iostream>
#include "Tree.h"

using namespace std;

Tree* treeN(T& t, int id)
{
	Tree* temporary = new Tree;

	temporary->id = id;
	temporary->left = NULL;
	temporary->right = NULL;

	return temporary;
}

Tree* treeNew(T& t, int id)
{
	t.size++;
	return treeN(t, id);
}

Tree* treeInsert(T& t, Tree* tree, int id)
{
	if (tree == NULL) return treeNew(t, id);

	if (id < tree->id)
		tree->left = treeInsert(t, tree->left, id);
	else
		tree->right = treeInsert(t, tree->right, id);

	return tree;
}

void treeTakeIds(Tree* tree, int id, int* temp)
{
	if (tree != NULL)
	{
		treeTakeIds(tree->left, id, temp);
		if (tree->id != id)
		{
			int i = 0;
			bool flag = true;
			while (flag)
				if (temp[i] == -1)
				{
					temp[i] = tree->id;
					flag = false;
				}
				else i++;
		}
		treeTakeIds(tree->right, id, temp);
	}
}

Tree* treeRemove(T& t, Tree* tree, int id)
{	
	t.size--;
	if (t.size != 0)
	{
		int size = t.size;
		int* temp = (int*)malloc(sizeof(int) * t.size);
		for (int i = 0; i < t.size; i++) temp[i] = -1;

		treeTakeIds(tree, id, temp);

		tree = treeDel(t, tree);

		for (int i = 0; i < size; i++)
			tree = treeInsert(t, tree, temp[i]);

		free(temp);

		return tree;
	}
	else treeDel(t, tree);
}

Tree* treeSearch(Tree* tree, int id)
{
	if (tree == NULL or tree->id == id)
		return tree;

	if (tree->id < id)
		return treeSearch(tree->right, id);

	return treeSearch(tree->left, id);
}

void treePrint(Tree* tree)
{
	if (tree != NULL)
	{
		treePrint(tree->left);
		cout << tree->id << " ";
		treePrint(tree->right);
	}
}

void treeDelete(Tree* tree)
{
	if (tree->left) treeDelete(tree->left);
	if (tree->right) treeDelete(tree->right);

	delete tree;
	tree = NULL;
}

Tree* treeDel(T& t, Tree* tree)
{
	if (tree != NULL)
	{
		treeDelete(tree);
		t.size = 0;
		return NULL;
	}
	return NULL;
}