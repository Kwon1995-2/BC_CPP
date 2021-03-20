#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main(void)
{
	NODE** bucket = NULL;
	bucket = hash_init(bucket, 10);
	if (bucket == NULL)	return 1;

	hash_insert(bucket, 10, "ȫ�浿", 2000, 1, 1);
	hash_insert(bucket, 11, "ȫ�ϵ�", 2000, 1, 1);
	hash_insert(bucket, 12, "ȫ�̵�", 2000, 1, 1);
	hash_insert(bucket, 13, "ȫ�ﵿ", 2000, 1, 1);
	hash_insert(bucket, 14, "ȫ�絿", 2000, 1, 1);
	hash_insert(bucket, 15, "ȫ����", 2000, 1, 1);
	hash_insert(bucket, 21, "���ϵ�", 2000, 1, 1);
	hash_insert(bucket, 31, "���ϵ�", 2000, 1, 1);

	hash_display(bucket);

	printf("search node : 15\n");
	NODE* t = hash_search(bucket, 17);
	if (t != NULL)	hash_displaynode(t);
	else			printf("\tnot found node\n");

	hash_deleteall(bucket);

	return 1;
}