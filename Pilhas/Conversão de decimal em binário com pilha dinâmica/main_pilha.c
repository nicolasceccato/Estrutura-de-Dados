#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main(int argc, char *argv[]) {
	Pilha p1;

	inicializa_pilha(&p1, 31);

	int n;

	printf("Digite qual numero desejas converter para binario: ");
	scanf("%d", &n);

	do{
		int resto = n % 2;
		empilha (&p1, resto);

		n /= 2;
	}while(n > 0);

	while (! pilha_vazia(p1)){
		int temp;
		desempilha(&p1, &temp);
		printf("%d", temp);
	}
	printf("\n");

	desaloca_pilha(&p1);
	
	return 0;
}