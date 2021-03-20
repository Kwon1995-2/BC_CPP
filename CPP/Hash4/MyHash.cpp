#include <iostream>
#include <string>
#include <iomanip>
#include "Hashpp.h"

using namespace std;

int BucketSize = 0;

MyHash::~MyHash() 
{
    cout << endl;
    cout << "¼Ò¸êÀÚ È£Ãâ" << endl;
    NODE* t, * p;
    for (int i = 0; i < BucketSize; i++)
    {
        t = head[i];
        while (t != NULL)
        {
            p = t;
            t = t->next;
            cout << "delete " << p->id<<endl;
            delete p;
        }
    }

    delete[] head;
}

int hash_func(int key)
{
    int h = key % BucketSize;
    return h;
}

void MyHash::initializeNode(int size)
{
    BucketSize = size;
    //head = (NODE**)malloc(sizeof(NODE*) * BucketSize);
    head = new NODE*[BucketSize];
    if (head == NULL)
    {
        cout << "memory allocation failed!" << endl;
        return;
    }

    for (int i = 0; i < BucketSize; i++)
        head[i] = NULL;
}

void MyHash::deleteNode(int id)
{
    NODE* t = NULL;
    int key = id % BucketSize;;

     t = head[key];
     NODE* p = t->next;

     if (t->id == id)
     {
         head[key] = p;
         delete t;
         return;
     }
     else{
         while (p->id != id)
            {
                p = p->next;
                t = t->next;
            }
            t->next = p->next;
            delete p;
            return;
        }
   
}

void MyHash::insertNode(int _id, string _name, int y, int m, int d)
{
    //NODE* t = (NODE*)malloc(sizeof(NODE));
    NODE* t = new NODE;
    t->id = _id;
    t->name = _name;
    t->year = y;
    t->month = m;
    t->day = d;
    t->next = NULL;

    int h = hash_func(t->id);

    if (head[h] == NULL)
        head[h] = t;
    else
    {
        NODE* n = head[h];
        while (n->next != NULL)
            n = n->next;

        n->next = t;
    }
}

void MyHash::displayNode()
{
   
    for (int i = 0; i < BucketSize; i++)
    {
        cout<<"Bucket "<<i<<"\t";
        NODE* t = head[i];
        while (t != NULL)
        {
            cout << "[" << t->id << "," << t->name << "," << t->year << "." << t->month << "." << t->day << "]";
            t = t->next;
        }
        cout << endl;
    }
}

NODE* MyHash::searchNode(int id)
{
    int h = hash_func(id);

    NODE* t = head[h];
    while (t != NULL)
    {
        if (t->id == id)
            return t;
        t = t->next;
    }
    return t;
}
