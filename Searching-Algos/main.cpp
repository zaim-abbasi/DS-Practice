#include <iostream>
using namespace std;
int BinarySearch(int arr[], int size, int key)
{
    // Will return position of the key
    int low = 0, high = size - 1, mid = 0;
    while (low <= high)
    {
        mid = ((high + low) / 2);
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            high = mid - 1;
        if (arr[mid] < key)
            low = mid + 1;
    }
    return -1;
}
int BinarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;
    int mid = ((high + low) / 2);
    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return BinarySearchRecursive(arr, low, mid - 1, key);
    if (arr[mid] < key)
        return BinarySearchRecursive(arr, mid + 1, high, key);
}

int InsertionSort(int arr[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            // shift elements to right
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int SelectionSort(int arr[], int size)
{
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main()
{
    int size, key;
    cout << "Enter size of array:";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter Elements in array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i << ":";
        cin >> arr[i];
    }

    cout << "\nEnter key to Search:";
    cin >> key;
    int position = BinarySearch(arr, size, key);
    if (position == -1)
        cout << "Key not Found!" << endl;
    else
        cout << "Key Found at position " << position << endl;
}