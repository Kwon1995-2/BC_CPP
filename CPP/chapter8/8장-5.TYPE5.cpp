// 8장-5.TYPE5.CPP  8.1 타입 호환성 규칙  
#include <iostream>
using namespace std;

class TwoChars {
    char first;
    char second;
public:
    TwoChars (char f, char s) : first (f),  second (s)
    { }
};
//class StateCode : public TwoChars {
class StateCode : protected TwoChars {
public:
    StateCode (char f, char s) : TwoChars (f, s)
    { }
} ;
void main(){
    StateCode * pState1;
    TwoChars * pState2;

    pState1 = new StateCode ('C', 'A');
    pState2 = new TwoChars ('H', 'I');

    pState2 = pState1;
//    pState1 = pState2; 
    pState2 = new StateCode ('A', 'R');
	system("pause");
}