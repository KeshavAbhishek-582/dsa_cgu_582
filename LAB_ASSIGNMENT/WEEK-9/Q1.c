#include <stdio.h>

int main(){
    int array[] = {3,2,4,1,10,30,40,20};

    int i;
    int j;
    int temp;
    int sizeofArray = sizeof(array)/sizeof(int);
    int newIndex=0;

    printf("Before Sort : ");
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
        }
    }

    if(sizeofArray%2==0){
        newIndex = sizeofArray/2;
    }
    else{
        newIndex = (sizeofArray/2)+1;
    }
    int p = 0;
    for(int x = newIndex; x < sizeofArray-(newIndex/2); x++){
        temp = array[x];
        array[x]=array[sizeofArray-p-1];
        array[sizeofArray-p-1]=temp;
        p++;
    }
    printf("After Sort : ");
    for (int x = 0; x < sizeofArray; x++)
    {
        printf("%d ", array[x]);
    }
    
    return 0;
}