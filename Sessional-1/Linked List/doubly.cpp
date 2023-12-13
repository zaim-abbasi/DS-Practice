#include<iostream>
using namespace std;
//doubly LL
class Node{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
void InsertHead(Node* &head, int data)
{
    Node *temp = new Node(data);
    temp->prev = nullptr;
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void InsertTail(Node* &head, int data)
{
    Node *temp = new Node(data);
    Node *traverse = head;
    while(traverse->next != nullptr)
    {
        traverse = traverse->next;
    }
    traverse->next = temp;
    temp->prev = traverse;
    temp->next = nullptr;
}

void InsertMiddle(Node* &head, int position, int data)
{
    if(position == 1)
        {
            InsertHead(head, data);
            return;
        }
        Node *temp = head;
        int counter = 1;
        while (counter < position - 1)
        {
            temp = temp->next;
            counter++;
        }
        if(temp == nullptr)
        {
            InsertTail(head, data);
        }
        Node *newNode = new Node(data);
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
}

void DeleteNode(Node* &head, int position)
{
    Node *temp = head;
    Node *current = head;
    Node *prev = nullptr;
    int counter = 1;
    while(counter < position)
    {
        prev = current;
        current = current->next;
        counter++;
    }
    prev->next = current->next;
    current->next->prev = prev;

    current = nullptr;
    delete current;
}
void Display(Node* &head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(15);
    InsertHead(head, 10);
    InsertHead(head, 5);
    InsertTail(head, 20);
    Display(head);

    InsertMiddle(head, 3, 5);
    Display(head);

    DeleteNode(head, 2);
    Display(head);
}