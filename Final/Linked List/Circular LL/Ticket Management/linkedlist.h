#include "node.h"
#include "fstream"
#include "vector"
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
    vector<string> split(const string &s, char delimiter)
    {
        vector<string> tokens;
        stringstream ss(s);
        string token;

        while (getline(ss, token, delimiter))
        {
            tokens.push_back(token);
        }

        return tokens;
    }

    void readCSVtoLinkedList()
    {
        ifstream file;
        file.open("tickets.csv", ios::in);

        if (!file.is_open())
        {
            cerr << "Error opening file: " << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens.size() == 5) // Assuming the CSV file has 5 columns
            {
                int id = stoi(tokens[0]);
                string passengerName = tokens[1];
                string startLoc = tokens[2];
                string endLoc = tokens[3];
                float fare = stof(tokens[4]);

                Ticket *newTicket = new Ticket(id, startLoc, endLoc, fare, passengerName);
                Node *newNode = new Node(newTicket);

                // Inserting the new node at the end
                if (head == NULL)
                {
                    head = newNode;
                    newNode->next = head;
                }
                else
                {
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

        file.close();
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

            while (getline(myFile, line)) // read an entire row from file and store it in string 'line'
            {
                row.clear();

                stringstream s(line); // used for breaking words

                // read every column data of a row and store it in a string variable, 'word'
                while (getline(s, word, ','))
                {
                    row.push_back(word); // add all the column data of a row to a vector
                }

                // Check if the row has the correct number of elements
                if (row.size() < 5)
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