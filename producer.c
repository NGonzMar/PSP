#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int  main()
{
   int  fp; 
   char  cadena[]= "Hola, soy una cadena.";
	
    fp = open("FIFODAM",1);

    printf("Mandando  informacion  al  FIFO...\n"); 
    write(fp,cadena,strlen(cadena));
    
   close(fp);
   return 0;
}
