#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

int main(){
    char s[50];
    printf("Digite uma frase: ");
    gets(s);
    Pilha p;
    inicializa_pilha(&p, 24);
   
    int i;
    int x;
    int j = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] != ' '){
            empilha(&p, (int)s[i]);
        }else{
            
            while(! pilha_vazia(p)){
                desempilha(&p,&x);
                printf("%c", x);

            }
            printf(" ");
            
           
        }
    }
    while(! pilha_vazia(p)){
        desempilha(&p,&x);
        printf("%c", x);
       
    }
    printf("\n");
    desaloca_pilha(&p);

    return 0;
}