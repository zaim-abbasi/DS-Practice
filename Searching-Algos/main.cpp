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