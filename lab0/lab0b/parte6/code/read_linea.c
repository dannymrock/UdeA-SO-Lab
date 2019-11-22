#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char filename[80];
  char line[201];
  int numLinea = 1;
  FILE *iF;
  printf("Ingrese el nombre del archivo: ");
  fflush(stdin);
  scanf("%[^\n]s",filename); // Formato para que la entrada pueda aceptar espacios
  iF = fopen(filename,"r");
  if (iF == NULL) {
    printf("Error al abrir el archivo %s\n", filename);
    exit(-1);
  }
  while(fgets(line, 201, iF)!=NULL) {
    printf("%-5d",numLinea++);
    printf("%s",line);
  } 
  fclose(iF);
  exit(0);
}


