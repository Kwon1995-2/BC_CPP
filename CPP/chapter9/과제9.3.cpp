#include <iostream>
using namespace std;

class A {
public:
	int data;
	//A() { cout << "A생성자" << endl; }
	virtual ~A() { cout << "A소멸자" << endl; }
};
class B : public A {
public:
	int data;
	//B() { cout << "B생성자" << endl; }
	~B() { cout << "B소멸자" << endl; }
};
class C : public B {
public:
	//C() { cout << "C생성자" << endl; }
	~C() { cout << "C소멸자" << endl; }

};

int main() {

	A* a[3];
	a[0] = new A;
	a[1] = new B;
	a[2] = new C;

	for (int i = 0; i < 3;i++) { delete a[i]; }
	//virtual이 없으면 ~A 만 호출
	return 0;
}