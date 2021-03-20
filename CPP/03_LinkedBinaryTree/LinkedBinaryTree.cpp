#include <iostream>
#include "LinkedBinaryTree.h"

LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) { }            // constructor
int  LinkedBinaryTree::size() const { return n; }                       // number of nodes
bool LinkedBinaryTree::empty() const { return size() == 0; }            // is tree empty?
Position LinkedBinaryTree::root() const { return Position(_root); }     // get the root

// list of nodes
PositionList LinkedBinaryTree::positions(int order) const
{
    PositionList pl;

    if (order == 0)
        preorder(_root, pl);					// preorder traversal
    else if (order == 1)
        inorder(_root, pl);
    else
        postorder(_root, pl);
    return PositionList(pl);				// return resulting list
}

// add root to empty tree
void LinkedBinaryTree::addRoot()
{
    _root = new Node;
    n = 1;
}

// expand external node
void LinkedBinaryTree::expandExternal(const Position& p)
{
    static int val = 1;

    Node* v = p.v;					    // p's node
    v->left = new Node;					// add a new left child
    v->left->par = v;					// v is its parent
    v->left->elt = val++;

    v->right = new Node;				// and a new right child
    v->right->par = v;					// v is its parent
    v->right->elt = val++;

    n += 2;						        // two more nodes
}

// remove p and parent
Position LinkedBinaryTree::removeAboveExternal(const Position& p)
{
    Node* w = p.v;  Node* v = w->par;			// get p's node and parent
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root) {					// child of root?
        _root = sib;					// ...make sibling root
        sib->par = NULL;
    }
    else {
        Node* gpar = v->par;				// w's grandparent
        if (v == gpar->left) gpar->left = sib; 		// replace parent by sib
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w; delete v;					// delete removed nodes
    n -= 2;						// two fewer nodes
    return Position(sib);
}

// preorder traversal
void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const
{
    pl.push_back(Position(v));				// add this node
    if (v->left != NULL)					// traverse left subtree
        preorder(v->left, pl);
    if (v->right != NULL)					// traverse right subtree
        preorder(v->right, pl);
}

// inorder traversal
void LinkedBinaryTree::inorder(Node* v, PositionList& pl) const
{
    if (v->left != NULL)					// traverse left subtree
        inorder(v->left, pl);
    pl.push_back(Position(v));				// add this node
    if (v->right != NULL)					// traverse right subtree
        inorder(v->right, pl);
}

// postorder traversal
void LinkedBinaryTree::postorder(Node* v, PositionList& pl) const
{
    if (v->left != NULL)					// traverse left subtree
        postorder(v->left, pl);
    if (v->right != NULL)					// traverse right subtree
        postorder(v->right, pl);
    pl.push_back(Position(v));				// add this node
}
