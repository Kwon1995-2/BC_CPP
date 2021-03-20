// Listing 9.1 The lethead1.c Program
/* lethead1.c */
#include <stdio.h>
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#include <stdlib.h>
void starbar(void); /* prototype the function */
// 선언없을 경우의 오류 확인
int main(void)
{
	int count = 100;
	starbar();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	starbar(); /* use the function */
	printf("main()::count = %d\n", count);
	system("pause");
	return 0;
}
void starbar(void) /* define the function */
{
	int count; //local variable
	for (count = 1; count <= WIDTH; count++)
		putchar('*');
	putchar('\n');
	printf("starbar()::count = %d\n", count);

}
