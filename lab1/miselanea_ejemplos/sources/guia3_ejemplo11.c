#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  pid_t my_pid;
  my_pid = getpid();
  printf("Mi ID del proceso es: %d \n",(int)my_pid);
  printf("El ID del padre del proceso es: %d \n",(int)getppid());
  printf("Hola mundo. \n");
  printf("Hola mundo. \n");
  printf("Hola mundo. \n");
  printf("Hola mundo. \n");
  printf("Hasta la vista baby. \n");
  kill(my_pid,9);//Forma alternativa:kill(pid_hijo,SIGKILL);
  printf("Hasta la vista baby. \n");
  printf("Hasta la vista baby. \n");
  printf("Hasta la vista baby. \n");
  return 0;
}
