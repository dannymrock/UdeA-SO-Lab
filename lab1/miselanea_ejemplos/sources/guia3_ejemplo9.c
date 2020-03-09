
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  pid_t pid_h1, pid_h2, pid_h3;
  int status_h1, status_h2, status_h3;
  pid_t pid_n;
  int status_n;
  int i = 0;
  pid_h1 = fork();
  if(pid_h1 == 0) {
    i++;
    pid_n = fork();
    if( pid_n == 0 ) {
      i++;
      printf("NIETO: i = %d\n",i);
    }
    else {
      wait(&status_n); // Papa (hijo 1) esperando hijo (nieto)
      i++;
      printf("HIJO 1: finalizo nieto %u con estado %d\n", pid_n, status_n );
      printf("HIJO 1: i = %d\n",i);
    }
  }
  else {
    pid_h2 = fork();
    if(pid_h2 == 0) {
      i++;
      printf("HIJO 2: i = %d\n",i);
    }
    else {
      pid_h3 = fork();
      if(pid_h3 == 0) {
         i++;
         printf("HIJO 3: i = %d\n",i);
      }
      else {
         // El papa decidió esperar todos los hijos al final
         wait(&status_h1); // Papa esperando un hijo
     printf("PAPA: ha finalizado un hijo con estado %d\n", status_h1);
         wait(&status_h2); // Papa esperando otro hijo
    printf("PAPA: ha finalizado otro hijo con estado %d\n", status_h2);
         wait(&status_h3); // Papa esperando el ultimo hijo
     printf("PAPA: ha finalizado el ultimo hijo con estado %d\n", status_h3);
         i++;
         printf("PAPA: i = %d\n",i);
      }
    }
  }

  return 0;
}
