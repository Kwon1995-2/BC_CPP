//4장-10. return by reference2.cpp   4.4.4 reference에 의한 함수 return 값
#include <iostream>
using namespace std;

const int& maxInt(int a, int b);

void main(){
   int i = 12, j = 13;
   cout << endl << "&i = " << &i << "\t" << "&j = " << &j << endl;
   const int &k = maxInt(i, j);//maxInt(a,b)의 b 주소를 return하는 것을 확인
   cout << "&k = " << &k << endl;

   //cout << "maxInt() = " << maxInt(i, j) << endl;
   system("pause");
}
const int& maxInt(int a, int b){//a,b, return 값의 주소는 i, j와 상관 없음을 확인
	printf("&a = %p, &b = %p\n", &a, &b);
    return (a>b) ? a : b;
    //local variable 또는 임시 변수 a, b의 주소를 반환하는 오류 메시지 발생
}