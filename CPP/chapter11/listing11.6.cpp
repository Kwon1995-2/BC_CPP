//Listing 11.6
/*  getsputs.c  -- using gets() and puts() */
#include <stdio.h>

#define STLEN 81
int main(void)
{
	//char* name;
	
	char name[10];
	//scanf("%s", name);
	gets_s(name);
	printf("%s", name);
	
	char words[STLEN];

	puts("Enter a string, please.");
	//C99, C11은 gets()를 지원하지 않음
	//gets(words);  // read an entire line of input instead of a single word until newline
	//gets() not check if the input line fits into the array
	gets_s(words);
	printf("Your string twice:\n");
	printf("%s", words);
	puts(words);
	puts("Done.");
	getchar();
	return 0;
}
