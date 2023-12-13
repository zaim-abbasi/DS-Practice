#include <iostream>
using namespace std;
int SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
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
int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(int);
    SelectionSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}