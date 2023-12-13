#include <iostream>
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = nullptr;
    }
};
class myStack{
public:
    Node *head;
    int size;
    myStack()
    {
        head = NULL;
        size = 0;
    }

    void push(int a)
    {
        Node *temp = new Node(a);
        temp->next = head;
        head = temp;
        size++;
    }

    void pop()
    {
        if(head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int top()
    {
        if(head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        return head->val;
    }
    void size()
    {
        cout << "Size is " << size << endl;
    }
};