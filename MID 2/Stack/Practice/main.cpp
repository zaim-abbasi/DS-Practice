#include<iostream>
using namespace std;
class Stack{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    bool isFull()
    {
        if(top == size-1)
            return true;
        return false;
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        return false;
    }

    void Push(int data)
    {
        if(isFull())
            cout << "Stack is Full" << endl;
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void Pop()
    {
        if(isEmpty())
            cout << "Stack is empty" << endl;
        else
        {
            top--;
        }
    }

};