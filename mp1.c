#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {

  pid_t pid, hijo; // creacion de variable de almacenaje


  pid = fork(); // creacion de proceso hijo
	
	if(pid==0){

		printf("Nuria González Margallo\n");

	}else{

		hijo = wait(NULL); // el padre espera a que su hijo termine

		printf("Mi pid como padre es %d\n", getpid()); // se muestra el pid del padre

		printf("El pid de mi hijo es %d\n", hijo); // se nuestra el pid hijo

	}

	exit(0);
}
