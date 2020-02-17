# Laboratorio de introducción al lenguaje C

> **Objetivos**
> * Reforzar los conceptos discutidos en el laboratorio.
> * Ir ganando experiencia en la resolución de problemas empleando lenguaje C. 

## Lecturas opcionales previas

Se recomienda antes de empezar revisar los siguientes enlaces:
1. **Teoria sobre la introduccion al lenguaje C**: La cual puede ser accedida en el siguiente [enlace](https://github.com/dannymrock/UdeA-SO-Lab/blob/master/lab0/lab0b/parte1/intro_C_basico.ipynb).

## Ejemplos resueltos

A modo de repaso se mostraran algunos ejercicios resueltos que implican el uso de programacion modular. Puede descargarlos, compilarlos y ejecutarlos.

1. Hacer un programa que calcule el máximo de 2 números.

**Solucion**: [example1.c](example1.c)

```C
#include <stdio.h>

int maximo(int a, int b); /* prototipo de funcion */

int main() {
    int x, y;
    int max;
    printf("Introduzca dos numeros: ");
    scanf("%d %d", &x, &y);
    max = maximo(x, y); /* llamada a la funcion */
    printf("El maximo es %d\n", max);
    return 0;
}

int maximo(int a, int b) /* definicion de la funcion */ {
    int max;
    if (a > b)
        max = a;
    else
        max = b;
    return max; /* devuelve el valor maximo */
}
```

**Comando de compilación**:

```bash
gcc -Wall example1.c -o exampĺe1.out
```

1. Hacer un programa que diga si un numero es cuadrado perfecto.
   
**Solucion**: [example2.c](example2.c)

```C
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
```

**Comando de compilación**:

```bash
gcc -Wall example2.c -o exampĺe2.out -lm
```

¿Por que en el anterior comando se uso la opción ```-lm```?

3. Hacer un programa que permita calcular el área de diferentes figuras geométricas.

**Solucion**: [example3.c](example3.c)

```C

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
```

**Comando de compilación**:

```bash
gcc -Wall example3.c -o exampĺe3.out -lm
```

4. Hacer una función que solicite 2 números, genere 10 números aleatorios entre estos 2
números y cuente la cantidad de números pares.

**Solucion**: [example4.c](example4.c)

```C

#include <stdio.h>
#include <stdlib.h> //rand() y srand()
#include <time.h>   //time()

int main (void)
{
  int min, max, num, cnt, i;
  printf("Digite los dos limites (minimo maximo): ");
  scanf("%d %d", &min, &max);
  cnt = 0;
  srand(time(NULL)); //genera la semilla
  for(i = 0; i < 10; i++)
  {
    num = rand()%(max - min + 1) + min;
    if(num % 2 == 0)
      cnt++;
    printf("%d ", num);
  }
  putchar('\n');
  printf("La cantidad de numeros pares generados es de: %d\n", cnt);
  return 0;
}
```

**Comando de compilación**:

```bash
gcc -Wall example4.c -o exampĺe4.out -lm
```


