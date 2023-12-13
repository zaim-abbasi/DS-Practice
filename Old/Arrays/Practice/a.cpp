#include <iostream>
using namespace std;
// Binary Search,
int BinarySearch(int arr[], int size, int value)
{
    // Position ko return karna ha
    int low = 0, high = size - 1, mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            high = mid - 1;
        if (arr[mid] < value)
            low = mid + 1;
    }
    return -1;
}
// Bubble Sort
void BubbleSort(int arr[], int size)
{
    // ander waley loop me sub se highest ko end me le kar jana ha
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
}
void SelectionSort(int arr[], int size)
{
}
void Input(int arr[], int size)
{
    cout << "Enter Elements in Array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element" << i << ":";
        cin >> arr[i];
    }
}
void Display(int arr[], int size)
{
    cout << "Displaying Array:" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int size, value;
    cout << "Enter size of Array:";
    cin >> size;
    int *arr = new int[size];
    Input(arr, size);
    BubbleSort(arr, size);
    // SelectionSort(arr, size);
    Display(arr, size);

    cout << "Enter value to Search:";
    cin >> value;
    int answer = BinarySearch(arr, size, value);
    if (answer == -1)
        cout << "Not Found!" << endl;
    else
        cout << "Found at position " << answer << endl;
}