#include <stdio.h>

int main(){
    int temp;
    int n;

    printf("Enter number of elements you want to insert : ");
    scanf("%d", &n);

    int array[n]; // Declaration of array

    for (int i = 0; i < n; i++)
    {
        printf("Enter data : ");
        scanf("%d", &array[i]); // Insertion of data in array
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            temp = array[j+1];

            if(array[j]>array[j+1]){
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
        
    }

    if(n%2==0){
        printf("Median : %d", (array[(n/2)-1]+array[(n/2)])/2);
    }
    else{
        printf("Median : %d", array[n/2]);
    }
    return 0;
}