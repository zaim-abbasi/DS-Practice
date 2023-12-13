#include <iostream>
using namespace std;
void BubbleSort(int arr[], int size)
{
    // highest ko end pe le kar jana ha
    for (int a = 0; a < size - 1; a++)
    {
        for (int i = 0; i < size - a - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = 0;
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}
void SelectionSort(int arr[], int size)
{
    // lowest ko shuru me
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minIndex] > arr[j])
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

int BinarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        if (arr[mid] > key)
        {
            high = mid - 1;
        }
    }
}
void Display(int arr[], int size)
{
    SelectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {10, 3, 1, 9, 7, 1, 8, 0, 2, 6, 8, 3};
    int size = sizeof(arr) / sizeof(int);
    Display(arr, size);
    int index=BinarySearch(arr, size, 9);
    cout << "Position: " << index << endl;
}