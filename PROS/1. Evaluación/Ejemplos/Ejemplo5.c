
// funcionesforkwait2.c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main ()
{ //UNO
    pid_t pid, Hijo_pid, pid2, Hijo2_pid;
    pid = fork();
    if (pid == -1)
    {//DOS
printf("No se ha podido crear el proceso hijo...");
	exit (-1);
    }//DOS
    if (pid == 0)   ////////// Nos encontramos en el proceso hijo
	{//TRES
		pid2 = fork(); ///////// Soy el hijo, creo el nieto
    		switch (pid2)
 		{//CUATRO
			case -1:
				printf("No se ha podido crear el proceso nieto...");
				exit (-1);
				break;
			case 0:
				printf ("Soy el proceso NIETO \n\t Mi PID es %d, El PID de mi padre es: %d.\n", getpid(), getppid());
				break;
			default:  ///////// Proceso padre (HIJO, padre del NIETO)
				Hijo2_pid = wait (NULL); //espero que acabe el hijo (NIETO)
			printf ("Soy el proceso HIJO \n\t Mi PID es %d, El PID de mi padre es: %d.\n\t Mi hijo : %d terminó. \n", getpid(), getppid(),Hijo2_pid);
		}  // Fin switch
	} //if (pid==0)
     	else ////// Nos encontramos en el proceso padre
	{
		Hijo_pid = wait(NULL); //espera a que acabe el hijo (HIJO)
		printf ("Soy el proceso PADRE \n\t Mi PID es %d, El PID de mi padre es: %d.\n\t Mi hijo : %d terminó. \n", getpid(), getppid(),pid);
	}
	exit(0);
}