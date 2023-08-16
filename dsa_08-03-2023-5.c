#include <stdio.h>

int main(){
    int test_scores[20]={
        85,78,92,65,89,76,94,81,87,90,72,88,95,79,83,91,70,84,86,93
    }; // Scores of 20 students.

    float avg=0;
    int highest = test_scores[0];
    int lowest = test_scores[0];

    for (int i = 1; i < 20; i++)
    {
        avg+=test_scores[i];
        if(highest<test_scores[i]){
            highest=test_scores[i];
        }

        if(lowest>test_scores[i]){
            lowest=test_scores[i];
        }
    }
    
    printf("Average Marks : %.2f\nHighest Marks : %d", avg/20, highest);
    return 0;
}