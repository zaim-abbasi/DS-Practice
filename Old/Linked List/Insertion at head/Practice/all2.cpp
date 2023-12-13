#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(){}
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void Insert_Head(Node* &head, int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
void Insert_Tail(Node* &tail, int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void Insert_Middle(Node* &head, Node* &tail, int position, int data){
    if(position==1){
        Insert_Head(head, data);
    }
    int counter=1;
    Node* temp=head;
    while(counter<(position-1)){
        temp=temp->next;
        counter++;
    }
    if(temp->next==NULL){
        Insert_Tail(tail,data);
    }
    Node* Newnode=new Node(data);
    Newnode->next=temp->next;
    temp->next=Newnode;
}
