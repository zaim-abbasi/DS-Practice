#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Stack{
public:
    Node* top;
    Stack(){
        this->top = NULL;
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = this->top;
        this->top = temp;
    }

    void Pop()
    {
        Node *temp = top;
        top = top->next;
        temp = NULL;
        delete temp;
    }

    void minElement()
    {
        int min = top->data;
        Node *temp = top;
        while(temp != NULL)
        {
            if(temp->data < min)
                min = temp->data;
            temp = temp->next;
        }
        cout << "Minimum element in stack is: " << min << endl;
    }
};

int main()
{
    Stack s;

    s.push(5);
    s.push(1);
    s.push(3);
    s.push(2);
    return 0;
}