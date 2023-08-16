#include <stdio.h>
#include <math.h>

int main(){
    int n; // Number of elements
    int xi; // current element
    float x = 0.0; // Mean
    float variance; // Variance
    float sd; // Standard Deviation
    float sum = 0.0; // Temp Variable

    printf("Number of elements to be entered : ");
    scanf("%d", &n);
    
    int arr1[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter number : ");
        scanf("%d", &arr1[i]);
        
        xi = arr1[i];
        x = x+xi;
    }
    
    x = x/n; // Mean Calculated

    for (int i = 0; i < n; i++)
    {
        xi = arr1[i];
        sum += pow(xi-x,2);
    }

    variance = sum/(n-1); // Variance Calculated
    sd = pow(variance, 0.5); // Standard Deviation Calculated

    printf("\nMean = %f\nVariance = %f\nStandard Deviation = %f", x, variance, sd);
    
    return 0;
}