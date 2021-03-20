#include<stdio.h>

int main()
{
	printf("%d", sizeof(int*));
	printf("%d", sizeof(char*));

	int a = 10;
	int(*p)[3] = &a;  // int* p[3] = &a -> error
	
	int b[16] = {1,2,3,4,5,6,7};
	int(*q)[4] = b;

	int c[2][2] = { {1,2},{3,4} };
	int* r = c;

}