#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int g = 0;

void *myThreadFun(void *vargp)
{
    int *myid = (int *)vargp;
    static int s = 0;

    ++s;
    ++g;

    printf("Thread ID: %d, Static: %d, Global: %d\n", 
           *myid, ++s, ++g);

    return NULL;
}

int main()
{
    int i;
    pthread_t tid[3];
    int ids[3];

    for (i = 0; i < 3; i++) {
        ids[i] = i + 1;
        pthread_create(&tid[i], NULL, myThreadFun, &ids[i]);
    }

    for (i = 0; i < 3; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}

