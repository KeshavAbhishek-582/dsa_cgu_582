// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int key = 30;
    int a[] = {5,10,15,20,25,30,45,50};
    int l=0;
    int r = 8;
    int mid = 0;
    while(a[mid]!=key){
        mid = (l+r)/2;
        if(key>a[mid]){
            l = mid+1;
        }
        if(key<a[mid]){
            r = mid-1;
        }
    }
    printf("At %dth index\nAt %dth position", mid, mid+1);

    return 0;
}