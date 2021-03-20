#ifndef _MYCLASS_H_
#define _MYCLASS_H_

class myclass01 {
private:
	int table[5][5];
	int** pMatrix;
	int rows, cols;
public:
	myclass01();  //持失切
	~myclass01();  //社瑚切
	myclass01(int row, int col);
	void setMatrix(int row, int col);
	void displayTable();
	void diplayMatrix();
	void free_Matrix();
};

# endif



