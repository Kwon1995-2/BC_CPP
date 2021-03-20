#pragma once
#include<stdio.h>

void mikado(int);

int main(void)
{
	int pooh = 2, bah = 5;

	printf("In main(), pooh=%d and &pooh = %p\n", pooh, &pooh);
	printf("In main(), bah = %d and &bah=%p\n", bah, &bah);
	mikado(pooh);

	return 0;
}

void mikado(int bah)
{
	int pooh = 10;
	int *p = &bah;
	printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In mikado(), bah=%d and &bah = %p %p\n", bah, &bah, p);
}