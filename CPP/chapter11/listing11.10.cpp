//Listing 11.9
/*  fgets3.c  -- using fgets() */
#include <stdio.h>
#define STLEN 10
int main(void)
{
	//char words[STLEN];
	//int i;
	int n = 0;
	char name[10][20];

	puts("Enter strings (empty line to quit):");

	int j = 0;

	while (fgets(name[j], STLEN, stdin) != NULL && name[j][0] != '\n')
	{
		int i = 0;
		while (name[j][i] != '\n' && name[j][i] != '\0')
			i++;
		if (name[j][i] == '\n')
			name[j][i] = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
		j++;

		if (j >= STLEN)
			break;	
	}	

	
	puts("done");

	for (int n = 0; n < 10; n++)
		puts(name[n]);

	return 0;
}
//Listing 11.10   The  s_gets()  Function 
char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)  // i.e., ret_val != NULL      {   
		while (st[i] != '\n' && st[i] != '\0')
			i++;
	if (st[i] == '\n')
		st[i] = '\0';
	else // must have words[i] == '\0'              while (getchar() != '\n')                  continue; 
	return ret_val;
}

