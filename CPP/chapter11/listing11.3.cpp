//Listing 11.3
//  addresses.c  -- addresses of strings
//string�� ����Ű�� array, pointer, string ��ü�� �ּҸ� Ȯ��
#define MSG "I'm special." 

#include <stdio.h>
int main()
{
	int n = 8;
	//char data[n];//C99�� �������� ����
	char* p;
	p = "hong";
	puts(p);
	*p = "kim";
	char ar[] = MSG;
	const char* pt = MSG;
	printf("address of \"I'm special\": %p \n", "I'm special.");//MSG�ʹ� .�� ���� ����
	printf("              address ar: %p\n", ar);
	printf("              address pt: %p\n", pt);
	printf("          address of MSG: %p\n", MSG);
	printf("address of \"I'm special\": %p \n", "I'm special.");
	getchar();
	return 0;
}
