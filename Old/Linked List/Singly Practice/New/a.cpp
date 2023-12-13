// Singly Linked List Practice
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
};
void InsertHead(Node *&head, int data)
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
void InsertMiddle(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        InsertHead(head, data);
        return;
    }

    int counter = 1;
    Node *temp = head;
    while (counter < (position - 1))
    {
        temp = temp->next;
        counter++;
    }
    if (temp->next == NULL)
    {
        InsertTail(tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void DeleteNode(Node *&head, int position)
{
    Node *curr = head;
    Node *prev = NULL;
    int counter = 1;
    while (counter < position)
    {
        prev = curr;
        curr = curr->next;
        counter++;
    }
    prev->next = curr->next;
    curr = NULL;
    delete curr;
}
void Display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    Display(head);

    InsertHead(head, 5);
    Display(head);

    InsertTail(tail, 15);
    Display(head);

    InsertMiddle(head, tail, 2, 100);
    Display(head);

    InsertMiddle(head, tail, 4, 50);
    Display(head);

    InsertMiddle(head, tail, 6, 20);
    Display(head);

    InsertMiddle(head, tail, 7, 200);
    Display(head);
}