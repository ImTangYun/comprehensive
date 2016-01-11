#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int pfd1[2];
    int pfd2[2];
    if (pipe(pfd1) < 0) {
        printf("pipe error\n");
        return 0;
    }
    if (pipe(pfd2) < 0) {
        printf("pipe error\n");
        return 0;
    }
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        dup2(pfd1[0], STDIN_FILENO);
        dup2(pfd2[1], STDOUT_FILENO);
        close(pfd1[1]);
        close(pfd2[0]);
        char buff[100];
        system("php stdio.php");
    } else if (pid > 0) {
        close(pfd2[1]);
        close(pfd1[0]);
        char out_buf[100];
        char in_buf[100];
        int len = snprintf(out_buf, 100, "from father process of c code!\n");
        write(pfd1[1], out_buf, len);
        len = read(pfd2[0], in_buf, 100);
        in_buf[len] = '\0';
        printf("get data from son of php code: \n%s\n", in_buf);
    }
    return 0;
}
