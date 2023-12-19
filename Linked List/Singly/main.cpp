#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void InsertHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void InsertTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void InsertMiddle(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        InsertHead(head, data);
        return;
    }
    Node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == nullptr)
    {
        InsertTail(tail, data);
        return;
    }

    Node *node1 = new Node(data);
    node1->next = temp->next;
    temp->next = node1;
}

void Remove(Node *head, int position)
{
    // // delete by position
    if (position == 1)
    {
        // deleting first node
        Node *temp = head;
        temp = temp->next;
        head = temp;

        temp = nullptr;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = nullptr;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;

        curr = nullptr;
        delete curr;
    }

}
void Display(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // full fledge menu driven program
    Node *head = nullptr;
    Node *tail = nullptr;
    int choice;
    do
    {
        cout << "1. Insert Head" << endl;
        cout << "2. Insert Tail" << endl;
        cout << "3. Insert Middle" << endl;
        cout << "4. Remove" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data: ";
            cin >> data;
            InsertHead(head, data);
            if (tail == nullptr)
            {
                tail = head;
            }
            break;
        }
        case 2:
        {
            int data;
            cout << "Enter data: ";
            cin >> data;
            InsertTail(tail, data);
            break;
        }
        case 3:
        {
            int data, position;
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> position;
            InsertMiddle(head, tail, position, data);
            break;
        }
        case 4:
        {
            int position;
            cout << "Enter data: ";
            cin >> position;
            Remove(head, position);
            break;
        }
        case 5:
        {
            Display(head);
            break;
        }
        case 6:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (choice != 6);
    return 0;
}