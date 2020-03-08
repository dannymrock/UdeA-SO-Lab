#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
gcc -Wall example3.c -o example3.out

-> sleep
-> getpid
-> fork
-> wait
*/
int main (void){
  char rol;
  int fin = 2;
  int i;
  int estado;
  printf("Empezando proceso %d\n", getpid());  
  if(fork() == 0) {
     // Código hijo
     rol = 'H';
     printf("Empezando proceso %d\n", getpid()); 
     fin = fin + 3;
     for(i = 0; i < fin; i++) {
       sleep(1);
       printf("%c -> i = %d\n",rol ,i);
     }
   }
   else {
     // Código padre
     rol = 'P';
     for(i = 0; i < fin; i++) {
       sleep(1);
       printf("%c -> i = %d\n",rol ,i);
     }
     int pid_h_espera = wait(&estado);
     if (pid_h_espera == 0) {
       printf("Bien chino - status: %d\n",estado);
       printf("Finish him: %d\n", pid_h_espera);
     }
     else {
       printf("Esperando al chino - status: %d\n",estado);
       printf("pid espera: %d\n", pid_h_espera);
     }   
     printf("\n");
   }
   // Código ejecutado por ambos (para el caso)
   printf("%c -> i = %d\n",rol ,i);
   printf("Finalizando proceso %d\n", getpid());
   return 0;
}
