// Queues
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Queue{
public:
    Node *head;
    Node *tail;
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void EnQueue(int data)
    {
        // insert at tail
        Node *newNode = new Node(data);
        if(head == nullptr)
        {
            //LL is empty
            this->head = this->tail = newNode;
        }
        else
        {
            // LL empty nahi ha
            // add at tail karna hoga
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeQueue()
    {
        // remove from head
        if(head == nullptr)
            return;
        else
        {
            Node *temp = head;
            head = head->next;

            if(head == nullptr)
            {
                // head akhri node tha to tail bhi null kar do
                tail = nullptr;
            }
            delete temp;
        }
    }

    bool isEmpty()
    {
        if(head == nullptr)
            return true;
    }

    void Display()
    {
        Node *temp = head;
        if(temp == nullptr)
        {
            cout<<"Queue is empty"<<endl;
        }
        while( temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    Queue q;
    // full fledged menu
    int choice;
    int data;
    while(true)
    {
        cout << "1. EnQueue" << endl;
        cout << "2. DeQueue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            q.EnQueue(data);
            cout << endl;
            break;
        case 2:
            q.DeQueue();
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
