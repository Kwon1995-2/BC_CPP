//4장-13 const_cast.cpp   4.5.1 const_cast
#include<iostream>
using namespace std;
int increase(int *p) { return (*p + 5);}
int main()
{
   const int a = 100;
   const int *ptr = &a;
   //*ptr += 1;
   //a++;
   int *q = const_cast <int*> (ptr);//const_cast의 목적은 무엇인가?
   *q += 1;
   cout << "a = " << a << endl;
   cout<<"*q = "<<*q << endl<< "increase(q) = " << increase(q)<<endl;
   cout << " address of q = " << q << endl<<"address of a" << &a << endl;//주소는 같은데 값이 다르다 이유는?
   system("pause");
}