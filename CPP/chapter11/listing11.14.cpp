//Listing 11.14   The  put1()  Function
/* put1.c -- prints a string  without adding \n */
#include <stdio.h>
void put1(const char* string)
/* string not altered */
{
	while (*string != '\0')
		putchar(*string++);
}

int main(void)
{
	char side_a[] = "Side A";
	char dont[] = { 'W', 'O', 'W', '!' , '\0'};
	//char dont[] = { 'W', 'O', 'W', '!' };//null 문자가 없어 오류 발생
	char side_b[] = "Side B";
	//puts(dont);
	put1(dont);   /* dont is not a string */
	getchar();
	return 0;
}