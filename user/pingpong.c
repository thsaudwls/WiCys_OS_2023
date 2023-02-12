#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
    int pipefd[2];
    int pid;
    char msg[6] = "Hello";

    if (pipe(pipefd) == -1)
        exit(1);

    pid = fork();
    if (pid == -1)
        exit(1);

    if (pid == 0)
    {
        write(pipefd[1], msg, strlen(msg));
        printf("%d: received ping\n", getpid());
    }
    else if (pid > 0)
    {
        wait(0);
        read(pipefd[0], msg, strlen(msg));
        printf("%d: received pong\n", getpid());
    }
    exit(0);
}
