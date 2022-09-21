#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main(int argc, char *argv[]) {
	Pilha p1, p2;
	inicializa_pilha( &p1 );
   	inicializa_pilha( &p2 );

	int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    do{
        int resto = n % 2;
        empilha (&p1, resto);
        n /= 2;
    }while(n > 0);

    while( !pilha_vazia(p1)){
        int temp;
        desempilha(&p1, &temp);
        empilha (&p2, temp);
    }
    mostra_pilha(p2);    
    
    
    
    return 0;
}