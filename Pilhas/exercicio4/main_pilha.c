#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main(){
    int n, i;
    Pilha p1;
    
    printf("Quantos termos deseja: ");
    scanf("%d", &n);
    char s[n];
    char s2[n];
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
        desempilha(&p1, &s2[i]);
    }
    for(i = 0; i < n; i++){
        if (s[i] != s2[i]){
            printf("Strings diferentes!\n");
            printf("%s\n", s);
            printf("%s\n", s2);
            return 0;
        }
    }            
    printf("As Strings são palindromes!\n");
    printf("%s\n", s);
    printf("%s\n", s2);
        
    //mostra_pilha(p1);
    desaloca_pilha(&p1);

    return 0;
}

