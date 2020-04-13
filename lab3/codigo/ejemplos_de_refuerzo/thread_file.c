
/*
Ejemplo tomado y levemente (casi nada) adaptado de:
-> https://vcansimplify.wordpress.com/2013/03/08/pthread-tutorial-simplified
*/

#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

void* say_hello(void* data)
{
    char *str;
    str = (char*)data;
    while(1)
    {
        printf("%s\n",str);
        usleep(1);
    }
}

void* open_file(void* data)
{
    char *str;
    str = (char*)data;
    printf("Opening File\n");
    FILE* f = fopen(str,"w");
    for(int i = 0; i < 100; i++) {
      fprintf(f,"%d\n",i);
    }
    fclose(f);
    printf("Closing File\n");
}

void main()
{
    pthread_t t1,t2;

    pthread_create(&t1,NULL,open_file,"hello.txt");
    pthread_create(&t2,NULL,say_hello,"The CPU is mine now :D");
    pthread_join(t1,NULL);
}
