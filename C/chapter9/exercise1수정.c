#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Prime(x);

int main(void)
{
	int x;
	int y=0;
	int lcnt = 2;
	
	printf("Enter the integer\n");
	scanf("%d", &x);
	
	if (x > 0)
	{
		while (lcnt < x)
		{
			if ((x % lcnt) == 0)
			{
				y = 0;
				break;
			}
			else
			{
				lcnt++;
				y = 1;
			}
		}
		
		if (y == 0)
			printf("%d is not Prime.\n", x);
		else if(y==1)
			printf("%d is Prime.\n", x);
		
	}
	else
	printf("%d is not Prime.\n", x);
	return 0;
}


