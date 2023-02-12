#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void find_prime()
{
    int num;
    int pipdfd[2];
    int pid;

    if (read (0, &num, sizeof(num)) < 0)
        exit(1);

    if (pipe(pipefd) < 0)
        exit(1);

    printf("prime %d\n", num);

    pid = fork();
    if (pid == 0)
    {
        
    }
    else
    {

    }
}

int main(int argc, char *argv[])
{
    int pipefd[2];
    int pid;

    if (pipe(pipefd) == -1)
    {
        fprintf(2, "ERROR : pipe nonexist");
        exit(1);
    }

    pid = fork();
    if (pid == 0)
    {
        find_prime();
    }
    else
    {
        for (int i = 2; i < 36; i ++)
            write()
    }

    exit(0);
}
