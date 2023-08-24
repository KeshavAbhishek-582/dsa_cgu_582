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
    printf("Factorial of 7 = %d", fact(7));
    
    return 0;
}