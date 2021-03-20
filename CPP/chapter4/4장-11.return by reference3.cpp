//4장-11 return by reference3.cpp   4.4.4 reference에 의한 함수 return 값
#include <iostream>
using namespace std;
int& sub(int a, int b);

void main(){
    int c = 1, d = 2;
    int &temp2 = sub(c,d);
	printf("&temp2 = %p, sub() = %p\n", &temp2, &sub(c, d));
	system("pause");
}
int& sub(int a, int b){
    int temp;
    temp = a+b;
	printf("&temp = %p\n", &temp);
    return temp;//local variable의 주소가 return되는 것을 확인 - 나중에 stack에서 사라질수 있어 위험
}
