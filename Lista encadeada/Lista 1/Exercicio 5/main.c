#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Pilha.h"

int compara_int(void *x, void *y);
void imprime_int (void *x);

int main(){
    Lista x;
    inicializa_lista(&x, 4);

    Pilha p;
    inicializa_pilha(&p, 50);
    int informacao = 1;
    insere_fim(&x, &informacao);
    empilha(&p, &informacao);
    
    informacao = 2;
    insere_fim(&x, &informacao);
    empilha(&p, &informacao);
    
    informacao = 3;
    insere_fim(&x, &informacao);
    empilha(&p, &informacao);

    informacao = 4;
    insere_fim(&x, &informacao);
    empilha(&p, &informacao);

    informacao = 5;
    insere_fim(&x, &informacao);
    empilha(&p, &informacao);

    printf("Lista:\n");
    mostra_lista(x, imprime_int);

    int y;
    printf("Lista de tras para frente:\n");
    while (!pilha_vazia(p)){
        desempilha(&p, &y);
        printf("%d\n", y);
    }

    return 0;
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
