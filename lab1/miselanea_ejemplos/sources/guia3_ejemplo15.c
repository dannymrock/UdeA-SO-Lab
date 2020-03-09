#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>


int main(int argc, char *argv[]) {
  pid_t pid_h1, pid_h2;
  int status;
  pid_h1 = fork();
  if(pid_h1 == 0) {
    // Proceso hijo el cual ejecuta el comando ls
    execl("/bin/ls","/bin/ls","/",NULL);
  }
  else {
    pid_h2 = fork();
    if(pid_h2 == 0) {
      // Proceso hijo que ejecuta el comando date
      execl("/bin/date","/bin/date",NULL);
    }
    else {
      // Proceso padre
      wait(&status); // wait para esperar un proceso
      wait(&status); // wait para esperar el otro proceso
      printf("Hasta la vista baby\n");
    }
  }
  return 0;
}
