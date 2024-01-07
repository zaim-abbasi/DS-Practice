#include "node.h"

// implementation of a circular queue using LL
class Queue{
public:
    Node *front;
    Node *rear;

    void Enqueue(int data)
    {
        Node *newNode = new Node(data);
        // add element to the rear
        if(front == NULL)
        {
            // queue empty ha
            front = rear = newNode;
            front->next = newNode;
        }
        else
        {
            // traverse to the end of the queue
            Node *temp = front;
            do{
                temp = temp->next;
            } while (temp->next != front);

            // now we have reached the end of queue
            temp->next = newNode;
            newNode->next = front;
        }
    }

    void display()
    {
        // checking if node inserted correctly
        Node *temp = front;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp->next != front);
    }
};