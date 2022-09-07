#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "biblioteca_distancia.h"



void inicializa_ponto(Ponto *p){
    printf("Digite o valor para o eixo x: ");
    scanf("%f", &p->x);
    printf("Digite o valor para o eixo y: ");
    scanf("%f", &p->y);
     
}
void imprime_ponto(Ponto p){
    printf ("( %.1f , %.1f )\n", p.x,p.y);
}
float get_x(Ponto p){
    return p.x;
}
float get_y(Ponto p){
    return p.y;
}
float calcula_distancia(Ponto p, Ponto q){
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}
    
