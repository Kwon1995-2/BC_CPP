// Listing 9.4 The misuse.c Program
/* misuse.c -- uses a function incorrectly */
#include <stdio.h>
#include <stdlib.h>
int imax(int, int);//function 선언 - formal parameter의 type을 명시
//int imax();//옛날 방식 - 지금은 오류
int main(void)
{
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3, 5));
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3.0, 5.0));//actual argument라 한다.
	system("pause");
	return 0;
}
int imax(int n, int m) //formal arguments라 한다
//int imax(n, m)
{
	return (n > m ? n : m);//return 값이 expression
}
