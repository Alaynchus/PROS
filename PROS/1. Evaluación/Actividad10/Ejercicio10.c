#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

/*Simple código a llamar al recibir señal*/
void manejador (int signal)
{
	printf ("Señal recibida...%d\n", signal);
}

void main ()
{ 
	int pid_hijo, cont;
    cont=1;
	pid_hijo = fork(); 	//Creación del hijo
	switch (pid_hijo) 							
	{
    	case -1:	//No se ha creado al hijo
			printf("No se ha podido crear el proceso hijo...\n");
			exit(-1);
    	case 0:   	//Nos encontramos en el hijo
            while (cont<4)
            {
                kill(getppid(), SIGUSR1);   //Envia una señal al padre
                sleep(1);                    //Espera un segundo
                cont++;
            }
            kill(getppid(), SIGKILL);  //Matamos al padre
		default: 	//Nos encontramos en el padre			
			signal(SIGUSR1, manejador);
            wait(NULL);
	}
	exit(0);
}

