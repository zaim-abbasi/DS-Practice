#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList inventory;

    cout << "Enter Car 1 details:" << endl;
    inventory.addCar();

    cout << "Enter Car 2 details:" << endl;
    inventory.addCar();

    inventory.displayCars();

    return 0;
}
