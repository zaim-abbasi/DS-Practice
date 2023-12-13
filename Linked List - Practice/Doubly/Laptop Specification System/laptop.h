#pragma once
#include<iostream>
using namespace std;
class Laptop{
private:
    string brand;
    string model;
    int price;
public:
    Laptop()
    {
        brand = "";
        model = "";
        price = 0;
    }
    Laptop(string brand, string model, int price)
    {
        this->brand = brand;
        this->model = model;
        this->price = price;
    }
    string GetBrand()
    {
        return brand;
    }
    string GetModel()
    {
        return model;
    }
    int GetPrice()
    {
        return price;
    }

    void SetBrand(string brand)
    {
        this->brand = brand;
    }
    void SetModel(string model)
    {
        this->model = model;
    }
    void SetPrice(int price)
    {
        this->price = price;
    }
};