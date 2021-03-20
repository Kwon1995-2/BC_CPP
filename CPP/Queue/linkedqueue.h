#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#pragma warning(disable:4290)
#include "RuntimeException.h"

/////////////////////////////////////////////////////////////////////////////////////

typedef string Elem;			// 원소 타입
class CNode						// 환형 연결 리스트 노드
{
private:
	Elem elem;					// 연결 리스트 원소 값
	CNode* next;				// 리스트의 다음 엔트리
	friend class CircleList;	// CircleList에게 접근 허용
};

class CircleList				// 환형 연결 리스트
{
public:
	CircleList();				// 생성자
	~CircleList();				// 소멸자
	bool empty() const;			// 비었나?
	const Elem& front() const;	// 커서 다음의 원소
	const Elem& back() const;	// 커서의 원소
	void advance();				// 커서를 다음으로 이동
	void add(const Elem& e);	// 커서 뒤에 추가
	void remove();				// 커서의 다음 노드 삭제
private:
	CNode* cursor;				// 커서
};

CircleList::CircleList() :cursor(NULL) {}
CircleList::~CircleList() { while (!empty()) remove(); }
bool CircleList::empty() const { return cursor == NULL; }
const Elem& CircleList::back() const { return cursor->elem; }
const Elem& CircleList::front() const { return cursor->next->elem; }
void CircleList::advance() { cursor = cursor->next; }
void CircleList::add(const Elem& e)
{
	CNode* v = new CNode;
	v->elem = e;
	if (cursor == NULL)
	{
		v->next = v;
		cursor = v;
	}
	else
	{
		v->next = cursor->next;
		cursor->next = v;
	}
}
void CircleList::remove()
{
	CNode* old = cursor->next;
	if (old == cursor)
		cursor = NULL;
	else
		cursor->next = old->next;
	delete old;
}
/////////////////////////////////////////////////////////////////////////////////////

class LinkedQueue
{
public:
	LinkedQueue() :C(), n(0) {}
	int size() const { return n; }
	bool empty() const { return n == 0; }
	const Elem& front() const throw(QueueEmpty) {
		if (empty()) throw QueueEmpty("front of empty queue");
			return C.front();
	}
	void enqueue(Elem e) {
		C.add(e);
		C.advance();
		n++;
	}
	void dequeue() throw(QueueEmpty) {
		if (empty()) throw QueueEmpty("dequeue from empty queue");
			C.remove();
		n--;
	}
private:
	CircleList C;
	int n;
};

#endif