// Listing 9.3 The lesser.c Program
/* lesser.c -- finds the lesser of two evils */
#include <stdio.h>
#include <stdlib.h>
int imin(int, int);//function type
				   //return 값을 확인
int main(void)
{
	int evil1, evil2;
	printf("Enter a pair of integers (q to quit):\n");
	while (scanf("%d %d", &evil1, &evil2) == 2)
	{
		printf("The lesser of %d and %d is %d.\n",
			evil1, evil2, imin(evil1, evil2));//function 호출을 driver라 한다
		printf("Enter a pair of integers (q to quit):\n");
	}
	printf("Bye.\n");
	system("pause");
	return 0;
}
int imin(int n, int m) //n,m은 local variable
{
	int min;
	if (n < m)
		min = n;
	else
		min = m;
	return min;
}
