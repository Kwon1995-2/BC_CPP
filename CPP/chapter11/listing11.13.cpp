//Listing 11.13
/* nono.c -- no! */
#include <stdio.h>
int main(void)
{
	char side_a[] = "Side A";
	//char dont[] = { 'W', 'O', 'W', '!' , '\0'};
	char dont[] = { 'W', 'O', 'W', '!'};//null ���ڰ� ���� ���� �߻�
	char side_b[] = "Side B";
	
	puts(dont);   /* dont is not a string */
	getchar();
	return 0;
}
