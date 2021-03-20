// 8��-9.animal.h   8.8 ������ class�� ��ȭ 
#include "8��-8.point.h"
#include <iostream>

using namespace std;

class Animal{
public:
    
    Animal (Point p = Point ());
	Animal(char* n) {
        strcpy(name, n); //n�� name���ٰ� ����
    }
    virtual void Speak();
    void Speak2();
    void JumpBy (int x, int y);
    void MoveTo (Point newPosition);

protected:
    Point position;
    void MoveOutput ();
    char name[16];  //������ private����
};