#include <stdio.h>

int main(){
    int array[] = {25, 6, 15, 12, 8, 34, 9, 18, 2};
    int sizeOfArray = sizeof(array)/sizeof(int);

    printf("Initial Array : ");
    for(int i=0; i<sizeOfArray; i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    int pos;
    int index;
    int currentElement;
    for(index=1; index < sizeOfArray; index++){
        pos = index;
        currentElement = array[index];
        while(currentElement < array[pos-1] && pos>0){
            array[pos]=array[pos-1];
            pos = pos-1;
        }
        array[pos]=currentElement;
        printf("After Pass %d : ", index);
        for(int i=0; i<sizeOfArray; i++){
            printf("%d ", array[i]);
        }
        printf("\n");

    }
    printf("\nFinal Array : ");
    for(int i=0; i<sizeOfArray; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}