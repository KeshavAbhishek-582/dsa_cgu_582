#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter value of n : ");
    scanf("%d", &n);
    printf("Enter value of m : ");
    scanf("%d", &m);
    int array1[n][m];
    int array2[n][m];
    int array3[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("\nEnter value for array1 index (%d %d): ", i, j);
            scanf("%d", &array1[i][j]);
            printf("\nEnter value for array2 index (%d %d): ", i, j);
            scanf("%d", &array2[i][j]);
            array3[i][j] = array1[i][j] + array2[i][j];
        }
    }printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", array1[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", array2[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", array3[i][j]);
        }
        printf("\n");
    }

    return 0;
}