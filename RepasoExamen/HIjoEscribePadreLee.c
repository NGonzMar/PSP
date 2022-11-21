#include <unistd.h> // pipe()
#include <stdlib.h> // exit()
#include <stdio.h> // printf()

int main(void){

    int fd[2]; // Array de dos posiciones con los FileDescriptors
    pid_t pidC; // Variable que recoge el PID del proceso hijo
    char buf[10]; // Buffer donde se almacenara el mensaje del hijo
    int num;

    pipe(fd);  // Función pipe() con la variable fd
    pidC = fork();

    switch(pidC)
    {
        case 0: // Hijo
            close(fd[0]); // Se cierra su descriptor de lectura (escribe)
            write(fd[1], "abcde", 5); // 1º fd de lectura, 2º mensaje, 3º tamaño en bytes
            close(fd[0]); // Se cierra descriptor de escritura
            exit(0); // Termina
            break;

        case -1: // Error
            
            printf("Error");

            break;

        default: // Padre

            close(fd[1]); // Se cierra su descriptor de escritura (lee)
            num = read(fd[0], buf, sizeof(buf)); // 1º fd de escritura, 2º buffer, 3º max bytes que queremos leer
            printf("Padre lee %d bytes %s \n", num, buf);
            close(fd[1]); // Se cierra descriptor de lectura

            break;
    }

    return 0;

}