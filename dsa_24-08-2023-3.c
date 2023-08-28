#include <stdio.h>

int main(){
    char string[]="KESHAV";
    int size = sizeof(string)/sizeof(char);
    int top = size-2;
    char reversed[100];
    printf("\nReversed String : ");

    for (int i = top; i >= 0; i--)
    {
        reversed[top-i]=string[i];
    }

    printf("%s", reversed);

    return 0;
}