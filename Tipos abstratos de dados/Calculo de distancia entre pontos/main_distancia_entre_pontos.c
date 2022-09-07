#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "biblioteca_distancia.h"

int main (){
    int i, n;
    Ponto *p;
    
    printf("Quantos pontos você deseja criar? ");
    scanf("%d", &n);

    p = malloc(sizeof(Ponto)*n);

    for (i = 0; i < n; i++){
        inicializa_ponto(&p[i]);
    }
    for (i = 0; i < n; i++){
        imprime_ponto(p[i]);
        printf("---Usando getters: ( %.2f , %.2f)\n", get_x(p[i]), get_y(p[i]));
    }
    for (i = 0; i < n-1; i++){
        printf("Distancia entre os pontos %d e %d = %.2f\n", i+1,i+2, calcula_distancia(p[i], p[i+1]));
    }
    free(p);
    return 0;
}

