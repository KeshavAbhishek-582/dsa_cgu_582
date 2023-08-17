#include<stdio.h>
void transpose()
{
    int i,j,x,y;
    printf("Enter row: ");
    scanf("%d",&x);
    
    printf("Enter column: ");
    scanf("%d",&y);
    
    int array1[x][y]; // Main Matrix
    int array2[y][x]; // New Matrix
    
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("Enter value = ");
            scanf("%d",&array1[i][j]);
        }
    }
    printf("\nOriginal Matrix : \n\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d ", array1[i][j]); // Printing Original Matrix
        }
        printf("\n");
    }
    
    printf("\n\n"); // For Vertical Spacing
    
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            array2[j][i]=array1[i][j];
        }
    }
    printf("Transposed Matrix : \n");
    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            printf("%d ", array2[i][j]); // Printing Transposed Matrix
        }
        printf("\n");
    }
}

int main()
{
    transpose(); // User defined function.
    return 0;
}