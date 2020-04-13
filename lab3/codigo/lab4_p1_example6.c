#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
/* Funcion para calcular primo.*/
void* calcular_primo (void* arg);

int main(){
  pthread_t id_hilo;
  int cual_primo = 5000;
  int* primo;
  // Inicia el hilo, se requiere el 5000-iesimo numero primo
  pthread_create(&id_hilo, NULL, &calcular_primo, &cual_primo);
  // Puedo hacer algo mientras... si quiero
  // Espero que el número sea calculado y retornado
  pthread_join(id_hilo, (void *) &primo);
  // Imprimo el número entregado
  printf("El %d-esimo número primo es %d\n", cual_primo, *primo);
  free(primo);
  return 0;
}

/* Calcula los numeros primos sucesivamente. retorna el n-esimo numero primo donde n es el valor apuntado por arg*/
void* calcular_primo (void* arg){
  int candidato = 2;
  int n = *((int*)arg);
  int factor;
  int es_primo;
  while(1){
    es_primo = 1;
    for(factor = 2; factor < candidato; factor++)
      if(candidato % factor == 0){
	es_primo = 0;
	break;
      }
    if(es_primo){
      if (--n == 0){
	int* p_c = malloc(sizeof(int));
	*p_c = candidato;
	return p_c;
      }
    }
    candidato++;
  }
  return NULL;
}
