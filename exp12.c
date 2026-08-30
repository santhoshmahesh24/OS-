#include <stdio.h>

void fifo() {
    int pages[50], frames[10];
    int n, f, i, j, k = 0;
    int fault = 0, found;
    printf("\n--- FIFO PAGE REPLACEMENT ---\n");
    printf("Enter Number of Pages: ");
    scanf("%d", &n);
    printf("Enter Reference String:\n");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter Number of Frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) frames[i] = -1;
    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if(found == 0) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            fault++;
        }
    }
    printf("Total Page Faults = %d\n", fault);
}

void lru() {
    int pages[50], frames[10], time[10];
    int n, f, i, j;
    int fault = 0, count = 0;
    int found, pos, min;
    printf("\n--- LRU PAGE REPLACEMENT ---\n");
    printf("Enter Number of Pages: ");
    scanf("%d", &n);
    printf("Enter Reference String:\n");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter Number of Frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) frames[i] = -1;
    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }
        if(found == 0) {
            min = time[0];
            pos = 0;
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }
            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            fault++;
        }
    }
    printf("Total Page Faults = %d\n", fault);
}

void optimal() {
    int pages[50], frames[10];
    int n, f, i, j, k, pos;
    int fault = 0, found;
    printf("\n--- OPTIMAL PAGE REPLACEMENT ---\n");
    printf("Enter Number of Pages: ");
    scanf("%d", &n);
    printf("Enter Reference String:\n");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter Number of Frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) frames[i] = -1;
    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if(found == 0) {
            for(j = 0; j < f; j++) {
                int future = 999;
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        future = k;
                        break;
                    }
                }
                if(j == 0 || future > pos) {
                    pos = future;
                }
            }
            frames[0] = pages[i];
            fault++;
        }
    }
    printf("Total Page Faults = %d\n", fault);
}

int main() {
    int choice;
    printf("====================================================\n");
    printf("     EXPERIMENT 12: PAGE REPLACEMENT ALGORITHMS     \n");
    printf("====================================================\n");
    printf("1. FIFO (First In First Out)\n");
    printf("2. LRU (Least Recently Used)\n");
    printf("3. Optimal Page Replacement\n");
    printf("4. Exit\n");
    printf("====================================================\n");
    printf("Enter choice (1-4): ");
    if (scanf("%d", &choice) != 1) return 0;

    switch(choice) {
        case 1: fifo(); break;
        case 2: lru(); break;
        case 3: optimal(); break;
        case 4: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}
