// stacker.cpp -- testing the Stack class

#include <iostream>
#include "stack.h"
int main(void)
{
    using namespace std;
    Stack st; // create an empty stack

   // st.top = 100; -> ���� �Ұ����̶�� ���.
    Element inputdata, outputdata;
    cout << "�Է°�:" << endl;
    while (st.isfull())  // public function ���� ����
    {
        cin >> inputdata;
        st.push(inputdata);
    }
    cout << "stack pop ��:" << endl;
    while (st.isempty())
    {
        st.pop(outputdata);
        cout << outputdata;
    }
    cout << "Bye\n";
    system("pause");
    return 0;
}
