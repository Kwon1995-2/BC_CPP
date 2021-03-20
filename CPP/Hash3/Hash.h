#ifndef _HASH_H
#define _HASH_H

typedef struct _node
{
    int id;
    char name[16];
    int year, month, day;
    struct _node *next;
} NODE;

NODE** hash_init(NODE** base, int size);
void hash_deleteall(NODE** base);
void hash_insert(NODE** base, int _id, char* _name, int y, int m, int d);
void hash_displaynode(NODE* t);
void hash_display(NODE** base);
NODE* hash_search(NODE** base, int id);

#endif