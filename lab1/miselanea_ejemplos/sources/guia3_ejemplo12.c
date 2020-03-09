#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main () {
  pid_t child_pid;
  /* Creacion del proceso hijo. */
  child_pid = fork ();
  if (child_pid > 0) {
    /*Este es el proceso padre el cual duerme por 20 segundos.*/
    sleep (20);
  }
  else {
    /* Este es el proceso hijo el cual culmina inmediatamente.*/
    exit (0);
  }
  return 0;
}
