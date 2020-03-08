#include <stdio.h>
#include <unistd.h>

/*
gcc -Wall example2.c -o example2.out

-> sleep
-> getpid
-> fork
*/
int main (void){
  char rol;
  int fin = 2;
  int i;
  printf("Empezando proceso %d\n", getpid());  
  if(fork() == 0) {
     // Codigo hijo
     rol = 'H';
     printf("Empezando proceso %d\n", getpid()); 
     fin = fin + 3;
     for(i = 0; i < fin; i++) {
       sleep(1);
       printf("%c -> i = %d\n",rol ,i);
     }
   }
   else {
     // Codigo padre
     rol = 'P';
     for(i = 0; i < fin; i++) {
       sleep(1);
       printf("%c -> i = %d\n",rol ,i);
     }
   }
   // Codijo ejecutado por ambos (para el caso)
   printf("%c -> i = %d\n",rol ,i);
   printf("Finalizando proceso %d\n", getpid());
   return 0;
}
