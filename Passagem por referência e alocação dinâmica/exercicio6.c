/*Escreva uma função que recebe um vetor float v e sua capacidade n, e retorne o endereço
de um vetor alocado dinamicamente, cujo conteúdo seja o mesmo de v, ou seja, a função
retorna um clone do vetor v. Faça o programa principal com a entrada de dados (ou um
vetor fixo), chame a função e mostre o vetor resultante na tela. Protótipo da função:
float *clone( float *v, int n );*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *clone( float *v, int n );
void imprime_vetor (float vet[], int tam);
int main(int argc, char *argv[ ]) {
    int n, i, indice;
    float *v, *v2;

    printf("quantos termos deseja no vetor? ");
    scanf("%i", &n);

    v = (float*)malloc(sizeof(float)*n);
    
    srand(time(0));

    for (i = 0; i < n; i++){
        v[i] = rand()%10;
    }
    //printf("vetor original: endereço %lf\n",v);
    imprime_vetor(v,n);
    v2 = clone(v,n);
    //printf("vetor clone: endereço %lf\n",v2);
    imprime_vetor(v2,n);


    
    free(v);
    free(v2);
    return 0;
    }
void imprime_vetor (float vet[], int tam){
    int i;

    for (i = 0; i < tam; i++){
        printf("%.2f ", vet[i]);
    }
    printf("\n");

}
float *clone( float *v, int n ){
    float *v2_clone;
    int i;

    v2_clone = (float*)malloc(sizeof(float)*n);

    for (i = 0; i < n; i++){
        v2_clone[i] = v[i];    
    }
    return v2_clone;
}
