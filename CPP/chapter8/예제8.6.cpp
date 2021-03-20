#include<iostream>
using namespace std;

class Shape {
public:
	virtual void display() {
		cout << "Space" << endl;}
};
class Rectangle : public Shape {
public:
	void display() {
		cout << "Rectangle" << endl;
	}
};
class Square : public Rectangle {
public:
	void display() {
		cout << "Square" << endl;
	}
};
class Circle : public Shape {
public:
	void display() {
		cout << "Circle" << endl;
	}
};
class ColorRect : public Rectangle {
public:
	void display() {
		cout << "ColorRect" << endl;
	}
};
class Triangle : public Shape {
public:
	void display() {
		cout << "Triangle" << endl;
	}
};
class Ellipse : public Shape {
public:
	void display() {
		cout << "Ellipse" << endl;
	}
};

int main()
{
	Shape* mixedShapes[20];
	mixedShapes[0] = new Triangle();
	mixedShapes[1] = new Ellipse();
	mixedShapes[2] = new ColorRect();
	mixedShapes[3] = new ColorRect();
	mixedShapes[4] = new Circle();
	mixedShapes[5] = new Square();
	mixedShapes[6] = new Rectangle();

	for (int i = 0; i < 20; i++)
		mixedShapes[i]->display();

	return 0;
}