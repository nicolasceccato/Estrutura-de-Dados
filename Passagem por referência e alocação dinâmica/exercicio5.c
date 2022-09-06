/*5) Escreva um programa que determine o maior valor de um vetor bem como sua posição no
vetor (índice). Tal processamento deve ser feito em uma função que recebe o vetor (do
tipo float) e sua capacidade, e “retorna” o maior elemento e sua posição.
void max_vetor(float vet[], int tam, float *pMax, int *pIndice);*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void max_vetor(float vet[], int tam, float *pMax, int *pIndice);
void imprime_vetor (float vet[], int tam);
int main(int argc, char *argv[ ]) {
    int n, i, indice;
    float *v, maior, menor;

    printf("quantos termos deseja no vetor? ");
    scanf("%i", &n);

    v = (float*)malloc(sizeof(float)*n);
    
    srand(time(0));

    for (i = 0; i < n; i++){
        v[i] = rand()%10;
    }
    imprime_vetor(v,n);
    max_vetor(v,n,&maior,&indice);


    printf("O maior valor e seu indice sao:\n");

    printf("Maior: %.2f\nIndice: %i\n",maior,indice);
    
    free(v);
    return 0;
    }
void imprime_vetor (float vet[], int tam){
    int i;

    for (i = 0; i < tam; i++){
        printf("%.2f ", vet[i]);
    }

}
void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
    int i;
    *pIndice = 0;
    *pMax = vet[0];

    for (i = 1; i < tam; i++){
        
        if (vet[i] > *pMax){
            *pMax = vet[i];
            *pIndice = i;
        }    
    }

}
