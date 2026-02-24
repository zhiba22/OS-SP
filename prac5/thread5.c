#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
    int i;

#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int nloops = 0;

#pragma omp for
        for (i = 0; i < 1000; ++i)
        {
            ++nloops;
        }

#pragma omp critical
        printf("Thread %d performed %d iterations of the loop.\n",
               thread_id, nloops);
    }

    return 0;
}
