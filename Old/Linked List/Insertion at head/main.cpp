#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void InsertionAtHead(Node* &head, int d){
    // first create a new node
    Node *temp = new Node(d);
    // now point it's next-address to head
    temp->next = head;
    // now point head to new start i.e temp
    head = temp;
}
void InsertionAtTail(Node* &tail, int d){
    Node *temp = new Node(d);
    tail->next=temp;
    tail=temp;
}
void print(Node *&head){
    // first make a copy of head
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        // point to next address location
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << " " << node1->next << endl;

    // Head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);

    InsertionAtHead(head, 20);
    print(head);
}