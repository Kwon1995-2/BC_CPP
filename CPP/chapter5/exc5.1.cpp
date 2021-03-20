#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person {
	//const 
	char* name;
public:
	Person(char* n) :name(n) {} //const char* n
	Person() { name = NULL; }
	int operator==(const Person& p) const {
		return strcmp(name, p.name);
	}
	const char* Name() { return name; }

	Person& operator=(const Person& source) {
		name = new char[10];
		strcpy(name, source.name);
		return *this;
	}
};
class Queue {
	Person line[20];
	int number;
public:
	Queue() {
		number = 0;
	}
	void Push(Person p);
	Person Pop();
	int Number();

	friend ostream& operator<<(ostream& os, Queue& q);
	friend istream& operator>>(istream& is, Queue& q);

	Queue& operator=(const Queue& source);
	int operator==(Queue q2);
};
void Queue::Push(Person p) {
	if (number >= 20) {
		cout << "Queue is Full" << endl;
		return;
	}
	line[number] = p;
	number++;
	cout << p.Name() << " has joined the Queue" << endl;
}
Person Queue::Pop() {
	if (number <= 0) {
		cout << "Queue is Empty" << endl;
		return NULL;
	}
	Person p = line[0];
	for (int i = 0; i < number; i++)
	{
		line[i - 1] = line[i];
	}
	number--;
	cout << p.Name() << " has left the Queue" << endl;
	return p;
}
int Queue::Number() {
	return number;
}

int main(void)
{
	/*Queue q;
	cout << "queue에 있는 사람은 " << q.Number() << "명 입니다." << endl << endl;
	q.Push(Person((char*)"홍길동"));
	q.Push(Person((char*)"사임당"));
	q.Push(Person((char*)"류성룡"));
	q.Push(Person((char*)"정약용"));
	cout << "queue에 있는 사람은 " << q.Number() << "명 입니다." << endl << endl;

	q.Pop();
	cout << "queue에 있는 사람은 " << q.Number() << "명 입니다." << endl << endl;

	q.Push(Person((char*)"홍대용"));

	cout << "모든 사람이 queue에서 나갑니다." << endl << endl;
	while (q.Number() > 0) {
		q.Pop();
		cout << "queue에 있는 사람은 " << q.Number() << "명 입니다." << endl << endl;
	}

	Queue* pq = &q;
	(*pq).Push(Person((char*)"홍경래"));
	cout << "queue에 있는 사람은 " << (*pq).Number() << "명 입니다." << endl << endl;

	(*pq).Pop();*/

	//system("pause");

	Queue q1, q2;
	Person p1((char*)"Kim");
	q1.Push(p1);
	q1.Pop();
	//cout << q1;

	cout << "Insert three persons's name" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> q1;
	}
	cout << q1;
	return 0;
	q2 = q1;
	if (q1 == q2)
		cout << "q1 and q2 are identical" << endl;
	else
		cout << "q1 and q2 are different" << endl;

	q1.Pop();
	q1.Pop();
	q1.Pop();

	cout << q2;
}//return 시 오류 발생
ostream& operator<<(ostream& os, Queue& q) {
	os << endl << "##Queue Status: ";
	for (int i = 0; i < q.number; i++) {
		os << q.line[i].Name() << "-";
	}
	os << "END" << endl << endl;
	return os;
}
istream& operator>>(istream& is, Queue& q) {
	char* buf = new char[10];
	is >> buf;
	Person p1(buf);
	q.Push(p1);
	return is;
}
Queue& Queue::operator=(const Queue& source) {
	number = source.number; //1

	for (int i = 0; i < source.number; i++) { //2
		line[i] = source.line[i];
	}
	return *this;
}
int Queue:: operator==(Queue q2) {
	if (number != q2.number) return 0;

	for (int i = 0; i < number; i++) {
		if (line[i] == q2.line[i]) {
			cout << "different" << endl;
			return 0; //1이면 다르다.
		}
	}
	return 1; 
}


