#include "node.h"
class Inventory
{
private:
    Node *head;

public:
    Inventory()
    {
        head = nullptr;
    }

    void AddLaptop()
    {
        string brand, model;
        int price;
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Price: ";
        cin >> price;

        Laptop LaptopObj(brand, model, price);
        Node *temp = new Node(LaptopObj);

        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            // insert at end
            Node *tempNode = head;
            while (tempNode->GetNext() != nullptr)
            {
                tempNode = tempNode->GetNext();
            }
            tempNode->SetNext(temp);
            temp->SetPrev(tempNode);
            return;
        }
    }

    void RemoveLaptop()
    {
        // remove by model no
        string model;
        cout << "Enter model no to remove: ";
        cin >> model;

        Node *curr = head;
        Node *prev = nullptr;

        if (curr == nullptr)
        {
            cout << "Inventory Empty" << endl;
            return;
        }

        // Check the first node separately
        if (curr->GetLaptopObj().GetModel() == model)
        {
            head = curr->GetNext();
            if (head != nullptr)
                head->SetPrev(nullptr);
            delete curr;
            return;
        }

        // Iterate through the list to find the matching model
        while (curr != nullptr)
        {
            if (curr->GetLaptopObj().GetModel() == model)
            {
                prev->SetNext(curr->GetNext());
                if (curr->GetNext() != nullptr)
                    curr->GetNext()->SetPrev(prev);
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->GetNext();
        }

        cout << "Model not found in inventory." << endl;
    }

    void Display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "Brand: " << temp->GetLaptopObj().GetBrand() << endl;
            cout << "Model: " << temp->GetLaptopObj().GetModel() << endl;
            cout << "Price: " << temp->GetLaptopObj().GetPrice() << endl;
            cout << endl;
            temp = temp->GetNext();
        }
    }
};