#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h> 
#include <string.h>

// Función que devuelve la fecha y hora local
char* fechaHora()
{
    time_t hora;
    char* fecha;
    time(&hora);
    fecha = ctime(&hora);

    return fecha;
}

void main(){
				
     int fd[2]; // Hasta 3 elementos: 0, 1 ,2			
     char buffer[24]; // Buffer con tamaño 24
     pid_t pid; // Proceso padre

     // Creamos el PIPE1
     pipe(fd);
     
     // Se crea un proceso hijo
     pid = fork();

    if (pid==0)
    {
        close(fd[1]); // Cierra el descriptor de escritura
        printf("Soy el proceso hijo con pid %d\n", getpid());
        // El hijo lee el buffer del pipe1 | Si este no contiene nada, se bloquea hasta que el padre escriba algo en el
        read(fd[0], buffer, sizeof(buffer)); 
        printf("Fecha/Hora: %s\n", buffer); // Muestra por pantalla el contenido del buffer
        
    }
     
     else
     {
        close(fd[0]); // Cierra el descriptor de lectura

        char* fecha = fechaHora();
        write(fd[1], fecha, strlen(fecha));

        wait(NULL);
     }
}