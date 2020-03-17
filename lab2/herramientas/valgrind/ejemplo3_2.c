#include <stdlib.h>

int main(){
  char *a=(char *)0xFF;
  free(a);
  return EXIT_SUCCESS;
}
