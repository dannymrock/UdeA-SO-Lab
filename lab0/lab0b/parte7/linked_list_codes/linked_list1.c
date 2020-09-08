#include <stdio.h>
#include <stdlib.h>

/*
https://gist.github.com/echo-akash/b1345925b6c801217f7cde452f8e2c73
https://gist.github.com/ardrabczyk/1cdc413b9eaa9a9a0c4be71d3fc9bc37
https://github.com/skorks/c-linked-list
https://gist.github.com/KevinTyrrell/9f4d13107b32d2ad0421a7881fcd1199
*/


struct nodo {
    int dato;
    struct nodo **next;
};

typedef struct nodo nodo;

void recorrer_lista(nodo **L);
void insertar_elemento(nodo **L, int dato);

int main() {
  nodo *head = NULL;
  insertar_elemento(&head, -4);
  insertar_elemento(&head, 3);
  insertar_elemento(&head, 10);
  //recorrer_lista(head);
  return 0;
}

void recorrer_lista(nodo **L) {
  /*
  nodo *p = L;  
  int i = 0;
  while(*p != NULL) {
    //printf("%d ---> \n", p->dato);
    *p = p->next;
    printf("& = %p\n",p);
  }
  printf("NULL");
  */


  nodo *p = *L;  

  while (p != NULL) { 
    printf("%d --> ", p->dato);
    p = p->next;   
  } 
  puts("NULL\n");



  
}


void insertar_elemento(nodo **L, int dato) {
  nodo *new_nodo = (nodo *)malloc(sizeof(nodo)); 
  new_nodo->dato = dato;
  new_nodo->next = L;
  (*L)->next = &new_nodo;
  //new_nodo->next = NULL;
}
 