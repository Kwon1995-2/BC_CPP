#include <iostream>
using namespace std;
#define MAX 20
class Complex {
	friend class Stack;
	float real;
	float imag;
public:
	Complex(float r, float i) { real = r; imag = i; }
	Complex():real(0), imag(0) {}
	friend ostream& operator<<(ostream& s, Complex& c);
	friend istream& operator>>(istream& s, Complex& c);
};
class Stack {
	Complex line[MAX];
	int number;
public:
	Stack() { number = 0; }
	void Push(Complex p);
	Complex Pop();
	friend ostream& operator<<(ostream& s, Stack& c);
	friend istream& operator>>(istream& s, Stack& c);
};

ostream& operator<<(ostream& s, Stack& c) {
	for (int i = 0; i < c.number; i++) {
		s << c.line[i];
	}
	return s;
}
istream& operator>>(istream& s, Complex& c) {
	cout << "real : ";
	s >> c.real;
	cout << "imag : ";
	s >> c.imag;
	return s;
}
ostream& operator<<(ostream& s, Complex& c) {
	s << c.real << "^" << c.imag << ' ';
	//cout << endl;
	return s;
}
istream& operator>>(istream& s, Stack& c) {
	s >> c;
	return s;
}
void Stack:: Push(Complex p) {

	if (number >= MAX) {
		cout << "Stack Full" << endl;
		return;
	}
	line[number++] = p;
	cout << "Current Top is " << number << endl;

	//while (1) {
	//	if (line == NULL) {//line[number].real == NULL && line[number].imag == NULL
	//		*(line) = p; 
	//		break;
	//	}
	//	else {
	//		*line = *(line + 1);
	//		continue;
	//	}
	//}
}
Complex Stack:: Pop() {
	/*number = 0;
	while (1) {
		if (line[number].real != NULL && line[number].imag != NULL)
		{
			number++; 
			continue;
		}
		else {
			return line[number];
		}
	}*/

	if (number <= 0) {
		cout << "Stack is empty" << endl;
		return Complex(-1, -1);
	}
	cout << "Current Top is " << --number << endl;
	return line[number];

}

int main() {
	Stack st;
	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);
	//Complex c3;
	//cin >> c3;
	//st.Push(c3);
	
	st.Push(c1);
	st.Push(c2);
	cout <<"After push() :"<<st;
	cout << endl;
	c1 = st.Pop();
	c2 = st.Pop();
	cout << "After pop() :"<< st;
	return 0;
}