#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char inFilename[80];
  char outFilename[80] = "inventario_";
  char cntS[10];
  int tam;
  char ch;
  int cnt[] = {0,0,0,0}; 
  FILE *inFile;
  FILE *outFile;
  int i, j;
  printf("Ingrese el nombre de la cadena de ADN a generar: ");
  scanf("%[^\n]s",inFilename); // Formato para que la entrada pueda aceptar espacios
  inFile = fopen(inFilename,"r");
  if (inFile == NULL) {
    printf("Error al abrir el archivo %s\n", inFilename);
    exit(-1);
  }
  do {
    ch = getc(inFile);
    if(ch == 'A') {
      cnt[0]++;
    }
    else if(ch == 'G') {
      cnt[1]++;
    }
    else if(ch == 'T') {
      cnt[2]++;
    }
    else if(ch == 'C') {
      cnt[3]++;
    }
  } while(ch != EOF);
  fclose(inFile);
  strcat(outFilename,inFilename);
  outFile = fopen(outFilename,"w");
  for(i = 0; i < 4; i++) {
    snprintf(cntS,10,"%d", cnt[i]);
    j = 0;
    while(cntS[j] != '\0') {
      putc(cntS[j],outFile);
      j++;
    }
    putc(' ',outFile);
  }
  putc('\0',outFile);
  fclose(outFile);
  exit(0);
}
