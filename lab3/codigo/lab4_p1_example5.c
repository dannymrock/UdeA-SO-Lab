
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* Globla variable */
int x;

void fd(void);

int main(void) {
  pthread_t threads_ids[4];
  int i;
  for(i = 0; i < 4; i++) {
    pthread_create(&threads_ids[i],NULL,(void *)fd, NULL);
    printf("Iniciando hilo: %d\n", i + 1);
    //usleep(1);
  }
  for(i = 0; i < 4; i++) {
    pthread_join(threads_ids[i],NULL);
  }
}
void fd(void) {
  int i;
  printf("Thread PID: %lu \n-> x = %d (before to be incremented 1000 times for this thread)\n", (unsigned long)pthread_self(),x);
  for(i = 1;i <=1000;i++) {
    x++;
  }
}
