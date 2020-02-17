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
