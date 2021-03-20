#include <iostream>
using namespace std;

class Person {
	int pnumber;
	int* ref;
public:
	Person() :pnumber(1), ref(&pnumber) {}
	friend istream& operator>>(istream& s, Person& per);
	friend ostream& operator<<(ostream& s, Person& per);
};
class Students {
	Person men;
	Person women;
public:
	Students() {}
	friend istream& operator>>(istream& s, Students& stu);
	friend ostream& operator<<(ostream& s, Students& stu);
};
//Person overloading
istream& operator>>(istream& s, Person& per) {
	cout << "Person >>" << endl;
    s >> per.pnumber;
	return s;
}
ostream& operator<<(ostream& s, Person& per) {
	cout << "Person <<" << endl;
	s << "per.pnumber:"<<per.pnumber<<","<<"per.ref:"<< per.ref<<"," <<"*(per.ref):"<< *(per.ref)<<endl;
	return s;
}
//Students overloading
istream& operator>>(istream& s, Students& stu) {
	cout << "Students >>" << endl;
	s >> stu.men>>stu.women;
	return s;
}
ostream& operator<<(ostream& s, Students& stu) {
	cout << "Students <<" << endl;
	s << stu.men<<stu.women;
	return s;
}
int main()
{
	Students s;
	cin >> s;
	cout << s;
}