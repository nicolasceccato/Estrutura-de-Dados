#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int compara_int(void *x, void *y);
void imprime_int (void *x);

int main(){
    
    FilaEnc a;
    
    inicializa_fila (&a, 4);
    mostra_fila(a, imprime_int);

    int x = 10;
    inserir(&a, &x);
    mostra_fila(a, imprime_int);

    x = 50;
    inserir(&a, &x);
    mostra_fila(a, imprime_int);

    x = 3;
    inserir(&a, &x);
    mostra_fila(a, imprime_int);

    x = 9;
    inserir(&a, &x);
    mostra_fila(a, imprime_int);

    remover(&a, &x);

    printf("\nfoi removido o valor %d\n", x);

    mostra_fila(a, imprime_int);

    remover(&a, &x);

    printf("\nfoi removido o valor %d\n", x);
    
    mostra_fila(a, imprime_int);

    desaloca_fila(&a);    
    
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
