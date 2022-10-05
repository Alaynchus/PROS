// funcionfork.c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void main(){
    pid_t pid, pid_hijo;
    for (int i = 1; i < 4 ; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            printf("No se ha podido crear el hijo %d", i);
        }
        if (pid == 0)
        {
            printf("Soy el hijo %d, mi padre es %d y mi PID es %d", i, getppid(), getpid());
            printf("\n");
            exit(0);
        }
        wait(NULL);
    }

    printf("Proceso padre %d \n",getpid());
    
}
