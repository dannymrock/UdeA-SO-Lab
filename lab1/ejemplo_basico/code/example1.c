#include <stdio.h>
#include <unistd.h>

/*
gcc -Wall example1.c -o example1.out

-> sleep
-> getpid
*/

int main (void){
  int pid_proceso = getpid();
  printf("Empezando proceso %d\n", pid_proceso);
  for(int i = 0; i < 3; i++) {
    sleep(1);
    printf("i = %d\n", i);
  }
  printf("Finalizando proceso %d\n", pid_proceso);
  return 0;
}
