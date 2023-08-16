// Write a C program to perform three tuple representation of sparse matrix and display all the elements.

#include <stdio.h>

int main(){
    int rows, columns;
    printf("Enter rows and columns (rxc): ");
    scanf("%dx%d", &rows, &columns);

    int count0=0, countNon0=0;

    int array[rows][columns];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter value = ");
            scanf("%d", &array[i][j]);

            if(array[i][j]==0){
                count0++;
            }
            else{
                countNon0++;
            }
        }

    }
    printf("\n\n");
    if(count0<countNon0){
        printf("Not a sparse matrix.");
    }
    else{
        printf("i\tj\tValue\n\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if(array[i][j]!=0){
                    printf("(%d\t%d\t%d)\n", i, j, array[i][j]);
                }
            }
            
        }
    }
    return 0;
}