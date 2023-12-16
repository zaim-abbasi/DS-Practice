#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void InsertHead(Node* &head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void InsertTail(Node* &tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void InsertMiddle(Node* &head,Node* &tail, int position, int data)
{
    if(position == 1)
    {
        InsertHead(head, data);
        return;
    }
    Node *temp = head;
    int count = 1;

    while(count < position-1)
    {
        temp = temp->next;
        count++;
    }

    if(temp ->next == nullptr)
    {
        InsertTail(tail, data);
        return;
    }

    Node *node1 = new Node(data);
    node1->next = temp->next;
    temp->next = node1;
    
}

void Remove(Node*& head, int position)
{
    // delete by position
    if(position == 1)
    {
        //deleting first node
        Node *temp = head;
        temp = temp->next;
        head = temp;

        temp = nullptr;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = nullptr;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;

        curr = nullptr;
        delete curr;
    }
}
void Display(Node* &head)
{
    Node *temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // full fledge menu driven program
}