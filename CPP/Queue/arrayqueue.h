#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#pragma warning(disable:4290)
#include "RuntimeException.h"

template <typename E>
class ArrayQueue
{
	enum { DEF_CAPACITY = 100 };
public:
	ArrayQueue(int cap = DEF_CAPACITY);
	int size() const;
	bool empty() const;
	const E& front() const throw(QueueEmpty);
	void enqueue(const E& e) throw(QueueFull);
	void dequeue() throw(QueueEmpty);
private:
	E* S;
	int capacity;
	int n;
	int f;
	int r;
};

template <typename E> ArrayQueue<E>::ArrayQueue(int cap)
	:S(new E[cap]), capacity(cap), n(0), f(0), r(0) {}	// 디폴트 용량을 갖는 생성자

template <typename E> int ArrayQueue<E>::size() const
{
	return n;
}

template <typename E> bool ArrayQueue<E>::empty() const
{
	return n == 0;
}

template <typename E> const E& ArrayQueue<E>::front() const throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Queue is Empty!");
	return S[f];
}

template <typename E> void ArrayQueue<E>::dequeue() throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Queue is Empty!");
	f = (f + 1) % capacity;
	n--;
}

template <typename E> void ArrayQueue<E>::enqueue(const E& e) throw(QueueFull)
{
	if (size() == capacity) throw QueueFull("Queue is Full!");
	S[r] = e;
	r = (r + 1) % capacity;
	n++;
}
#endif