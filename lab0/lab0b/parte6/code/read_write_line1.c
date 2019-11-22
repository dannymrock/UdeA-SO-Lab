#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void complementar(char *cad);

int main() {
  char inFilename[80];
  char outFilename[80] = "complemento_";
  char adn_string[21]; 
  FILE *inFile;
  FILE *outFile;
  printf("Ingrese el nombre de la cadena de ADN a generar: ");
  fflush(stdin);
  scanf("%[^\n]s",inFilename); // Formato para que la entrada pueda aceptar espacios
  strcat(outFilename,inFilename);
  inFile = fopen(inFilename,"r");
  outFile = fopen(outFilename,"w");
  if (inFile == NULL) {
    printf("Error al abrir el archivo %s\n", inFilename);
    exit(-1);
  }
  while(fgets(adn_string, 21, inFile)!=NULL) {
    complementar(adn_string);
    fputs(adn_string, outFile); 
  }
  fclose(inFile);
  fclose(outFile);
  exit(0);
}

void complementar(char *cad) {
  while(*cad != '\0') {
    switch(*cad) {
      case 'A':
        *cad = 'T';
        break;
      case 'T':
        *cad = 'A';
        break;
      case 'G':
        *cad = 'C';
        break;
      case 'C':
        *cad = 'G';
        break;
    }
    cad++;
  }
}
