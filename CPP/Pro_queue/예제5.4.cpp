#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int>myqueue;

	myqueue.push(5);
	myqueue.push(3);
	myqueue.push(4);
	cout << "front : " << myqueue.front() << endl;
	cout << "size : " << myqueue.size() << endl;
	myqueue.pop();
	myqueue.push(7);
	myqueue.pop();
	cout << "front : " << myqueue.front() << endl;
	myqueue.pop();
	//myqueue.pop();
	cout << "empty : " << myqueue.empty() << endl;

	//queue�� ����µ� pop, front�� �õ��ϸ� error�� ��
}