#include "pch.h"
//#include <iostream>
//#include <string>
//#include <vector>
#include "MyHash4.h"


//using namespace std;

//int BucketSize = 0;

//??ü ?ʱ?ȭ
Node::Node() {
    name = "";
    mobile_tel = "";
    office_tel = "";
    home_tel = "";
    e_mail = "";
    birth = "";
    Node* next = NULL;
}

MyHash::~MyHash()
{
    cout << endl;
    cout << "?Ҹ??? ȣ??" << endl;
    Node* t, * p;
    for (int i = 0; i < BucketSize; i++)
    {
        t = bucketArray[i];
        while (t != NULL)
        {
            p = t;
            t = t->next;
            cout << "delete " << p->name << endl;
            delete p;
        }
    }

    delete[] bucketArray;
}

//void MyHash::deleteAll() {
//    Node* t, * p;
//    for (int i = 0; i < BucketSize; i++)
//    {
//        t = bucketArray[i];
//        while (t != NULL)
//        {
//            p = t;
//            t = t->next;
//            cout << "delete " << p->name << endl;
//            delete p;
//        }
//    }
//
//    delete[] bucketArray;
//}

void MyHash::initializeNode(int size) {
    BucketSize = size;
    //head = (NODE**)malloc(sizeof(NODE*) * BucketSize);
    bucketArray = new Node * [BucketSize];
    if (bucketArray == NULL)
    {
        cout << "memory allocation failed!" << endl;
        return;
    }

    for (int i = 0; i < BucketSize; i++)
        bucketArray[i] = NULL;
}

void MyHash::displayNodes()
{
    for (int i = 0; i < BucketSize; i++)
    {
        cout << "Bucket " << i << "\t";
        Node* t = bucketArray[i];
        while (t != NULL)
        {
            cout << "[" << t->name << "," << t->mobile_tel << "," << t->office_tel << "," << t->home_tel << "," << t->e_mail << ", " << t->birth << "]";
            t = t->next;
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------------";
    cout << endl;

    //for (int i = 0; i < BucketSize; i++)
    //{
    //    cout << "Bucket " << "["<<i <<"]:";
    //    Node* t = bucketArray[i];
    //    int j = 0;
    //    while (t != NULL)
    //    {
    //        cout << t->name <<",";  j++;
    //        t = t->next; 
    //    }
    //    cout << j;
    //    cout << endl;
    //}
    ////cout << "---------------------------------------------------------------";
    //cout << endl;
}

int MyHash::dataload(string fname) {
    FILE* fp;
    errno_t err = fopen_s(&fp, fname.c_str(), "rt");//"contact.txt"
    if (err != 0)
    {
        AfxMessageBox("Fail to open file!");
        return 0;
    }
    int cnt = 0;
    Node** bucketArray = getBackArray();
    for (int i = 0; i < getBucketSize(); i++) {
        bucketArray[i] = NULL;

    }
    //initializeNode(10);
    char fpln[64];
    while (fgets(fpln, 64, fp) != NULL)
    {
        vector<string> vec;
        size_t len = strlen(fpln);
        if (fpln[len - 1] == '\n')
        {
            fpln[len - 1] = '\0';
        }

        if (strlen(fpln) != 0)
        {
            tockenstring(vec, fpln, strlen(fpln));
            insertNode(vec[0], vec[1], vec[2], vec[3], vec[4], vec[5]);
        }
        //cnt += 6;
        //linked list?? ?߰? Ȥ?? ?ε????? ?߰?
    }
    fclose(fp);
    return 1;
}

void MyHash::tockenstring(vector<string>& vec, char* str, int len)
{
    //string t = "";
    //for (int i = 0; i < len; i++)
    //{
    //    //char s = str.GetAt(i);
    //    if (t[i] == ',')
    //    {
    //        t.push_back(i);
    //        t = "";
    //        continue;
    //    }
    //    t += s;
    //} 
    //arr = 

    string t = "";
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ',')
        {
            vec.push_back(t);
            t = "";
            continue;
        }
        t += str[i];
    }
    vec.push_back(t);
}

void MyHash::insertNode(string name, string mobile_tel, string office_tel, string home_tel, string e_mail, string birth)
{
    Node* t = new Node;
    t->name = name;
    t->mobile_tel = mobile_tel;
    t->office_tel = office_tel;
    t->home_tel = home_tel;
    t->e_mail = e_mail;
    t->birth = birth;

    int h = hash_func(name);

    if (bucketArray[h] == NULL)
        bucketArray[h] = t;
    else
    {
        Node* n = bucketArray[h];
        while (n->next != NULL)
            n = n->next;

        n->next = t;
    }
}

int MyHash::hash_func(string key)
{
    const char* p = key.c_str();  //string p -> p[i]ǥ?? ???? 
    unsigned int sum = 0;
    for (unsigned int i = 0; i < key.size(); i++)
    {
        sum += p[i];
    }
    int h = sum % BucketSize;
    return h;
}

Node* MyHash::searchNode(string name)
{
    int h = hash_func(name);

    Node* t = bucketArray[h];
    while (t != NULL)
    {
        if (t->name == name)
            return t;
        t = t->next;
    }
    return t;
}

void MyHash::deleteNode(string name)
{
    Node* t = NULL;
    int key = hash_func(name);

    t = bucketArray[key];
    Node* p = t->next;

    if (t->name == name)
    {
        bucketArray[key] = p;
        delete t;
        return;
    }
    else {
        while (t->name != name)
        {
            p = p->next;
            t = t->next;
        }
        t->next = p->next;
        delete p;
        return;
    }
}

Node* MyHash::modifyNode(string _name, string _mobile_tel, string _office_tel, string _home_tel, string _e_mail, string _birth)
{
    Node* t;
    t = searchNode(_name);
    //string _name;
    t->mobile_tel = _mobile_tel;
    t->office_tel = _office_tel;
    t->home_tel = _home_tel;
    t->e_mail = _e_mail;
    t->birth = _birth;

    insertNode(_name, t->mobile_tel, t->office_tel, t->home_tel, t->e_mail, t->birth);

    return t;
}