#include <stdio.h>
#include <stdlib.h>

void addRecord(char *addName, int addAge);

int main() {
    char name[64]; int age;
    printf("Enter name: "); scanf("%s", name);
    printf("Enter age: "); scanf("%d", &age);
    addRecord(name, age);
    return 0;
}

void addRecord(char *addName, int addAge) {
    FILE *f;
    f = fopen("first.txt", "a");
    if(f != NULL) {
        fprintf(f, "%s %d\n", addName, addAge);
        fclose(f);
    }
}