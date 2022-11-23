#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int compara_int(void *x, void *y);
void imprime_int (void *x);

int main(){
    Lista x, y;
    inicializa_lista(&x, 4);
    inicializa_lista(&y, 4);
    int informacao = 10;
    insere_fim(&x, &informacao);
    informacao = 6;
    insere_fim(&x, &informacao);    
    informacao = 4;
    insere_fim(&x, &informacao);
    informacao = 10;
    insere_fim(&x, &informacao);
    informacao = 4;
    insere_fim(&x, &informacao);


    printf("Antes da busca:\n");
    mostra_lista(x, imprime_int);
    mostra_lista(y, imprime_int);
    informacao = 5;
    
    y = busca_todos(x, &informacao, compara_int);

    if(lista_vazia(y)){
        printf("A informacao nao foi encontrada na lista!\n");
    }else{
        printf("Depois da busca essas são as posicoes onde a informacao foi localizada na lista:\n");
        mostra_lista(y, imprime_int);
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
