#include "node.h"
class Library
{
private:
    Node *head;
    int counter = 0;

public:
    Library() {}
    void addBook()
    {
        string title, author;
        int ibanNum;
        cout << "Entering Book: " << endl;
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author's name: ";
        cin >> author;
        cout << "Enter IBAN number: ";
        cin >> ibanNum;
        cout << endl;

        Book bookobj(title, author, ibanNum);
        Node *node1 = new Node(bookobj);

        if (head == nullptr)
        {
            head = node1;
        }
        else
        {
            node1->setNext(head);
            head = node1;
        }
        counter++;
    }

    void RemoveBook()
    {
        //remove by title
        string title;
        cout << "Enter Title to remove: ";
        cin >> title;
        Node *temp = head;
        Node *curr = head;
        Node *prev = nullptr;
        while(temp->getBookObj().getTitle() != title && temp != NULL)
        {
            prev = curr;
            curr = temp;
            temp = temp->getNext();
        }

        if(temp->getBookObj().getTitle() == title)
        {
            //remove here
            cout << "Book Found" << endl;
            if(temp == head)
            {
                head = head->getNext();
                delete temp;
            }
            else
            {
                prev->setNext(temp->getNext());
                delete temp;
            }
            counter--;
        }
        else
        cout << "No such book found" << endl;

    }
    void Display()
    {
        int count = 0;
        cout << "Displaying all books in Record: " << endl;
        Node *temp = head;
        while (count < counter)
        {
            cout << "Book " << count+1 << " : " << endl;
            cout << "Title: " << temp->getBookObj().getTitle() << endl;
            cout << "Author: " << temp->getBookObj().getAuthor() << endl;
            cout << "IBAN: " << temp->getBookObj().GetIbanNum() << endl;
            cout << endl;
            temp = temp->getNext();
            count++;
        }
    }
};
