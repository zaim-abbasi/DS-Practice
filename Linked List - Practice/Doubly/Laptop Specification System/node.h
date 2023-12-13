#include "laptop.h"
class Node
{
private:
    Laptop LaptopObj;
    Node *next;
    Node *prev;

public:
    Node()
    {
        next = nullptr;
        prev = nullptr;
    }
    Node(Laptop LaptopObj)
    {
        this->LaptopObj = LaptopObj;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Laptop GetLaptopObj()
    {
        return LaptopObj;
    }

    void SetLaptopObj(Laptop LaptopObj)
    {
        this->LaptopObj = LaptopObj;
    }

    Node *GetNext()
    {
        return next;
    }
    Node *GetPrev()
    {
        return prev;
    }
    void SetNext(Node *next)
    {
        this->next = next;
    }
    void SetPrev(Node *prev)
    {
        this->prev = prev;
    }
};