#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*El proceso padre le envia una señal al hijo y viceversa y ambas son funciones definidas por el usuario*/

/* gestión de señales en proceso padre*/
void manejadorHijo( int numsenal )
{
 printf("Hijo recibe señal número: %d\n", numsenal);
 
}

void manejadorPadre(int numsenal){
    printf("Padre recibe señal número: %d\n", numsenal);
}

int main()
{
  int pid_hijo;  
  pid_hijo = fork(); //creamos hijo   
  
  switch(pid_hijo)
     case -1:
  {
          printf( "Error al crear el proceso hijo...\n");
          exit( -1 );        
     case 0:   //HIJO     	         
          signal(SIGUSR1, manejadorHijo); //Función manejadora de la señal
          pause();
          printf("Soy el hijo y le mando la señal %d a mi padre\n",getppid());
          kill(getppid(), SIGUSR1);
          
          break;    
     default: 
          //PADRE envia 1 señal
          signal(SIGUSR1, manejadorPadre);
          sleep(1);
          kill(pid_hijo, SIGUSR1);//ENVIA SEÑAL AL HIJO 
          pause(); // Espera a recibir la señal del hijo
          sleep(1);
          break;
  } 
  return 0;
}
