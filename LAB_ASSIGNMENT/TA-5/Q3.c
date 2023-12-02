#include <stdio.h>

int main() {

    int a[] = {21,6,3,57,13,9,14,18,2};
    int min = 0;
    int j = 0;
    int temp = 0;

    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        min = i;
        for (j = i + 1; j < sizeof(a) / sizeof(int); j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        for (int x = 0; x < sizeof(a) / sizeof(int); x++) {
            printf("%d ", a[x]);
        }
        printf("\n");
    }

    return 0;
}