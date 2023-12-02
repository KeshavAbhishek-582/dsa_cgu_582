#include <stdio.h>

int main()
{
    int r, c;
    printf("Enter No. of Rows : ");
    scanf("%d", &r);

    printf("Enter No. of Columns : ");
    scanf("%d", &c);

    int array[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter number : ");
            scanf("%d", &array[i][j]);
        }
        
    }
    int zeros = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(array[i][j]==0){
                zeros+=1;
            }
        }
        
    }

    int nonzeros = (r*c)-zeros;

    int sparse[3][nonzeros];

    int newCol = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(array[i][j]!=0){
                sparse[0][newCol]=i;
                sparse[1][newCol]=j;
                sparse[2][newCol]=array[i][j];
                newCol++;
            }
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < nonzeros; j++)
        {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
        
    return 0;
}