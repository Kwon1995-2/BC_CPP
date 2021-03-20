#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
	friend class CMyMFC3Dlg;
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
	MyHash() :bucketArray(NULL) {
		initializeNode(10);
	}
	~MyHash();
	void initializeNode(int);
	int dataload(string fname);
	void tockenstring(vector<string>& vec, char* arr, int str);
	void displayNodes();

	Node* searchNode(string);
	void insertNode(string name, string mobile_tel, string office_tel, string home_tel, string e_mail, string birth);
	int hash_func(string key);
	//Node* modifyNode(string);
	Node* modifyNode(string _name, string _mobile_tel, string _office_tel, string _home_tel, string _e_mail, string _birth);
	void deleteNode(string);
	Node** getBackArray() { return bucketArray; }
	int getBucketSize() { return BucketSize; }
	//void deleteAll();

};
