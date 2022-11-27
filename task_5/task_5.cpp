#include "Tree.h"

int main()
{
	Tree t(50);

	//Tree t;
	//t.insert(50);

	t.insert(30);
	t.insert(20);
	t.insert(40);
	t.insert(70);
	t.insert(60);
	t.insert(80);

	//t.clear();

	t.inorder();
	t.preorder();
	t.postorder();
	t.search(30);

	t.remove(30);

	t.inorder();
	t.preorder();
	t.postorder();
	t.search(30);

	cout << t.findMin() << endl;
	cout << t.findMax() << endl;

	return 0;
}