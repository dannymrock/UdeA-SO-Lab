#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Inicializacion del generador
  char outFilename[80];
  int N;
  int num;
  FILE *outFile;
  printf("Ingrese el nombre del archivo: ");
  fflush(stdin);
  scanf("%[^\n]s",outFilename); // Formato para que la entrada pueda aceptar espacios
  fflush(stdin);
  printf("La cantidad de numeros que desea que se guarden en este: ");
  scanf("%d", &N);
  outFile = fopen(outFilename,"w");
  for(int i = 0; i < N; i++) {
    num = rand()%101; //Generando un aleatorio entre 0 y 100
    // printf("%d\n",num);
    fprintf(outFile,"%d\n",num);
  }
  fclose(outFile);
  exit(0);
}
