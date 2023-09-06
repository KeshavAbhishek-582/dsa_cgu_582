#include <stdio.h>

int array[]={};
int top = -1;
int factorial = 1;

int fact(int x){
    if(array[x]==0){
        return factorial;
    }
    else{
        factorial *= array[x];
        fact(x-1);
    }
}

int main(){
    printf("Enter a number : ");
    int n;
    scanf("%d", &n);
    int i=0;

    for (i = 0; i <= n; i++)
    {
        array[i]=i;
    }

    top = i-1;
    
    if(n>0){
        printf("Factorial of %d = %d", n, fact(top));
    }
    
    return 0;
}