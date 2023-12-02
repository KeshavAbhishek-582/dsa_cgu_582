#include <stdio.h>

int main(){
    int pos, temp;
    int a[8]={4,3,2,10,12,1,5,6};

    for (int i = 0; i < 8; i++)
    {
        pos=i;
        temp=a[i];
        while (temp<a[pos-1] && pos>0)
        {
            a[pos]=a[pos-1];
            pos = pos-1;
        }
        a[pos]=temp;

        for (int x = 0; x < 8; x++)
        {
            printf("%d ", a[x]);
        }

        printf("\n\n");
    }
    
    return 0;
}