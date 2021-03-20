// Listing 9.6 The recur.c Program
/* recur.c -- recursion illustration */
#include <stdio.h>
#include <stdlib.h>
void up_and_down(int); //return 값이 없는 경우의 recursion
int main(void)
{
	up_and_down(1);
	system("pause");
	return 0;
}
void up_and_down(int n)
{
	printf("Level %d: n location %p\n", n, &n); // %p는 주소를 출력하는 데 사용되는 format specifier
	if (n < 4)
		up_and_down(n + 1);
	printf("LEVEL %d: n location %p\n", n, &n); // 2
}
