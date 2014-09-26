//
// a test of linux signal
// function: a timing program
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void my_func(int sig)
{
    if (sig == SIGALRM) {
        printf("geted a SIGALRM\n");
        signal(SIGALRM, my_func);
        alarm(5);
    }
}

int main()
{
    signal(SIGALRM, my_func);
    alarm(5);
    while (true) {
        sleep(100);
    }
    return 0;
}

