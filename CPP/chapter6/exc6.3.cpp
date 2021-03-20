#include <iostream>
using namespace std;
class Person {
	int p; //int p#;
	char* pname;
public:
	Person():p(1) {
		char name[] = "Kim";
		pname = name;
	}
	//friend ostream& operator<<(ostream& s, Person& _p);
	friend ostream& operator<<(ostream& s, Person* _p);
};
class Student {
	int id;
	Person *pp;
public:
	Student() :id(2) {
		pp = new Person;
	}
	~Student() {
		cout << "destructor" << endl;
		delete pp;
	}
	friend ostream& operator<<(ostream& s, Student& _s);
};

//ostream& operator<<(ostream& s, Person& _p) {
//	s << _p.p<< *(_p.pname);
//	//printf("%s", *(_p.pname));
//	return s;
//}
ostream& operator<<(ostream& s, Person* _p) {
	s << _p->p; //<< *(_p->pname);
	printf(" %s", _p->pname);
	return s;
}
ostream& operator<<(ostream& s, Student& u) {
	s << "stu_m_int id : " << u.id << endl;
	//s << "m_Person *pp : " << *(u.pp) << endl;
	s << "stu_m_Person *pp : " << u.pp << endl;
	//printf("%s\n", *(u.pp));
	//s <<u.id<<u.pp;
	return s;
}
void main() {
	//Person aa;
	Student a;
	cout << a;
}

//#include <iostream>
//using namespace std;
//class Person {
//	int p=1; //int p#;
//	char* pname;
//public:
//	Person(char* str){
//		pname = str;
//	}
//	friend ostream& operator<<(ostream& s, Person& p);
//};
//class Student {
//	int s=2;
//	Person *p;
//public:
//	Student(char* str);
//	friend ostream& operator<<(ostream& s, Student& std);
//};
//Student::Student(char* str) {
//		p = new Person(str); //Person에 이런 형식의 생성자가 없어서 오류가 났던 것
//}
//void main() {
//	char name[] = "Kim";
//	Student s(name);
//
//	cout << s;
//}
//ostream& operator<<(ostream& s, Person& p) {
//	s << p.p << p.pname;
//	return s;
//}
//ostream& operator<<(ostream& s, Student& std) {
//	s << std.s<<*(std.p);
//	return s;
//}