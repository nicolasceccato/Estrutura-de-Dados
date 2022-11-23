#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void inicializa_pilha (Pilha *p, int c){
    p->topo = -1;
    p->capacidade = c;
    p->dados = malloc (sizeof(int)*c);    
}
int pilha_vazia (Pilha p){
    return p.topo == -1;
}
int pilha_cheia (Pilha p){
    return p.topo == p.capacidade -1;
}
int empilha (Pilha *p, void *info){
    if (pilha_cheia(*p)){
        return ERRO_PILHA_CHEIA;
    }
    int *x = info;
    p->topo++;
    p->dados[p->topo] = *x;
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
int le_topo(Pilha p, int *info){
    if (pilha_vazia(p)){
        return ERRO_PILHA_VAZIA;
    }
    *info = p.dados[p.topo];
    return 1;
}
void mostra_pilha(Pilha p){
    if (pilha_vazia(p)){
        printf("Pilha vazia!\n");
    }else{
        int i;
        for (i = 0; i <= p.topo; i++){
            printf("%d\n", p.dados[i]);
        }
    }
    printf("--------------\n");
}
void desaloca_pilha (Pilha *p){
    free(p->dados);
}
