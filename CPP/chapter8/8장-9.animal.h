// 8장-9.animal.h   8.8 유도된 class의 상세화 
#include "8장-8.point.h"
class Animal{
public:
    Animal (Point p = Point ());
	Animal(char*) {}
    virtual void Speak ();
    void JumpBy (int x, int y);
    void MoveTo (Point newPosition);

protected:
    Point position;
    void MoveOutput ();
};