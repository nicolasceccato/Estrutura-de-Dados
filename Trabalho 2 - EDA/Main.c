#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
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
   
    int vertice_inicial, vertice_final;
    char resposta;
    do{
        imprime_apresentacao();
        mostra_matriz(a);
        int *vetor_de_status = inicializa_vetor(a.lin);
        int *vetor_de_antecessores = inicializa_vetor(a.lin);
        Fila f;
        inicializa_fila(&f, a.lin);

        do{
            printf("Em qual vertice, A, de 1 a %i voce gostaria de iniciar a busca?\n", a.lin);
            scanf("%d", &vertice_inicial); 
        }while(vertice_inicial < 1 || vertice_inicial > a.lin);
        do{
            printf("Em qual vertice, B, de 1 a %i voce gostaria de finalizar a busca?\n", a.lin);
            scanf("%d", &vertice_final); 
        }while(vertice_final < 1 || vertice_final > a.lin);
        int inicial = vertice_inicial-1;
        int final = vertice_final-1;
        
        vetor_de_status[inicial] = 1;
        inserir(&f, inicial);

        int i, j, x, achou = 0;

        while (!fila_vazia(f) && !achou){
            remover(&f, &x);
            if (x == final){
                achou = 1;
            }else{
                for(i = x, j = 0; j < a.col; j++){
                    if(a.dados[i][j] == 1 && vetor_de_status[j] == 0){
                        vetor_de_status[j] = 1;
                        vetor_de_antecessores[j] = x;
                        inserir(&f, j);
                    }
                }

            }
        }
    if(achou){
        Pilha p;

        inicializa_pilha(&p, a.lin);
        
        while(x != inicial ){
            empilha(&p, x);
            x = vetor_de_antecessores[x];
        }
        empilha(&p, x);
       // mostra_pilha(p);
       // mostra_fila(f);
        printf("--------------------------------------------------------\n");
        printf("O menor caminho entre os vertices %d e %d eh o seguinte : \n\n", vertice_inicial, vertice_final);
        int cont = 1;
        while(!pilha_vazia(p)){
            
            desempilha(&p, &x);
            printf("[%dº]%d\n",cont, x+1);
            cont++;
        }
        printf("\n-------------------------------------------------------\n");
        desaloca_pilha(&p);
    /*printf("vetor de status:\n");
    for(i = 0; i < a.lin; i ++){
        printf("%d ", vetor_de_status[i]);
    }
    printf("\n");
    for(i = 0; i < a.lin; i ++){
        if(vetor_de_antecessores[i] == 0){
            vetor_de_antecessores[i] = 98;
        }
    }
    printf("vetor de antecessores: \n");
    for(i = 0; i < a.lin; i ++){
        printf("%d ", vetor_de_antecessores[i]+1);
    }
    printf("\n");*/
    }
    else{
        printf("O ponto final B nao eh alcancavel a partir do ponto inicial A!\n");
    }

    free(vetor_de_status);
    free(vetor_de_antecessores);
    desaloca_fila(&f);
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
    printf("---- Trabalho 2 de Estrutura de Dados ----\n");
    printf("------ Busca em largura em um grafo ------\n");
    printf("-------- Nicolas Gabriel Ceccato ---------\n");
    printf("------------------------------------------\n");
}