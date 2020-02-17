
#include <stdio.h>
#include <math.h>

#define PI 3.14

/*
#define TRIANGULO 1
#define RECTANGULO 2
#define CUADRADO 3
#define CIRCULO 4
*/

enum opcion{TRIANGULO = 1,RECTANGULO = 2,CUADRADO = 3,CIRCULO = 4};

/* Declaracion de las funciones */
void borrar_pantalla(void);
int menu(void);
float a_triangulo(float, float);
float a_cuadrado(float);
float a_circulo(float);
float a_rectangulo(float, float);

int main() {
    float A, r, l, b, h; /* Variables*/
    int opc;
    do {
        opc = menu();
        switch (opc) {
            case TRIANGULO:
                printf("\n\nAREA DEL TRIANGULO\n");
                printf("Digite la base: ");
                scanf("%f", &b);
                printf("Digite la altura: ");
                scanf("%f", &h);
                A = a_triangulo(b, h);
                printf("El area del triangulo es: %f\n", A);
                break;
            case RECTANGULO:
                printf("\n\nAREA DEL RECTANGULO\n");
                printf("Digite la base: ");
                scanf("%f", &b);
                printf("Digite la altura: ");
                scanf("%f", &h);
                A = a_rectangulo(b, h);
                printf("El area del rectangulo es: %f\n", A);
                break;
            case CUADRADO:
                printf("\n\nAREA DEL CUADRADO\n");
                printf("Digite el lado: ");
                scanf("%f", &l);
                A = a_cuadrado(l);
                printf("El area del cuadrado es: %f\n", A);
                break;
            case CIRCULO:
                printf("\n\nAREA DEL CIRCULO\n");
                printf("Digite el radio: ");
                scanf("%f", &r);
                A = a_circulo(r);
                printf("El area del cuadrado es: %f\n", A);
                break;
            default:
                printf("\n\nOPCION INVALIDA !!!!\n");
        }
        printf("\nPresione 1 si desea continuar u otro valor para terminar: ");
        scanf("%d",&opc);
        borrar_pantalla();
    }while(opc==1);
    printf("Fin del programa, Suerte es que le digo\n");
    return 0;
}

void explicacion(void) {
    printf("Este programa dice si un numero ");
    printf("es cuadrado perfecto \n");
    printf("Introduzca un numero: ");
}

float a_triangulo(float ancho, float alto) {
  float area; /* Area of the triangle */
  area = ancho * alto / 2.0;
  return (area);
}

float a_cuadrado(float lado) {
  /* Area del cuadrado */
  return lado*lado;
}

float a_circulo(float radio) {
  /* Area del circulo */
    float area;
    area = PI*radio*radio;
    return area;
}

float a_rectangulo(float ancho, float alto) {
  float area; /* Area of the triangle */
  area = ancho * alto;
  return (area);
}


int menu(void) {
    int opc; // Variable que almacena la opcion seleccionada
    printf("PROGRAMA QUE CALCULA EL AREA DE DIFERENTES FIGURAS GEOMETRICAS\n\n");
    printf("1. Area del triangulo\n");
    printf("2. Area del rectangulo\n");
    printf("3. Area del cuadrado\n");
    printf("4. Area del circulo\n");
    printf("\n\nElija una opcion: ");
    scanf("%d",&opc);
    return opc;
}

void borrar_pantalla(void) {
    printf("\033[2J\033[0;0f");
    printf("\033[%d;%df", 0, 0);
}
