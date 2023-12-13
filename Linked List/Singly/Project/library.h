#include "node.h"
class Library{
private:
    Node *head;
public:
    Library(){}
    void AddBook()
    {
        string title, author;
        int iban;

        cout << "Title: ";
        cin >> title;
        cout << "Author: ";
        cin >> author;
        cout << "IBAN: ";
        cin >> iban;
        cout << endl;

        Book BookObj(title, author, iban);
        Node *node1 = new Node(BookObj);

        node1->SetNext(head);
        head = node1;
    }

    void Remove()
    {
        //remove by ibanNum
        int iban;
        cout << "Enter IBAN Number to remove: ";
        cin >> iban;

        Node *temp = head;
        if(temp->GetBookObj().GetIban() == iban)
        {
            cout << "Iban Found: " << temp->GetBookObj().GetIban() << endl;
            head = temp->GetNext();
            delete temp; // Add this line to free the memory
            return;      // Exit the function after removing the first node
        }
        Node *curr = head;
        Node *prev = nullptr;
        while(temp != nullptr)
        {
            prev = curr;
            curr = curr->GetNext();
            if(temp->GetBookObj().GetIban() == iban && temp != nullptr)
            {
                prev->SetNext(curr->GetNext());

                curr->SetNext(nullptr);
                delete curr;
            }
            temp = temp->GetNext();
        }
    }
    void Display()
    {
        Node *temp = head;
        if(temp == nullptr)
        {
            cout << "List empty" << endl;
            return;
        }
        while(temp != nullptr)
        {
            cout << endl;
            cout << "Title: " << temp->GetBookObj().GetTitle() << endl;
            cout << "Author: " << temp->GetBookObj().GetAuthor() << endl;
            cout << "IBAN: " << temp->GetBookObj().GetIban() << endl;
            cout << endl;
            temp = temp->GetNext();
        }
        cout << endl;
    }
};
