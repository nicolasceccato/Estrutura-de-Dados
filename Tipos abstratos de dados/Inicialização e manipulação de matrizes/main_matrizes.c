#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

int main (){
    Matriz m;
    int x, y;
    inicializa_matriz(&m);
    
    imprime_matriz(m);
    
    do{
        x = set_valor(&m);

        if ( x == ERRO_COORDENADA_INVALIDA){
            printf("Coordenadas inseridas sao invalidas\n");
        }else{
            printf("Matriz alterada com sucesso!\n");
        }
        
    }while (x == ERRO_COORDENADA_INVALIDA);
    
    imprime_matriz(m);
    
    do{
        y = get_valor(m);

        if ( y == ERRO_COORDENADA_INVALIDA){
            printf("Coordenadas inseridas sao invalidas\n");
        }else{
            printf("o valor é %d!\n", y);
        }
        
    }while (x == ERRO_COORDENADA_INVALIDA);
    
    Matriz m2;

    inicializa_matriz(&m2);
    
    imprime_matriz(m2);
    
    do{
        x = set_valor(&m2);

        if ( x == ERRO_COORDENADA_INVALIDA){
            printf("Coordenadas inseridas sao invalidas\n");
        }else{
            printf("Matriz alterada com sucesso!\n");
        }
        
    }while (x == ERRO_COORDENADA_INVALIDA);
    
    imprime_matriz(m2);
    
    do{
        y = get_valor(m2);

        if ( y == ERRO_COORDENADA_INVALIDA){
            printf("Coordenadas inseridas sao invalidas\n");
        }else{
            printf("o valor é %d!\n", y);
        }
        
    }while (x == ERRO_COORDENADA_INVALIDA);
    
    int compara = compara_matrizes(m, m2);
    if (compara == 0){
        printf("As matrizes sao diferentes!\n");
    }else{
        printf("As matrizes sao iguais!\n");
    }
    Matriz m3;
    

    if ((m.linha == m2.linha) && (m.coluna == m2.coluna)){
        printf("As matrizes podem ser somadas!\n");
        soma_matrizes(m, m2, &m3);
        imprime_matriz(m3);

        
    }else{
        printf("matrizes incompativeis para soma!\n");
    }   

    Matriz m4;

    if (m.coluna == m2.linha){
        printf("As matrizes podem ser multiplicadas!\n");
        multiplica_matrizes(m, m2, &m4);
        imprime_matriz(m4);
    }else{
        printf("matrizes incompativeis para multiplicacao!\n");
    }   
    libera_matriz(&m);
    libera_matriz(&m2);
    libera_matriz(&m3);
    libera_matriz(&m4);
    printf("Fim!\n");
    return 0;
}