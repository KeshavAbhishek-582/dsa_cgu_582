#include <stdio.h>

int main(){
    int temperature_data[]={25,28,27,30,31,29,26};
    float avg;
    int high = temperature_data[0];
    int low = temperature_data[0];

    for (int i = 0; i < sizeof(temperature_data)/sizeof(int); i++)
    {
        avg+=temperature_data[i];
        if(high<temperature_data[i]){
            high=temperature_data[i];
        }

        if(low>temperature_data[i]){
            low=temperature_data[i];
        }
    }

    printf("\nA. Average Temperature : %f\nB. Hottest : %d\t\tColdest : %d\nC. Temperature Difference : %d\n", avg/(sizeof(temperature_data)/sizeof(int)), high, low, high-low);
    
    return 0;
}