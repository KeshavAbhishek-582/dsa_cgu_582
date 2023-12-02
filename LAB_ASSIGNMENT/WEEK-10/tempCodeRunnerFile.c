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