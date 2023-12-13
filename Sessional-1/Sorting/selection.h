#include <iostream>
using namespace std;
void SelectionSort(int arr[], int size)
{
    //selection me ander waley loop me minimum find kar ke bahar waley loop ke i me assign karna ha
    for (int i = 0; i < size-1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}