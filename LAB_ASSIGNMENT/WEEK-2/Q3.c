// Write a C program to perform three tuple representation of sparse matrix and display all the elements.

#include <stdio.h>

int main(){
    int rows, columns;
    char labels[3][100]={"Rows    :   ", "Columns :   ", "Value   :   "};
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
    int sparse[3][countNon0];
    int iterator=0;
    printf("\n\n");
    if(count0>=(rows*columns)/100){
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if(array[i][j]!=0){
                    sparse[0][iterator]=i;
                    sparse[1][iterator]=j;
                    sparse[2][iterator]=array[i][j];
                    iterator++;
                }
            }
            
        }

        for (int i = 0; i < 3; i++)
        {
            printf("%s", labels[i]);
            for (int j = 0; j < countNon0; j++)
            {
                printf("%d ", sparse[i][j]);
            }
            printf("\n");
            
        }
    }
    else{
        printf("Not a sparse matrix.");
    }
    return 0;
}