
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  pid_t valor_retornado;
  printf("Ejemplo de fork. Este proceso va a crear otro proceso\n");
  printf("El PID del programa principal es: %d\n", (int)getpid());
  switch(valor_retornado = fork()) {
    case -1: // Caso de error
       printf("Error al crear el proceso");
    return -1;
    case 0: // Codigo ejecutado por el hijo
       printf("PROCESO HIJO:\n");
       printf("Mi PID es:%d\n", (int)valor_retornado);
    break;
    default: // Codigo ejecutado por el padre
      printf("PROCESO PADRE:\n");
      printf("El PID de mi hijo es:%d\n", (int)valor_retornado);
  }
  // Código ejecutado tanto por el padre como el hijo
  printf("Finalizando el programa...:\n");
  return 0;
}
