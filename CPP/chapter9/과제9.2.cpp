#include <iostream>
using namespace std;

class A {
public : 
	int data;
	A() { cout << "A������" << endl; }
	~A(){ cout << "A�Ҹ���" << endl; }
};
class B : public A {
public : 
	int data;
	B() { cout << "B������" << endl; }
	~B() { cout << "B�Ҹ���" << endl; }
};
class C : public B {
public :
	C() { cout << "C������" << endl; }
	~C() { cout << "C�Ҹ���" << endl; }
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
	delete b;  //  B�Ҹ���, A�Ҹ���
	   // A�Ҹ��� -> ����(���� �ν��Ͻ��� delete�ؼ� ������ ������ ����)
	return 0;
}