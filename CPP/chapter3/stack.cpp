// stack.cpp -- Stack member functions
#include "stack.h"
Stack::Stack()    // create an empty stack
{
    top = 0;
    for (int i = 0; i < Total; i++)
        elements[i] = -1;
}

bool Stack::isempty() const //if empty, return false
{
    return top != 0;
}

bool Stack::isfull() const //if full, return false
{
    return top != Total;
}

bool Stack::push(const Element& element)
{
    if (top < Total)
    {
        elements[top++] = element;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Element& element)
{
    if (top > 0)
    {
        element = elements[--top];
        return true;
    }
    else
        return false;
}
