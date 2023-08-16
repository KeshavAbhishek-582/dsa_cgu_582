#include <stdio.h>

int main(){
    int array[5]={15,20,1,4};
    int value;
    int index;
    int temp;
    int j;
    printf("Enter the value : ");
    scanf("%d", &value);

    printf("Enter index b/w (0-4) : ");
    scanf("%d", &index);

    if(index>=0 && index<=4){
        for (j = 4; j>index; j--)
        {
            array[j]=array[j-1];
        }
        
    }

    array[j]=value;

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", array[i]);
    }
    
    return 0;
}