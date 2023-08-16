#include <stdio.h>

int main(){
    int test_scores[20]={
        85,78,92,65,89,76,94,81,87,90,72,88,95,79,83,91,70,84,86,93
    }; // Scores of 20 students.

    float avg=0;
    int pass=0,failed=0;
    int highest = test_scores[0];

    int gradeO=0, gradeE=0, gradeA=0, gradeB=0, gradeF=0;

    for (int i = 0; i < 20; i++)
    {
        int currentMark = test_scores[i];
        
        avg+=currentMark;
        
        if(highest<currentMark){
            highest=currentMark;
        }

        if(currentMark>=60){pass++;}else{failed++;}

        if(currentMark>90){gradeO++;}
        if(80<currentMark && currentMark<=90){gradeE++;}
        if(70<currentMark && currentMark<=80){gradeA++;}
        if(60<currentMark && currentMark<=70){gradeB++;}
        if(currentMark<=60){gradeF++;}
    }

    printf("Average Marks : %.2f\nHighest Marks : %d\n\n", avg/20, highest);
    printf("Pass : %d\nFailed : %d", pass, failed);
    printf("\n\nGrades :-\n\n");
    printf("Grade O:- %d\nGrade E:- %d\nGrade A:- %d\nGrade B:- %d\nGrade F:- %d", gradeO, gradeE, gradeA, gradeB, gradeF);
    
    return 0;
}