//listing 4.10
/* stringf.c -- string formatting */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char name[10];
	printf("write your first name : \n");
	scanf("%s", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);

	return 0;
}