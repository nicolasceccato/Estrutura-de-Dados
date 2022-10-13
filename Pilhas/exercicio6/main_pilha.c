#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define MAX 50

int main(){
    char expressao[MAX];

    printf("Digite uma expressao aritmetica: ");
    gets(expressao);

    int i, x;
    Pilha p;

    inicializa_pilha(&p, MAX);

    for(i = 0; expressao[i] != '\0'; i++){
        if(expressao[i] == '('){
            empilha(&p, expressao[i]);
        }
        if(expressao[i] == ')'){
            if(pilha_vazia(p)){
                printf("Fecha parenteses sem abre parenteses (posição %d).\n", i);
                return -1;
            }else {
                
                desempilha(&p, &x); 
            }
        }
    }
    if(!pilha_vazia(p)){
        printf("Ha parenteses abertos que nao foram fechados.\n");
        mostra_pilha(p);
    }else{
        printf("Expressao OK!\n");
    }
    return 0;

}

