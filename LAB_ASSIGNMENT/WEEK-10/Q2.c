#include <stdio.h>

void findTheMissing(){
    int arr1[]={7,2,5,3,5};
    int arr2[]={7,2,5,4,3,6,5};
    int cnt=0;
    int size_arr1 = sizeof(arr1)/sizeof(int);
    int size_arr2 = sizeof(arr2)/sizeof(int);
    printf("Array 1 : ");

    for(int x=0; x<size_arr1; x++){
        printf("%d ", arr1[x]);
    }
    printf("\nArray 2 : ");
    for(int x=0; x<size_arr2; x++){
        printf("%d ", arr2[x]);
    }
    printf("\n");

    for (int i = 0; i < size_arr2; i++)
    {
        cnt=0;
        for (int j = 0; j < size_arr1; j++)
        {
            if(arr2[i]==arr1[j]){
                cnt++;
            }
        }
        if(cnt==0){
            printf("Missing : %d\n", arr2[i]);
        }
    }
}

int main(){
    findTheMissing();
    return 0;
}