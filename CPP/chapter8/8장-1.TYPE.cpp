// 8장-1.TYPE1.CPP  8.1 타입 호환성 규칙 
#include <iostream> 
using namespace std;
void main (){
    typedef struct{
        char  first;
        char  second;
    } twoChars;

    twoChars state1;
    twoChars state2;

    state1.first = 'M';
    state1.second = 'N';

    state2 = state1;//type compatible
    state2.second ++;

    cout << "Original structure: " << state1.first
          << state1.second << endl
          << "Changed structure: "  << state2.first
          << state2.second << endl;
	system("pause");
}