//listing 11.18
/* str_cat.c -- joins two strings */
#include <stdio.h>
#include <string.h>  /* declares the strcat() function */
#define SIZE 80
char* s_gets(char* st, int n);//뒤에서 자주 반복됨
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	char name[10][20];
	char bc[] = "block chain";

	for (int i = 0; i < 10; i++)
	{
		s_gets(name[i], SIZE);
		strcat(name[i], bc);
	}
	for (int j = 0; j < 10; j++)
	{
		puts(name[j]);
	}

	puts("What is your favorite flower?");
	if (s_gets(flower, SIZE))
	{
		strcat(flower, addon);
		puts(flower);
		puts(addon);
	}
	else
		puts("End of file encountered!");
	puts("bye");

	getchar();
	return 0;
}


char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
