#include<iostream>
#include<string>
using namespace std;

class Vector {
 public:
	int r; //실수부
	int i; //허수부

	Vector() {
		r = 0; i = 0;
	}
	Vector(int a, int b) {
		r = a; i = b;
	}
	
	void setvalue(int x, int y);

	Vector operator++();
	Vector& operator++(int);
	//Vector operator<<(Vector c);
};

ostream& operator <<(ostream& s, Vector d) {
	s << d.r << "+" << d.i<<"i";
	return s;

	//cout<<d.r<<"+"<<d.i<<"i"<<endl;
	//return s;
}

istream& operator >>(istream& s, Vector& d) {
	
	s >> d.r >> d.i;
	return s;

	//int x, y;
	//cin>>x>>y;
	//d.setvalue(x,y);
}


void Vector::setvalue(int x, int y) {
	r = x; i = y;
}

Vector Vector::operator++() //전위 연산자
{
	Vector c;
	c.r = ++r; //r+1은 값이 안 나옴
	c.i = ++i;
	return c;

	// r++; i++; return *this;
}

Vector& Vector::operator++(int) //후위 연산자
{
	Vector c;
	c.r = r++;
	c.i = i++;
	return c;

	//Vector old = *this; r++; i++; return old;
}

void Print(Vector c) {
	cout << c.r << "+" << c.i << "i" << endl;
}
void Print(int n) {
	cout << n << endl;
}
void Print(const char* string) {
	cout << string << endl;
}
void Print() {
	cout << endl;
}


void main() 
{
	Vector v1(1, 2);
	Print(v1);
	Vector v2 = ++v1; 
	Print(v2);
	//v2=v2++;
	cout << v2 << endl;
	Print(v2);
	Vector v3;
	cin >> v3;
	cout << v3;

}