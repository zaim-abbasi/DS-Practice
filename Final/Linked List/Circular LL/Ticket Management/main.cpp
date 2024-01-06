#include "linkedlist.h"
int main()
{
    LinkedList LinkedlistObj;
    char choice;
    while (choice != '5')
    {
        cout << "Welcome to ticket management system: " << endl;
        cout << "1. Generate new Ticket" << endl;
        cout << "2. Remove a ticket" << endl;
        cout << "3. Display all generated tickets: " << endl;
        cout << "4. Total revenue" << endl;
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter Details:" << endl;
            LinkedlistObj.addTicket();
            break;

        case '2':
            cout << "Removing Ticket" << endl;
            LinkedlistObj.removeTicket();
            break;

        case '3':
            LinkedlistObj.displayTickets();
            break;

        case '4':
            LinkedlistObj.CalculateRevenue();
            break;

        case '5':
            exit(0);
            break;

        default:
            cout << "Invalid Input" << endl
                 << endl;
            break;
        }
    }
}