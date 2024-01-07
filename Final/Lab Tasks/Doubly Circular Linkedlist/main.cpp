#include "DoublyCircular.h"
int main()
{
    DoublyCircular obj;
    int choice = 9;

    while (choice != 0)
    {
        cout << "1. Add Elements at end" << endl;
        cout << "2. BubbleSort Sort" << endl;
        cout << "3. Display" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.insertEnd();
            break;
        case 2:
            obj.BubbleSort();
            break;
        case 3:
            obj.Display();
            break;
        }
    }
}