#include<iostream>
using namespace std;

struct Point { int x; int y; };
class Line {
public:
	Line(struct Point p1, struct Point p2);  //»ı¼ºÀÚ
	Line(int x1, int y1, int x2, int y2);
	Line(struct Point p1, int angle);
	Line(int x1, int y1, int angle);

};

Line(struct Point p1, struct Point p2)
{

}
Line(int x1, int y1, int x2, int y2)
{
	float line = sqrt((x1 - x2) ^ 2 + (y1 - y2) ^ 2);
	cout << "line is " << line;
}
Line(struct Point p1, int angle)
{

}
Line(int x1, int y1, int angle)
{

}

int main()
{
	Line(1, 2, 3, 4);
}

