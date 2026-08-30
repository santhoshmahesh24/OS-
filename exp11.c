#include <stdio.h>

void first_fit() {
    int blockSize[20], processSize[20], allocation[20];
    int nb, np, i, j;
    printf("\n--- FIRST FIT MEMORY ALLOCATION ---\n");
    printf("Enter Number of Blocks: ");
    scanf("%d", &nb);
    printf("Enter Number of Processes: ");
    scanf("%d", &np);
    printf("Enter Block Sizes:\n");
    for(i = 0; i < nb; i++) scanf("%d", &blockSize[i]);
    printf("Enter Process Sizes:\n");
    for(i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }
    for(i = 0; i < np; i++) {
        for(j = 0; j < nb; j++) {
            if(blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if(allocation[i] != -1) printf("%d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
}

void best_fit() {
    int blockSize[20], processSize[20], allocation[20];
    int nb, np, i, j, bestIdx;
    printf("\n--- BEST FIT MEMORY ALLOCATION ---\n");
    printf("Enter Number of Blocks: ");
    scanf("%d", &nb);
    printf("Enter Number of Processes: ");
    scanf("%d", &np);
    printf("Enter Block Sizes:\n");
    for(i = 0; i < nb; i++) scanf("%d", &blockSize[i]);
    printf("Enter Process Sizes:\n");
    for(i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }
    for(i = 0; i < np; i++) {
        bestIdx = -1;
        for(j = 0; j < nb; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if(allocation[i] != -1) printf("%d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
}

void worst_fit() {
    int blockSize[20], processSize[20], allocation[20];
    int nb, np, i, j, worstIdx;
    printf("\n--- WORST FIT MEMORY ALLOCATION ---\n");
    printf("Enter Number of Blocks: ");
    scanf("%d", &nb);
    printf("Enter Number of Processes: ");
    scanf("%d", &np);
    printf("Enter Block Sizes:\n");
    for(i = 0; i < nb; i++) scanf("%d", &blockSize[i]);
    printf("Enter Process Sizes:\n");
    for(i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }
    for(i = 0; i < np; i++) {
        worstIdx = -1;
        for(j = 0; j < nb; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if(worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if(allocation[i] != -1) printf("%d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
}

int main() {
    int choice;
    printf("====================================================\n");
    printf("     EXPERIMENT 11: MEMORY ALLOCATION METHODS       \n");
    printf("====================================================\n");
    printf("1. First Fit Memory Allocation\n");
    printf("2. Best Fit Memory Allocation\n");
    printf("3. Worst Fit Memory Allocation\n");
    printf("4. Exit\n");
    printf("====================================================\n");
    printf("Enter choice (1-4): ");
    if (scanf("%d", &choice) != 1) return 0;

    switch(choice) {
        case 1: first_fit(); break;
        case 2: best_fit(); break;
        case 3: worst_fit(); break;
        case 4: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}
