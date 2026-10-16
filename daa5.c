#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        return binarySearch(arr, mid + 1, high, key);
    }
    else
    {
        return binarySearch(arr, low, mid - 1, key);
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = 9;
    int key = 70;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}


binary search iterative