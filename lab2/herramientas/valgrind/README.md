
# Uso basico del valgring #

Tal y como se muestra en [The Valgrind Quick Start Guide](http://valgrind.org/docs/manual/quick-start.html). Asumiendo que ya usted ha compilado y enlazado un programa mediante el siguiente comando

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

Los siguientes códigos son tomados del siguiente del tutorial [Manual Rápido de Valgrind](https://users.dcc.uchile.cl/~skreft/material/cc31a/valgrind.pdf). 
Acceda a este y trate de entender las salidas que allí se muestran pues aceleraran el desarrollo del laboratorio el dia de la sesión presencial. 

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

## 4. Parámetros con permisos inadecuados ##

**Código**: ejemplo4.c

```C
#include <stdlib.h>
#include <unistd.h>

int main(){
  char *arr=(char *)malloc(10*sizeof(char));
  int *arr2=(int *)malloc(sizeof(int));
  write(1,arr,10);/*Trata de escribir en la salida estandar 10 caracteres, pero hay basura*/
  exit(arr2[0]);/*se trata de salir con un valo no inicializado*/
}
```

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

## Otros recursos ##
1. http://www.st.ewi.tudelft.nl/koen/ti2725-c/
2. http://web.mit.edu/amcp/drg/valgrind-howto.pdf
3. http://www.valgrind.org/docs/manual/valgrind_manual.pdf
4. http://www.st.ewi.tudelft.nl/koen/ti2725-c/valgrind.pdf
5. https://users.dcc.uchile.cl/~skreft/material/cc31a/valgrind.pdf
6. https://www.tldp.org/HOWTO/pdf/Valgrind-HOWTO.pdf
7. https://www.phys.uconn.edu/~rozman/Courses/P2200_14F/downloads/valgrind-quick-start.pdf
8. https://aleksander.es/data/valgrind-memcheck.pdf
9. http://www.liv.ic.unicamp.br/~rteixeira/ensino/valgrind.pdf
10. http://www.betterembedded.it/media/conference/slides/detecting-memory-leaks-with-valgrind.pdf
11. http://www.mathcs.richmond.edu/~lbarnett/cs240/assignments/lab4.pdf
12. http://pages.cs.wisc.edu/~bart/537/valgrind.html
13. https://www.cprogramming.com/debugging/valgrind.html
14. http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/
15. https://www.thegeekstuff.com/2011/11/valgrind-memcheck/
16. https://riptutorial.com/c/topic/2674/valgrind
17. https://www.ic.unicamp.br/~rafael/cursos/2s2017/mc202/valgrind.html
18. https://en.wikipedia.org/wiki/Valgrind
19. https://heeris.id.au/2016/valgrind-gdb/
20. https://waterprogramming.wordpress.com/2018/03/25/making-valgrind-easy/
21. https://github.com/damarquezg/Tools-Cheat-Sheet/wiki/Valgrind
22. http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/
23. https://linoxide.com/tools/valgrind-memcheck/
24. https://www.tldp.org/HOWTO/pdf/Valgrind-HOWTO.pdf
25. https://courses.cs.washington.edu/courses/cse333/19sp/sections/02/gdb-valgrind%20cheatsheet.pdf

