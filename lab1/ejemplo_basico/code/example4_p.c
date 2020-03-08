#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
gcc -Wall example4_p.c -o example4_p.out

-> sleep
-> getpid
-> fork
-> wait
-> exec
*/
int main (void){
  int *status_code;
  printf("Padre -> \n");
  switch(fork()) {
    case 0:
      // Codigo del proceso hijo
      execl("./example4_h.out", "./example4_h.out", NULL);
    case -1: 
      // Error
      printf("ERROR!!!");
      break;
  }
  wait(status_code); // Ensayarlo sin comentarlo y comentandolo a ver que pasa
  printf("Esto no lo ejecutara el hijo\n");
  return 0;
}
