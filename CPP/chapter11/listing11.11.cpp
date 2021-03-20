//Listing 11.11
/* scan_str.c -- using scanf() 
   이중 pointer를 사용하여 string 처리
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char name1[11], name2[11];
	int count;

	printf("Please enter 2 names.\n");
	count = scanf("%5s %10s", name1, name2);
	printf("I read the %d names %s and %s.\n",
		count, name1, name2);

	/*
int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
printf("a 주소 = %p\n", a);
//method1
int** p;
//p = &a[0][0];
//*p = a[0];
//method2
int* pt = &a[0][0];
p = &pt;
*p = a[0];
for (int i = 0; i < 12; i++)
{
printf("p = %p\n",*p);
(*p)++;
}
char b[3];
char* ptr;
ptr = b;
scanf("%s", ptr);
*/
	char c[4][4] = {};
	char** ptr2;
	char* pt2 = &c[0][0];
	ptr2 = &pt2;
	*ptr2 = c[0];
	for (int i = 0; i < 4; i++)
	{
		scanf("%s", *ptr2);
		printf("%s\n", *ptr2);
		(*ptr2)++;
	}
	*ptr2 = c[0];
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", *(ptr2)+i);
	}
	system("pause");
	return 0;
}
