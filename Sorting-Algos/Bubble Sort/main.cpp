#include <iostream>
using namespace std;
void BubbleSort(int arr[], int size)
{
    // Bubble Sort me ander waley loop me sub se highest find karna ha, or usse agey swap kartey jana ha
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // yani ke j bara ja, or usse swap kara do
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            // find minimum
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        // swap minIndex with i
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {1, 5, 0, 3, 12, 4, 11, 9, 4, 7, 1, 4, 6, 8, 12, 17, 14};
    int size = sizeof(arr) / sizeof(int);
    SelectionSort(arr, size);
    Display(arr, size);
}