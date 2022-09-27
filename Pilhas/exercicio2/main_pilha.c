#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Pilha.h"

int main(){
    Pilha p1, p2;
    int i, c;
    printf("Digite qual a capacidade da pilha: ");
    scanf("%d", &c);

    inicializa_pilha(&p1, 2*c);
    inicializa_pilha(&p2, c);

    srand(time(0));

    for (i = 0; i < c; i++){
        empilha(&p1, rand() % 10);
        empilha(&p2, rand() % 10);        
    }   
    printf("----- Pilha 1 -----\n");
    mostra_pilha(p1);
    printf("----- Pilha 2 -----\n");
    mostra_pilha(p2);

    for(i = 0; i < c; i++){
        int temp;
        desempilha(&p2, &temp);
        empilha(&p1, temp);
    }
    printf("----- Pilha 1 -----\n");
    mostra_pilha(p1);
    printf("----- Pilha 2 -----\n");
    mostra_pilha(p2);

    desaloca_pilha(&p1);
    desaloca_pilha(&p2);

    return 0;
}

