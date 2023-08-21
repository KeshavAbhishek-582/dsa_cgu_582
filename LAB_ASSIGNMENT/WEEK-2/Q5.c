#include<stdio.h>
void display(int row,int column,int array[row][column]){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");   
    } 
}
int main(){
    int row,column;
    printf("Enter Rows: ");
    scanf("%d",&row);
    printf("Enter Columns : ");
    scanf("%d",&column);
    int array[row][column];
    int nonzero=0;
    int total=row*column;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter element at index(%d,%d) : ",i,j);
            scanf("%d",&array[i][j]);
            if (array[i][j]!=0)
            {
                nonzero++;
            } 
        }
    }
    printf("\nYour Given Matrix is :-\n");
    display(row,column,array);
        int new[3][nonzero];


    if ((total-nonzero)>=(total/2))//50 or more than 50%
    {
        printf("\nIt is a sparse matrix\n\n");
        int k=0;
        for (int i = 0; i < row ; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (array[i][j]!=0)
                {
                    new[0][k]=i;
                    new[1][k]=j;
                    new[2][k]=array[i][j];
                    k=k+1;
                } 
            }
        }
    char data[3][100]={"Row    : ","Column : ","Value  : "};
    for (int i = 0; i < 3; i++)
    {
        printf("%s",data[i]);
        for (int j = 0; j < nonzero; j++)
        {
            printf("%d\t",new[i][j]);

        }
        printf("\n");  
    }
    }
    else
    {
        printf("\nit's not a sparse matrix\n");
    }
    return 0;
}