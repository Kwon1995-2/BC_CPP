#include <iostream>
using namespace std;

class A {
public:
	int data;
	//A() { cout << "A������" << endl; }
	virtual ~A() { cout << "A�Ҹ���" << endl; }
};
class B : public A {
public:
	int data;
	//B() { cout << "B������" << endl; }
	~B() { cout << "B�Ҹ���" << endl; }
};
class C : public B {
public:
	//C() { cout << "C������" << endl; }
	~C() { cout << "C�Ҹ���" << endl; }

};

int main() {

	A* a[3];
	a[0] = new A;
	a[1] = new B;
	a[2] = new C;

	for (int i = 0; i < 3;i++) { delete a[i]; }
	//virtual�� ������ ~A �� ȣ��
	return 0;
}