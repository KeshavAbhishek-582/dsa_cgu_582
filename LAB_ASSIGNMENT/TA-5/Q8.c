#include <stdio.h>

int main() {
    int key = 15;
    int a[] = {3,10,15,20,35,40,60};
    int l=0;
    int r = 7;
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