#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *prev;
    Node *next;
    Node(){
        prev = nullptr;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};