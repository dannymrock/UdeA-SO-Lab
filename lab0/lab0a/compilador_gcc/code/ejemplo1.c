/* Name: ejemplo1.c
 * Author: Sistemas Operativos UdeA
 * Purpose: Ejemplo de bienvenida
 * Compilation: gcc -Wall ejemplo1.c -o exe1
 * Execution    : ./exe1
 */

#include <stdio.h>
#include <unistd.h>

char nombre[50];
int main(void) {
 int pid = getpid();
 /* Solicitud de los datos al usuario */
 printf("Ingrese su nombre por favor: ");                   // Despliegue en pantalla
 scanf("%s", nombre);                                       // Entrada de datos
 /* Salida el programa */
 printf("Hola %s, su ID de proceso es %d\n", nombre, pid);  
 return 0;
}