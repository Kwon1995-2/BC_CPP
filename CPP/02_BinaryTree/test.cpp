#include "BinaryTree.h"

int main()
{
    Tree<char> tree('A');
    tree.buildTree();
    cout << "Preorder >> ";
    tree.preorder(tree.getRoot());
    cout << endl;

    cout << "Inorder >> ";
    tree.inorder(tree.getRoot());
    cout << endl;

    cout << "Postorder >> ";
    tree.postorder(tree.getRoot());
    cout << endl;

    return 1;
}
