#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main(){
    int n, i;
    Pilha p1;
    
    printf("Quantos termos deseja: ");
    scanf("%d", &n);
    char s[n];
    //s = malloc(sizeof(int)*n);
    inicializa_pilha(&p1, n);
    printf("Digite a string: ");
    scanf("%s", s);
    for(i = 0; i < n; i++){
       // printf("Digite o %i termo da string: ", i+1);
       // scanf(" %c", &s[i]);
        empilha(&p1, (int)s[i]);
    }
    for(i = 0; i < n; i++){
        desempilha(&p1, &s[i]);
    }
    for(i = 0; i < n; i++){
        printf("%c\n",s[i]);
    }



    //mostra_pilha(p1);
    desaloca_pilha(&p1);

    return 0;
}

