#include <stdlib.h>

int main(){
  char *a=(char *)malloc(sizeof(char));
  free(a);
  free(a);
  return EXIT_SUCCESS;
}
