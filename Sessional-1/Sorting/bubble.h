#include <iostream>
using namespace std;
void BubbleSort(int arr[], int size)
{
    // ander waley loop me dono me highest find kar ke swap kar dena ha

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                // swap both
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}