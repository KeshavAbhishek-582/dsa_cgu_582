// Q4. Imagine you are developing a student grading system for aschool. The school has multiple classes, each with a fixednumber of students, and each student has grades for multiplesubjects. To efficiently manage this data, you decide to use amulti-dimensional array to store the student information. Design the data structure for the multi-dimensional array to store student grades. Consider that there are N classes, eachwith M students, and each student has grades for P subjects.

#include <stdio.h>

int main(){
    int N,M,P;
    // char GRADE[1];
    printf("Enter number of classes (N) : ");
    scanf("%d", &N);

    printf("Enter number of students (M) : ");
    scanf("%d", &M);

    printf("Enter number of subjects (P [1-5]) : ");
    scanf("%d", &P);

    if(P>0 && P<=5){


        printf("\nGrades which can be given : O, E, A, B, C, D, F\n\n");

        char array[N][M][P];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                for (int k = 0; k < P; k++)
                {
                    printf("Grade for Class-%d Student-%d Subject-%d :- ", i+1, j+1, k+1);
                    scanf("%s", &array[i][j][k]);
                }
            }
        }

        printf("\n\nGrades :-\n");

        for (int i = 0; i < N; i++)
        {
            printf("\n*****\nFor class-%d :-\n\n", i+1);
            for (int j = 0; j < M; j++)
            {
                for (int k = 0; k < P; k++)
                {
                    printf("Student-%d Subject-%d :- %c\n", j+1, k+1, array[i][j][k]);
                }
                printf("\n\n");
            }
        }

    }
    else{
        printf("Number of subjects out of scope.");
    }
    return 0;
}