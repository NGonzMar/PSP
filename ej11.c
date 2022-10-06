#include <stdio.h>
#include <stdlib.h> //libreria para system()
#include <unistd.h> //libreria para sleep()

int main()
{
  printf("\nNombre del alumno: Nuria González Margallo\n");
  
  printf("\nNombre del usuario: \n");
  system("whoami");
  
  printf("\nContenido del directorio '/home/alumno/Descargas': \n");
  system("ls -S /home/alumno/Descargas");
  
  printf("\nEl proceso se esta ejecutando en la terminal: \n");
  system("tty");
   
  printf("\nMe voy a dormir 1 minuto... \n");
  sleep(60);
  printf("\n¡He despertado!\n");
  
  printf("\nInformacion del proceso:\n");
  system("ps -l");
  
  printf("\nFin del programa.\n");
}	