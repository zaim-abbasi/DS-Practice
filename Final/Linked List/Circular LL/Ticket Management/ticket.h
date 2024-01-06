#include <iostream>
using namespace std;
class Ticket
{
public:
    int TicketID;
    string startLoc;
    string endLoc;
    float fare;
    string passengerName;

    Ticket()
    {
        TicketID = 0;
        startLoc = endLoc = passengerName = "";
        fare = 0.0;
    }

    Ticket(int TicketID, string startLoc, string endLoc, float fare, string passengerName)
    {
        this->TicketID = TicketID;
        this->startLoc = startLoc;
        this->endLoc = endLoc;
        this->fare = fare;
        this->passengerName = passengerName;
    }
};