#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[]) {
  printf("ID del proceso: %d\n", (int)getpid());
  printf("ID del padre de este proceso: %d\n", (int)getppid());
  for(;;) {
      pause();
  }
  return 0;
}
