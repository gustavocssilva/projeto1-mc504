#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>
#include"animation.h"

/*
    MC504 - O Problema do Tour da UPA
    Feito por: Gustavo Costa Salles Silva, R.A.: 198487
    Solução inspirada no Roller Coaster problem do "The Little Book of Semaphores"
*/

/*--------------------------------------- Universal Variables ---------------------------------------*/

sem_t boardQueue;                       // semáforo de pessoas embarcadas no onibus
sem_t allAboard;                        // semáforo que avisa que todos embarcaram
sem_t unboardQueue;                     // semáforo de pessoas desembarcando do onibus
sem_t allAshore;                        // semáforo que avisa que todos desbarcaram

pthread_mutex_t mutex1;                 // mutex que impede que mais de um passageiro suba por vez 
pthread_mutex_t mutex2;                 // mutex que impede que mais de um passageiro desca por vez

size_t passangerCap = 15;               // capacidade máxima de passageiros, não alterar acima de 15
size_t busCap = 5;                      // capacidade máxima do onibus

volatile int totalPassangers;           // total de passageiros
volatile int remainingPassangers;       // passageiros restantes para viajar
volatile int boarders = 0;              // passageiros que subiram no onibus
volatile int unboarders = 0;            // passageiros que desceram do onibus

/*----------------------------------------------- Bus ----------------------------------------------*/

// load(): incrementa o semaforo boardQueue até encher o onibus
void load() {
    cleanScreen();
    printf("[Bus thread] o onibus está carregando os passageiros.\n");
    printOverview(remainingPassangers, 0);
    sleep(2);

    for(int i = 0; i < busCap; i++) sem_post(&boardQueue);

}

// unload(): incrementa o semaforo unboardQueue até envaziar o onibus
void unload() {
    cleanScreen();
    printf("[Bus thread] o onibus está descarregando os passageiros.\n");
    printOverview(remainingPassangers, 0);
    sleep(2);
    
    for(int i = 0; i < busCap; i++) sem_post(&unboardQueue);

}

// run(): apenas faz a animação do onibus rodando
void run() {
    for(int i = 0; i <= 7; i++){
        cleanScreen();
        printf("[Bus thread] o onibus está rodando.\n");
        printOverview(remainingPassangers, i);
        sleep(2);
    }
}

// busThread(): thread do onibus que recebe os passageiros
void* busThread() {
    while(remainingPassangers >= busCap){    
        
        load();
        
        sem_wait(&allAboard);           // espera pelo allAboard

        run();

        unload();

        sem_wait(&allAshore);           // espera pelo allAshore
    }

    // caso o número de passageiros que sobraram for menor que a capacidade do onibus, eles não viajarao
    if(remainingPassangers > 0) {
        cleanScreen();
        printf("[bus thread] acabaram as viagens por hoje, %d pessoas ficaram de fora. :(\n", remainingPassangers);
        printOverview(remainingPassangers, 0);
    }
}



/*--------------------------------------------- Passanger --------------------------------------------*/

// board(): adiciona passageiros no onibus até encher e incrementa allAboard
void board() {
    cleanScreen();
   
    boarders++;

    printf("[Passanger thread] passageiro %d está subindo no onibus.\n", boarders);
    
    remainingPassangers--;
    printOverview(remainingPassangers,0);
    
    sleep(1);

    if (boarders == busCap) {
        sem_post(&allAboard);
        boarders = 0;
    }
}

// unboard(): desce os passageiros do onibus até esvaziar e incrementa allAshore
void unboard() {
    cleanScreen();
  
    unboarders++; 

    printf("[Passanger thread] passageiro %d está descendo do onibus.\n", unboarders);
    
    printOverview(remainingPassangers,0);
    
    sleep(1);
    
    if (unboarders == busCap) {
        sem_post(&allAshore);
        unboarders = 0;
    }
}

// passangerThread(): thread dos passageiros
void* passangerThread() {
    sem_wait(&boardQueue);              // espera o onibus comecar a encher

    pthread_mutex_lock(&mutex1);        // impede que mais de um suba por vez
    
    board(); 
    
    pthread_mutex_unlock(&mutex1);      // permite que o proximo suba
    
    sem_wait(&unboardQueue);            // espera o onubus comecar a desembarcar os passageiros

    pthread_mutex_lock(&mutex2);        // impede que mais de um desembarque por vez

    unboard();

    pthread_mutex_unlock(&mutex2);      // permite que o proximo desembarque
}

/*----------------------------------------------- Main ----------------------------------------------*/

int main(int argc, char const *argv[]) {

    // recebe os passageiros, respeitando o limite
    while(1) {
        cleanScreen();
        printf("Quantos passageiros tem na fila hoje? ");
        scanf("%d", &totalPassangers);

        if(totalPassangers > passangerCap) {
            printf("O limite da fila é de %d passageiros, insira outro valor!\n", passangerCap);
            sleep(4);
        }
        else break;
    }

    remainingPassangers = totalPassangers;

    // cria os mutex usados nos passangerThread
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    // inicializa os semaforos
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
