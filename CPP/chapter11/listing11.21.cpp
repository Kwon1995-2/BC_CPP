/* listing 11.21 compare.c -- this will work */
#include <stdio.h>
#include <string.h>   // declares strcmp()

#define ANSWER "Grant"
#define SIZE 40
char* s_gets(char* st, int n);

int main(void)
{
	//char tr[SIZE];
	char name[5][20];

	puts("Who is buried in Grant's tomb?");
	//s_gets(tr, SIZE);
	int index = 0;
	int i = 0;
	    for(int i=0;i<5;i++)
			s_gets(name[i], 20);

		while (strcmp(name[i], ANSWER) != 0)
		{
			index++;

			if (i > 5)
			{
				break;
			}
			i++;
		}
		if(index<5)
			printf("%d", index);
		else
			printf("not found it.");
	
	//while (strcmp(tr, ANSWER) != 0)
	//{
	//	puts("No, that's wrong. Try again.");
	//	//s_gets(tr, SIZE);
	//}
	//puts("That's right!");

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
