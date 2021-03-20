#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#pragma warning(disable:4290)
#include "RuntimeException.h"

template <typename E>
class ArrayStack
{
	enum { DEF_CAPACITY = 100 };
public:
	ArrayStack(int cap = DEF_CAPACITY);
	int size() const;
	bool empty() const;
	const E& top() const throw(StackEmpty);
	void push(const E& e) throw(StackFull);
	void pop() throw(StackEmpty);
private:
	E* S;
	int capacity;
	int t;
};

template <typename E> ArrayStack<E>::ArrayStack(int cap)
	:S(new E[cap]), capacity(cap), t(-1) {}	// 디폴트 용량을 갖는 생성자

template <typename E> int ArrayStack<E>::size() const
{ return (t + 1); }

template <typename E> bool ArrayStack<E>::empty() const
{ return (t < 0); }

template <typename E> const E& ArrayStack<E>::top() const throw(StackEmpty)
{
	if (empty()) throw StackEmpty("Stack is Empty!");
	return S[t];
}

template <typename E> void ArrayStack<E>::push(const E& e) throw(StackFull)
{
	if (size() == capacity) throw StackFull("Stack is Full!");
	S[++t] = e;
}

template <typename E> void ArrayStack<E>::pop() throw(StackEmpty)
{
	if (empty()) throw StackEmpty("Stack is Empty!");
	t--;
}
#endif