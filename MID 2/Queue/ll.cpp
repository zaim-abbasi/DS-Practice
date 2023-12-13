#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class Queue{
public:
    Node *front;
    Node *rear;
    int numItems;
    Queue()
    {
        front = rear = NULL;
        numItems = 0;
    }
    bool isEmpty()
    {
        if(numItems == 0)
            return true;
        return false;
    }
    void Enqueue(int num)
    {
        Node *newNode = new Node(num);
        if(isEmpty())
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        numItems++;
    }
    void Dequeue()
    {
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            numItems--;
        }
    }
    void Display()
    {
        Node *temp = front;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};