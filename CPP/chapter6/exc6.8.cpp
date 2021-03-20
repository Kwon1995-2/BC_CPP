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
	Complex two;
	Complex* three;
	Complex* four;
public:
	Triplet();
	~Triplet() {};
	Triplet(const Triplet& src);
	Triplet& operator=(const Triplet& src); //void로 해도 작동함
};
Triplet::Triplet()
{
	one.real = 1;
	one.imag = 2;
	two.real = 3;
	two.imag = 4;
	//three = new Complex
	three = &one;
	four = &two;
	cout << "Default" << endl;
}

Triplet::Triplet(const Triplet& src) {
	one = src.one;
	//one.imag = src.one.imag;
	two = src.two;
	//two.imag = src.two.imag;
	//three = new Complex
	//*three = *(src.three);
	//three = src.three -> deep copy가 안됨
	three = &one;
	four = &two;
	cout << "Copy Constructor" << endl;
}
Triplet& Triplet::operator=(const Triplet& src) {
	one = src.one;
	//one.imag = src.one.imag;
	two = src.two;
	//two.imag = src.two.imag;
	//three = new Complex
	//*three = *(src.three);
	three = &one;
	four = &two;
	cout << "Assignment Operator Overloading" << endl;
	return (*this);
}
Triplet PrintTriplet(Triplet t) {
	return t;
}
int main(void)
{
	Triplet t1;
	Triplet t2 = t1;
	Triplet t3 = PrintTriplet(t1);
	t2 = PrintTriplet(t3);
}