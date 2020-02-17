
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

void explicacion(void);
int cuadrado_perfecto(int x);

int main() {
    int n;
    int perfecto;
    explicacion();
    scanf("%d", &n);
    perfecto = cuadrado_perfecto(n);
    if (perfecto) {
        printf("%d es cuadrado perfecto.\n", n);
    }
    else {
        printf("%d no es cuadrado perfecto.\n", n);
    }
    return 0;
}

void explicacion(void) {
    printf("Este programa dice si un numero ");
    printf("es cuadrado perfecto \n");
    printf("Introduzca un numero: ");
}

int cuadrado_perfecto(int x) {
    int raiz;
    int perfecto;
    raiz = (int) sqrt(x);
    if (x == raiz * raiz) {
        perfecto = TRUE; /* cuadrado perfecto */
    }
    else {
        perfecto = FALSE; /* no es cuadrado perfecto */
    }
    return perfecto;
}
