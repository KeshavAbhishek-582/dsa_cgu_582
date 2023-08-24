#include <stdio.h>

int main(){
    char string[]="KESHAV";

    printf("Reversed String : ");

    for (int i = sizeof(string)/sizeof(char); i >=0; i--)
    {
        printf("%c", string[i]);
    }
    
    return 0;
}