//Listing 11.2
/* strptr.c -- strings as pointers
string�� �ּ�, * ������ ����
*/

#include <stdio.h>
int main(void)
{
	int n = 99;
	int* p = &n;
	int m;
	m = *p;
	printf("%d\n", n);
	printf("%s, %p, %c\n", "We", "are", *"space farers");
	printf("n�� �ּҴ� %p, p�� �ּҴ� %p\n", &n, p);
	getchar();
	return 0;
}
