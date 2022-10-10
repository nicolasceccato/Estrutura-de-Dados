#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Matriz.h"
int *inicializa_vetor(int c);
void imprime_apresentacao();
int main(){
    

    Matriz a;
	
	if( !carrega_arquivo( "m1.txt", &a ) ){
		printf("Arquivo nao encontrado!\n");
		return -1;
	}
   
    int vert;
    char resposta;
    do{
        imprime_apresentacao();
        mostra_matriz(a);
        int *v = inicializa_vetor(a.lin);
        Pilha p;
        inicializa_pilha(&p, a.lin);
        do{
            printf("Em qual vértice, de 1 a %i voce gostaria de iniciar a busca?\n", a.lin);
            scanf("%d", &vert);
        }while(vert < 1 || vert > a.lin);
        printf("--------------------------------------------------------\n");
        printf("Para o vertice %i escolhido tem-se a seguinte ordem de busca em profundidade no grafo:\n\n", vert);
        a.vertice = vert - 1;
    
        int i, j;
             
        empilha(&p, a.vertice);

        int info;
        while (! pilha_vazia(p)){
            desempilha(&p, &info);
            if(v[info] == 0){
                printf("%d\n", info+1);
            }
            v[info] = 1;
            for (i = info, j = 0; j < a.col; j++){
                if(a.dados[i][j] == 1 && v[j] == 0){
                    empilha(&p, j);
                }
            }
        }
        free(v);
        desaloca_pilha(&p);
        printf("Deseja continuar? Digite n para sair\n");
        scanf(" %c", &resposta);
        system("clear"); 
        
    }while(resposta != 'n');
    
    libera_matriz(&a); 
    return 0;
}
int *inicializa_vetor(int c){
    int *v;
    v = malloc (sizeof(int)*c);
    int i;
    for ( i = 0; i < c; i++){
        v[i] = 0;
    }
    return v;
}
void imprime_apresentacao(){
    printf("------------------------------------------\n");
    printf("---- Trabalho de Estrutura de Dados ------\n");
    printf("--- Busca em profundidade em um grafo ----\n");
    printf("------- Nicolas Gabriel Ceccato ----------\n");
    printf("------------------------------------------\n");
}