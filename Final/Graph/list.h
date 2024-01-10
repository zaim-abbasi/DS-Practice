#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    ListNode *head;
    LinkedList()
    {
        head = NULL;
    }
    void insert(int data)
    {
        ListNode *newNode = new ListNode(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void print()
    {
        ListNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};