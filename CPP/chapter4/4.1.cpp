// #include <iostream>
// using namespace std;

// class Person{
//   // ostream& operator<<(char);
//   // ostream& operator<<(short);
//   // ostream& operator<<(int);
//   // ostream& operator<<(long);
//   // ostream& operator<<(float);
//   // ostream& operator<<(double);
// private: 
// int idNum;
// int age;

// public:
// Person(){}
// Person(int i, int a){idNum=i, age=a;}
// ~Person(){cout<<"destrutor";}
// friend ostream& operator<<(ostream& stream, const Person &p);
// };

// ostream& operator<<(ostream& stream, const Person &p){
//   stream<<"생년월일은 "<<p.idNum<<"이고, 나이는 "<<p.age<<"세";
//   return stream;
// }

// int main()
// {
//   Person p(941111, 20);
//   cout<<"저의 "<<p<<"입니다."<<endl;
  
//   return 0;
// }