/*
Write a function that takes a 2-dimensional array of size N x M as input and returns a new array containing the transpose of the original matrix.
*/

#include <stdio.h>

int main(){
    int n;
    int temp;
    printf("Transpose of the elements of 2D array (nxn):\n\n");
    printf("Enter value of n : ");
    scanf("%d", &n);
    int array[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element at position %d,%d  ",i,j);
            scanf("%d",&array[i][j]);
        }
        
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {   
            temp=array[i][j];
            array[i][j]=array[j][i];
            array[j][i]=temp;
        }  
    }
    
    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
        
    }
    
    return 0;
}