#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void inicializa_fila (Fila *f, int c){
    f->dados = malloc (sizeof(int)*c);
    f->fim = 0;
    f->capacidade = c;
}
int fila_vazia (Fila f){
    return f.fim == 0;
}
int fila_cheia (Fila f){
    return f.fim == f.capacidade - 1;
}
int inserir (Fila *f, int info){
    if (fila_cheia(*f)){
        return ERRO_FILA_CHEIA;
    }
    f->dados[f->fim] = info;
    f->fim++;
    return 1;
}
int remover (Fila *f, int *info){
    if (fila_vazia(*f)){
        return ERRO_FILA_VAZIA;
    }
    *info = f->dados[0];
    int i;
    for(i = 0; i < f->fim; i++){
        f->dados[i] = f->dados[i+1];
    }
    return 1;
}

void mostra_fila (Fila f){
    if(fila_vazia(f)){
        printf("Fila vazia!\n");
    }else{
        printf("Dados da fila:\n");
        int i, cont;

        for( i = 0; i < f.fim; i++){
            printf("[%d] ", i); // Esta linha é para visualizar que a fila é circular!;
            printf("%d\n", f.dados[i]);
        }
    }
}

void desaloca_fila (Fila *f){
    free(f->dados);
}

