// 9-1. ABSTR2.CPP  9.4 추상 class
#include <iostream>
using namespace std;

class Printer{   //부모 class
public:
    Printer (){ }  //생성자
    virtual void Method (char * buffer) = 0;   //순수 가상 함수
    virtual int Dpi () = 0;  //순수 가상 함수
};

class DotMatrixPrinter : public Printer{   //자식 class
    int nDots;
public:
    DotMatrixPrinter (int n) :  //생성자
        nDots (n)
        { }
	//*
    void Method (char * buffer){
        sprintf (buffer, "Dot matrix printer with %d pins", nDots);
    }
	//*/
    int Dpi (){
        switch (nDots){
            case 8: return 150;
            case 9: return 160;
            case 24: return 300;
            default: return 100;
        }
    }
} ;

void main(){
    char description [40];
    DotMatrixPrinter dmp (24);  // 생성자 호출
    dmp.Method (description);
    cout << description << endl << "DPI: " << dmp.Dpi () << endl <<endl;
    Printer * pPri;
    pPri = new DotMatrixPrinter (9);
    pPri -> Method (description);
    cout << description << endl << "DPI: " << pPri -> Dpi ()<< endl <<endl;
	delete pPri;
	system("pause");
}