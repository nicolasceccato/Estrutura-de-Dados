#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"


void inicializa_matriz(Matriz *x){
    int i, j;
    printf("quantas linhas deseja nessa matriz? ");
    scanf("%d", &x->linha);
    int lin = x->linha;
    printf("quantas colunas deseja nessa matriz? ");
    scanf("%d", &x->coluna);
    int col = x->coluna;
    
    x->dados = malloc(sizeof(int*)*lin);

    for (i = 0; i < x->linha; i++){
        x->dados[i] = malloc (sizeof(int)*col);
        for (j = 0; j < x->coluna; j++){
            x->dados[i][j] = 0;
        }
    }   
}

void imprime_matriz(Matriz x){
    int i, j;
    for (i = 0; i < x.linha; i++){
        for(j = 0; j < x.coluna; j++){
            printf("%d ", x.dados[i][j]);
        }
        printf("\n");
    }
    
}
int set_valor (Matriz *x){
    int i, j, lin, col, valor;
    printf("Digite a linha e a coluna e qual valor deseja inserir: ");
    scanf("%d%d%d", &lin, &col, &valor);

    if (lin >= x->linha || col >= x->coluna){
        return ERRO_COORDENADA_INVALIDA;
    }
    x->dados[lin][col] = valor;

    return 1;

}
int get_valor (Matriz x){
    int i, j, lin, col;
    printf("Digite a linha e a coluna que deseja resgatar o valor: ");
    scanf("%d%d", &lin, &col);

    if (lin >= x.linha || col >= x.coluna){
        return ERRO_COORDENADA_INVALIDA;
    }
    
    return x.dados[lin][col];
}
int compara_matrizes(Matriz m, Matriz y){
    int i, j;
    if (m.linha != y.linha || m.coluna != y.coluna){
        return 0;
    }
    for (i = 0; i < m.linha; i++){
        for (j = 0; j < m.coluna; j++){
            if (m.dados[i][j] != y.dados[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
void soma_matrizes(Matriz m, Matriz y, Matriz *m3){
    int i, j;
    int lin = m.linha;
    int col = m.coluna;
    m3->dados = malloc(sizeof(int*)*lin);
    for (i = 0; i < lin; i++){
        m3->dados[i] = malloc(sizeof(int)*col);
    }
    
    for (i = 0; i < lin; i++){
        for (j = 0; j < col; j++){
            m3->dados[i][j] = m.dados[i][j] + y.dados[i][j];        
        }
    }
    m3->linha = lin;
    m3->coluna = col;
}

void multiplica_matrizes(Matriz m, Matriz m2, Matriz *m4){
    int i, j, k, aux = 0;
    m4->dados = malloc(sizeof(int*)*(m.linha));
    for (i = 0; i < m.linha; i++){
        m4->dados[i] = malloc(sizeof(int)*(m2.coluna));
    }
    m4->linha = m.linha;
    m4->coluna = m2.coluna;

    for (i = 0; i < m.linha; i++){
        for (j = 0; j < m2.coluna; j++){
            m4->dados[i][j] = 0;
            for (k = 0; k < m.coluna; k++){
                aux = aux + (m.dados[i][k] * m2.dados[k][j]); 
            }
            m4->dados[i][j] = aux;
            aux = 0;
        }
        
    }

}
void libera_matriz(Matriz *m){
    int i;

    for(i = 0; i < m->linha; i++){
        free(m->dados[i]);
    }
    free(m->dados);
}
