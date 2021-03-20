// Listing 9.12 The loccheck.c Program
/* loccheck.c -- checks to see where variables are stored */
//& operator 를 실습
#include <stdio.h>
#include <stdlib.h>

void mikado(int); /* declare function */
int main(void)
{
	int pooh = 2, bah = 5; /* local to main() */
	printf("In main(), pooh = %d and &pooh = %p\n",
		pooh, &pooh);
	printf("In main(), bah = %d and &bah = %p\n",
		bah, &bah);
	mikado(pooh); //호출 전후에 bah 값과 주소를 확인
	printf("In main(), bah = %d and &bah = %p\n",
		bah, &bah);
	system("pause");
	return 0;
}
void mikado(int bah) /* define function */
{
	int pooh = 10; /* local to mikado() */
	bah++;
	printf("In mikado(), pooh = %d and &pooh = %p\n",
		pooh, &pooh);
	printf("In mikado(), bah = %d and &bah = %p\n",
		bah, &bah);
}
