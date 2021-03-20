#include <iostream>
using namespace std;

class Complex {
	friend class Triplet;
	float real;
	float imag;
public:
	Complex() :real(NULL), imag(NULL) {};
	~Complex() {};
};
class Triplet {
	Complex one;
	Complex* two;
public:
	Triplet();
	~Triplet() {};
	Triplet(const Triplet& src);
};
Triplet::Triplet()
{
	one.real = 1;
	one.imag = 2;
	two = &one;
}
Triplet::Triplet(const Triplet& src)
{
	one.real = src.one.real;
	one.imag = src.one.imag;
	two = &one;
}
Triplet PrintTriplet(Triplet t)
{
	return t;
}

int main(void) {
	Triplet t1; // 객체 선언 -> 생성자 호출
	Triplet t2 = t1;
	Triplet t3 = PrintTriplet(t1);
	t2 = PrintTriplet(t3);

	return 1;
}