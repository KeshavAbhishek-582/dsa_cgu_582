#include <stdio.h>

int main(){
    int array[]={96,48,63,29,87,77,48,66,69,93,61};
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("%d-->%d\n", array[i], array[i]%20);
    }
    
    return 0;
}