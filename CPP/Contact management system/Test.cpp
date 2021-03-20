#include <iostream>
#include "ContactM.h"

using namespace std;

int main()
{
	MyHash h;
	h.initializeNode(10); 
	//데이터 로딩(contact.txt)
	h.dataload();
	h.displayNodes();

	//데이터 추가 입력
	cout << endl;
	h.insertNode("Simon","000","","","000","");
	h.displayNodes();

	//데이터 조회
	cout << endl;
	Node* t = h.searchNode("Simon");
	cout << "[" << t->name << "," << t->mobile_tel << "," << t->office_tel << "," << t->home_tel << "," << t->e_mail << ", " << t->birth << "]"<<endl;
	cout << endl;
	//데이터 삭제
	h.deleteNode("Kimchulsoo");
	h.displayNodes();

	//데이터 변경

	h.modifyNode("Simon");
	cout << endl;
	h.displayNodes();
	
	//cout << endl;
	
}