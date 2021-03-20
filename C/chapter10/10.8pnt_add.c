#include<stdio.h>
#define SIZE 4
int main(void)
{
	short dates[SIZE];
	short* pti;
	short index;
	double bills[SIZE];
	double* ptj;

	pti = dates;

	printf("Before pti++: pti=%p\n", pti);
	pti++;
	printf("After pti++: pti=%p\n", pti);
	printf("dates=%p\t,&dates[0]=%p\n", dates, &dates[0]);

	ptj = bills;
	printf("%23s %15s\n", "short", "double");
	for (index = 0; index < SIZE; index++)
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptj + index);

	return 0;
}