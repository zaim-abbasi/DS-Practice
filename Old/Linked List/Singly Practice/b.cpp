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
    ~Node(){
        if(this->next!=NULL){
        cout<<"Deleting "<<data<<endl;
        this->next=NULL;
        delete next;
        }
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
void Insert_Middle(Node* &head, Node* & tail, int position, int data){
    if(position==1){
        Insert_Head(head, data);
        return;
    }
    int counter=1;
    Node* temp=head;
    while(counter<(position-1)){
        temp=temp->next;
        counter++;
    }
    if(temp->next==NULL){
        Insert_Tail(tail, data);
        return;
    }
    Node* new_temp=new Node(data);
    new_temp->next=temp->next;
    temp->next=new_temp;
}
void Delete_Node(Node* &head, int position){
    Node* temp=head;
    int counter=1;
    Node* curr=head;
    Node* prev=NULL;
    while(counter<position){
        prev=curr;
        curr=curr->next;
        counter++;
    }
    prev->next=curr->next;
    curr=NULL;
    delete curr;

}
void Display(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Node* head=new Node(10);
    Node* tail=new Node(1);
    Insert_Middle(head,tail,1,20);
    Insert_Middle(head,tail,1,40);
    Insert_Middle(head,tail,2,47);
    Display(head);
    cout<<endl;
    // output:40 47 20 10 
    Delete_Node(head,2);
    Display(head);
    //output: 40 20 10 
}