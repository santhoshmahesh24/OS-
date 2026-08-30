#include <stdio.h>

void fcfs() {
    int n, i;
    int bt[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;
    printf("\n--- FCFS SCHEDULING ---\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
}

void sjf() {
    int n, i, j, temp;
    int bt[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;
    printf("\n--- SJF SCHEDULING (NON-PREEMPTIVE) ---\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
}

void priority_sched() {
    int n, i, j, temp;
    int bt[20], pr[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;
    printf("\n--- PRIORITY SCHEDULING ---\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter Priority for P%d: ", i + 1);
        scanf("%d", &pr[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(pr[i] > pr[j]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];
    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t\t%d\t%d\t%d\n", i + 1, pr[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
}

void round_robin() {
    int n, tq, i;
    int bt[20], rem_bt[20];
    int wt[20] = {0}, tat[20];
    int time = 0, done;
    float avg_wt = 0, avg_tat = 0;
    printf("\n--- ROUND ROBIN SCHEDULING ---\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;
                if(rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
    } while(!done);
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
}

int main() {
    int choice;
    printf("====================================================\n");
    printf("     EXPERIMENT 4: CPU SCHEDULING ALGORITHMS        \n");
    printf("====================================================\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Priority Scheduling\n");
    printf("4. Round Robin Scheduling\n");
    printf("5. Exit\n");
    printf("====================================================\n");
    printf("Enter choice (1-5): ");
    if (scanf("%d", &choice) != 1) return 0;

    switch(choice) {
        case 1: fcfs(); break;
        case 2: sjf(); break;
        case 3: priority_sched(); break;
        case 4: round_robin(); break;
        case 5: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}
