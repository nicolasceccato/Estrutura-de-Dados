#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void inicializa_matriz(Matriz *m, int linhas, int colunas){
    int i, j;
    m->lin = linhas;
    m->col = colunas;

    m->dados = malloc(sizeof(int*)*linhas);
    
    for (i = 0; i < linhas; i++){
        m->dados[i] = malloc(sizeof(int)*colunas);
    }
        
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            m->dados[i][j] = 0;
        }
    }
}
void desaloca_matriz(Matriz *m){
    int i;
    for(i = 0; i < m->lin; i++){
        free(m->dados[i]);
    }
    free(m->dados);
}
int carrega_arquivo(char *nome, Matriz *m){
    FILE *f = fopen(nome, "rt");
    if(f == NULL){
        return 0;
    }
    int i, j, l, c;
    
    fscanf(f, "%d%d", &l, &c);

    inicializa_matriz(m,l,c);

    for (i = 0; i < l; i++){
        for (j = 0; j < c; j++ ){
            fscanf(f, "%d", &m->dados[i][j]);
        }
    }
    fclose(f);
    return 1;
}
int soma_matrizes(Matriz a, Matriz b, Matriz *c){
    if (a.lin != b.lin || a.col != b.col){
        return ERRO_MATRIZES_INCOMPATIVEIS;
    }
    inicializa_matriz(c, a.lin, b.col);

    int i, j;
   
    for(i = 0; i < a.lin; i++){
        for(j = 0; j < b.col; j++){
            c->dados[i][j] = a.dados[i][j] + b.dados[i][j];
        }
    }
    return 1;
}
int salva_arquivo(char *nome, Matriz m){
    FILE *f = fopen(nome, "wt");
    if(f == NULL){
        return 0;
    }
    int i, j;
    fprintf(f, "%d %d\n", m.lin, m.col);

    for(i = 0; i < m.lin; i++){
        for(j = 0; j < m.col; j++){
            fprintf(f, "%4d", m.dados[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    return 1;
}

