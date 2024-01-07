#pragma once
#include "node.h"
#include "student.h"
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
class Stack
{
public:
    Node *head;
    Stack()
    {
        head = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        // removes top element
        Node *temp = head;
        temp = temp->next;
        head = temp;
        delete temp;
    }

    int peak()
    {
        return head->data;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    vector<string> splitString(const string &line, char delimiter)
    {
        vector<string> result;
        string word;
        int start = 0;
        int end = line.find(delimiter);

        while (end != string::npos)
        {
            word = line.substr(start, end - start);
            result.push_back(word);
            start = end + 1;
            end = line.find(delimiter, start);
        }

        word = line.substr(start, end);
        result.push_back(word);

        return result;
    }

    void loadfromFile()
    {
        head = NULL;
        fstream myFile;
        myFile.open("file.csv", ios::in);
        if (myFile.is_open())
        {
            vector<string> row;
            string line, word;

            getline(myFile, line);        // to skip the first line
            while (getline(myFile, line)) // read a row from file and store it in 'line'
            {
                row.clear();

                // read every column data of a row and store it in a string variable, 'word'
                row = splitString(line, ',');

                if (row.size() < 19) // 19: total elements in a row in csv file
                {
                    cout << "Skipping line due to incorrect format: " << line << endl;
                    continue;
                }

                try
                {
                    int srNo = stoi(row[0]);
                    string regDt = row[1];
                    string rollNo = row[2];
                    string name = row[3];
                    int as1 = stoi(row[4]);
                    int as2 = stoi(row[5]);
                    int as3 = stoi(row[6]);
                    int as4 = stoi(row[7]);
                    double as = stod(row[8]); // Changed to stod
                    int si1 = stoi(row[9]);
                    double si2 = stod(row[10]); // Changed to stod
                    int proj1 = stoi(row[11]);
                    double proj2 = stod(row[12]); // Changed to stod
                    int final1 = stoi(row[13]);
                    double final2 = stod(row[14]); // Changed to stod
                    int mid1 = stoi(row[15]);
                    double mid2 = stod(row[16]); // Changed to stod
                    double gtot = stod(row[17]); // Changed to stod
                    string grade = row[18];

                    Student *newStudent = new Student(srNo, regDt, rollNo, name, as1, as2, as3, as4, as, si1, si2, proj1, proj2, final1, final2, mid1, mid2, gtot, grade);

                    Node *newNode = new Node(newStudent);

                    // Insert the new node at the head of the list (top of the stack)
                    newNode->next = head;
                    head = newNode;
                }
                catch (std::invalid_argument &e)
                {
                    cout << "Invalid number in row: " << line << endl;
                    continue; // Skip this row and move on to the next one
                }
            }
        }
        else
            cout << "File not opened!" << endl;
    }

    void DisplayStudentStack()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            temp->studentObj->display();
            temp = temp->next;
        }
    }

    // Create an array named stdData and add all student objects to this array from the Stack:

    int countStudents()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void addToArray(int* arr)
    {
        int count = countStudents();
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            arr[i] = temp->data;
            i++;
            temp = temp->next;
        }
    }

    void sortArray(Student *stdData)
    {
        int count = countStudents();
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (stdData[j].gtot < stdData[j + 1].gtot)
                {
                    Student temp = stdData[j];
                    stdData[j] = stdData[j + 1];
                    stdData[j + 1] = temp;
                }
            }
        }
    }

    void saveToFile(Student *stdData)
    {
        int count = countStudents();
        fstream myFile;
        myFile.open("file.csv", ios::out | ios::app);

        if (myFile.is_open())
        {
            for (int i = 0; i < count; i++)
            {
                myFile << stdData[i].srNo << "," << stdData[i].regDt << "," << stdData[i].rollNo << "," << stdData[i].name << "," << stdData[i].as1 << "," << stdData[i].as2 << "," << stdData[i].as3 << "," << stdData[i].as4 << "," << stdData[i].as << "," << stdData[i].si1 << "," << stdData[i].si2 << "," << stdData[i].proj1 << "," << stdData[i].proj2 << "," << stdData[i].final1 << "," << stdData[i].final2 << "," << stdData[i].mid1 << "," << stdData[i].mid2 << "," << stdData[i].gtot << "," << stdData[i].grade << endl;
            }
        }
        else
        {
            cout << "File not opened!" << endl;
        }
    }
};