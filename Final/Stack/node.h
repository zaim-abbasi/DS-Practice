#pragma once
#include <iostream>
#include "student.h"
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Student* studentObj;

    Node() {
        next = nullptr;
    }

    Node(int data) {
        this->data = data;
        next = nullptr;
    }

    Node(Student *studentObj)
    {
        this->studentObj = studentObj;
        next = NULL;
    }
};