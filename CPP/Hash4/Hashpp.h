#ifndef _Hashpp_H
#define _Hashpp_H
#include <string>

using namespace std;

typedef struct _node
{
    int id;
    string name;
    int year, month, day;
    struct _node* next;
} NODE;

class MyHash {
    NODE** head;
public:
    MyHash() : head(NULL) {};
    ~MyHash(); 
   // NODE** hash_init(NODE** base, int size);
    void initializeNode(int);
    void deleteNode(int id);
    void insertNode(int _id, string _name, int y, int m, int d);
    void displayNode();
    NODE* searchNode(int id);
};
#endif