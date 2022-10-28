#include <stdio.h>
#include <stdlib.h>
int *aloca_vetor(int n);
void aloca_vetor_void(int **v, int n);
void imprime_vetor_na_tela(int *v, int n);
int main(){
    int n, *v, *v1;
    printf("Qual o tamanho dos vetores: ");
    scanf("%d", &n);

    v = aloca_vetor(n);
    aloca_vetor_void(&v1, n);
    imprime_vetor_na_tela(v, n);
    imprime_vetor_na_tela(v1, n);
}
int *aloca_vetor(int n){
    int *vetor;
    vetor = malloc(sizeof(int)*n);
    int i;
    for(i = 0 ; i < n; i++){
        vetor[i] = i;
    }
    return vetor;
}
void aloca_vetor_void(int **v, int n){
    *v = malloc(sizeof(int)*n);
    int i;
    for(i = 0 ; i < n; i++){
        (*v)[i] = i;
    }
}
void imprime_vetor_na_tela(int *v, int n){
    int i;
    for(i = 0; i < n; i++ ){
        printf("%d ", v[i]);
    }
    printf("\n");
}
