#include <stdio.h>

struct student
{
    int regno;
    char name[20];
};

void sequential_org() {
    FILE *fp;
    struct student s;
    printf("\n--- SEQUENTIAL FILE ORGANIZATION ---\n");
    fp = fopen("student.dat", "w");
    printf("Enter Register Number: ");
    scanf("%d", &s.regno);
    printf("Enter Name: ");
    scanf("%s", s.name);
    fprintf(fp, "%d %s\n", s.regno, s.name);
    fclose(fp);

    fp = fopen("student.dat", "r");
    fscanf(fp, "%d %s", &s.regno, s.name);
    printf("\nRecord Details\n");
    printf("Register Number : %d\n", s.regno);
    printf("Name : %s\n", s.name);
    fclose(fp);
}

void direct_org() {
    FILE *fp;
    struct student s;
    printf("\n--- DIRECT (RANDOM) FILE ORGANIZATION ---\n");
    fp = fopen("random.dat", "wb+");
    printf("Enter Register Number: ");
    scanf("%d", &s.regno);
    printf("Enter Name: ");
    scanf("%s", s.name);
    
    fwrite(&s, sizeof(s), 1, fp);
    rewind(fp);
    fread(&s, sizeof(s), 1, fp);
    
    printf("\nRecord Found\n");
    printf("Reg No : %d\n", s.regno);
    printf("Name : %s\n", s.name);
    fclose(fp);
}

void indexed_org() {
    struct student s[3];
    int key, i, found = 0;
    printf("\n--- INDEXED FILE ORGANIZATION ---\n");
    printf("Enter 3 Student Records (RegNo Name):\n");
    for(i = 0; i < 3; i++) {
        scanf("%d %s", &s[i].regno, s[i].name);
    }
    printf("Enter Register Number to Search: ");
    scanf("%d", &key);
    for(i = 0; i < 3; i++) {
        if(s[i].regno == key) {
            printf("\nRecord Found\n");
            printf("Reg No : %d\n", s[i].regno);
            printf("Name : %s\n", s[i].name);
            found = 1;
            break;
        }
    }
    if (!found) printf("Record Not Found\n");
}

int main() {
    int choice;
    printf("====================================================\n");
    printf("     EXPERIMENT 13: FILE ORGANIZATION TECHNIQUES    \n");
    printf("====================================================\n");
    printf("1. Sequential File Organization\n");
    printf("2. Direct (Random) File Organization\n");
    printf("3. Indexed File Organization\n");
    printf("4. Exit\n");
    printf("====================================================\n");
    printf("Enter choice (1-4): ");
    if (scanf("%d", &choice) != 1) return 0;

    switch(choice) {
        case 1: sequential_org(); break;
        case 2: direct_org(); break;
        case 3: indexed_org(); break;
        case 4: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}
