#include<stdio.h>
#include<stdlib.h>

char passanger[14];         // fila de passageiros

// cleanScreen(): limpa a tela usando clear (só funciona no linux)
void cleanScreen() {
    system("clear");
}

// createPassangerList(int remainingPassangers): cria fila de 15 lugares, se tiver um 
// passageiro nesse lugar da fila, então seu caractere é '0', senão é um espaço em branco
void createPassangerList(int remainingPassangers){
    for(int i = 0; i < 15; i++){
        if(i < remainingPassangers) passanger[i] = '0';
        else passanger[i] = ' ';
    }
}

// printOverview(int remainingPassangers, int carPos): imprime o overview da fila e do onibus
void printOverview(int remainingPassangers, int carPos) {

    createPassangerList(remainingPassangers);

    if(carPos == 0) {
        printf("┌────────────────────────────────────────────┐\n");
        printf("│ Fila                                       │\n");
        printf("├───────┐        Tour da Unicamp             │\n");
        printf("│       │                                    │\n");
        printf("│       ▼                                    │\n");
        printf("│     │ %c ┌─────────────────────────────┐    │\n", passanger[14]);
        printf("│     │ %c │                             │    │\n", passanger[13]);
        printf("│     │ %c │                             │    │\n", passanger[12]);
        printf("│     │ %c │                             │    │\n", passanger[11]);
        printf("│     │ %c │                             │    │\n", passanger[10]);
        printf("│     │ %c │     ┌─────────────────┐     │    │\n", passanger[9]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[8]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[7]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[6]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[5]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[4]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[3]);
        printf("│     │ %c │     └─────────────────┘     │    │\n", passanger[2]);
        printf("│     │ %c │ ┌─┐                         │    │\n", passanger[1]);
        printf("│     │ %c   │ │                         │    │\n", passanger[0]);
        printf("│     │   │ └─┘                         │    │\n");
        printf("│     └───┤                             │    │\n");
        printf("│         └─────────────────────────────┘    │\n");
        printf("│                                            │\n");
        printf("└────────────────────────────────────────────┘\n");
    }

    else if(carPos == 1) {
        printf("┌────────────────────────────────────────────┐\n");
        printf("│ Fila                                       │\n");
        printf("├───────┐        Tour da Unicamp             │\n");
        printf("│       │                                    │\n");
        printf("│       ▼                                    │\n");
        printf("│     │ %c ┌─────────────────────────────┐    │\n", passanger[14]);
        printf("│     │ %c │                             │    │\n", passanger[13]);
        printf("│     │ %c │                             │    │\n", passanger[12]);
        printf("│     │ %c │                             │    │\n", passanger[11]);
        printf("│     │ %c │                             │    │\n", passanger[10]);
        printf("│     │ %c │ ┌─┐ ┌─────────────────┐     │    │\n", passanger[9]);
        printf("│     │ %c │ │ │ │                 │     │    │\n", passanger[8]);
        printf("│     │ %c │ └─┘ │                 │     │    │\n", passanger[7]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[6]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[5]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[4]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[3]);
        printf("│     │ %c │     └─────────────────┘     │    │\n", passanger[2]);
        printf("│     │ %c │                             │    │\n", passanger[1]);
        printf("│     │ %c                               │    │\n", passanger[0]);
        printf("│     │   │                             │    │\n");
        printf("│     └───┤                             │    │\n");
        printf("│         └─────────────────────────────┘    │\n");
        printf("│                                            │\n");
        printf("└────────────────────────────────────────────┘\n");        
    }

    else if(carPos == 2) {
        printf("┌────────────────────────────────────────────┐\n");
        printf("│ Fila                                       │\n");
        printf("├───────┐        Tour da Unicamp             │\n");
        printf("│       │                                    │\n");
        printf("│       ▼                                    │\n");
        printf("│     │ %c ┌─────────────────────────────┐    │\n", passanger[14]);
        printf("│     │ %c │                             │    │\n", passanger[13]);
        printf("│     │ %c │      ┌───┐                  │    │\n", passanger[12]);
        printf("│     │ %c │      └───┘                  │    │\n", passanger[11]);
        printf("│     │ %c │                             │    │\n", passanger[10]);
        printf("│     │ %c │     ┌─────────────────┐     │    │\n", passanger[9]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[8]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[7]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[6]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[5]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[4]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[3]);
        printf("│     │ %c │     └─────────────────┘     │    │\n", passanger[2]);
        printf("│     │ %c │                             │    │\n", passanger[1]);
        printf("│     │ %c                               │    │\n", passanger[0]);
        printf("│     │   │                             │    │\n");
        printf("│     └───┤                             │    │\n");
        printf("│         └─────────────────────────────┘    │\n");
        printf("│                                            │\n");
        printf("└────────────────────────────────────────────┘\n");

    }

    else if(carPos == 3) {
        printf("┌────────────────────────────────────────────┐\n");
        printf("│ Fila                                       │\n");
        printf("├───────┐        Tour da Unicamp             │\n");
        printf("│       │                                    │\n");
        printf("│       ▼                                    │\n");
        printf("│     │ %c ┌─────────────────────────────┐    │\n", passanger[14]);
        printf("│     │ %c │                             │    │\n", passanger[13]);
        printf("│     │ %c │                  ┌───┐      │    │\n", passanger[12]);
        printf("│     │ %c │                  └───┘      │    │\n", passanger[11]);
        printf("│     │ %c │                             │    │\n", passanger[10]);
        printf("│     │ %c │     ┌─────────────────┐     │    │\n", passanger[9]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[8]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[7]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[6]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[5]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[4]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[3]);
        printf("│     │ %c │     └─────────────────┘     │    │\n", passanger[2]);
        printf("│     │ %c │                             │    │\n", passanger[1]);
        printf("│     │ %c                               │    │\n", passanger[0]);
        printf("│     │   │                             │    │\n");
        printf("│     └───┤                             │    │\n");
        printf("│         └─────────────────────────────┘    │\n");
        printf("│                                            │\n");
        printf("└────────────────────────────────────────────┘\n");
    }

    else if(carPos == 4) {
        printf("┌────────────────────────────────────────────┐\n");
        printf("│ Fila                                       │\n");
        printf("├───────┐        Tour da Unicamp             │\n");
        printf("│       │                                    │\n");
        printf("│       ▼                                    │\n");
        printf("│     │ %c ┌─────────────────────────────┐    │\n", passanger[14]);
        printf("│     │ %c │                             │    │\n", passanger[13]);
        printf("│     │ %c │                             │    │\n", passanger[12]);
        printf("│     │ %c │                             │    │\n", passanger[11]);
        printf("│     │ %c │                             │    │\n", passanger[10]);
        printf("│     │ %c │     ┌─────────────────┐ ┌─┐ │    │\n", passanger[9]);
        printf("│     │ %c │     │                 │ │ │ │    │\n", passanger[8]);
        printf("│     │ %c │     │                 │ └─┘ │    │\n", passanger[7]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[6]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[5]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[4]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[3]);
        printf("│     │ %c │     └─────────────────┘     │    │\n", passanger[2]);
        printf("│     │ %c │                             │    │\n", passanger[1]);
        printf("│     │ %c                               │    │\n", passanger[0]);
        printf("│     │   │                             │    │\n");
        printf("│     └───┤                             │    │\n");
        printf("│         └─────────────────────────────┘    │\n");
        printf("│                                            │\n");
        printf("└────────────────────────────────────────────┘\n");
    }

    else if(carPos == 5) {
        printf("┌────────────────────────────────────────────┐\n");
        printf("│ Fila                                       │\n");
        printf("├───────┐        Tour da Unicamp             │\n");
        printf("│       │                                    │\n");
        printf("│       ▼                                    │\n");
        printf("│     │ %c ┌─────────────────────────────┐    │\n", passanger[14]);
        printf("│     │ %c │                             │    │\n", passanger[13]);
        printf("│     │ %c │                             │    │\n", passanger[12]);
        printf("│     │ %c │                             │    │\n", passanger[11]);
        printf("│     │ %c │                             │    │\n", passanger[10]);
        printf("│     │ %c │     ┌─────────────────┐     │    │\n", passanger[9]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[8]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[7]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[6]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[5]);
        printf("│     │ %c │     │                 │ ┌─┐ │    │\n", passanger[4]);
        printf("│     │ %c │     │                 │ │ │ │    │\n", passanger[3]);
        printf("│     │ %c │     └─────────────────┘ └─┘ │    │\n", passanger[2]);
        printf("│     │ %c │                             │    │\n", passanger[1]);
        printf("│     │ %c                               │    │\n", passanger[0]);
        printf("│     │   │                             │    │\n");
        printf("│     └───┤                             │    │\n");
        printf("│         └─────────────────────────────┘    │\n");
        printf("│                                            │\n");
        printf("└────────────────────────────────────────────┘\n");
    }

   else if(carPos == 6) {
        printf("┌────────────────────────────────────────────┐\n");
        printf("│ Fila                                       │\n");
        printf("├───────┐        Tour da Unicamp             │\n");
        printf("│       │                                    │\n");
        printf("│       ▼                                    │\n");
        printf("│     │ %c ┌─────────────────────────────┐    │\n", passanger[14]);
        printf("│     │ %c │                             │    │\n", passanger[13]);
        printf("│     │ %c │                             │    │\n", passanger[12]);
        printf("│     │ %c │                             │    │\n", passanger[11]);
        printf("│     │ %c │                             │    │\n", passanger[10]);
        printf("│     │ %c │     ┌─────────────────┐     │    │\n", passanger[9]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[8]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[7]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[6]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[5]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[4]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[3]);
        printf("│     │ %c │     └─────────────────┘     │    │\n", passanger[2]);
        printf("│     │ %c │                             │    │\n", passanger[1]);
        printf("│     │ %c                      ┌───┐    │    │\n", passanger[0]);
        printf("│     │   │                    └───┘    │    │\n");
        printf("│     └───┤                             │    │\n");
        printf("│         └─────────────────────────────┘    │\n");
        printf("│                                            │\n");
        printf("└────────────────────────────────────────────┘\n");
    }

    else if(carPos == 7) {
        printf("┌────────────────────────────────────────────┐\n");
        printf("│ Fila                                       │\n");
        printf("├───────┐        Tour da Unicamp             │\n");
        printf("│       │                                    │\n");
        printf("│       ▼                                    │\n");
        printf("│     │ %c ┌─────────────────────────────┐    │\n", passanger[14]);
        printf("│     │ %c │                             │    │\n", passanger[13]);
        printf("│     │ %c │                             │    │\n", passanger[12]);
        printf("│     │ %c │                             │    │\n", passanger[11]);
        printf("│     │ %c │                             │    │\n", passanger[10]);
        printf("│     │ %c │     ┌─────────────────┐     │    │\n", passanger[9]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[8]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[7]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[6]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[5]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[4]);
        printf("│     │ %c │     │                 │     │    │\n", passanger[3]);
        printf("│     │ %c │     └─────────────────┘     │    │\n", passanger[2]);
        printf("│     │ %c │                             │    │\n", passanger[1]);
        printf("│     │ %c          ┌───┐                │    │\n", passanger[0]);
        printf("│     │   │        └───┘                │    │\n");
        printf("│     └───┤                             │    │\n");
        printf("│         └─────────────────────────────┘    │\n");
        printf("│                                            │\n");
        printf("└────────────────────────────────────────────┘\n");
    }
}
