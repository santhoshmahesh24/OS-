#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void prog1_fork_process() {
    pid_t pid = fork();
    if(pid < 0) {
        printf("Fork Failed\n");
        exit(1);
    } else if(pid == 0) {
        printf("\nCHILD PROCESS");
        printf("\nChild PID : %d", getpid());
        printf("\nParent PID : %d\n", getppid());
        exit(0);
    } else {
        wait(NULL);
        printf("\nPARENT PROCESS");
        printf("\nParent PID : %d", getpid());
        printf("\nParent's Parent PID : %d\n", getppid());
    }
}

void prog2_wait_demo() {
    pid_t pid = fork();
    if(pid == 0) {
        printf("Child Process Running\n");
        sleep(2);
        printf("Child Process Completed\n");
        exit(0);
    } else {
        wait(NULL);
        printf("Parent Resumes Execution\n");
    }
}

void prog3_close_demo() {
    int fd = open("exp3.c", O_RDONLY);
    if(fd < 0) {
        printf("File Opening Failed\n");
        return;
    }
    printf("File Opened Successfully\n");
    close(fd);
    printf("File Closed Successfully\n");
}

int main() {
    int choice;
    printf("====================================================\n");
    printf("   EXPERIMENT 3: SYSTEM CALLS (FORK, WAIT, CLOSE)   \n");
    printf("====================================================\n");
    printf("1. Process Creation (fork, getpid, getppid, exit)\n");
    printf("2. Wait System Call Demo\n");
    printf("3. Close System Call Demo\n");
    printf("4. Exit\n");
    printf("====================================================\n");
    printf("Enter choice (1-4): ");
    if (scanf("%d", &choice) != 1) return 0;

    switch(choice) {
        case 1: prog1_fork_process(); break;
        case 2: prog2_wait_demo(); break;
        case 3: prog3_close_demo(); break;
        case 4: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}
