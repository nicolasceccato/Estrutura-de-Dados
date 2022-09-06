/*4) Escreva uma função que recebe um vetor e sua capacidade como parâmetros e precisa
“retornar” o maior e o menor valores do vetor.
void max_min(int vet[], int tam, int *pMin, int *pMax);*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void max_min(int vet[], int tam, int *pMin, int *pMax);
void imprime_vetor (int vet[], int tam);
int main(int argc, char *argv[ ]) {
    int n, *v, i, maior, menor;

    printf("quantos termos deseja no vetor? ");
    scanf("%i", &n);

    v = (int*)malloc(sizeof(int)*n);
    
    srand(time(0));

    for (i = 0; i < n; i++){
        v[i] = rand()%10;
    }
    imprime_vetor(v,n);
    max_min(v, n, &menor, &maior);


    printf("O maior e o menor valor sao:\n");

    printf("Maior: %i\nMenor: %i\n",maior,menor);
    
    free(p);
    return 0;
    }
void imprime_vetor (int vet[], int tam){
    int i;

    for (i = 0; i < tam; i++){
        printf("%i ", vet[i]);
    }

}
void max_min(int vet[], int tam, int *pMin, int *pMax){
    int i;
    *pMin = vet[0];
    *pMax = vet[0];

    for (i = 1; i < tam; i++){
        if (vet[i] < *pMin){
            *pMin = vet[i];
        }
        if (vet[i] > *pMax){
            *pMax = vet[i];
        }    
    }

}
