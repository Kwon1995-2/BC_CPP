#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main(void)
{
	NODE** bucket = NULL;
	bucket = hash_init(bucket, 10);
	if (bucket == NULL)	return 1;

	hash_insert(bucket, 10, "全辨悼", 2000, 1, 1);
	hash_insert(bucket, 11, "全老悼", 2000, 1, 1);
	hash_insert(bucket, 12, "全捞悼", 2000, 1, 1);
	hash_insert(bucket, 13, "全伙悼", 2000, 1, 1);
	hash_insert(bucket, 14, "全荤悼", 2000, 1, 1);
	hash_insert(bucket, 15, "全坷悼", 2000, 1, 1);
	hash_insert(bucket, 21, "辫老悼", 2000, 1, 1);
	hash_insert(bucket, 31, "捞老悼", 2000, 1, 1);

	hash_display(bucket);

	printf("search node : 15\n");
	NODE* t = hash_search(bucket, 17);
	if (t != NULL)	hash_displaynode(t);
	else			printf("\tnot found node\n");

	hash_deleteall(bucket);

	return 1;
}