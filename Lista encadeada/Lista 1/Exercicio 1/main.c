#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void concatena (Lista *a, Lista *b);
void imprime_int (void *x);
int compara_int (void *x, void *y);
int main(){
    Lista l1, l2;

    inicializa_lista(&l1, 4);
    inicializa_lista(&l2, 4);
    int x = 9; 
    insere_ordem(&l1, &x, compara_int);
    x = 2; 
    insere_ordem(&l1, &x, compara_int);
    x = 5; 
    insere_ordem(&l1, &x, compara_int);
    x = 3;
    insere_ordem(&l2, &x, compara_int);
    x = 33;
    insere_ordem(&l2, &x, compara_int);

    mostra_lista(l1, imprime_int);
    mostra_lista(l2, imprime_int);

    concatena(&l1, &l2);

    mostra_lista(l1, imprime_int);
    mostra_lista(l2, imprime_int);

    return 0;
}
void concatena (Lista *a, Lista *b){
    Elemento *auxiliar = b->cabeca;
    while(auxiliar->proximo != NULL){
        insere_fim(a, auxiliar->info);
        auxiliar = auxiliar->proximo;
    }
    insere_fim(a, auxiliar->info);
    limpa_lista(b);
}
void imprime_int (void *x){
    int *a = x;
    printf("%d\n", *a);

}
int compara_int (void *x, void *y){
    int *a = x, *b = y;
    return *a - *b;

}

