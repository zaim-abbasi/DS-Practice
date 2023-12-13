#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue()
    {
        arr = new int[100];
        capacity = 100;
        front = 0;
        rear = -1;
        count = 0;
    }
    Queue(int size)
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        cout << "Removing " << arr[front] << '\n';
        front = (front + 1) % capacity;
        count--;
    }

    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Overflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        cout << "Inserting " << item << '\n';
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    bool isEmpty()
    {
        return (size() == 0);
    }
    bool isFull()
    {
        return (size() == capacity);
    }
    int size()
    {
        return count;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        return arr[front];
    }
};
