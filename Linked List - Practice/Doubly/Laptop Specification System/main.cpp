#include "inventory.h"
int main()
{
    Inventory i;
    // full menu
    int choice;
    do
    {
        cout << "1. Add Laptop" << endl;
        cout << "2. Remove Laptop" << endl;
        cout << "3. Display Inventory" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            i.AddLaptop();
            break;
        case 2:
            i.RemoveLaptop();
            break;
        case 3:
            i.Display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    while(choice != 4);
}