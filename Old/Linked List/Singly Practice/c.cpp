#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node() {}
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        this->next = NULL;
        delete next;
    }
};
void InsetHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void InsertTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void InsertMiddle(Node *head, int position, int data)
{
    if (position == 1)
    {
        InsetHead(head, data);
        return;
    }
    Node *temp = head;
    int counter = 1;
    while (counter < (position - 1))
    {
        temp = temp->next;
        counter++;
    }
    if (temp->next == NULL)
    {
        InsertTail(head, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void DeleteNode(Node *&head, int position)
{
    Node *temp = head;
    Node *curr = head;
    Node *prev = NULL;
    int counter;
    while (counter < (position))
    {
        prev = curr;
        curr = curr->next;
        counter++;
    }
    prev->next = curr->next;
    delete curr;
}
void display(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Node* head= new Node(10);
    InsetHead(head,5);
    InsetHead(head,15);
    display(head);
    InsertMiddle(head,2,30);

    // Node* tail= new Node(20);
    // display(tail);
    // InsertTail(tail,30);
    // display(tail);
}