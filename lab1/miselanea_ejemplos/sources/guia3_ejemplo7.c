#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  pid_t pid_hijo;
  printf("El pid del programa principal es: %d\n",(int)getpid());

  switch(pid_hijo=fork()) {

    case -1: /* Código ejecutado en caso de error*/
      printf("Error al crear el proceso");
      return -1;
    case 0: /* Código ejecutado por el hijo */
      printf("Hijo: Valor de retorno fork: %d\n",(int)pid_hijo);
      printf("Hijo: Mi PID: %d\n",(int)getpid());
      printf("Hijo: PID del padre: %d\n",(int)getppid());
      exit(0);
    printf("Esta instrucción nunca se ejecutara en el proceso hijo\n");
      break;
    default: /* Código ejecutado por el padre */
      printf("Padre: PID del proceso hijo: %d\n",(int)pid_hijo);
      printf("Padre: Mi PID: %d\n",(int)getpid());
      printf("Padre: PID de mi padre: %d\n",(int)getppid());
  }
  return 0;
}
