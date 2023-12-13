// Inserting an element at beginning of a node
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
void Insert_Head(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void Insert_Tail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void Insert_Middle(Node* &tail, Node* &head, int position, int d){
    if(position==1){
        Insert_Head(head,d);
        return;
    }
    Node* temp=head;
    
    int count=1;
    while(count<(position-1)){  //us position se pechey tak jana ha
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        Insert_Tail(tail,d);
        return;
    }
    Node* NodeToInsert=new Node(d);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *node1 = new Node(20);
    Node *head = node1;
    Node *tail = node1;
    Insert_Head(head, 40);
    // display(head);
    
    Insert_Middle(tail,head,2,60);
    Insert_Middle(tail,head,3,60);
    Insert_Middle(tail,head,5,80);
    Insert_Middle(tail,head,1,20);
    display(head);
}