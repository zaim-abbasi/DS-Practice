#include<iostream>
using namespace std;
class Employee{
public:
    int id;
    string cnic;
    double salary, bonus;
    Employee(){}
    Employee(int id, string cnic, double salary, double bonus)
    {
        this->id = id;
        this->cnic = cnic;
        this->salary = salary;
        this->bonus = bonus;
    }
    void Display()
    {
        cout << "ID: " << id << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Salary: " << cnic << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

class Node{
public:
    Employee *EmployeeObject;
    Node *next;
    Node(){}
    Node(Employee *EmployeeObject)
    {
        this->EmployeeObject = EmployeeObject;
        this->next = NULL;
    }
};

class LinkedList{
public:
    Node *node1;
    LinkedList()
    {
        node1 = new Node();
        node1->next = NULL;
        node1->EmployeeObject = NULL;
    }

    void Insert(const Employee &emp)
    {
        if (node1 != NULL)
        {
            //list is not empty and insert node at end
            Employee *empPtr = new Employee(emp); // Create a new Employee pointer
            Node *temp = new Node(empPtr);

            Node *current = node1;
            while(current ->next != NULL)
                current = current->next;
            current->next = temp;
        }
        else{
            Employee *empPtr = new Employee(emp); // Create a new Employee pointer
            Node *temp = new Node(empPtr);
            node1 = temp;
        }
    }
};

