/*10) Escreva uma função que realiza a união entre dois conjuntos de inteiros contidos nos
vetores v1 e v2. A função recebe os vetores e suas respectivas capacidades (n1 e n2) como
parâmetros de entrada e retorna o endereço do vetor alocado (contendo a união entre v1
e v2). Além disso, há um parâmetro passado por referência (ponteiro p3), que serve para
“retornar” a capacidade do vetor gerado. Faça o programa principal invocando a função.
Protótipo da função:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int *uniao( int *v1, int n1, int *v2, int n2, int *p3 ){
    int *v3, i, j=0;

    v3 = (int*)malloc(sizeof(int)*(n1+n2));

    for (i = 0; i < n1; i++){
        v3[j] = v1[i];
        j++;
    }
    for (i = 0; i < n2; i++){
        v3[j] = v2[i];
        j++; 
    }
    int k, aux;
    for (i = 0; i < (n1+n2)-1; i++){
        for (k = i+ 1; k < (n1+n2); k++){
            if(v3[i] > v3[k]){
                aux = v3[i];
                v3[i] = v3[k];
                v3[k] = aux;
            }
        }
    }
    int tam = n1+n2;
    for (i = 0; i < (tam); i++){
        for(j = i+1; j <(tam);){
            if (v3[i] == v3[j])
            {
                for (k = j; k < (tam); k++){
                    v3[k] = v3[k+1];
                }
                tam--;
            }
            else{
                j++;
            }
            
        }
    }
    *p3 = tam;
    return v3;
}
int *gera_vetor(int *v, int tamanho){
    int i;

    v =  (int*)malloc(sizeof(int)*tamanho);

    for (i = 0; i < tamanho; i++){
        printf("digite o %i termo do vetor:", i+1);
        scanf("%i", &v[i]);
    }
    
    return v;

}
void imprime_vetor(int *v, int tamanho){
    int i;

    for (i = 0; i < tamanho; i++){
        printf("%i ", v[i]);
    }
    printf("\n");
}
int main(){
    int *v1, n1, *v2, n2, *v3, n3;

    printf("quantos elementos no v1? ");
    scanf("%i", &n1);
    
    v1 = gera_vetor(v1,n1);
    
    printf("Vetor 1: \n");
    imprime_vetor(v1,n1);

    printf("quantos elementos no v2? ");
    scanf("%i", &n2);
    
    v2 = gera_vetor(v2, n2);

    printf("Vetor 2: \n");
    imprime_vetor(v2,n2);

    v3 = uniao(v1,n1,v2,n2,&n3);

    printf("Vetor Resultante: \n");
    imprime_vetor(v3,n3);
   
    return 0;
}