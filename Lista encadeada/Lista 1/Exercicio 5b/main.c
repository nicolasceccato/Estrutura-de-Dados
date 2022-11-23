#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int compara_int(void *x, void *y);
void imprime_int (void *x);
void mostra_inverso (Elemento *e);


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

    int y;
    printf("Lista de tras para frente:\n");
    mostra_inverso(x.cabeca);
    

    return 0;
}
void mostra_inverso (Elemento *e){
    if (e == NULL){
        return;
    }
    mostra_inverso(e->proximo);
    imprime_int(e->info);

}
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
