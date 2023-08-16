#include <stdio.h>

int main(){
    int n, search, count=0;
    printf("Number of elemets you want enter : ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter value : ");
        scanf("%d", &array[i]);
    }
    
    printf("Enter the element you want to search : ");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {
        if(search==array[i]){
            count++;
        }
    }

    if(count==0){
        printf("Elemet found !");
    }
    else{
        printf("Element not found.");
    }
    
    return 0;
}