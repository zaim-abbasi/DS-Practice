#pragma once
#include <iostream>
using namespace std;
class Student
{
public:
    int srNo;
    string regDt;
    string rollNo;
    string name;
    int as1;
    int as2;
    int as3;
    int as4;
    double as; // Changed to double
    int si1;
    double si2; // Changed to double
    int proj1;
    double proj2; // Changed to double
    int final1;
    double final2; // Changed to double
    int mid1;
    double mid2; // Changed to double
    double gtot; // Changed to double
    string grade;

    Student()
    {
        srNo = 0;
        regDt = "";
        rollNo = "";
        name = "";
        as1 = 0;
        as2 = 0;
        as3 = 0;
        as4 = 0;
        as = 0.0;
        si1 = 0;
        si2 = 0.0;
        proj1 = 0;
        proj2 = 0.0;
        final1 = 0;
        final2 = 0.0;
        mid1 = 0;
        mid2 = 0.0;
        gtot = 0.0;
        grade = " ";
    }

    Student(int srNo, string regDt, string rollNo, string name, int as1, int as2, int as3, int as4, double as, int si1, double si2, int proj1, double proj2, int final1, double final2, int mid1, double mid2, double gtot, string grade)
    {
        this->srNo = srNo;
        this->regDt = regDt;
        this->rollNo = rollNo;
        this->name = name;
        this->as1 = as1;
        this->as2 = as2;
        this->as3 = as3;
        this->as4 = as4;
        this->as = as;
        this->si1 = si1;
        this->si2 = si2;
        this->proj1 = proj1;
        this->proj2 = proj2;
        this->final1 = final1;
        this->final2 = final2;
        this->mid1 = mid1;
        this->mid2 = mid2;
        this->gtot = gtot;
        this->grade = grade;
    }

    void display()
    {
        cout << "Sr.#: " << srNo << endl;
        cout << "RegDt.: " << regDt << endl;
        cout << "RollNo: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "As:1: " << as1 << endl;
        cout << "As:2: " << as2 << endl;
        cout << "As:3: " << as3 << endl;
        cout << "As:4: " << as4 << endl;
        cout << "As: " << as << endl;
        cout << "S-I:1: " << si1 << endl;
        cout << "S-I:2: " << si2 << endl;
        cout << "Proj:1: " << proj1 << endl;
        cout << "Proj:2: " << proj2 << endl;
        cout << "Final:1: " << final1 << endl;
        cout << "Final:2: " << final2 << endl;
        cout << "Mid:1: " << mid1 << endl;
        cout << "Mid:2: " << mid2 << endl;
        cout << "G.Tot: " << gtot << endl;
        cout << "Grade: " << grade << endl;

        cout << endl
             << endl
             << endl;
    }
};