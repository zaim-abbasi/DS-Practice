#include <iostream>
using namespace std;
int LinearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int BinarySearch(int arr[], int size, int element)
{
    int low=0, high=size-1, mid=0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    // int arr[] = {20, 64, 92, 64, 82, 63, 91, 47};
    // int size = sizeof(arr) / sizeof(int);
    // int Index = LinearSearch(arr, size, 191);
    // cout << "Found at " << Index << endl;

    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr1) / sizeof(int);
    int index = LinearSearch(arr1, size, 6);
    if(index==-1)
        cout << "Not Found" << endl;
    else
        cout << "Found at " << index << endl;
}