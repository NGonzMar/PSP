#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo; // Variables que almacenarán los pid del padre e hijo.
  pid = fork(); // El proceso padre usa el fork() para crear un proceso hijo.


    if (pid == 0) // Si el valor que el fork() devuelve es 0 (hijo) hará lo siguiente.
  {
    fork(); // El proceso hijo creará el proceso nieto.

    if(pid == 0) // Si el valor que el fork() devuelve es 0 (hijo) hará lo siguiente.
    { 
      printf("Soy el proceso 3(nieto) y mi PID es = %d\n",getpid()); // El proceso 3 o nieto muestra su PID
      printf ("\tEl pid de mi padre es %d\n\n",getppid()); // El proceso 3 o nieto muestra el PID de su padre(hijo).
    }

    wait(NULL); // Espera hasta que acabe

    printf("Soy el proceso 2(hijo) y mi PID es = %d\n",getpid()); // El proceso 2 o hijo muestra su PID.

    printf ("\tEl pid de mi padre es %d\n\n",getppid()); // El proceso 2 o hijo muestra el PID de su padre(abuelo).
      
      
  } 

  else // En caso de que fork() no devuelva 0
  {
    pid_hijo = wait(NULL); 

    printf("Soy el proceso 1(abuelo) y mi PID es = %d\n", getpid()); // El proceso 1 o abuelo muestra su PID.
   
    printf("\tEl pid de mi hijo es %d \n\n", pid_hijo); // El proceso 1 o abuelo muestra el PID de su hijo.
  }

  exit(0);
  
 }
