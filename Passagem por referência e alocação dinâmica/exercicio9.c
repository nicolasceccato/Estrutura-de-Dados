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


void imprime_vetor (int *v, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%i ", v[i]);
    }
    printf("\n");

}

int main(){
    int *vetor,*vp = NULL, *vn = NULL, nTotal, nPositivo = 0, nNegativo = 0;

    printf("Quantos termos deseja? ");
    scanf("%i", &nTotal);

    vetor = (int*)malloc(sizeof(int)*nTotal);

    int i;

    for (i = 0; i < nTotal; i++){
        printf("Digite o %io termo do vetor: ", i+1);
        scanf("%i", &vetor[i]);

        if (vetor[i] > 0){
            nPositivo++;
            vp = realloc(vp, sizeof(int)*nPositivo);
            vp[nPositivo-1] = vetor[i];
        }else{
            if(vetor[i] < 0){
                nNegativo++;
                vn = realloc(vn,sizeof(int)*nNegativo);
                vn[nNegativo-1] = vetor[i];
            }
        }
    }

    printf("Vetor original: ");
    imprime_vetor(vetor, nTotal);

    printf("Vetor positivo: ");
    imprime_vetor(vp, nPositivo);
    
    printf("Vetor original: ");
    imprime_vetor(vn, nNegativo);


    return 0;
}