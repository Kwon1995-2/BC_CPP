//4-1. STREAM_IN_OUT.cpp  4.1 변수 scope와 표준 입출력
#include <iostream>
using namespace std;

class Person{
	/*
    ostream& operator<<(char); 
    ostream& operator<<(short);
    ostream& operator<<(int);
    ostream& operator<<(long);
    ostream& operator<<(float);
    ostream& operator<<(double);
   */
	friend ostream& operator<<(ostream& stream, const Person &p);
private:
    int idNum;
    int age;

public:
    Person() {}
    Person(int i, int a){ idNum = i, age = a; }

};

//주석 1번
//* operator overloading 사용예
ostream& operator<<(ostream& stream, const Person &p){
    stream<<"생년월일은 "<<p.idNum<<"이고, 나이는"<<p.age<<"세";
    return stream;
}
//*/
void main(){	
    Person p(941111,20);
    cout<<"저의"<<p<<"입니다."<<endl; //error - 주석1을 해제하지 않으면 오류 발생을 확인
	system("pause");
}