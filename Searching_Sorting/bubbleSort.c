#include <stdio.h>

int main()
{
    int array[] = {15, 16, 6, 8, 5};
    int temp = 0;
    int n = sizeof(array) / sizeof(int); // Size of Array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            temp = array[j];
            if (array[j] > array[j + 1])
            {
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        for (int k = 0; k < n; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");
    }

    return 0;
}