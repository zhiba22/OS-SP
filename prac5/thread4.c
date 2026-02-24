// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #define NTHREADS 5
// void *myFun(void *x)
// {
//  int tid;
//  tid = *((int *) x);
//  printf("Hi from thread %d!\n", tid);
//  return NULL;
// }
// int main(int argc, char *argv[])
// {
//  pthread_t threads[NTHREADS];
//  int thread_args[NTHREADS];
//  int rc, i;
//  /* spawn the threads */
//  for (i=0; i<NTHREADS; ++i)
//  {
//  thread_args[i] = i;
//  printf("spawning thread %d\n", i);
//  rc = pthread_create(&threads[i], NULL, myFun, (void *) &thread_args[i]);
//  }
//  /* wait for threads to finish */
//  for (i=0; i<NTHREADS; ++i) {
//  rc = pthread_join(threads[i], NULL);
//  }
//  return 1;
// }

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 5

void *myFun(void *x)
{
    int tid = *((int *)x);
    printf("Hi from thread %d!\n", tid);
    return NULL;
}

int main(void)
{
    pthread_t threads[NTHREADS];
    int thread_args[NTHREADS];
    int rc, i;

    /* spawn the threads */
    for (i = 0; i < NTHREADS; ++i)
    {
        thread_args[i] = i;
        printf("Spawning thread %d\n", i);

        rc = pthread_create(&threads[i], NULL, myFun, &thread_args[i]);
        if (rc != 0)
        {
            printf("Error: unable to create thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    /* wait for threads to finish */
    for (i = 0; i < NTHREADS; ++i)
    {
        rc = pthread_join(threads[i], NULL);
        if (rc != 0)
        {
            printf("Error: unable to join thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
