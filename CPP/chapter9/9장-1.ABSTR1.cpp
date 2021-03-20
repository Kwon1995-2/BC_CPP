//9¿Â-1.ABSTR1.CPP   9.4 √ﬂªÛ class
#include <iostream>
using namespace std;
class Printer{
public:
    Printer ()
    { }
    virtual void Method (char * buffer) = 0;
    virtual int Dpi () = 0;
};
void main (){
   // Printer pri; 
    Printer * pPri;
    //pPri = new Printer ();//Abstract class
	system("pause");
}