#include <iostream>

using namespace std;

class A {
public:
	A() {}
	void print()
	{
		cout << "A::print()" << endl;
	}
	virtual void printV()
	{
		cout << "A::printV()" << endl;
	}

	virtual void printPV() = 0;
};

class B : public A {
public:
	B() {}
	void print()
	{
		cout << "B::print()" << endl;
	}
	void printV()
	{
		cout << "B::printV()" << endl;
	}

	void printPV()
	{
		cout << "B::printPV()" << endl;
	}
};

int main()
{
	A* a = new B;

	a->print();

	a->printV();

	a->printPV();


	system("pause");
	return 1;
}