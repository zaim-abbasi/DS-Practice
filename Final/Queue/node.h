#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};