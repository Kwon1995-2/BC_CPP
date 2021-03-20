
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	Node();
	string name;
	string mobile_tel;
	string office_tel;
	string home_tel;
	string e_mail;
	string birth;
	Node* next;
};

class MyHash {
	Node** bucketArray;
	int BucketSize;
public: //조회,추가,수정,삭제
	MyHash() :bucketArray(NULL), BucketSize(0) {}
	~MyHash();
	void initializeNode(int);
	void dataload();
	void tockenstring(vector<string>& vec, char* arr, int str);
	void displayNodes();

	Node* searchNode(string);
	void insertNode(string name, string mobile_tel, string office_tel, string home_tel, string e_mail, string birth);
	int hash_func(string key);
	Node* modifyNode(string);
	void deleteNode(string);
	//void deleteAll();
	
};