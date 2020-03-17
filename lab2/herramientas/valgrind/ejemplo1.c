#include <stdio.h>
#include <stdlib.h>

int main(){
  int *a=(int*)0xFF;
  *a=1;
  return EXIT_SUCCESS;
}
