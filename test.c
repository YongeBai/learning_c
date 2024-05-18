#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Shared variable
int shared_var = 0;

void *thread_function(void *arg)
{
    // Each thread has its own stack
    int local_var = 0;

    // Accessing and modifying shared data
    shared_var++;

    // Allocating memory on the heap
    int *heap_var = (int *)malloc(sizeof(int));
    *heap_var = 10;

    // Demonstrating that each thread has its own stack
    printf("Thread %ld: local_var = %d, shared_var = %d, *heap_var = %d\n", pthread_self(), local_var, shared_var, *heap_var);

    // Cleaning up dynamically allocated memory
    free(heap_var);

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    // Creating two threads
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    // Waiting for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}
