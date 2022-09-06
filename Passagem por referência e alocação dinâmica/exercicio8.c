/*8) Escreva um programa que aloca dinamicamente um vetor do tipo float e realiza a entrada
de dados. Em seguida, o programa deve calcular a média dos valores do vetor e alocar
dinamicamente um novo vetor contendo somente os valores maiores ou iguais à media. O
processo pode ser feito usando malloc(), ou seja, fazendo a contagem, alocação e cópia
dos valores. Outra alternativa consiste em usar realloc() para ir aumentando o espaço
alocado à medida que os valores vão sendo encontrados.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float *aloca_vetor (float *media, int *tam);
float *novo_vetor(float *v, float media, int tam, int *nv_tam);
void imprime_vetor (float vet[], int tam);
int main(int argc, char *argv[ ]) {
    float *v, *v2, media;
    int tam, nv_tam;
    
    v = aloca_vetor(&media, &tam);

    printf("Vetor original: \n");
    imprime_vetor(v, tam);

    printf("A media dos valores do Vetor original eh: %f \n", media);

    printf("O novo vetor eh: \n");

    v2 = novo_vetor(v, media, tam, &nv_tam);

    imprime_vetor(v2, nv_tam);



    return 0;
    }
float *novo_vetor(float *v, float media, int tam, int *nv_tam)    {
    float *v2 = NULL;
    int i,j = 0;

    for ( i = 0; i < tam; i++)
    {
        if(v[i] > media){
            v2 = (float*)realloc(v2, sizeof(float)*(j+1));
            v2[j] = v[i];
            j++;
        }
    }
    *nv_tam = j;
    
    return v2;
}
float *aloca_vetor ( float *media, int *tam){
    float *v2, soma = 0;
    int i, n;
    printf("Digite quantos termos deseja no vetor: ");
    scanf("%i", &n);
    *tam = n;

    v2 = (float*)malloc(sizeof(float)*n);

    srand(0);

    for (i=0;i<n;i++){
        v2[i] = rand()%10;
        soma += v2[i];
    }
    *media = soma/n;
    return v2;

    
}    
void imprime_vetor (float vet[], int tam){
    int i;

    for (i = 0; i < tam; i++){
        printf("%.2f ", vet[i]);
    }
    printf("\n");

}
