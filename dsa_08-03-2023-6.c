#include <stdio.h>

int main(){
    int array1[]={1,2,3};
    int array2[]={4,5,6};
    int temp;

    for (int i = 0; i < 3; i++)
    {
        temp = array1[i];
        array1[i]=array2[i];
        array2[i]=temp;
    }

    printf("Array 1 (Swapped)\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n\n");
    printf("Array 2 (Swapped)\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", array2[i]);
    }

    return 0;
}