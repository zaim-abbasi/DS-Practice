#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            this->next=NULL;
            delete next;
        }
        cout<<"Memory Free "<<value<<endl;
    }
};

// Function to insert a node at the head of the linked list
void Insert_Head(Node *&head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the tail of the linked list
void Insert_Tail(Node *&tail, int data) {
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// Function to insert a node at the middle of the linked list
void Insert_Middle(Node *&head, Node *&tail, int position, int data) {
    if (position == 1) {
        Insert_Head(head, data);
        return;
    }

    int counter = 1;
    Node *temp = head;
    while (counter < (position - 1)) {
        temp = temp->next;
        counter++;
    }

    if (temp->next == nullptr) {
        Insert_Tail(tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
// void DeleteNode(Node* &head, int position){
//     if(position==1){
//         head=head->next;
//         //memory free
//     }
//     else{
//         //deleting any middle or last node
//         Node* curr=head;
//         Node* prev=NULL;
//         int count=1;
//         while(count<position){
//             prev=curr;
//             curr=curr->next;
//             count++;
//         }
//         prev->next=curr->next;
//         curr->next=NULL;
//     }
// }
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
// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list
    Node* head = new Node(5);
    Node* tail = new Node(20);

    Insert_Middle(head, tail, 1, 10);
    Insert_Middle(head, tail, 2, 15);
    Insert_Middle(head, tail, 2, 20);
    Insert_Middle(head, tail, 3, 30);
    DeleteNode(head,30);
    printList(head);

    
    return 0;
}
