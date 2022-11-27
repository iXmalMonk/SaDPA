#include "Tree.h"

Tree::Tree()
{
	this->root = nullptr;
};

Tree::Tree(int rootKey)
{
	this->root = new Node;
	this->root->key = rootKey;
	this->root->left = nullptr;
	this->root->right = nullptr;
};

Tree::~Tree()
{
	this->clear(this->root);
};

void Tree::insert(int key)
{
	this->root = insert(this->root, key);
};

void Tree::remove(int key)
{
	this->root = this->remove(this->root, key);
};

void Tree::inorder()
{
	if (this->root != nullptr)
	{
		this->inorder(this->root);
		cout << "\n";
	}
};

void Tree::preorder()
{
	if (this->root != nullptr)
	{
		this->preorder(this->root);
		cout << "\n";
	}
};

void Tree::postorder()
{
	if (this->root != nullptr)
	{
		this->postorder(this->root);
		cout << "\n";
	}
};

void Tree::search(int key)
{
	if (this->search(this->root, key))
		cout << key << " found\n";
	else
		cout << key << " not found\n";
};

int Tree::findMin()
{
	return this->findMin(this->root);
};

int Tree::findMax()
{
	return this->findMax(this->root);
};

void Tree::clear()
{
	this->clear(this->root);
}

Tree::Node* Tree::minNode(Tree::Node* node)
{
	Node* temporary = node;

	while (temporary != nullptr and temporary->left != nullptr)
		temporary = temporary->left;

	return temporary;
}

Tree::Node* Tree::maxNode(Tree::Node* node)
{
	Node* temporary = node;

	while (temporary != nullptr and temporary->right != nullptr)
		temporary = temporary->right;

	return temporary;
}

Tree::Node* Tree::insert(Tree::Node* node, int key)
{
	if (node == nullptr)
	{
		node = new Node;
		node->key = key;
		node->left = nullptr;
		node->right = nullptr;
	}
	else if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
};

Tree::Node* Tree::remove(Tree::Node* node, int key)
{
	if (node == nullptr)
		return node;
	else if (node->key > key)
		node->left = remove(node->left, key);
	else if (node->key < key)
		node->right = remove(node->right, key);
	else
	{
		if (node->left == nullptr and root->right == nullptr)
		{
			return nullptr;
		}
		else if (node->left == nullptr)
		{
			Node* temporary = node->right;
			delete node;
			return temporary;
		}
		else if (node->right == nullptr)
		{
			Node* temporary = node->left;
			delete node;
			return temporary;
		}
		else
		{
			Node* temporary = minNode(node->right);
			node->key = temporary->key;
			node->right = remove(node->right, temporary->key);
		}
	}

	return node;
};

void Tree::inorder(Tree::Node* node)
{
	if (node != nullptr)
	{
		inorder(node->left);
		cout << node->key << " ";
		inorder(node->right);
	}
};

void Tree::preorder(Tree::Node* node)
{
	if (node != nullptr)
	{
		cout << node->key << " ";
		preorder(node->left);
		preorder(node->right);
	}
};

void Tree::postorder(Tree::Node* node)
{
	if (node != nullptr)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->key << " ";
	}
};

Tree::Node* Tree::search(Tree::Node* node, int key)
{
	if (node == nullptr or node->key == key)
		return node;

	if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
};

int Tree::findMin(Tree::Node* node)
{
	if (node == nullptr)
		return INT_MAX;

	int temporary = node->key;
	int temporaryLeft = findMin(node->left);
	int temporaryRight = findMin(node->right);

	if (temporaryLeft < temporary)
		temporary = temporaryLeft;

	if (temporaryRight < temporary)
		temporary = temporaryRight;

	return temporary;
};

int Tree::findMax(Tree::Node* node)
{
	if (node == nullptr)
		return INT_MIN;

	int temporary = node->key;
	int temporaryLeft = findMax(node->left);
	int temporaryRight = findMax(node->right);

	if (temporaryLeft > temporary)
		temporary = temporaryLeft;

	if (temporaryRight > temporary)
		temporary = temporaryRight;

	return temporary;
};

void Tree::clear(Tree::Node* node)
{
	if (node != nullptr)
	{
		clear(node->left);
		clear(node->right);
		delete node;
		this->root = nullptr;
	}
};
