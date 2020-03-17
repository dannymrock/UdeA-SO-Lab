
# Uso basico del valgring #


## Antes de empezar ##

Se recomienda que vea el video [3ra Charla 1c 2019 - Valgrind](https://www.youtube.com/watch?v=knRei6OBU4Q&t=248s) el cual cuenta con un tutorial que puede ser consultado en el siguiente [enlace](https://docs.google.com/document/d/1flOJ2P2g9UGVRiruuA4OCF6nucbN_BWVI0WDlYTJNf4/edit).

En el directorio [referencias](./referencias) se encuentra alguna documentación recolectada que le puede ser útil para la comprensión de la herramienta valgrind. De esta se recomienda dar un vistazo rapido (y volver a profundizar en estos cuando este haciendo el laboratorio si lo ve necesario) a los siguientes documentos:
1. [Manual Rápido de Valgrind](./referencias/valgrind.pdf)
2. [Valgrind - Tutorial basico de Memcheck](./referencias/valgrind_slide.pdf)
3. [Valgrind Debugging	Utility](./referencias/Valgrind.pdf)
4. [Valgrind](./referencias/Gunter.Valgrind.pdf)

Tambien se sugiere que tenga a la mano [cheatsheet](https://courses.cs.washington.edu/courses/cse333/19sp/sections/02/gdb-valgrind%20cheatsheet.pdf) que resume los comandos basicos de gdb y valgrind.


## Manejo muy basico de valgring ##

Tal y como se muestra en [The Valgrind Quick Start Guide](http://valgrind.org/docs/manual/quick-start.html). Asumiendo que ya usted ha compilado y enlazado un programa mediante el siguiente comando.

```
gcc myprog.c -o myprog
```

De modo que para ejecutarlo si se diese el caso en el que el programa solicita el ingreso de dos argumentos, la intrucción a ejecutar es:

```
./myprog arg1 arg2
```

Si usted quiere analizar el programa usando valgrind una de las formas basicas puede ser mediante la aplicación del siguiente comando:

```
valgrind --leak-check=yes ./myprog arg1 arg2
```

**Bonus**: Aprender a usar Valkyrie (a graphical user interface for Valgrind) en paralelo.

# Codigos ejemplo #

Los siguientes códigos son tomados del siguiente del tutorial [Manual Rápido de Valgrind](https://users.dcc.uchile.cl/~skreft/material/cc31a/valgrind.pdf). Inicialmente compile los códigos y ejecutelos para ver  cual es la salida si no sacan error alguno en tiempo de compilación. Luego, como cada programa tiene su trampa, use valgrind para analizarlo, observe las salidas arrojadas y trate de entenderlas. Esto le será sumamente util pues el dia de la sesión presencial, le ayudará a acelerar el desarrollo del laboratorio.

Para facilitar seguir el tutorial se proporsionan los codigos.

## 1. Lectura/Escritura no permitida ##

**Código**: ejemplo1.c

```C
#include <stdio.h>
#include <stdlib.h>
int main(){
  int *a=(int*)0xFF;
  *a=1;
  return EXIT_SUCCESS;
}
```

El codigo del **ejemplo1.c** puede ser simulado siguiendo el siguiente [enlace](http://www.pythontutor.com/c.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0Aint%20main%28%29%7B%0A%20%20int%20*a%3D%28int*%290xFF%3B%0A%20%20*a%3D1%3B%0A%20%20return%20EXIT_SUCCESS%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D)

##  2. Uso de variables no inicializadas ##

**Código**: ejemplo2.c

```C
#include <stdio.h>
#include <stdlib.h>

int main(){
  int x;
  printf("%d\n",x);
  return EXIT_SUCCESS;
}
```

El codigo del **ejemplo2.c** puede ser simulado siguiendo el siguiente [enlace](http://www.pythontutor.com/c.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20x%3B%0A%20%20printf%28%22%25d%5Cn%22,x%29%3B%0A%20%20return%20EXIT_SUCCESS%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D)

## 3. Free inválido ##

### Caso 1 ###

**Código**: ejemplo3_1.c

```C
#include <stdlib.h>

int main(){
  char *a=(char *)0xFF;
  free(a);
  return EXIT_SUCCESS;
}
```

El codigo del **ejemplo3_1.c** puede ser simulado siguiendo el siguiente [enlace](http://www.pythontutor.com/c.html#code=%23include%20%3Cstdlib.h%3E%0A%0Aint%20main%28%29%7B%0A%20%20char%20*a%3D%28char%20*%290xFF%3B%0A%20%20free%28a%29%3B%0A%20%20return%20EXIT_SUCCESS%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D)

### Caso 2 ###

**Código**: ejemplo3_2.c

```C
#include <stdlib.h>

int main(){
  char *a=(char *)malloc(sizeof(char));
  free(a);
  free(a);
  return EXIT_SUCCESS;
}
```

El codigo del **ejemplo3_2.c** puede ser simulado siguiendo el siguiente [enlace](http://www.pythontutor.com/c.html#code=%23include%20%3Cstdlib.h%3E%0A%0Aint%20main%28%29%7B%0A%20%20char%20*a%3D%28char%20*%29malloc%28sizeof%28char%29%29%3B%0A%20%20free%28a%29%3B%0A%20%20free%28a%29%3B%0A%20%20return%20EXIT_SUCCESS%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D)

## 4. Parámetros con permisos inadecuados ##

**Código**: ejemplo4.c

```C
#include <stdlib.h>
#include <unistd.h>

int main(){
  char *arr=(char *)malloc(10*sizeof(char));
  int *arr2=(int *)malloc(sizeof(int));
  write(1,arr,10); // Trata de escribir en la salida 
                   // estandar 10 caracteres, pero hay 
                   // basura*
  exit(arr2[0]);   // Se trata de salir con un valo no 
                   // inicializado
}
```

El codigo del **ejemplo4.c** puede ser simulado siguiendo el siguiente [enlace](http://www.pythontutor.com/c.html#code=%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cunistd.h%3E%0A%0Aint%20main%28%29%7B%0A%20%20char%20*arr%3D%28char%20*%29malloc%2810*sizeof%28char%29%29%3B%0A%20%20int%20*arr2%3D%28int%20*%29malloc%28sizeof%28int%29%29%3B%0A%20%20write%281,arr,10%29%3B%20%20//Trata%20de%20escribir%20en%20la%20salida%20%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//%20estandar%2010%20caracteres,%20pero%20hay%20basura%0A%20%20exit%28arr2%5B0%5D%29%3B%20%20%20%20//se%20trata%20de%20salir%20con%20un%20valo%20%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//no%20inicializado%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D)

## 5. Detección de memory leaks ##

**Código**: ejemplo5.c

```C
#include <stdlib.h>

int main(){
  int *a=(int *)malloc(1024*sizeof(int));
  int *b=(int *)malloc(10*sizeof(int));
  *a=1;
  b=(int *)NULL;
  return EXIT_SUCCESS;
}
```

El codigo del **ejemplo5.c** puede ser simulado siguiendo el siguiente [enlace](http://www.pythontutor.com/c.html#code=%23include%20%3Cstdlib.h%3E%0A%0Aint%20main%28%29%7B%0A%20%20int%20*a%3D%28int%20*%29malloc%281024*sizeof%28int%29%29%3B%0A%20%20int%20*b%3D%28int%20*%29malloc%2810*sizeof%28int%29%29%3B%0A%20%20*a%3D1%3B%0A%20%20b%3D%28int%20*%29NULL%3B%0A%20%20return%20EXIT_SUCCESS%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D)

## 6. Observación sobre variables no inicializadas ##

**Código**: ejemplo6.c

```C
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
```

El codigo del **ejemplo6.c** puede ser simulado siguiendo el siguiente [enlace](http://www.pythontutor.com/c.html#code=%23include%20%3Cstdlib.h%3E%0A%0Aint%20main%28%29%7B%0A%20%20int%20i,%20j%3B%0A%20%20int%20a%5B10%5D,%20b%5B10%5D%3B%0A%20%20for%20%28%20i%20%3D%200%3B%20i%20%3C%2010%3B%20i%2B%2B%20%29%20%7B%0A%20%20%20%20j%20%3D%20a%5Bi%5D%3B%0A%20%20%20%20b%5Bi%5D%20%3D%20j%3B%0A%20%20%7D%0A%20%20return%20EXIT_SUCCESS%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D)

## Otros recursos ##
1. https://drbfraser.es-cam.com/
2. http://www.st.ewi.tudelft.nl/koen/ti2725-c/
3. http://web.mit.edu/amcp/drg/valgrind-howto.pdf
4. http://www.valgrind.org/docs/manual/valgrind_manual.pdf
5. http://www.st.ewi.tudelft.nl/koen/ti2725-c/valgrind.pdf
6. https://users.dcc.uchile.cl/~skreft/material/cc31a/valgrind.pdf
7. https://www.tldp.org/HOWTO/pdf/Valgrind-HOWTO.pdf
8. https://www.phys.uconn.edu/~rozman/Courses/P2200_14F/downloads/valgrind-quick-start.pdf
9. https://aleksander.es/data/valgrind-memcheck.pdf
10. http://www.liv.ic.unicamp.br/~rteixeira/ensino/valgrind.pdf
11. http://www.betterembedded.it/media/conference/slides/detecting-memory-leaks-with-valgrind.pdf
12. http://www.mathcs.richmond.edu/~lbarnett/cs240/assignments/lab4.pdf
13. http://pages.cs.wisc.edu/~bart/537/valgrind.html
14. https://www.cprogramming.com/debugging/valgrind.html
15. http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/
16. https://www.thegeekstuff.com/2011/11/valgrind-memcheck/
17. https://riptutorial.com/c/topic/2674/valgrind
18. https://www.ic.unicamp.br/~rafael/cursos/2s2017/mc202/valgrind.html
19. https://en.wikipedia.org/wiki/Valgrind
20. https://heeris.id.au/2016/valgrind-gdb/
21. https://waterprogramming.wordpress.com/2018/03/25/making-valgrind-easy/
22. https://github.com/damarquezg/Tools-Cheat-Sheet/wiki/Valgrind
23. http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/
24. https://linoxide.com/tools/valgrind-memcheck/
25. https://www.tldp.org/HOWTO/pdf/Valgrind-HOWTO.pdf
26. https://courses.cs.washington.edu/courses/cse333/19sp/sections/02/gdb-valgrind%20cheatsheet.pdf

