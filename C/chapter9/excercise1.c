
#include <stdio.h>

int Prime(x);

int main(void)
{
	int x;
	int ph=0;
	printf("Enter the integer\n");
	scanf("%d", &x);
	
		ph = Prime(x);
	if (ph == 1)
			printf("%d is Prime.\n", x);
		else
			printf("%d is not Prime.\n", x);
	
}

int Prime(x)
{
  
  for(int lcnt = 2;lcnt<x;lcnt++)
  {
	  if ((x % lcnt) == 0)
	  {
		  return 0;
	  }
  }
  return 1;
}
