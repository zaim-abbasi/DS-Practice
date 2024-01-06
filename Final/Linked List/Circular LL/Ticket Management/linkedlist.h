#include "node.h"
#include <fstream>
#include <vector>
#include "sstream"
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

        // csv file handling
        fstream myFile;
        myFile.open("tickets.csv", ios::out | ios::app);

        if (myFile.is_open())
        {
            myFile << idCounter << "," << passengerName << "," << startLoc << "," << endLoc << "," << fare << endl;
        }
        else
        {
            cout << "File not opened!" << endl;
        }
    }
    vector<string> splitString(const string &line, char delimiter)
    {
        vector<string> result;
        string word;
        int start = 0;
        int end = line.find(delimiter);

        while (end != string::npos)
        {
            word = line.substr(start, end - start);
            result.push_back(word);
            start = end + 1;
            end = line.find(delimiter, start);
        }

        word = line.substr(start, end);
        result.push_back(word);

        return result;
    }

    void loadfromFile()
    {
        head = NULL;
        fstream myFile;
        myFile.open("tickets.csv", ios::in);
        if (myFile.is_open())
        {
            vector<string> row;
            string line, word;

            // getline(myFile, line);        // to skip the first line
            while (getline(myFile, line)) // read a row from file and store it in 'line'
            {
                row.clear();

                // read every column data of a row and store it in a string variable, 'word'
                row = splitString(line, ',');

                if (row.size() < 5) // 5: total elements in a row in csv file
                {
                    cout << "Skipping line due to incorrect format: " << line << endl;
                    continue;
                }

                int TicketID = stoi(row[0]);
                string passengerName = row[1];
                string startLoc = row[2];
                string endLoc = row[3];
                float fare = stof(row[4]);

                Ticket *newTicket = new Ticket(TicketID, startLoc, endLoc, fare, passengerName);

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
        }
        else
            cout << "File not opened!" << endl;
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