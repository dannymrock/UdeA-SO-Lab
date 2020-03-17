#include <stdio.h>

int factorial(int num);
int factorial_recursivo(int num);

int main() {
  int f1 = factorial(4);
  int f2 = factorial_recursivo(5);
  printf("4! = %d\n",f1);
  printf("5! = %d\n",f2);
  return 0;
}

int factorial(int num){
  int fac = 1;
  for(int i = 1; i <= num;i++) {
    fac = fac*i;  
  }
  return fac;
}

int factorial_recursivo(int num){
  if(num > 0) {
    return num*factorial_recursivo(num - 1);
  }
  else {
    return 1;
  }
}


