#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

int BucketSize = 0;

int hash_func(int key)
{
    int h = key % BucketSize;
    return h;
}

NODE** hash_init(NODE** base, int size)
{
    BucketSize = size;
    base = (NODE**)malloc(sizeof(NODE*) * BucketSize);
    if (base == NULL)
    {
        printf("memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < BucketSize; i++)
        base[i] = NULL;

    return base;
}

void hash_deleteall(NODE** base)
{
    NODE* t, * p;
    for (int i = 0; i < BucketSize; i++)
	{
        t = base[i];
        while (t != NULL)
        {
	        p = t;
	        t = t->next;
	        free(p);
        }
	}

    free(base);
}

void hash_insert(NODE** base, int _id, char* _name, int y, int m, int d)
{
    NODE* t = (NODE*)malloc(sizeof(NODE));
    t->id = _id;
    strcpy(t->name, _name);
    t->year = y;
    t->month = m;
    t->day = d;
    t->next = NULL;

    int h = hash_func(t->id);

    if (base[h] == NULL)
        base[h] = t;
    else
    {
        NODE* n = base[h];
        while (n->next != NULL)
            n = n->next;

        n->next = t;
    }
}

void hash_displaynode(NODE* t)
{
    printf("\t%d, %s, %d-%02d-%02d\n", t->id, t->name, t->year, t->month, t->day);
}

void hash_display(NODE** base)
{
    for (int i = 0; i < BucketSize; i++)
    {
        printf("Bucket %d\n", i);
        NODE* t = base[i];
        while (t != NULL)
        {
            hash_displaynode(t);
            t = t->next;
        }
    }
}

NODE* hash_search(NODE** base, int id)
{
    int h = hash_func(id);

    NODE* t = base[h];
    while (t != NULL)
    {
        if (t->id == id)
            return t;
        t = t->next;
    }
    return NULL;
}
