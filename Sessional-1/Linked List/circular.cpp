#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
void InsertHead(Node* &head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void Remove(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

void DeleteNode(Node *&head, int data)
{
    Node *temp = head;
    if (temp->data == data)
    {
        head = head->next;
        delete temp;
        return;
    }
    while (temp->next != nullptr)
    {
        if (temp->next->data == data)
        {
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
            return;
        }
        temp = temp->next;
    }
}
void Print(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    system("cls");
    Node *node1 = new Node(10);

    Node *head = node1;

}