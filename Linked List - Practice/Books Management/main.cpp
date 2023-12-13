#include <iostream>
#include "library.h"
using namespace std;
int main()
{
    Library l;
    main:
    cout<<"Welcome to the Library Management System"<<endl;
    cout<<"1. Enter a book to the record"<<endl;
    cout<<"2. Remove a book from the record"<<endl;
    cout<<"3. Display all books in the record"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
        l.addBook();
        goto main;
    case 2:
        l.RemoveBook();
        goto main;
    case 3:
        l.Display();
        goto main;
    case 4:
        exit(0);
        break;
    default:
        cout<<"Invalid Choice"<<endl;
        goto main;
    }
}