#include <stdio.h>

int main(){
    int n, m;
    printf("Enter value of n : ");scanf("%d", &n);
    printf("Enter value of m : ");scanf("%d", &m);
    int array[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Enter value : ");scanf("%d", &array[i][j]);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("At index %d %d value is : %d\n", i, j, array[i][j]);
        }
        
    }
    
    
    return 0;
}