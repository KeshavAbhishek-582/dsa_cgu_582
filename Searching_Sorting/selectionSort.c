#include <stdio.h>

int main()
{
    // Write C code here
    int a[] = {7, 4, 10, 8, 3, 1};
    int min = 0;
    int j = 0;
    int temp = 0;

    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        min = i;
        for (j = i + 1; j < sizeof(a) / sizeof(int); j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        for (int i = 0; i < sizeof(a) / sizeof(int); i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    // for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
    //     printf("%d ", a[i]);
    // }

    return 0;
}