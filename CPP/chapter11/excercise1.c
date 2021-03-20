#include <stdio.h>

#define STLEN 81
int main(void)
{
	char data[40][20];
	char words[80];
	char ch="";
	int w = 0;
	int windex = 0;
	
	gets_s(words, sizeof(words));

	for (int i = 0; i < 80; i++)
	{
		words[i] = ch;
		if (ch != ' ')
		{
			ch = data[i][windex];
			windex++;
		}
		else if (ch == ' ')
		{
			printf("%s\n", data);
			w++;
			windex = 0;
		}
	}

	printf("%s\n", words);
	puts(words);

	puts("Done.");
	getchar();
	return 0;
}