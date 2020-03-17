#include <stdlib.h>

int main(){
  int i, j;
  int a[10], b[10];
  for ( i = 0; i < 10; i++ ) {
    j = a[i];
    b[i] = j;
  }
  return EXIT_SUCCESS;
}
