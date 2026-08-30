#include <stdio.h>

void sequential_alloc() {
    int start, length, i;
    printf("\n--- SEQUENTIAL FILE ALLOCATION ---\n");
    printf("Enter Starting Block: ");
    scanf("%d", &start);
    printf("Enter File Length (Number of Blocks): ");
    scanf("%d", &length);
    printf("\nAllocated Blocks:\n");
    for(i = 0; i < length; i++) {
        printf("%d ", start + i);
    }
    printf("\n");
}

void indexed_alloc() {
    int n, indexBlock, blocks[20], i;
    printf("\n--- INDEXED FILE ALLOCATION ---\n");
    printf("Enter Index Block: ");
    scanf("%d", &indexBlock);
    printf("Enter Number of Blocks: ");
    scanf("%d", &n);
    printf("Enter Block Numbers:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
    }
    printf("\nIndex Block : %d\n", indexBlock);
    printf("Allocated Blocks : ");
    for(i = 0; i < n; i++) {
        printf("%d ", blocks[i]);
    }
    printf("\n");
}

void linked_alloc() {
    int n, blocks[20], i;
    printf("\n--- LINKED FILE ALLOCATION ---\n");
    printf("Enter Number of Blocks: ");
    scanf("%d", &n);
    printf("Enter Block Numbers:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
    }
    printf("\nLinked Allocation:\n");
    for(i = 0; i < n - 1; i++) {
        printf("%d --> ", blocks[i]);
    }
    printf("%d --> NULL\n", blocks[n - 1]);
}

int main() {
    int choice;
    printf("====================================================\n");
    printf("      EXPERIMENT 14: FILE ALLOCATION METHODS        \n");
    printf("====================================================\n");
    printf("1. Sequential File Allocation\n");
    printf("2. Indexed File Allocation\n");
    printf("3. Linked File Allocation\n");
    printf("4. Exit\n");
    printf("====================================================\n");
    printf("Enter choice (1-4): ");
    if (scanf("%d", &choice) != 1) return 0;

    switch(choice) {
        case 1: sequential_alloc(); break;
        case 2: indexed_alloc(); break;
        case 3: linked_alloc(); break;
        case 4: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}
