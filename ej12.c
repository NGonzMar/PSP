#include <stdio.h>
#include <stdlib.h> //libreria para system()
#include <unistd.h> //libreria para sleep()
#include <string.h> //libreria para strncpy()

int main()
{
  char dni[]= "54302907E"; //variable tipo array de tipo char de 8 posiciones para almecenar el dni
  
  char ultimos4[5]; //variable tipo array de tipo char de 4 posiciones para almacenar los ultimos 4 caracteres
  
  printf("\nNombre del alumno: \nNuria González Margallo\n");
  
  printf("\nNombre del usuario: \n");
  system("whoami");
  
  
  printf("\nEL DNI es: %s\n", dni);
  
  // sacar los ultimos 4 caracteres del dni
  strncpy(ultimos4,&dni[4],4); // [n] -> posicion , n -> longitud
  ultimos4[4] = '\0'; // en la siguiente posicion elimino todo lo demas
  printf("\nLas ultimas cifras del DNI son: %s\n", ultimos4);
  
  sleep(120);
  
  printf("\nFin del programa.\n");
}	