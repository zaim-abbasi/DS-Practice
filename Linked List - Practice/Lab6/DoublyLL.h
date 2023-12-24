#include "node.h"
class DoublyCircular
{
public:
    Node *head;
    DoublyCircular()
    {
        head = nullptr;
    }

    void Display()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    void InsertEnd()
    {
        int data;
        cout << "Enter data: ";
        cin >> data;
        Node *temp = new Node(data);

        Node *travserse = head;
        while (travserse->next != head)
        {
            travserse = travserse->next;
        }
        travserse->next = temp;
        temp->prev = travserse;
        temp->next = head;
        head->prev = temp;
    }

    void AddElement()
    {
        int data;
        cout << "Enter data: ";
        cin >> data;
        Node *temp = new Node(data);

        if (head == nullptr)
        {
            // list empty ha
            head = temp;
            temp->next = temp;
            temp->prev = temp;
            return;
        }
        else
        {
            // traverse karna ha
            Node *travsere = head;
            while (travsere->next != head)
            {
                travsere = travsere->next;
            }
            travsere->next = temp;
            temp->prev = travsere;
            temp->next = head;
            head->prev = temp;
        }
    }

    void BubbleSort()
    {
        Node *i, *j;
        for (i = head; i->next != head; i = i->next)
        {
            for (j = head; j->next != head; j = j->next)
            {
                if (j->next->data < j->data)
                {
                    swap(j->next->data, j->data);
                }
            }
        }
    }
    void SelectionSort()
    {
        Node *i, *j, *min;
        for (i = head; i->next != head; i = i->next)
        {
            min = i;
            for (j = i->next; j != head; j = j->next)
            {
                if (j->data < min->data)
                {
                    min = j;
                }
            }
            swap(min->data, i->data);
        }
    }
};