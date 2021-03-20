#include <iostream>
using namespace std;

class A {
public : 
	int data;
	A() { cout << "A생성자" << endl; }
	~A(){ cout << "A소멸자" << endl; }
};
class B : public A {
public : 
	int data;
	B() { cout << "B생성자" << endl; }
	~B() { cout << "B소멸자" << endl; }
};
class C : public B {
public :
	C() { cout << "C생성자" << endl; }
	~C() { cout << "C소멸자" << endl; }
};

int main()
{
	A* a;
	B* b = new B;
	C* c = new C;

	//a = b; b = c; //=>B*b  = new C
	a = c; 
	b = c;
	delete a;
	delete b;  //  B소멸자, A소멸자
	   // A소멸자 -> 오류(같은 인스턴스를 delete해서 오류난 것으로 추정)
	return 0;
}