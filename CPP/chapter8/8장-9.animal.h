// 8장-9.animal.h   8.8 유도된 class의 상세화 
#include "8장-8.point.h"
#include <iostream>

using namespace std;

class Animal{
public:
    
    Animal (Point p = Point ());
	Animal(char* n) {
        strcpy(name, n); //n을 name에다가 복사
    }
    virtual void Speak();
    void Speak2();
    void JumpBy (int x, int y);
    void MoveTo (Point newPosition);

protected:
    Point position;
    void MoveOutput ();
    char name[16];  //변수는 private으로
};