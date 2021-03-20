#include<iostream>
using namespace std;
// constructor°¡ ¾ø´Ù.
class A {
	int a1;
protected:
	int a2;
public:
	int a3;
};
class B1 : public A {
	int b11; //default is private
};
class B2 :public A {
	int abb;
};
class C :public B1, public B2 {
	int abb;
};
class D1 :virtual public A {
	int d11;
};
class D2 :virtual public A {
	int add;
};
class E : public D1, public D2 {
	int add;
};

int main()
{
	B1 b1;
	B2 b2;
	C c;
	D1 d1;
	D2 d2;
	E e;
}
