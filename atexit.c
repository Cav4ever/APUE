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
        perror("Failed in fun:");
    }
    else {
        printf("continue\n");
    }

    signal(SIGINT, funSignal);
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

}
