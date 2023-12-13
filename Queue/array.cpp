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
            // rear = (rear + 1) % queueSize;
            rear == size - 1 ? rear = 0 : rear++;
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
        front == size - 1 ? front = 0 : front++;
        numCounter--;
    }

    ~Queue()
    {
        delete[] arr;
    }
};