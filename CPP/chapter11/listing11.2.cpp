//Listing 11.2
/* strptr.c -- strings as pointers
string의 주소, * 연산자 적용
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
	printf("n의 주소는 %p, p의 주소는 %p\n", &n, p);
	getchar();
	return 0;
}
