#include <stdio.h>
#include <stdlib.h>

#define NO_SCORE 5
#define NO_STUDENT 10

typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void readStudentData(Student *pStd);
void findTotalScore(Student *pStd);
float findAverage(Student s);
void findLessThanTen(Student s);

int main() {
    Student std[NO_STUDENT];
    FILE *fp;
    int i;

    for(i = 0; i < NO_STUDENT; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        readStudentData(&std[i]);
    }

    fp = fopen("std10.dat", "w");
    if (fp != NULL) {
        for(i = 0; i < NO_STUDENT; i++) {
            fprintf(fp, "%s %s", std[i].name, std[i].surname);
            for(int j = 0; j < NO_SCORE; j++) {
                fprintf(fp, " %d", std[i].score[j]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
        printf("\nSave to file std10.dat successfully!\n");
    }

    printf("\nReading data and calculating results...\n");
    for(i = 0; i < NO_STUDENT; i++) {
        findTotalScore(&std[i]);
        float avg = findAverage(std[i]);
        printf("\nAverage score is %.2f", avg);
        findLessThanTen(std[i]);
        printf("\n---------------------------\n");
    }
    return 0;
}

void readStudentData(Student *pStd) {
    printf("Name: "); scanf("%s", pStd->name);
    printf("Surname: "); scanf("%s", pStd->surname);
    for(int i = 0; i < NO_SCORE; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &pStd->score[i]);
    }
}

void findTotalScore(Student *pStd) {
    pStd->total = 0;
    printf("\nStudent: %s %s got score ", pStd->name, pStd->surname);
    for(int i = 0; i < NO_SCORE; i++) {
        printf("%4d", pStd->score[i]);
        pStd->total += pStd->score[i];
    }
    printf("\nTotal score is %.2f", pStd->total);
}

float findAverage(Student s) {
    return s.total / NO_SCORE;
}

void findLessThanTen(Student s) {
    int i, count = 0;
    printf("\nScore less than 10:");
    for(i = 0; i < NO_SCORE; i++) {
        if(s.score[i] < 10) {
            printf("\nTest no.%d - %d", i + 1, s.score[i]);
            count++;
        }
    }
    if(count == 0) printf(" -> None");
}