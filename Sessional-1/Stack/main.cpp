#include<iostream>
#include <stack>
using namespace std;

class Stack{
public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout << "Stack Overflow " << endl;
    }

    void pop()
    {
        if(top >= 0)
        {
            top--;
        }
        else
            cout << "Stack Underflow " << endl;
    }

    int peek()
    {
        if(top >= 0)
            return arr[top];
        else
            cout << "Stack is empty" << endl;
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }
};
int main()
{
    Stack stack(5);
    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << stack.peek() << endl;
    stack.pop();
    cout << endl;

    cout << stack.peek();
}