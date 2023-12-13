#include<iostream>
using namespace std;
void InsertionSort(int arr[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = arr[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<arr[j] to key>arr[j].
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}