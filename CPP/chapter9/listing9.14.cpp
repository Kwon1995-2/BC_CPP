// Listing 9.14 The swap2.c Program
/* swap2.c -- researching swap1.c */
#include <stdio.h>
#include <stdlib.h>

void interchange(int u, int v);
int main(void)
{
	int x = 5, y = 10;
	printf("Originally x = %d and y = %d.\n", x, y);
	interchange(x, y);
	printf("Now x = %d and y = %d.\n", x, y);
	system("pause");
	return 0;
}
void interchange(int u, int v)
{
	int temp;
	printf("Originally u = %d and v = %d.\n", u, v);
	temp = u;
	u = v;
	v = temp;
	printf("Now u = %d and v = %d.\n", u, v);
}
