//Listing 11.32   The  hello.c  Program
/* hello.c -- converts command-line argument to number
- run the program in command-line mode
- 도구 창에 외부도구 열어 command prompt를 만듬
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])

{
	int i, times;
	if (argc < 2 || (times = atoi(argv[1])) < 1)
		printf("Usage: %s positive-number\n", argv[0]);
	else
		for (i = 0; i < times; i++)
			puts("Hello, good looking!");
	return 0;
	getchar();
}