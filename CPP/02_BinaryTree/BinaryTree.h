#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>

using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode
{
    friend class Tree<T>;
private:
    T data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(T _data = 0, TreeNode* _left = nullptr, TreeNode* _right = nullptr)
    {
        data = _data;
        left = _left;
        right = _right;
    }
};

template <typename T>
class Tree
{
private:
    TreeNode<T>* root;
public:
    Tree(T data = 0)
    {
        root = new TreeNode<T>(data);
    }
    // Tree 만들기
    /*
                A
            B        C
          D   E     F   G
         H   I J          K
    */
    void buildTree()
    {
        root->left = new TreeNode<T>('B',
            new TreeNode<T>('D',
                new TreeNode<T>('H')),
            new TreeNode<T>('E',
                new TreeNode<T>('I'), new TreeNode<T>('J')));
        root->right = new TreeNode<T>('C',
            new TreeNode<T>('F'),
            new TreeNode<T>('G',
                nullptr, new TreeNode<T>('K')));
    }

    TreeNode<T>* getRoot()
    {
        return root;
    }

    void visit(TreeNode<T>* current)
    {
        cout << current->data << " ";
    }

    // 전위 순회 Current - Left - Right
    void preorder(TreeNode<T>* current)
    {
        if (current == nullptr) return;

        visit(current);
        preorder(current->left);
        preorder(current->right);
    }

    // 중위 순회 Left - Current - Right
    void inorder(TreeNode<T>* current)
    {
        if (current == nullptr) return;

        inorder(current->left);
        visit(current);
        inorder(current->right);
    }

    // 후위 순회 Left - Right - Current
    void postorder(TreeNode<T>* current)
    {
        if (current == nullptr) return;

        postorder(current->left);
        postorder(current->right);
        visit(current);
    }
};

#endif