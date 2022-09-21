#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


void inicializa_pilha( Pilha *p){
    p->topo = -1;
}
int pilha_vazia (Pilha p){
    return p.topo == -1;
}
int pilha_cheia (Pilha p){
    return p.topo == MAX_PILHA -1;
}
int empilha (Pilha *p, int info){
    if(pilha_cheia(*p)){
        return ERRO_PILHA_CHEIA;
    }
    p->topo++;
    p->dados[p->topo] = info;
    return 1;
}
int desempilha (Pilha *p, int *info){
    if (pilha_vazia(*p)){
        return ERRO_PILHA_VAZIA;
    }
    *info = p->dados[p->topo];
    p->topo--;
    return 1;
}
int le_topo (Pilha p, int *info){
    if(pilha_vazia(p)){
        return ERRO_PILHA_VAZIA;
    }
    *info = p.dados[p.topo];
    return 1;
}
void mostra_pilha (Pilha p){
    if(pilha_vazia(p)){
        printf("Pilha vazia!\n");
    }else{
        int i;
        printf("Dados da pilha:\n");
        for(i = 0; i <= p.topo; i++){
            printf("%d",p.dados[i]);
        }
    }
    printf("\n--------------\n");
}
