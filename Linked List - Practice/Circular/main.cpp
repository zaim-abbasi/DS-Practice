#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void Insert(Node* &head, int value)
{
    Node *temp = new Node(value);
    if(head == nullptr)
    {
        head = temp;
        temp->next = temp;
        return;
    }
    else
    {
        // last me insertion
        Node *traversal = head;
        while(traversal->next != head)
        {
            traversal = traversal->next;
        }
        traversal->next = temp;
        temp->next = head;
    }
}

void Delete(Node*& head, int position)
{
    if(position == 1)
    {
        // head ko delete karna ha
        Node *temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }

    Node *temp = head;
    int count = 1;
    while(count != position-1)
    {
        temp = temp->next;
        count++;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

void Display(Node *&head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } 
    while (temp != head);
}

int main()
{
    Node *head = nullptr;
    Insert(head, 1);
    Insert(head, 2);
    Insert(head, 3);
    Display(head);
    return 0;
}