#include <iostream>

using namespace std;

struct Tree
{
	int** data = NULL;
	int vertex = 0;
};

void treeInitialization(Tree& tree)
{
	if (tree.data == NULL)
	{
		cout << "How many vertex: ";
		cin >> tree.vertex;

		tree.data = (int**)malloc(sizeof(int*) * tree.vertex);

		for (int i = 0; i < tree.vertex; i++)
			tree.data[i] = (int*)malloc(sizeof(int) * tree.vertex);

		for (int i = 0; i < tree.vertex; i++)
			for (int j = 0; j < tree.vertex; j++)
				tree.data[i][j] = 0;
	}
}

void treeDeinitialization(Tree& tree)
{
	if (tree.data != NULL)
	{
		for (int i = 0; i < tree.vertex; i++)
			free(tree.data[i]);

		free(tree.data);

		tree.data = NULL;

		tree.vertex = 0;
	}
}

void printTree(const Tree& tree)
{
	cout << "   ";
	for (int i = 0; i < tree.vertex; i++)
		printf("%2i ", i + 1); //cout << i + 1 << " ";
	cout << "\n";

	for (int i = 0; i < tree.vertex; i++)
	{
		printf("%2i ", i + 1); //cout << i + 1 << " ";
		for (int j = 0; j < tree.vertex; j++)
			printf("%2i ", tree.data[i][j]); //cout << tree.data[i][j] << " ";
		cout << "\n";
	}
}

void createTree(Tree& tree)
{
	int n = 0;

	for (int i = 0; i < tree.vertex; i++)
		for (int j = i + 1; j < tree.vertex; j++)
		{
			do
			{
				cout << i + 1 << " -> " << j + 1 << " = ";
				cin >> n;
			} while (n < 0 or n > 1);

			tree.data[i][j] = n;
			tree.data[j][i] = tree.data[i][j];
		}
}

void deleteTree(Tree& tree)
{
	for (int i = 0; i < tree.vertex; i++)
		for (int j = 0; j < tree.vertex; j++)
			tree.data[i][j] = 0;
}

void findLoopInTree(const Tree& tree)
{
	bool flag = false;
	int first_vertex = 0;

	for (int j = 2; j < tree.vertex; j++)
	{
		bool first_flag = false;
		bool second_flag = true;

		for (int k = 0; k < j; k++)
		{
			if (first_flag)
				if (tree.data[k][j] == 1)
				{
					if (second_flag)
					{
						cout << first_vertex + 1 << " -> " << j + 1 << "\n";
						second_flag = false;
						flag = true;
					}

					cout << k + 1 << " -> " << j + 1 << "\n";
				}

			if (tree.data[k][j] == 1 and !first_flag)
			{
				first_flag = true;
				first_vertex = k;
			}
		}
	}

	if (flag) cout << "Loop found\n";
	else cout << "Loop not found\n";
}

int main()
{
	system("chcp 1251");
	system("cls");

	Tree tree;

	treeInitialization(tree);
	createTree(tree);
	printTree(tree);
	findLoopInTree(tree);
	//deleteTree(tree);
	//printTree(tree);
	treeDeinitialization(tree);

	return 0;
}