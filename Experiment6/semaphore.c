#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

sem_t mutex;

void* thread(void* args) {
    sem_wait(&mutex);
    printf("Entered..\n");
    sleep(4);
    printf("Exiting..\n");
    sem_post(&mutex);
    return 0;
}

int main() {
    sem_init(&mutex, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread, NULL);
    sleep(2);
    pthread_create(&t2, NULL, thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mutex);
    return 0;
}
