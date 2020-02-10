/* main.c */
#include "mensajes.h"
#include "areas.h"
#include <stdio.h>

int main(){
    double b, h, A;
    printf("-----------------------------------------\n");
    hola();
    printf("-----------------------------------------\n");
    printf("Digite la base del triangulo: ");
    scanf("%lf", &b);
    printf("Digite la altura del triangulo: ");
    scanf("%lf", &h);
    A = area_triangulo(b, h); 
    printf("\n");
    printf("El area del triangulo es: %.2lf\n", A);
    printf("-----------------------------------------\n");
    void chao(void);
    printf("-----------------------------------------\n");
    return 0;
}
