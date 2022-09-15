#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
    Matriz a, b, c;

    if(!carrega_arquivo("m1.txt", &a)){
        printf("Erro ao carregar arquivo!\n");
        return -1;
    }
    if(!carrega_arquivo("m2.txt", &b)){
        printf("Erro ao carregar arquivo!\n");
        return -1;
    }
    if(soma_matrizes(a, b, &c) == ERRO_MATRIZES_INCOMPATIVEIS){
        printf("Matrizes incompativeis para soma!\n");
    }else{
        salva_arquivo("m3.txt", c);
        system("cat m3.txt");
        desaloca_matriz(&c);
    }
    desaloca_matriz(&a);
    desaloca_matriz(&b);   
    printf("fim\n");
    return 0;
}