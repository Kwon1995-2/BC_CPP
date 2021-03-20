#include <iostream>
#include "LinkedBinaryTree.h"

using namespace std;

// Tree 만들기
void makeTree(LinkedBinaryTree& tree)
{
	tree.addRoot();

	Position root = tree.root();

	tree.expandExternal(root);

	tree.expandExternal(root.left());
	tree.expandExternal(root.right());
}

int main()
{
	LinkedBinaryTree tree;

	makeTree(tree);

	// 전위 순회
	PositionList pl1 = tree.positions(0);
	cout << "Preorder Traversal" << endl;
	for (auto list : pl1)
	{
		cout << *list << " ";
	}
	cout << endl;

	// 중위 순회
	PositionList pl2 = tree.positions(1);
	cout << "Inorder Traversal" << endl;
	for (auto list : pl2)
	{
		cout << *list << " ";
	}
	cout << endl;

	// 후위 순회
	PositionList pl3 = tree.positions(2);
	cout << "Postorder Traversal" << endl;
	for (auto list : pl3)
	{
		cout << *list << " ";
	}
	cout << endl;

	return 1;
}