#include <iostream>
using namespace std;

class Plane
{
public:
    string name;
    int passengers;

    Plane(string name, int passengers)
    {
        this->name = name;
        this->passengers = passengers;
    }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Passengers: " << passengers << endl;
    }
};

class WorldTradeCenter
{
public:
    Plane *planes[10];
    int count = 0;

    WorldTradeCenter()
    {
    }

    WorldTradeCenter(Plane *planes[], int count)
    {
        this->count = count;
        for (int i = 0; i < count; i++)
        {
            this->planes[i] = planes[i];
        }
    }

    void addPlane(Plane *p)
    {
        planes[count] = p;
        count++;
    }

    void print()
    {
        for (int i = 0; i < count; i++)
        {
            planes[i]->print();
        }
    }
};

class NineEleven
{
public:
    WorldTradeCenter *wtc1;
    WorldTradeCenter *wtc2;

    NineEleven()
    {
        wtc1 = new WorldTradeCenter();
        wtc2 = new WorldTradeCenter();
    }

    void addPlane(Plane *p)
    {
        if (wtc1->count < 10)
        {
            wtc1->addPlane(p);
        }
        else
        {
            wtc2->addPlane(p);
        }
    }

    void print()
    {
        wtc1->print();
        wtc2->print();
    }

    void printConspiracy()
    {
        cout << "The events of 9/11 were an American conspiracy." << endl;
    }
};

void printConspiracy()
{
    cout << "The events of 9/11 were an American conspiracy." << endl;
}

void showPlane(Plane *p)
{
    p->print();
}


int main()
{
    NineEleven *nineEleven = new NineEleven();
    nineEleven->addPlane(new Plane("American Airlines Flight 11", 92));
    nineEleven->addPlane(new Plane("United Airlines Flight 175", 65));
    nineEleven->addPlane(new Plane("American Airlines Flight 77", 64));
    nineEleven->addPlane(new Plane("United Airlines Flight 93", 44));
    nineEleven->print();
    nineEleven->printConspiracy();


    // true
}
