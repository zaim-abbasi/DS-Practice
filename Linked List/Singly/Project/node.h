#include "book.h"
class Node{
private:
    Book BookObj;
    Node *next;
public:
    Node()
    {
        next = nullptr;
    }
    Node(Book BookObj)
    {
        this->BookObj = BookObj;
        this->next = nullptr;
    }
    Book GetBookObj()
    {
        return BookObj;
    }
    void SetBookObj(Book BookObj)
    {
        this->BookObj = BookObj;
    }
    Node* GetNext()
    {
        return next;
    }
    void SetNext(Node* next)
    {
        this->next = next;
    }
};