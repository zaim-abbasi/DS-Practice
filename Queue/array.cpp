// using array
#include<iostream>
using namespace std;
class Queue{
public:
    int *arr;
    int size;
    int front;
    int rear;
    int numCounter;
    Queue(int size)
    {
        //creates an empty D.array of size s
        arr = new int[size];
        this->size = size;
        front = rear = -1;
        numCounter = 0;
    }

    bool IsFull()
    {
        return (numCounter == size);
    }

    bool IsEmpty()
    {
        return numCounter == 0;
    }

    void makeNull()
    {
        front = rear = -1;
        numCounter = 0;
    }


    void Enqueue(int num)
    {
        if(IsFull())
            {
                cout << "Queue is Full" << endl;
                return;
            }
            rear = (rear + 1) % size;
            
            arr[rear] = num;
            numCounter++;
    }

    void Dequeue()
    {
        int num;
        if(IsEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        front = (front + 1) % size;
        numCounter--;
    }

    ~Queue()
    {
        delete[] arr;
    }
};