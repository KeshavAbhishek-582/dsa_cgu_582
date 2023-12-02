#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
void selectionSort(char arr[][MAX_LENGTH], int n, int passCount[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strlen(arr[j]) < strlen(arr[minIndex]))
            {
                minIndex = j;
            }
        }
        char temp[MAX_LENGTH];
        strcpy(temp, arr[minIndex]);
        strcpy(arr[minIndex], arr[i]);
        strcpy(arr[i], temp);
        passCount[i] = minIndex + 1;
    }
}
int main()
{
    int N;
    printf("Enter the number of strings : ");
    scanf("%d", &N);
    char strings[N][MAX_LENGTH];
    int passCount[N - 1];
    printf("Enter %d strings:\n", N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", strings[i]);
    }
    selectionSort(strings, N, passCount);
    printf("\nSorted in ASC:\n");
    for (int i = 0; i < N; i++)
    {
        printf("{%s}-%lu\n", strings[i], strlen(strings[i]));
    }
    // printf("\nPass Count:\n");
    // for (int i = 0; i < N - 1; i++)
    // {
    //     printf("%d ", passCount[i]);
    // }
    return 0;
}