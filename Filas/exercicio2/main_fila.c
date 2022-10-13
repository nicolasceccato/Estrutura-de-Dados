#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main(int argc, char *argv[]) {
	Fila f1;
	
	inicializa_fila(&f1, 5);
	mostra_fila(f1);
	
	inserir(&f1, 7);
	inserir(&f1, 5);
	inserir(&f1, 3);
	mostra_fila(f1);
	
	inserir(&f1, 8);
	mostra_fila(f1);
	
	int x;
	
	remover(&f1, &x);
	mostra_fila(f1);
	
	remover(&f1, &x);
	mostra_fila(f1);
	
	desaloca_fila(&f1);
	
	return 0;
}