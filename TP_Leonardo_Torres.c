#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_barrier_t barrier;

void *func_thread(void *id) {
    pthread_barrier_wait(&barrier);
    for (int i = 0; i < 100; i++){
        printf("%s: %d \n", (char*)id, i);
    }
}

int main(){
    pthread_t t1, t2, t3, t4;
    char* id1 = "Thread 1";
    char* id2 = "Thread 2";
    char* id3 = "Thread 3";
    char* id4 = "Thread 4";

    pthread_barrier_init(&barrier, NULL, 4);

    pthread_create( &t1, NULL, func_thread, (void*) id1);
    pthread_create( &t2, NULL, func_thread, (void*) id2);
    pthread_create( &t3, NULL, func_thread, (void*) id3);
    pthread_create( &t4, NULL, func_thread, (void*) id4);

    pthread_join( t1, NULL);
    pthread_join( t2, NULL);
    pthread_join( t3, NULL);
    pthread_join( t4, NULL);

    pthread_barrier_destroy(&barrier);

    
}
