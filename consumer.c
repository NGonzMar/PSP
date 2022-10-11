#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h> // Libreria de isdigit()

int main(void)
{
  int  fp;
  int  p,  bytesleidos;
  char buffer[10];
  int esNumero = -1; // Inicializo a que no hay numeros
  

   p=mkfifo("FIFODAM",  S_IFIFO|0666); // 1er PARÁMETRO: el nombre y la ruta | 2º PARÁMETRO: permiso  de  lectura y escritura 
   // El valor de retorno normal, si todo va bien, de mkfifo, es 0. En caso de error, se devuelve -1
	
  while (1) // Bucle infinito
  {
	fp = open("FIFODAM", 0); // Enlace con el documento gracias al pipe
	bytesleidos=read(fp,buffer,1); // Se almacena el primer caracter del archivo
	printf("OBTENIENDO  Informacion...\n");

	while (bytesleidos!=0) // Mientras sea un valor entero
	{
	   if(isdigit(buffer[0])){ // Si la primera posicion del buffer contiene un numero
			esNumero = 0; // La variable que comprueba, indica que es un NUMERO
	   }

	   printf("%c",buffer[0]); // %C -> imprime cada caracter
	   bytesleidos=read(fp,buffer,1); // Leo  el siguiente  byte
	}

	// Para imprimir por pantalla
	if(esNumero == 0){ 
		printf("Hay numero\n");
		esNumero = -1;
	}else{
		printf(": Hay letra\n");
	}

	close(fp); 
  }  
return(0); 
}
