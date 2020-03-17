#include <stdlib.h>

int main(){
  int *a=(int *)malloc(1024*sizeof(int));
  int *b=(int *)malloc(10*sizeof(int));
  *a=1;
  b=(int *)NULL;
  return EXIT_SUCCESS;
}
