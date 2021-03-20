#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	Node();
	~Node();
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
	int bucketSize;
public: //��ȸ,�߰�,����,����
	MyHash() :bucketArray(NULL) {}
	~MyHash();
	void initializeNode(int);
	void dataload();
	void tockenstring(vector<string>& vec, char* arr, int str);
	void displayNodes();

	Node* searchNode(string);
	bool insertNode(string& name, string& mobile_tel, string& office_tel, string& home_tel, string& e_mail, string& birth);
	Node* modifyNode(string);
	void deleteNode(string);
	//void deleteAll();
	
};