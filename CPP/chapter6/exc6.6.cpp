#include <iostream>
using namespace std;

class PointerClass {
	int number;
	int* pointer;
public:
	friend istream& operator >>(istream& s, PointerClass& pc);
	friend ostream& operator <<(ostream& s, PointerClass& pc);
};

int main() {
	PointerClass p;
	cout << "input an object..." << endl;
	cin >> p;
	cout << "You have input an object" << p;

	return 0;
}

istream& operator >>(istream& s, PointerClass& pc)
{
	s >> pc.number;
	pc.pointer = &(pc.number);
	return s;
}
ostream& operator <<(ostream& s, PointerClass& pc)
{
	cout << "print PointerClass : ";
	s <<pc.number <<", "<< pc.pointer <<", "<<*(pc.pointer)<<endl;
	return s;
}