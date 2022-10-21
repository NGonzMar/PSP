#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h> 
#include <time.h>

void main(){
				
     int fd[2];	
     int fd2[2];				
     int buffer[30];

     pid_t pid; // Proceso padre

     // Generacion de numero aleatorio
     time_t t;
     int numero1;
     srand((unsigned) time(&t));
     numero1=rand() % 10; 

     // Creamos el PIPE1
     pipe(fd); 

     // Creamos el PIPE2
     pipe(fd2);
     
     // Se crea un proceso hijo
     pid = fork();


    // Funcion que devuelve el factorial de un numero
    int factorial(int n)
    {   
        if(n == 0) return 1;
        else return n * factorial(n-1);
    } 


    if (pid==0)
    {
        // El hijo lee el PIPE1
        close(fd[1]); // Cierra el descriptor de escritura
        read(fd[0], buffer, sizeof(int));
        write(fd[0], buffer, sizeof(int));
        printf("El proceso padre genera el numero %d en el pipe1\n", buffer[0]);
                
        // El hijo calcula el factorial y lo escribe en el PIPE2        
        int resultadoFactorial = factorial(buffer[0]);
        close(fd2[0]); // Cierra el descriptor de lectura dos
        write(fd2[1], &resultadoFactorial, sizeof(int));
     
    }
     
     else
     
     {
     	// El numero se escribe en el PIPE1
        close(fd[0]); // Cierra el descriptor de lectura
        write(fd[1], &numero1, sizeof(int)); 
        wait(NULL); 
                
        // El padre lee el PIPE2 y muestra el factorial del numero
        close(fd2[1]); // Cierra el descriptor de escritura dos  
        read(fd2[0], buffer, sizeof(int));	
        printf("El factorial calculado por el proceso hijo: %d\n", buffer[0]);
     }
}
