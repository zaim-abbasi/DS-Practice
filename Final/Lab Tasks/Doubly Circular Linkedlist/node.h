#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        data = 0;
        next = prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        prev = next = NULL;
    }
};
