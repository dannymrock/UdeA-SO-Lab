# Introduccion al lenguaje C

## Objetivos ##

> 1. Retomar los conteptos adquiridos hasta el momento.
> 2. Aplicar lo aprendido en el desarrollo de aplicaciones para los laboratorios posteriores del curso.

Para profundizar mas sobre la información que se tratara a continuación, puede consultar los siguientes links:
1. [GCC and Make - Compiling, Linking and Building C/C++ Applications](https://www.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)
2. [Manejo básico del GNU Compiler Collection (GCC)](https://github.com/dannymrock/UdeA-SO-Lab/tree/master/lab0/lab0a/compilador_gcc/opcional)
3. [GCC and Make - Compiling, Linking and Building C/C++ Applications](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)
4. [Una Introducción a GCC](http://www.nongnu.org/gccintro-es/gccintro.es.pdf)

## Recordando el manejo del gcc GCC ##

### Compilación en una sola etapa ###

En este tipo de compilación solo se genera el ejecutable. A continuación se describen los pasos:

1. **Codifique el programa**: Asumiendo que el programa se almacena como **main.c**

```c
/* main.c */
#include <stdio.h>

int main (void) {
 printf ("Hello, world!\n");
 return 0;
}
```

2. **Compile el programa**: En su forma mas básica puede usar el siguiente comando

```bash
gcc -Wall main.c -o main
```

3. **Ejecute el programa**: 

```bash
./main
Hello, world!
```

### Compilación por etapas ###

En este tipo de compilación se generan los archivos objeto y el ejecutable. Es un método util sobre todo en los casos en los que se tienen aplicaciones multiarchivo. Supongamos que se tiene una aplicación la cual esta compuesta por los siguientes codigos fuente:
* **funciones.h**: 

```c
/* funciones.h */
#ifndef FUNCIONES_H
#define FUNCIONES_H
  void print_hello();
  int factorial(int n);
#endif
```

* **hello.c**:

```c
/* hello.c */
#include "funciones.h"
#include <stdio.h>

void print_hello(){
   printf("Hello World!\n");
}
```

* **factorial.c**:

```c
/* factorial.c */
#include "funciones.h"

int factorial(int n){
    if(n!=1){
	  return(n * factorial(n-1));
    } 
    else {
      return 1;
    }
}
```

* **main.c**:

```c
/* main.c */
#include "funciones.h"
#include <stdio.h>

int main(){
    print_hello();
    printf("\n");
    printf( "The factorial of 5 is %d\n",factorial(5));
    return 0;
}
```

Este proceso de lleva a cabo en dos etapas principales:
1. **Etapa 1**: Generar el **codigo objeto** (.o) de cada codigo fuente.

```bash
gcc -I. -Wall -c funciones.c
gcc -I. -Wall -c main.c
```

2. **Etapa 2**: Enlazar los archivos objeto previamente generados para crear el archivo ejecutable:

```bash
gcc funciones.o main.o -o app_example.out
```

Finalmenge lo que resta es ejecutar la aplicación:

```bash
./app_example.out
```

## Librerias ##

### Librerias estaticas ###

Son archivos especiales con extencion **.a**s creados a partir de los archivos objeto **.o** usando el GNU archiver **ar** el cual se usado por el linker (enlazador) para resolver las referencias en tiempo de compilación. Por ejemplo dados los siguientes archivos:

* **areas.h**: 

```c
/* areas.h */
#ifndef AREAS_H
#define AREAS_H
  double area_triangulo(double, double);
  double area_rectangulo(double, double);
  double area_trapecio(double, double);
  double area_circulo(double);
#endif
```

* **areas.c**: 

```c
/* areas.c */
/* areas.h */
#ifndef AREAS_H
#define AREAS_H
  
  #define PI 3.14
  double area_triangulo(double, double);
  double area_rectangulo(double, double);
  double area_trapecio(double, double, double); 
  double area_circulo(double);
#endif
```



* **mensajes.h**: 

```c
/* mensajes.h */
#ifndef MENSAJES_H
#define MENSAJES_H
  void hola(void);
  void chao(void);
#endif
```

* **mensajes.c**: 

```c
/* mensajes.c */
#include "mensajes.h"
#include <stdio.h>

void hola(void) {
  printf("Mr. Anderson!!! Welcome back\n");
}

void chao(void) {
  printf("Hasta la vista baby\n");
}
```


* **main.c**: 


```c
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
```
Veamos el proceder:
* **Paso 1**: Generar los archivos objeto a partir de loas archivos fuente **excepto del que contiene la función main**

```bash
gcc -I. -Wall -c mensajes.c
gcc -I. -Wall -c areas.c
```

* **Paso 2**: Crear la libreria estatica usando la opción **cr (create and replace)** del **ar**. :

```bash
ar cr libapp.a areas.o mensajes.o
```

Use la opcion **t (table of contents)** para listar los archivos objeto de la libreria creada:

```bash
ar t libapp.a 
```

Luego se procede a generar el ejecutable:

```bash
gcc main.c libapp.a -o main 
```

Otra forma es usar el cortocircuito **-l** para enlazar la libreria sin necesidad de poner la extención (**-a** en este caso). 


En general la opción **-lNAME** enlazara loa archivos objeto con el archivo de libreria ** libNAME.a** in los directorios de la libreria estandar.

Adicionalmente se usa el parametro **-L** para indicar la ruta donde se encuentran las librerias. Para el caso tenemos:

```bash
gcc main.c -L. -lapp -o main 
```

### Librerias dinamicas ###


Son manejadas con una forma mas avanzada de enlazado el cual hace que los archivos ejecutables sean mas pequeños. Estas librerias tienen la extención **.so**.

A continuación se explican los pasos para llevar a cabo la creación de una libreria dinamica:

* **Paso 1**: Compile los archivos fuente (**.c**) usando, además de las opciones normalmente empleadas, la opción **-fPIC**:

```bash
gcc -I. -Wall -fPIC -c mensajes.c
gcc -I. -Wall -fPIC -c areas.c
```

* **Paso 2**: Crear la libreria dinámica a partir de los archivos objetos previamente generados, para ello emplee con la opción **-shared**. 

```bash
gcc -shared -o libappdyn.so areas.o mensajes.o
```

* **Paso 3**: Como la libreria dinámica es enlazada en tiempo de ejecución, es necesario que este se encuentre disponible en dicho momento. El dynamic linker busca las rutas estandar disponibles en **LD_LIBRARY_PATH** y en la cache del sistema (se recomienda explorar el comando **ldconfig**) las librerias dinamicas. De modo que el proximo paso consiste en **agregar el directorio en el cual se encuentra la libreria dinamica a enlazar en la variable de entorno LD_LIBRARY_PATH** de modo que el linker pueda encontrar su archivo de libreria. A continuación se muestra como.

```c
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/my_path/
```

Para nuestro caso entonces el comando en cuestión será:

```c
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD
echo $LD_LIBRARY_PATH
```

Si no se quiere hacer uso de la variable de entorno **LD_LIBRARY_PATH** otra forma **/usr/local/lib** pues este ya se encuentra especificado en esta variable de entorno. Posteriormente, se ejecuta **ldconfig** en el directorio al cual se movio la libreria **.so** para agregarla a cache de modo que pueda ser encontrada cuando el sistema este indagando por una libreria compartidad:

```bash
ldconfig /usr/local/lib
```

* **Paso 4**: Una vez lo anterior es realizado el procedimiendo final consiste en general el ejecutable empleando la libreria dinamica recien creada:

```bash
gcc -Wall main.c -o  main2 libappdy.so
```

## Otras opciones con el gcc ##

A continuación mostramos algunas de las opciones más habituales al usar gcc:

| Opción | Descripción            |
|------|-------------------|
| ```-help``` | Indica a gcc que muestre su salida de ayuda (muy reducida).|
| ```-o <file>``` | El archivo ejecutable generado por gcc es por defecto a.out. Mediante este modificador, le especificamos el nombre del ejecutable.|
| ```-Wall``` | No omite la detección de ninguna advertencia (warning).|
| ```-g``` | Incluye en el binario información necesaria para utilizar un depurador posteriormente.|
| ```-O <nivel>``` | Indica a gcc que utilice optimizaciones en el código. Los niveles posibles van desde 0 (no optimizar) hasta 3 (optimización máxima). Utilizar el optimizador aumenta el tiempo de compilación, pero suele generar programas que se  ejecutan más rápido.|
| ```-E```| Sólo realiza la fase del preprocesador, no compila, ni ensambla, ni enlaza.|
| ```-S``` | Preprocesa y compila, pero no ensambla ni enlaza.|
| ```-c``` | Preprocesa, compila y ensambla, pero no enlaza.|
| ```-I <dir>``` | Especifica un directorio adicional donde gcc debe buscar los archivos de cabecera indicados en el código fuente.|
| ```-L <dir>``` | Especifica un directorio adicional donde gcc debe buscar las librerías necesarias en el proceso de enlazado.|
| ```-l<library>``` | Especifica el nombre de una librería adicional que deberá ser utilizada en el proceso de enlazado.|

## Enlaces de interes ##


1. https://medium.com/@meghamohan/everything-you-need-to-know-about-libraries-in-c-e8ad6138cbb4
2. http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html
3. https://linoxide.com/linux-command/ldd-command-examples-linux/
4. https://www.tecmint.com/understanding-shared-libraries-in-linux/
5. https://www.bogotobogo.com/cplusplus/embeddedSystemsProgramming_gnu_toolchain_ARM_cross_compiler.php
















