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
void InsertHead(Node* &head, int data)
{
    // create a new node
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void InsertTail(Node* &head, int data)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *temp1 = new Node(data);
    temp->next = temp1;
}

void InsertMiddle(Node* &head, int position, int data)
{
    Node *temp = head;
    int counter = 1;
    if (position == 1)
    {
        InsertHead(head, data);
        return;
    }
    while (counter < position - 1)
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

void DeleteNode(Node* &head, int position)
{
    //delete by position
    int counter = 1;
    Node *current = head;
    Node *prev = NULL;
    while(counter < position)
    {
        prev = current;
        current = current->next;
        counter++;
    }
    prev->next = current->next;
    current = NULL;
    delete current;
}

void Print(Node* &head)
{
    Node *temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() 
{
    system("cls");
    Node *node1 = new Node(10);

    Node *head = node1;

    InsertHead(head, 12);
    InsertHead(head, 15);
    InsertTail(head, 5);

    Print(head);
    cout << endl;

    InsertMiddle(head, 1, 50);
    Print(head);
    cout << endl;

    InsertMiddle(head, 6, 40);
    Print(head);
    cout << endl;

    DeleteNode(head,6);
    Print(head);
    cout << endl;
}