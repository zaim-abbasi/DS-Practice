// Write a function to delete the first occurrence of a node with a given value from a singly linked list. If the value is not found, the list remains unchanged.
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
        int value=this->data;
        if(this->next!=NULL){
            this->next=NULL;
            delete next;
        }
        cout<<"Deleted "<<value<<endl;
    }
};
void DeleteNode(Node* &head, int value){
    Node* curr=head;
    Node* prev=NULL;
    while((curr->data!=value)&&(curr->next!=NULL)){
        prev=curr;
        curr=curr->next;
    }
    if(curr->data==value){
        prev->next=curr->next;
        delete curr;
    }

}
int main(){
    
    
}