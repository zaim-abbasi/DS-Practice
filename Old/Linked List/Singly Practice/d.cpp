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
void InsertHead(Node* &head, int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
void InsertTail(Node* &tail, int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void InsertMiddle(Node* &head, int position, int data){
    if(position==1){
        InsertHead(head, data);
    }
    int counter=1;
    Node* temp=head;
    while(counter<(position-1)){
        temp=temp->next;
        counter++;
    }
    //chk for tail
    Node* newNode=new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;
}
void DeleteNode(Node* &head, int position){
    Node* temp=head;
    Node* curr=head;
    Node* prev=NULL;
    int counter=1;
    while(counter<position){
        prev=curr;
        curr=curr->next;
        counter++;
    }
    prev->next=curr->next;
    delete curr;
}