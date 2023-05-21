#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>

#define PASSANGER_CAP 20;

/* Universal Variables */
sem_t boardQueue;
sem_t allAboard;
sem_t unboardQueue;
sem_t allAshore;

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

size_t busCap = 5;

volatile int totalPassangers;
volatile int leftPassangers;
volatile int boarders = 0;
volatile int unboarders = 0;

/* bus */
void load() {
    printf("[Bus thread] bus is loading.\n");
    sleep(1);
}

void unload() {
    printf("[Bus thread] bus is unloading.\n");
    sleep(1);
}

void run() {
    printf("[Bus thread] bus is running.\n");
}

void* busThread() {

    while(leftPassangers > 0){    
        
        if(leftPassangers < busCap) {
            printf("[bus thread] no more trips for today, %d left out. :(\n", leftPassangers);
            return NULL;
        }
        
        load();

        for(int i = 0; i < busCap; i++) sem_post(&boardQueue);

        sem_wait(&allAboard);

        run();

        unload();

        for(int i = 0; i < busCap; i++) sem_post(&unboardQueue);

        sem_wait(&allAshore);
    
        leftPassangers -= busCap;
    }
}



/* Passanger */
void board() {
    printf("[Passanger thread] passanger is boarding.\n");
    sleep(1);
}

void unboard() {
    printf("[Passanger thread] passanger is unboarding.\n");
    sleep(1);
}

void* passangerThread() {
    sem_wait(&boardQueue);

    pthread_mutex_lock(&mutex1); 
    
    board(); 
    boarders++;

    if (boarders == busCap) {
        sem_post(&allAboard);
        boarders = 0;
    }
    
    pthread_mutex_unlock(&mutex1);
    
    sem_wait(&unboardQueue);

    pthread_mutex_lock(&mutex2);

    unboard();
    unboarders++; 
    
    if (unboarders == busCap) {
        sem_post(&allAshore);
        unboarders = 0;
    }

    pthread_mutex_unlock(&mutex2);
}

int main(int argc, char const *argv[]) {
    totalPassangers = 6;
    leftPassangers = totalPassangers;

    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    sem_init(&boardQueue, 0, 0);
    sem_init(&allAboard, 0, 0);
    sem_init(&unboardQueue, 0, 0);
    sem_init(&allAshore, 0, 0);

    pthread_t bus;
    pthread_t passangers[totalPassangers];

    pthread_create(&bus, 0, busThread, 0);

    for (int i = 0; i < totalPassangers; i++){
        pthread_create(&passangers[i], 0, passangerThread, 0);
    }

    pthread_join(bus, NULL);

    return 0;
}
