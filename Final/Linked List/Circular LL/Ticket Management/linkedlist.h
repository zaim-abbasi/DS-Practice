#include "node.h"
class LinkedList
{
public:
    Node *head;
    Ticket *ticketObj;

    LinkedList()
    {
        head = NULL;
    }

    void addTicket()
    {
        static int idCounter = 0;
        string startLoc;
        string endLoc;
        float fare;
        string passengerName;

        cout << "Enter Passenger's Name: ";
        cin >> passengerName;
        cout << "Enter start location: ";
        cin >> startLoc;
        cout << "Enter end location: ";
        cin >> endLoc;

        cout << "Enter fare: ";
        cin >> fare;

        idCounter++;

        Ticket *newTicket = new Ticket(idCounter, startLoc, endLoc, fare, passengerName);

        Node *newNode = new Node(newTicket);

        // adding a new object at tail
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }

        else
        {
            // end me insertion
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void removeTicket()
    {
        // removing ticket by ticket ID

        int TicketID;
        cout << "Enter Ticket ID to remove ticket: ";
        cin >> TicketID;

        Node *temp = head;
        Node *prev = NULL;
        while (temp->ticketObj->TicketID != TicketID && temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->ticketObj->TicketID == TicketID)
        {
            cout << "Ticket Found at location " << temp->ticketObj->TicketID;
            if (temp == head)
            {
                // first location
                Node *newNode = head;
                newNode = newNode->next;
                head = newNode;

                newNode = NULL;
                delete newNode;
            }

            else
            {
                // node to be deleted is in middle or end of LL
                cout << "Previous Node: " << prev->ticketObj->TicketID << endl;
                prev->next = temp->next;
            }
        }
    }

    void CalculateRevenue()
    {
        float totalRevenue = 0.0;
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No tickets generated yet!" << endl;
        }
        else
        {
            while (temp->next != head)
            {
                totalRevenue += temp->ticketObj->fare;
                temp = temp->next;
            }
            totalRevenue += temp->ticketObj->fare;
            cout << "Total Revenue: " << totalRevenue << endl;
        }
    }
    void displayTickets()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No tickets generated yet!" << endl;
        }
        else
        {
            while (temp->next != head)
            {
                cout << "Ticket ID: " << temp->ticketObj->TicketID << endl;
                cout << "Passenger Name: " << temp->ticketObj->passengerName << endl;
                cout << "Start Location: " << temp->ticketObj->startLoc << endl;
                cout << "End Location: " << temp->ticketObj->endLoc << endl;
                cout << "Fare: " << temp->ticketObj->fare << endl;
                cout << endl;
                temp = temp->next;
            }
            cout << "Ticket ID: " << temp->ticketObj->TicketID << endl;
            cout << "Passenger Name: " << temp->ticketObj->passengerName << endl;
            cout << "Start Location: " << temp->ticketObj->startLoc << endl;
            cout << "End Location: " << temp->ticketObj->endLoc << endl;
            cout << "Fare: " << temp->ticketObj->fare << endl;
            cout << endl;
            temp = temp->next;
        }
    }
};