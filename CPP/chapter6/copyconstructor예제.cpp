#include<iostream>

using namespace std;

class Test {
	int value;
	int obj_number;
	static int last_obj;
public:
	Test(int n) {
		value = n;
		obj_number = ++last_obj;
		cout << "Standard constructor (object no."<< obj_number
			<< ") : value = " << value
			<< endl;
	}

	Test(const Test& t) {
		value = t.value;
		obj_number = ++last_obj;
		cout << "Copy constructor (object no."
			<< obj_number
			<< ") : value = " << value
			<< endl;
	}

	~Test() {
		cout << "Destructor (object no."
			<< obj_number << ")"
			<< endl;
	}

	Test& operator= (const Test& t) {
		value = t.value;
		cout << "Assignment operator (from object no."
			<< t.obj_number << " to object no." <<") : value = " << value
			<< endl;
		return (*this);
	}

	int operator ++ () {
		return ++value;
	}
};


int Test::last_obj = 0;

Test PrintNext(Test t) {
	cout << "New increased value = " << ++t << endl;
	return t;
}


void main() {
	cout << "1. New object" << endl;
	Test	t1(25);
	cout << endl;
	cout << "2. New object... copied" << endl;
	Test	t2 = t1;
	cout << endl;
	cout << "3. New object... increased" << endl;
	Test t3 = PrintNext(t1);
	cout << endl;
	cout << "4. Assignment of increased object" << endl;
	t2 = PrintNext(t3);
	cout << endl;
}




