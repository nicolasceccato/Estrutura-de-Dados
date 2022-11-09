#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
void mostra_float(void *x);
int main(){
    Lista l1;
    inicializa_lista( &l1 , sizeof(float) );
    mostra_lista(l1, mostra_float);
    printf("quantidade de elementos: %d\n", conta_elementos(l1));

    float x = 7.5, y;
    insere_inicio( &l1 , &x );
    mostra_lista(l1, mostra_float);
    printf("quantidade de elementos: %d\n", conta_elementos(l1));
    
    x = 10;
    insere_inicio( &l1 , &x );
    mostra_lista(l1, mostra_float);
    printf("quantidade de elementos: %d\n", conta_elementos(l1));

    x = 0;
    insere_inicio( &l1 , &x );
    mostra_lista(l1, mostra_float);
    printf("quantidade de elementos: %d\n", conta_elementos(l1));
    
    x = 20;
    insere_inicio( &l1 , &x );
    mostra_lista(l1, mostra_float);
    printf("quantidade de elementos: %d\n", conta_elementos(l1));
    
    x = 30;
    insere_inicio( &l1 , &x );
    mostra_lista(l1, mostra_float);
    printf("quantidade de elementos: %d\n", conta_elementos(l1));
    
    remove_inicio( &l1 , &y );
    printf("valor removido: %.2f\n", y);
    printf("quantidade de elementos: %d\n", conta_elementos(l1));

    printf("VAMOS LIMPAR A LISTA A SEGUIR\n");
    limpa_lista(&l1);
    mostra_lista(l1, mostra_float);
    printf("quantidade de elementos: %d\n", conta_elementos(l1));

    return 0;
}
void mostra_float(void *x){
    printf("%.2f\n", *(float *)x);
}
