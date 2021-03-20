// Listing 9.5 The proto.c Program
/* proto.c -- uses a function prototype */
#include <stdio.h>
#include <stdlib.h>
int imax(int, int); /* prototype */
void print_name();
int main(void)
{
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3, 5));
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3.0, 5.0));
	print_name();
	system("pause");
	return 0;
}
int imax(int n, int m)
{
	float f = 3.14;
	return (n > m ? n : f);//if문 변경하여 실습,  type casting 발생
	//return(if (n > m)n; else f;);
}
void print_name()
{
	printf("\n argument를 check하지 않는다\n");
}