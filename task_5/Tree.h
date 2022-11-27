#ifndef _TREE_H
#define _TREE_H

#include <iostream>

using namespace std;

class Tree
{
private:
	struct Node
	{
		int key;
		Node* left, * right;
	};

	Node* root;

public:
	Tree();
	Tree(int rootKey);
	~Tree();

	void insert(int key);
	void remove(int key);

	void inorder();
	void preorder();
	void postorder();

	void search(int key);

	// if 2147483647 - error
	int findMin();
	// if -2147483648 - error
	int findMax();

	void clear();

private:
	Node* minNode(Node* node);
	Node* maxNode(Node* node);

	Node* insert(Node* node, int key);
	Node* remove(Node* node, int key);

	void inorder(Node* node);
	void preorder(Node* node);
	void postorder(Node* node);

	Node* search(Node* node, int key);

	int findMin(Node* node);
	int findMax(Node* node);

	void clear(Node* node);
};

#endif
