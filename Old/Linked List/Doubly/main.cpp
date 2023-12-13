#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node() {}
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void InsertHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void InsertTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void InsertMiddle(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        InsertHead(head, data);
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
        InsertTail(tail, data);
        return;
    }
    Node *newNode = new Node(data);
    temp->next->prev = newNode;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void DeleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
    }
    else
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
        if ((curr->next == NULL) || (curr == NULL))
        {
            prev->next = NULL;
            delete curr;
            return;
        }
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}
void display(Node *head)
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
    InsertHead(head, 5);
    display(head);

    InsertHead(head, 1);
    display(head);

    InsertTail(tail, 15);
    display(head);

    InsertTail(tail, 20);
    display(head);

    InsertMiddle(head, tail, 2, 30);
    display(head);

    InsertMiddle(head, tail, 7, 40);
    display(head);

    DeleteNode(head, 1);
    display(head);

    DeleteNode(head, 4);
    display(head);

    DeleteNode(head, 5);
    display(head);

    DeleteNode(head, 5);
    display(head);
}