#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main ()
{	
	pid_t pid, pidPadre;

	int n = 20; //Damos a n valor 20 como ejemplo. Este programa debería crear 20 hijos al proceso padre
	pid = fork(); //Creamos un primer proceso hijo antes de entrar al bucle
	for(int i = 1; i <= n; i++)
	{
        if(pid == -1){
            printf("No se ha podido crear al hijo %d\n", i);
			exit(-1);
        }
        else{
            printf("Soy el hijo %d, Mi padre es %d y mi PID es %d\n", i, getppid(), getpid());
			pid = fork(); //Creamos un hijo al proceso hijo
	
        }
        pidPadre = wait(NULL); //Esperamos a que termine el hijo del proceso en el que nos encontramos
		exit(0);

	}
	pidPadre = wait(NULL); //Esperamos a que todos los procesos por debajo del padre terminen
	exit(0); //Cerramos el proceso padre
}