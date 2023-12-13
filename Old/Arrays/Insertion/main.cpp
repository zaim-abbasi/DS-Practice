#include <iostream>
using namespace std;
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int initial_value = arr[i];//value
        int prev_index = i - 1;//index

        // Move elements of arr[0..i-1] that are greater than the initial_value,
        // to one position ahead of their current position.
        while (prev_index >= 0 && arr[prev_index] > initial_value)
        {
            arr[prev_index + 1] = arr[prev_index];
            prev_index--;
        }
        arr[prev_index + 1] = initial_value;
    }
}
int main()
{
    int arr[] = {5, 2, 6, 9, 4};
    int size = sizeof(arr) / sizeof(int);
    insertionSort(arr, size);
    for (int i = 0; i < size;i++){
        cout << arr[i] << " ";
    }
}