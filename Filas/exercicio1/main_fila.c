#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Pilha.h"
#define MAX 5

int main(int argc, char *argv[]) {
	Fila f1;
	Pilha p1;

	inicializa_fila (&f1, MAX);
	
	inicializa_pilha (&p1, MAX);
	
	mostra_fila(f1);
	mostra_pilha(p1);

	inserir(&f1, 1);
	inserir(&f1, 2);
	inserir(&f1, 3);
	inserir(&f1, 4);
	inserir(&f1, 5);
	inserir(&f1, 6); //tentando adicionar mais do que a capacidade estabelecida

	mostra_fila(f1); //fila estara cheia
	mostra_pilha(p1); //pilha estara vazia
	int x;

	remover(&f1, &x);
	empilha(&p1, x);
	remover(&f1, &x);
	empilha(&p1, x);
	remover(&f1, &x);
	empilha(&p1, x);
	remover(&f1, &x);
	empilha(&p1, x);
	remover(&f1, &x);
	empilha(&p1, x);
	remover(&f1, &x); //fila ja estara vazia e pilha cheia
	empilha(&p1, x);

	mostra_fila(f1);
	mostra_pilha(p1);

	desempilha(&p1, &x);
	inserir(&f1, x);
	desempilha(&p1, &x);
	inserir(&f1, x);
	desempilha(&p1, &x);
	inserir(&f1, x);
	desempilha(&p1, &x);
	inserir(&f1, x);
	desempilha(&p1, &x);
	inserir(&f1, x);

	mostra_fila(f1);
	mostra_pilha(p1);

	if(fila_cheia(f1)){
		printf("A fila esta cheia!\n");
	}
	
	return 0;
}