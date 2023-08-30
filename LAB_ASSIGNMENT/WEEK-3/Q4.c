#include <stdio.h>

int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        return n * fact(n-1);
    }
}

int main(){
    printf("Enter a number : ");
    int n;
    scanf("%d", &n);
    if(n>0){
        printf("Factorial of %d = %d", n, fact(n));
    }
    
    return 0;
}