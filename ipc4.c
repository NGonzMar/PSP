#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h> 
#include <time.h>

// Funcion que devuelve el factorial de un numero | Generada fuera de main para completo acceso 
int factorial(int n){   
    if(n == 0) return 1;
    else return n * factorial(n-1);
} 

void main(){
				
     int fd[2];	
     int fd2[2];				
     int buffer[30];

     pid_t pid; // Proceso padre

     // Creamos el PIPE1
     pipe(fd); 

     // Creamos el PIPE2
     pipe(fd2);
     
     // Se crea un proceso hijo
     pid = fork();

    if (pid==0)
    {
        // El hijo lee el PIPE1
        close(fd[1]); // Cierra el descriptor de escritura
        close(fd2[0]); // Cierra el descriptor de lectura dos

        read(fd[0], buffer, sizeof(int));
        write(fd[0], buffer, sizeof(int));
        printf("El proceso padre genera el numero %d en el pipe1\n", buffer[0]);
                
        // El hijo calcula el factorial y lo escribe en el PIPE2        
        int resultadoFactorial = factorial(buffer[0]);   
        write(fd2[1], &resultadoFactorial, sizeof(int));
     
    }
     
     else
     
     {
        // Generacion de numero aleatorio
        int numAleatorio()
        {
            time_t t;
            int numero1;
            srand((unsigned) time(&t));
            numero1=rand() % 10; 

            return numero1;
        }

     	// El numero se escribe en el PIPE1
        close(fd[0]); // Cierra el descriptor de lectura
        close(fd2[1]); // Cierra el descriptor de escritura dos  

        int numero1 = numAleatorio();
        write(fd[1], &numero1, sizeof(int)); 
        wait(NULL); 
                
        // El padre lee el PIPE2 y muestra el factorial del numero
        read(fd2[0], buffer, sizeof(int));	
        printf("El factorial calculado por el proceso hijo: %d\n", buffer[0]);
     }
}
