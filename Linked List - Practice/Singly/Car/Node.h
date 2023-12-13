#pragma once
#include "Car.h"
class Node
{
private:
    Car carObj;
    Node *next;

public:
    Node()
    {
        next = nullptr;
    }

    Node(Car carObj)
    {
        this->carObj = carObj;
        next = nullptr;
    }

    Car getCarObj()
    {
        return carObj;
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
