#include "balanced.h"
int main()
{
    int choice;
    do
    {
        cout << "1. Normal Stack Operations" << endl;
        cout << "2. Bracket Chacker" << endl;
        cout << "3. CSV Handling" << endl;
        cout<<"4. Save in array"<<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Stack s;
            int choice;
            do
            {
                cout << "1. Push" << endl;
                cout << "2. Pop" << endl;
                cout << "3. Display" << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    int data;
                    cout << "Enter data: ";
                    cin >> data;

                    s.push(data);
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.display();
                    break;
                default:
                    break;
                }
            } while (choice != 0);

            break;
        }
        case 2:
        {

        }

        case 3:
        {
            Stack s;
            s.loadfromFile();
            s.DisplayStudentStack();
            break;
        }
        case 4:
        {
            Stack s;
            s.loadfromFile();
            s.DisplayStudentStack();
            int* arr = new int[s.countStudents()];
            s.addToArray(arr);
            break;
        }
        default:
            break;
        }
    } while (choice != 0);
}