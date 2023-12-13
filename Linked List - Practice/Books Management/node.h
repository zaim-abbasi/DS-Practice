#include "books.h"
class Node
{
private:
    Book bookObj;
    Node *next;

public:
    Node()
    {
        next = nullptr;
    }
    Node(Book bookObj)
    {
        this->bookObj = bookObj;
        this->next = nullptr;
    }

    Book getBookObj()
    {
        return bookObj;
    }
    void setBookObj(Book bookObj)
    {
        this->bookObj = bookObj;
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }
};
