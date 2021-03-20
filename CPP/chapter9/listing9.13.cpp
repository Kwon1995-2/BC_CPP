// Listing 9.13 The swap1.c Program
/* swap1.c -- first attempt at a swapping function
코딩 시험에 사용 예정
*/
#include <stdio.h>
#include <stdlib.h>

void interchange(int u, int v); /* declare function */
int main(void)
{
	int x = 5, y = 10;
	printf("Originally x = %d and y = %d.\n", x, y);
	interchange(x, y);// 함수 호출 전후에 값의 변경이 없음을 확인
	printf("Now x = %d and y = %d.\n", x, y);
	system("pause");
	return 0;
}
void interchange(int u, int v) /* define function */
{
	int temp;
	temp = u;
	u = v;
	v = temp;
}
