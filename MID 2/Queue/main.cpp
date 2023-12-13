#include<iostream>
using namespace std;
class Queue{
public:
    int *arr;
    int size;
    int front;
    int rear;
    int numItems;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
        numItems = 0;
    }

    bool isFull()
    {
        if(numItems == size)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if(numItems == 0)
            return true;
        return false;
    }

    void Enqueue(int num)
    {
        if(isFull())
            cout << "Queue is full" << endl;
        else
        {
            rear = (rear+1)%size;
            arr[rear] = num;
            numItems++;
        }
    }

    void Dequeue()
    {
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else
        {
            front = (front+1)%size;
            numItems--;
        }
    }

};