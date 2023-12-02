#include <stdio.h>

int main(){
    int array[] = {35, 18, 7, 12, 5, 23, 16, 3, 1};

    int i;
    int j;
    int temp;
    int sizeofArray = sizeof(array)/sizeof(int);

    printf("Initial Array : ");
    for (int x = 0; x < sizeofArray; x++)
    {
        printf("%d ", array[x]);
    }
    printf("\n\n");

    for (i = 0; i < sizeofArray-1; i++)
    {
        for (j = 0; j < sizeofArray-1; j++)
        {
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
            for (int x = 0; x < sizeofArray; x++)
            {
                printf("%d ", array[x]);
            }
            printf("\n");
        }
        
        printf("\nAfter Pass %d : ", i+1);
        for (int x = 0; x < sizeofArray; x++)
            {
                printf("%d ", array[x]);
            }
        printf("\n");
    }

    printf("\nFinal Array : ");
    for (int x = 0; x < sizeofArray; x++)
    {
        printf("%d ", array[x]);
    }
    
    return 0;
}