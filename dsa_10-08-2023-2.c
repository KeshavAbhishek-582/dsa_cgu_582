#include <stdio.h>

int main(){
    int n;
    int count=0;

    printf("Number of values you want to enter : ");
    scanf("%d", &n);

    int array[n];
    int array2[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter value : ");
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(array[i]==array[j]){
                printf("Duplicate : %d\n", array[i]);
            }
        }
        
    }

    return 0;
}