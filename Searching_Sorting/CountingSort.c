#include <stdio.h>

int max(int Array[]){
    int max_num=Array[0];
    for(int i=0;i<7;i++){
        if(max_num<Array[i]){
            max_num=Array[i];
        }
    }
    return max_num;
}

int main() {
    int A[]={2,1,1,2,1,1,2};
    int maxE=max(A);
    int array[maxE+1];
    int count=0;

    for(int i=0; i<maxE+1; i++){
        for(int j=0; j<7; j++){
            if(i==A[j]){
                count++;
            }
        }
        array[i]=count;
        count = 0;
    }
    for(int i=0; i<maxE+1; i++){
        for(int j=0; j<array[i]; j++){
            printf("%d ", i);
        }
    }

    return 0;
}