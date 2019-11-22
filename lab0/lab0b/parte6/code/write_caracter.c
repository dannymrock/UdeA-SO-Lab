#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generarCaracter(void);

int main() {
  srand(time(NULL)); // Inicializacion del generador
  char filename[80];
  int tam;
  char ch;
  FILE *outFile;
  printf("Ingrese el nombre de la cadena de ADN a generar: ");
  scanf("%[^\n]s",filename); // Formato para que la entrada pueda aceptar espacios
  printf("Ingrese el tamaño de la cadena: ");
  scanf("%d",&tam);
  outFile = fopen(filename,"w");
  for(int i = 0; i < tam; i++) {
    ch = generarCaracter(); // Generacion de la letra
    putc(ch,outFile);
  }
  putc('\0',outFile);
  fclose(outFile);
  exit(0);
}

char generarCaracter(void) {
  int randomNum = rand()%4; //Generando un aleatorio entre 0 y 3
  switch(randomNum) {
    case 0:
      return 'A';
    case 1:
      return 'G';
    case 2:
      return 'T';
    case 3:
      return 'C';
  }
}
