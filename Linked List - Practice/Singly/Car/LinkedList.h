#pragma once
#include "Node.h"
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void addCar()
    {
        string make, model;
        int engineNumber;

        cout << "Enter Car's make: ";
        cin >> make;
        cout << "Enter Car's model: ";
        cin >> model;
        cout << "Enter Car's Engine Num: ";
        cin >> engineNumber;

        Car carObj(make, model, engineNumber);
        
        Node *nodeObj = new Node(carObj);

        if (head == nullptr)
        {
            head = nodeObj;
        }
        else
        {
            Node *temp = head;
            while (temp->getNext() != nullptr)
            {
                temp = temp->getNext();
            }
            temp->setNext(nodeObj);
        }
    }

    void displayCars()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Car car = temp->getCarObj();
            cout << "Make: " << car.getMake() << endl;
            cout << "Model: " << car.getModel() << endl;
            cout << "Engine Number: " << car.getEngineNumber() << endl;
            temp = temp->getNext();
        }
    }
};
