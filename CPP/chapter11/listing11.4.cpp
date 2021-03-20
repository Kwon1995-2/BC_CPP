//Listing 11.4
//  arrchar.c -- array of pointers, array of strings
#include <stdio.h>
#define SLEN 40
#define LIM 5

int main(void)
{
	int n[3] = { 1,2,3 };
	//n++;
	//printf("%p\n", n);
	//printf("%p", n + 1);
	
	char* p[2];
	p[0] = "hong";
	const char* mytalents[LIM] = 
	{
		"Adding numbers swiftly",
		"Multiplying accurately", "Stashing data",
		"Following instructions to the letter",
		"Understanding the C language"
	};
	char yourtalents[LIM][SLEN] =
	{
		"Walking in a straight line",
		"Sleeping", "Watching television",
		"Mailing letters", "Reading email"
	};
	
	//mytalent 출력
	for (int i = 0; i < LIM; i++)
	{
		//printf("%s\n", mytalents[i]);
		puts(mytalents[i]);
	}
	

	//your talent 출력
	
	for (int i = 0; i < LIM; i++)
	{
		//puts(yourtalents[i]);
		printf("%s\n", yourtalents[i]);
	}

	//puts("Let's compare talents.");
	//printf("%-36s  %-25s\n", "My Talents", "Your Talents");
	//for (i = 0; i < LIM; i++)
	//	printf("%-36s  %-25s\n", mytalents[i], yourtalents[i]);
	//printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
	//	sizeof(mytalents), sizeof(yourtalents));//5개 * 8(pointer 길이) = 40, 200
	
	//getchar();
	return 0;
}
