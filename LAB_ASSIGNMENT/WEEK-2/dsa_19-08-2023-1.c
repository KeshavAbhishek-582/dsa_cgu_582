#include <stdio.h>

int main(){
    int array[2][3] = {{1,2,3},{4,5,6,}};
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("At index %d %d value is : %d\n", i, j, array[i][j]);
        }
        
    }
    
    return 0;
}