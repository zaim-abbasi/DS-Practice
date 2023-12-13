#include <iostream>
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
using namespace std;

void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of array:";
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i << ":";
        cin >> arr[i];
    }

    InsertionSort(arr, size);

    Display(arr, size);
}