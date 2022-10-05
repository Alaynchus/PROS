// visualización de quien soy y quien es mi padre getpid.c
#include <stdio.h> //Libreria para el printf
#include <unistd.h> //Libreria para procesos como getpid
int main ()
	{	
	printf("El identificador de este proceso es PID = %d\n",(int)getpid ());
	printf("El identificador del proceso padre es PPID = %d\n",(int)getppid ());
	}