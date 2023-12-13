#pragma once
#include <iostream>
using namespace std;
class Car
{
private:
    string make;
    string model;
    int engineNumber;

public:
    Car()
    {
        make = "";
        model = "";
        engineNumber = 0;
    }

    Car(string make, string model, int engineNumber)
    {
        this->make = make;
        this->model = model;
        this->engineNumber = engineNumber;
    }

    // Getter and Setter methods
    string getMake()
    {
        return make;
    }

    void setMake(string make)
    {
        this->make = make;
    }

    string getModel()
    {
        return model;
    }

    void setModel(string model)
    {
        this->model = model;
    }

    int getEngineNumber()
    {
        return engineNumber;
    }

    void setEngineNumber(int num)
    {
        engineNumber = num;
    }
};
