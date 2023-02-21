#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include  <string.h>

void main(){
    
   int fd1[2];
   int fd2[2];

   char buffer1[9];
   char buffer2[1];

   char letra[1];
   int dni;

   // Creación de proceso padre
   pid_t pid;

   // Creación del pipe1
   pipe(fd1);

   // Creación del pipe2
   pipe(fd2);

   //Se crea un proceso hijo
   pid = fork();

   // Función que valida un DNI
   char* validarDNI()
   {
      char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
      dni = atoi(buffer1); // atoi -> Convertir una cadena a int
      dni %= 23;
      letra[0] = letras[dni];

      return letra;
   }

   if (pid==0)
   {
      close(fd1[0]); // Cierra el descriptor de lectura
      close(fd2[1]); // Cierra el descriptor de escritura

      printf("Introduce el número de tu DNI: "); // Se pide por teclado un DNI
      scanf("%i", &dni); // Recogida de variable DNI
        
      sprintf(buffer1,"%i",dni); // Se muestra el el DNI introducido
      write(fd1[1], buffer1, 9); 

      read(fd2[0], buffer2, 1);
      printf("La letra del NIF es: %s \n \n", buffer2);
   }
   else
   {
      close(fd1[1]); // Cierra el descriptor de lectura
      close(fd2[0]); // Cierra el descriptor de escritura

      read(fd1[0], buffer1, 9);

      validarDNI(); // Se ejecuta la funcion validarDNI(return letra)
      write(fd2[1], letra, 1);

      wait(NULL);
   }  
}