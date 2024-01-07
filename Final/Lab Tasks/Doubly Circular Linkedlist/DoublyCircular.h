#include "node.h"
class DoublyCircular{
public:
    Node *head;

    DoublyCircular()
    {
        head = NULL;
    }
    void insertHead()
    {
        int data;
        cout << "Enter data to Enter: ";
        cin >> data;

        Node *newNode = new Node(data);
        Node *temp = head;

        if(temp == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            Node *temp = head;
            newNode->next = temp;
            temp->prev = newNode;

            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;

            head = newNode;
        }


    }

    void insertEnd()
    {
        int data;
        cout << "Enter data: ";
        cin >> data;

        Node *newNode = new Node(data);

        // insert end
        Node *temp = head;
        if(temp == NULL)
        {
            // no node in LL
            head = newNode;
            head->next = newNode;
            head->prev = newNode;
        }
        else
        {
            // nodes are present in the LL
            while(temp->next != head)
            {
                temp = temp->next;
            }
            
            newNode->prev = temp;
            newNode->next = head;
            temp->next = newNode;
            head->prev = newNode;
        }
    }

    void BubbleSort()
    {
        // sorts nodes based on data using Bubble sort
        Node* i, *j;

        for (i = head; i->next != head; i = i->next)
        {
            for (j = head; j->next != head; j = j->next)
            {
                if (j->data > j->next->data)
                {
                    // swap
                    int temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                }
            }
        }
    }

    void SelectionSort()
    {
        Node *i, *j;

        for (i = head; i->next != head; i = i->next)
        {
            Node *minNode = i;

            // finding min Node of all nodes
            for (j = i->next; j->next != head; j = j->next)
            {
                if(j->data < minNode->data)
                {
                    minNode = j;
                }
            }
            
            // swapping data of i with minIndex
            int temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
    void Display()
    {
        Node *temp = head;
        if(temp == NULL)
        {
            cout << "No Node Exists" << endl;
        }
        else
        {
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } 
            while (temp != head);
            cout << endl;
        }
    }
};