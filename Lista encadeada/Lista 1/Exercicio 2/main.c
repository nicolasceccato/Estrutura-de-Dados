#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
int compara(void *x, void *y);
void imprime_int (void *x);
int busca( Lista *l, void *info, int (*compara)(void *, void *) );
int main(){
    Lista l1;

    inicializa_lista(&l1, 4);
    
    int x = 9; 
    insere_ordem(&l1, &x, compara);
    x = 2; 
    insere_ordem(&l1, &x, compara);
    x = 5; 
    insere_ordem(&l1, &x, compara);
    
    mostra_lista(l1, imprime_int);
    int y = 5;
    
    int busca_a = busca(&l1, &y, compara);
    if(busca_a == -1){
        printf("Nao foi encontrado o valor %d\n", y);
    }else{

        printf("Encontrado %d no indice %d\n",y, busca_a);
    }
    y = 9;
    
    busca_a = busca(&l1, &y, compara);
    if(busca_a == -1){
        printf("Nao foi encontrado o valor %d\n", y);
    }else{

        printf("Encontrado %d no indice %d\n",y, busca_a);
    }

    return 0;
}
void imprime_int (void *x){
    int *a = x;
    printf("%d\n", *a);

}
int busca( Lista *l, void *info, int (*compara)(void *x, void *y) ){
    Elemento *aux = l->cabeca;
    int i;
    for (i = 0; i < l->qtd; i++, aux = aux->proximo){
        int x = compara(aux->info, info);
        if (x == 0){
            return i;
        }
    }
    return -1;
}
int compara(void *x, void *y){
    int *a = x, *b = y;
    if (*a > *b){
        return 1;
    }
    if(*a < *b){
        return -1;
    }
    return 0;
}
