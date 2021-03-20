#include <iostream>
#include <queue>
#include <exception>

using namespace std;

int main()
{
	queue<int> myqueue;

	myqueue.push(5);
	myqueue.push(3);
	myqueue.pop();
	myqueue.push(7);
	myqueue.pop();
	myqueue.pop();
	cout << "front : " << myqueue.front() << endl;

	return 1;
}