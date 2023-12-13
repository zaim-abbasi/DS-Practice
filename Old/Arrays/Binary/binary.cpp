#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void BubbleSort(int arr[], int size)
{
    for (int a = 0; a < size; a++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp;
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int Binary(int arr[], int size, int key)
{
    int low = 0, high = size - 1, mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        if (arr[mid] > key)
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    // srand(time(0));
    // int size = 50;
    // int arr[size];
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = rand() % 100 + 1;
    // }
    int arr[] = {7, 2, 1, 8, 10, 3};
    int size = sizeof(arr) / sizeof(int);
    BubbleSort(arr, size);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    // int index = Binary(arr, size, 70);
    // cout << "Found at " << index << endl;
}