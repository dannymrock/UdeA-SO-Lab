/* Name: hello.c
 * Author: Sistemas Operativos UdeA
 * Purpose: Ejemplo de bienvenida
 * Compilation: 
 * Execution    : 
 */

#include <stdio.h>

#define TEST "Hello world!!!\n"

/* Programa que imprime un mensaje en pantalla */
int main(int argc, char *argv[])
{
  char str[] = TEST;
  printf("%s",str);
  return 0;
}