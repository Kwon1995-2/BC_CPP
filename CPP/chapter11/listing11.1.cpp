//Listing 11.1
//  strings1.c
//string이 array, pointer, macro 사용시 출력
#include <stdio.h>
#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81
int main(void)
{
	char words[MAXLENGTH] = "I am a string in an array.";
	const char* pt1 = "Something is pointing at me.";
	puts("Here are some strings:");//자동으로 newline을 append
	//printf("%s", MSG);//no newline
	puts(MSG);
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);
	getchar();
	return 0;
}
