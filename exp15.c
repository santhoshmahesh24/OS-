#include <stdio.h>
#include <stdlib.h>

void fcfs_disk() {
    int req[20], n, head, i, seek = 0;
    printf("\n--- FCFS DISK SCHEDULING ---\n");
    printf("Enter Number of Requests: ");
    scanf("%d", &n);
    printf("Enter Request Queue:\n");
    for(i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter Initial Head Position: ");
    scanf("%d", &head);
    for(i = 0; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
    }
    printf("Total Head Movement = %d\n", seek);
}

void sstf_disk() {
    int req[20], visited[20] = {0};
    int n, head, i, count = 0;
    int seek = 0, index, min, distance;
    printf("\n--- SSTF DISK SCHEDULING ---\n");
    printf("Enter Number of Requests: ");
    scanf("%d", &n);
    printf("Enter Request Queue:\n");
    for(i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter Initial Head Position: ");
    scanf("%d", &head);
    while(count < n) {
        min = 9999;
        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                distance = abs(req[i] - head);
                if(distance < min) {
                    min = distance;
                    index = i;
                }
            }
        }
        seek += min;
        head = req[index];
        visited[index] = 1;
        count++;
    }
    printf("Total Head Movement = %d\n", seek);
}

void scan_disk() {
    int head = 53;
    printf("\n--- SCAN DISK SCHEDULING ---\n");
    printf("Initial Head Position : %d\n", head);
    printf("Head moves towards higher cylinders,\n");
    printf("then reverses direction.\n");
}

void cscan_disk() {
    int head = 53;
    printf("\n--- C-SCAN DISK SCHEDULING ---\n");
    printf("Initial Head Position : %d\n", head);
    printf("Head moves in one direction.\n");
    printf("After reaching the end, it returns to the beginning.\n");
}

int main() {
    int choice;
    printf("====================================================\n");
    printf("      EXPERIMENT 15: DISK SCHEDULING ALGORITHMS     \n");
    printf("====================================================\n");
    printf("1. FCFS Disk Scheduling\n");
    printf("2. SSTF Disk Scheduling\n");
    printf("3. SCAN Disk Scheduling\n");
    printf("4. C-SCAN Disk Scheduling\n");
    printf("5. Exit\n");
    printf("====================================================\n");
    printf("Enter choice (1-5): ");
    if (scanf("%d", &choice) != 1) return 0;

    switch(choice) {
        case 1: fcfs_disk(); break;
        case 2: sstf_disk(); break;
        case 3: scan_disk(); break;
        case 4: cscan_disk(); break;
        case 5: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}
