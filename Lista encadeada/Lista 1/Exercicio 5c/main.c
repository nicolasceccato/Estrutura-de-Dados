#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int compara_int(void *x, void *y);
void imprime_int (void *x);
//void mostra_inverso (Elemento *e);


int main(){
    Lista x;
    inicializa_lista(&x, 4);

    
    int informacao = 1;
    insere_fim(&x, &informacao);
    
    informacao = 2;
    insere_fim(&x, &informacao);
    
    informacao = 3;
    insere_fim(&x, &informacao);

    informacao = 4;
    insere_fim(&x, &informacao);

    informacao = 5;
    insere_fim(&x, &informacao);

    printf("Lista:\n");
    mostra_lista(x, imprime_int);

    
    printf("Lista de tras para frente:\n");
    int i, j;
    for (i = 0; i < x.qtd; i++){
        Elemento *auxiliar = x.cabeca;
        for( j = 0; j < x.qtd - 1 - i; j++){
            auxiliar = auxiliar->proximo;
        }
        imprime_int(auxiliar->info);
    }
    

    return 0;
}/*
void mostra_inverso (Elemento *e){
    if (e == NULL){
        return;
    }
    mostra_inverso(e->proximo);
    imprime_int(e->info);

}*/
int compara_int(void *x, void *y){
    int *a = x, *b = y;
    if (*a > *b){
        return 1;
    }
    if(*a < *b){
        return -1;
    }
    return 0;
}
void imprime_int (void *x){
    int *a = x;
    printf("%d\n", *a);

}
