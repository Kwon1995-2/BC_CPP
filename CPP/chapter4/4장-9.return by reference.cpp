#include <stdio.h>
#include <stdlib.h>
//4장-9.return by reference.cpp   4.4.4 reference에 의한 함수 return 값
#include <iostream>
using namespace std;
const int& maxInt(const int&, const int& b);

void main()
{
	int i = 12, j = 13, n = 14;
   const int &k = maxInt(i, j);
   const int &m = maxInt(maxInt(i, n), j);
   printf("&k = %p\n", &k);
   cout << endl << "k = " << k<<endl;
   double d1 = 3.3, d2 = 4.4;
   cout << "&d1 = " << &d1 << ", &d2 = " << &d2 << endl;
   double d3 = maxInt(d1, d2);//임시변수를 생성
   double d4 = maxInt(i + 12, 4.44);//임시변수를 생성
   system("pause");
}
const int& maxInt(const int &a, const int &b)
{      
	//int *maxValue = new int;//heap 영역
	const int *maxValue; //stack 영역의 local variable
    if (a>b) maxValue = &a;
    else maxValue = &b;
	printf("&a = %p, &b = %p, maxvalue = %p\n", &a, &b, maxValue);
    return *maxValue;
}