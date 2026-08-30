#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    printf("====================================================\n");
    printf("   EXPERIMENT 1: OS INSTALLATION & SYSTEM COMMANDS  \n");
    printf("====================================================\n");
    printf("1. Display Windows Version (winver)\n");
    printf("2. Display System Information (systeminfo)\n");
    printf("3. Display Hostname (hostname)\n");
    printf("4. Display IP Configuration (ipconfig)\n");
    printf("5. Display Disk Partitions (diskpart)\n");
    printf("6. Exit\n");
    printf("====================================================\n");
    printf("Enter choice (1-6): ");
    if (scanf("%d", &choice) != 1) return 0;

    switch(choice) {
        case 1:
            system("winver");
            break;
        case 2:
            system("systeminfo");
            break;
        case 3:
            system("hostname");
            break;
        case 4:
            system("ipconfig");
            break;
        case 5:
            system("diskpart");
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}
