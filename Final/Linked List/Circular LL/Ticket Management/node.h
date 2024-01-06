#include "ticket.h"
class Node
{
public:
    Ticket *ticketObj;
    Node *next;

    Node()
    {
        ticketObj = NULL;
        next = NULL;
    }
    Node(Ticket *obj)
    {
        this->ticketObj = obj;
        next = NULL;
    }
};