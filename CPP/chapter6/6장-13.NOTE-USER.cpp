// 6장-13.NOTE-USE.CPP
#include <iostream>
#include "6장-11.NOTE.h"
//자료구조에서 Node, List에 대한 class를 정의한 것과 유사하여 반드시 실습이 필요
using namespace std;

int main() {
    Note n(5, 32);
 	cout<<"Press the button to play the sound"<<endl;
    n.Sound ();
    n.Increase (5);
    n.Sound ();
    n.Modulate (50);
    cout<<"Press the button to end the program"<<endl;
	system("pause");
    return 1;
}