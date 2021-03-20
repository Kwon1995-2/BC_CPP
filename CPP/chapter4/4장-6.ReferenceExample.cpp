//4장-6. ReferenceExample.cpp   4.4.3 reference에 의한 함수 parameter 전달
#include <iostream>
using namespace std;
void swap(int value_a, int value_b); //call by value
void swap(int *pointer_a, int *pointer_b); //call by pointer
void swap_ref(int &reference_a, int &reference_b); //call by reference

void main(){
    int num_1 = 10, num_2 = 20;

    swap (num_1, num_2);
    cout << "After swap (num_1, num_2)::num_1 = " << num_1 
		<< ", num_2 = "<< num_2<<endl;

	swap (&num_1, &num_2); 
	cout << "After swap (&num_1, &num_2)::num_1 = " << num_1 
		<< ", num_2 = "<< num_2<<endl;
	num_1 = 10; num_2 = 20;
    swap_ref (num_1, num_2); 
	cout << "After swap_ref (num_1, num_2)::num_1 = " << num_1 
		<< ", num_2 = "<< num_2<<endl;

	system("pause");
}


void swap(int value_a, int value_b){
    int temp;
    temp = value_a;
    value_a = value_b;
    value_b = temp;
}

void swap(int *pointer_a, int *pointer_b){
    int temp;
    temp = *pointer_a;
    *pointer_a = *pointer_b;
    *pointer_b = temp;
}

void swap_ref(int &reference_a, int &reference_b){
    int temp;
    temp = reference_a;
    reference_a = reference_b;
    reference_b = temp;
}