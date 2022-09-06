/*9) Faça um programa que leia uma certa quantidade de inteiros que são armazenados num
vetor v. A quantidade deve ser definida pelo usuário, e o programa aloca espaço para v. O
programa deve armazenar os valores positivos em um vetor vp e o valores negativos no
vetor vn. Como as quantidades de valores positivos e negativos são desconhecidas, o
espaço para vp e vn deve ser alocado dinamicamente. Os vetores vp e vn não devem
conter zeros. Ao final, imprima os três vetores. Pode ser feito com malloc() ou com
realloc(). */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int *gera_vetor(int tam){
    int i;
    
    int *v = malloc(sizeof(int)*tam);

    for (i = 0; i < tam; i++){
        printf("Digite o %io termo do vetor: ", i+1);
        scanf("%i", &v[i]);

    }
    return v;
}
int *gera_vetor_positivo(int *v, int tam , int *np ){
    int i;
    *np = 0;
    int *vp = NULL;
    for (i = 0; i < tam; i++){
        if (v[i] > 0){
            (*np)++;
            vp = realloc(vp, sizeof(int)*(*np));
            vp[(*np-1)] = v[i];
        
        }
    
    }
    return vp;
}
int *gera_vetor_negativo(int *v, int tam, int *nn){
    int i;
    *nn = 0;
    int *vn = NULL;
    for (i = 0; i < tam; i++){
        if (v[i] < 0){
            (*nn)++;
            vn = realloc(vn, sizeof(int)*(*nn));
            vn[(*nn)-1] = v[i];
        }
    }
    return vn;
}
void imprime_vetor(int *v, int tam){
    int i;

    for (i = 0; i < tam; i++){
        printf("%i ", v[i]);
    }
    printf("\n");
    
}
int main(){
    int *v, *vn, *vp, n, np, nn;

    printf("Quantos termos terá o vetor? ");
    scanf("%i", &n);

    v = gera_vetor(n);

    printf("Vetor original: \n");
    imprime_vetor(v,n);

    vp = gera_vetor_positivo(v, n,&np);
    printf("Vetor positivo: \n");
    imprime_vetor(vp,np);

    vn = gera_vetor_negativo(v, n, &nn);
    printf("Vetor negativo: \n");
    imprime_vetor(vn,nn);

    return 0;
}