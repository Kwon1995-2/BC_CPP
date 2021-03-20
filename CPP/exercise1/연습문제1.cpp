
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char first[10];
	char last[10];
	printf("what is your first name?\n");
	scanf("%s", first);
	printf("whatis your last name?\n");
	scanf("%s", last);
	printf("%s %s\n", last, first);

		return 0;

}