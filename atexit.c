#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fun(void);
void funSignal(int);

int main()
{
    printf("start\n");
    if (atexit(fun) != 0){
        perror("Failed in atexit:");
    }
    else {
        printf("continue\n");
    }

    signal(SIGINT, funSignal);
    //signal(SIGKILL, funSignal);
    signal(SIGTERM, funSignal);
    //fflush(stdout);
    sleep(20);

    return 0;
}

void fun(void)
{
    printf("end\n");
}

void funSignal(int sigNum)
{
    if (SIGINT == sigNum) {
        printf("end by Ctrl + C\n");
    }
    //else if (SIGKILL ==  sigNum) {//SIGKILL can't be ignored and handlering
    //    printf("end by kill -9\n");
    //}
    else if (SIGTERM ==  sigNum) {
        printf("end by SIGTERM kill -15\n");
    }
    exit(1);
}
