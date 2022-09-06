/*1) Escreva uma função que troca os valores entre duas variáveis do tipo float. Faça um
programa que leia duas variáveis e mostre seus valores na tela. Em seguida, troque os
valores (usando a função) e mostre novamente os valores.
void troca_valor(float *x, float *y);*/
#include <stdio.h>
#include <stdlib.h>

void troca_valor(float *x, float *y);


int main(int argc, char *argv[ ]) {
    float a, b;
    
    printf ("Digite dois valores(A e B respectivamente): ");
    scanf("%f%f", &a,&b);

    printf("A:%.2f\nB:%.2f\n", a,b);

    troca_valor (&a, &b);

    printf("Os novos valores sao:\n");

    printf("A:%.2f\nB:%.2f\n", a,b);
    
    return 0;
    }
void troca_valor(float *x, float *y){
    float aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
