#pragma once
// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned int Element;
/*
typedef int ** ptr;
ptr a; //int ** a;

typedef char str[20], arraystr[3][4];
str p; //char[20] p;
arraystr q; //char[3][4] q;

typedef int (*fnc)(int);
fnc f; //int (*f)(int);
*/

class Stack
{
private:
    enum { Total = 4 };    // maximum elements = 4
    Element elements[Total];    // stack elements
    int top;            // index for top stack element
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Element& element);   // add element to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Element& element);          // delete top into element
};
#endif
/*
1차 실습: 정수 처리
2차 실습: string 처리
3차 실습: person 객체 > person의 이름이 string 처리
*/