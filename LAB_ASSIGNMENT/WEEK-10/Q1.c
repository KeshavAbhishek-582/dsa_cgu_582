#include <stdio.h>
int findFirstOccurrence(int arr[], int n, int ele)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == ele)
        {
            result = mid;
            high = mid - 1; 
        }
        else if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
int findLastOccurrence(int arr[], int n, int ele)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == ele)
        {
            result = mid;
            low = mid + 1; 
        }
        else if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
int findElementCount(int arr[], int n, int ele)
{
    int firstOccurrence = findFirstOccurrence(arr, n, ele);
    int lastOccurrence = findLastOccurrence(arr, n, ele);
    if (firstOccurrence == -1)
    {
        return -1;
    }
    return lastOccurrence - firstOccurrence + 1;
}
int main()
{
    int N;
    printf("Enter the size of the array (N): ");
    scanf("%d", &N);
    if (N <= 0 || N > 1000000)
    {
        printf("Invalid size of the array.\n");
        return 0;
    }
    int arr[N];
    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ele;
    printf("Enter the element to search: ");
    scanf("%d", &ele);
    int count = findElementCount(arr, N, ele);
    if (count == -1)
    {
        printf("-1\n");
    }
    else
    {
        int firstOccurrence = findFirstOccurrence(arr, N, ele);
        int lastOccurrence = findLastOccurrence(arr, N, ele);
        printf("%d %d %d\n", firstOccurrence, lastOccurrence, count);
    }
    return 0;
}

/*
Time Complexity Analysis:
- Binary Search has a time complexity of O(log N).
- The findElementCount function calls findFirstOccurrence and findLastOccurrence, each with O(log N) complexity.
- Thus, the overall time complexity is O(log N).
*/