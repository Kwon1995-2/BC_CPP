/*
1. head node가 없는 경우
2. head node가 있는 경우에 구현
*/
#pragma once
//getnode, retnode
#include <iostream>
using namespace std;

template<class T> class CircularChain; //forward declaration

template<class T>
class ChainNode {
	friend class CircularChain<T>;
public:
	ChainNode(T element = 0)
	{
		data = element;
		link = 0;
	}
private:
	T data;
	ChainNode<T>* link;
};

template<class T>
class CircularChain {
public:
	CircularChain() { last = 0; };
	~CircularChain();
	void Delete(void);
	void Add(const T& element); //add a new node after last
	void InsertFront(const T& e);
	ChainNode<T>* GetNode();
	void RetNode(ChainNode<T>& x);
	//void Merge(CircularChain<T>& b);
	operator<<();
	findMax();
private:
	static ChainNode<T>* av;
	ChainNode<T>* last; //point to the last node
};

template<class T>
class CircularChainIterator {
public:
	First();
	Next();
	NotNull();
	NextNotNull();
private:
	ChainNode<T>* current;
	ChainNode<T>* last;
}

template <class T>
CircularChain<T>::~CircularChain() {}

template <class T>
void CircularChain<T>::Delete(void) //delete the last element after last
{
	ChainNode<T>* next;
	next = last->link;
	if (!last) //non-empty list
	{
		ChainNode<T>* temp = last;
		last = next;
		delete temp;
	}
	cout << "Empty List: Not deleted" << endl;
}

template <class T>
void CircularChain<T>::Add(const T& element) //add a new node after last
{
	ChainNode<T>* newnode = new ChainNode<T>(element);
	if (!last) //insert into empty list
	{
		last = newnode;
		return;
	}
	//insert a new node after last
	newnode->link = last;
	last = newnode;
}

template <class T>
void CircularChain<T>::InsertFront(const T& e)
{ //insert the element e at the 'front' of the circular list *this
  // last points to the last node in the list
	ChainNode<T>* newNode = new ChainNode<T>(e);
	if (last) { //nonempty list
		newNode->link = last->link;
		last->link = newNode;
	}
	else {//empty list
		last = newNode;
		newNode->link = newNode;
	}

}

template <class T>
ChainNode<T>* CircularChain<T>::GetNode()
{ //provide a node for use
	ChainNode<T>* x;
	if (av) { x = av, av = av->link; }
	else x = new ChainNode<t>;
	return x;
}
template <class T>
void CircularChain<T>::RetNode(ChainNode<T>& x)
{ //free the node pointed to by x
	x->link = av;
	av = x;
	x = 0;
}
/*
template <class T>
void Merge(CircularChain<T>& b)
{// a.Merge(b) produces list contains the merged result
 // coding한다.
}
*/
template <class T>
ChainNode<T>* CircularChain<T>::av = 0;
//ChainNode<T> CircularChain<T>::av = 0;//오류 발생