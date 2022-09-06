/*2) Faça uma função que calcula o perímetro e a área de um círculo, dado o raio.
void calcula_circulo(float raio, float *pPerimetro, float *pArea);*/
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
void calcula_circulo(float raio, float *pPerimetro, float *pArea);


int main(int argc, char *argv[ ]) {
    float r, perimetro, area;
    
    printf ("Digite o raio do circulo ");
    scanf("%f", &r);

    calcula_circulo(r, &perimetro, &area);

    printf("Os valores sao:\n");

    printf("Raio: %.2f\nArea: %.2f\nPerimetro: %.2f\n", r,area,perimetro);
    
    return 0;
    }
void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    *pArea = PI*raio*raio;
    *pPerimetro = 2*PI*raio;
}
