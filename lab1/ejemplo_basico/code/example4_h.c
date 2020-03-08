#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
gcc -Wall example4_h.c -o example4_h.out

-> sleep
-> getpid
*/

int main (void){
  for(int i = 0; i < 3; i++) {
    sleep(1);
    printf("i = %d\n", i);
  }
  return 0;
}
