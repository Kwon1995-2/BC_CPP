#ifndef _LINKEDBINARYTREE_H_
#define _LINKEDBINARYTREE_H_

#include <list>

typedef int Elem;                                           // base element type
struct Node                                                 // a node of the tree
{
    Elem elt;           					                // element value
    Node* par;	        			    	                // parent
    Node* left;		        		    	                // left child
    Node* right;			        		                // right child
    Node() : elt(), par(NULL), left(NULL), right(NULL) { }  // constructor
};

class Position                                                              // position in the tree
{
    friend class LinkedBinaryTree;			                                // give tree access
private:
    Node* v;                                                                // pointer to the node
public:
    Position(Node* _v = NULL) : v(_v) { }                                   // constructor
    Elem& operator*()       { return v->elt; }                              // get element
    Position left()   const { return Position(v->left); }                   // get left child
    Position right()  const { return Position(v->right); }                  // get right child
    Position parent() const { return Position(v->par); }                    // get parent
    bool isRoot()     const { return v->par == NULL; }                      // root of the tree?
    bool isExternal() const { return v->left == NULL && v->right == NULL; } // an external node?
    bool isInternal() const { return v->left != NULL || v->right != NULL; } // an internal node?
};
typedef std::list<Position> PositionList;                   // list of positions

class LinkedBinaryTree
{
public:
    LinkedBinaryTree();                                 // constructor
    int size() const;				                	// number of nodes
    bool empty() const;		            		    	// is tree empty?
    Position root() const;		            	    	// get the root
    PositionList positions(int order = 0) const;  		// list of nodes (order : 0:pre, 1:in, 1:post)
    void addRoot();			                	    	// add root to empty tree
    void expandExternal(const Position& p);	        	// expand external node
    Position removeAboveExternal(const Position& p);    // remove p and parent
    // housekeeping functions omitted...
protected: 			                        			// local utilities
    void preorder(Node* v, PositionList& pl) const;     // preorder utility

    // add
    void inorder(Node* v, PositionList& pl) const;      // inorder utility
    void postorder(Node* v, PositionList& pl) const;    // postorder utility
private:
    Node* _root;		                    			// pointer to the root
    int n;				                        		// number of nodes
};

#endif