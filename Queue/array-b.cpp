// using array
#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Queue(int size)
    {
        // creates an empty D.array of size s
        arr = new int[size];
        this->size = size;
        front = rear = -1;
    }

    bool IsFull()
    {
        // returns true if (rear + 1) % size is equal to front, indicating that the next position after rear is equal to front.
        return (rear + 1) % size == front;
    }

    bool IsEmpty()
    {
        return front == -1;
    }

    void makeNull()
    {
        front = rear = -1;
    }

    void Enqueue(int num)
    {
        if (IsFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (IsEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear == size - 1 ? rear = 0 : rear++;
        }
        arr[rear] = num;
    }

    void Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        if (front == rear)
        {
            makeNull();
        }
        else
        {
            front == size - 1 ? front = 0 : front++;
        }
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i == size - 1 ? i = 0 : i++;
        }
        cout << arr[i] << " ";
    }

    ~Queue()
    {
        delete[] arr;
    }
};
int main()
{
    // full fledged menu
    int choice;
    int data;
    Queue q(5);
    while (true)
    {
        cout << "1. EnQueue" << endl;
        cout << "2. DeQueue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            q.Enqueue(data);
            cout << endl;
            break;
        case 2:
            q.Dequeue();
            cout << endl;
            break;
        case 3:
            q.Display();
            cout << endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            cout << endl;
        }
    }
}