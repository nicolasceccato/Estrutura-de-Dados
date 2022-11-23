#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
// PRIVADO------------------------------
Elemento *aloca_elemento (void *info, int tam){
    Elemento *p = malloc(sizeof (Elemento));
    if(p == NULL){
        return 0; //Erro, falta de memória!
    }
    p->info = malloc(tam);
    if(p->info == NULL){
        free(p);
        return 0; //Erro, falta de memória!
    }
    memcpy(p->info, info, tam);
    return p;
}
//--------------------------------------
void inicializa_fila (FilaEnc *f, int c){
    f->tamInfo = c;
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
}

int fila_vazia (FilaEnc f){
    return f.inicio == NULL;
}

//int fila_cheia (FilaEnc f);

int inserir (FilaEnc *f, void *info){
    
    if (fila_vazia(*f)){
        Elemento *novo = aloca_elemento(info, f->tamInfo);
        
        f->inicio = novo;
        
        f->fim = f->inicio;
        
        novo->proximo = NULL;
        f->qtd++;
        
    }else{
        Elemento *auxiliar = f->fim;
        
        Elemento *novo = aloca_elemento(info, f->tamInfo);
        
        if (novo == NULL){
            return 0; // Erro por falta de memória!
        }
        
        f->fim->proximo = novo;
        f->fim = novo;

        novo->proximo = NULL;
        
        f->qtd++;
        
    }
    return 1; //Sucesso!

}

int remover (FilaEnc *f, void *info){
    if(fila_vazia(*f)){
        return ERRO_LISTA_VAZIA;
    }
    Elemento *auxiliar = f->inicio;
    memcpy(info, auxiliar->info, f->tamInfo);
    f->inicio = auxiliar->proximo;
    free(auxiliar->info);
    free(auxiliar);
    f->qtd--;
    return 1; //Sucesso
}

void mostra_fila (FilaEnc f, void (*mostra)(void*)){
    if(fila_vazia(f)){
        printf("Fila vazia!\n");
    }else{
        printf("Dados da fila: (%d elementos)\n", f.qtd);
        Elemento *p = f.inicio;
        int cont = 0;
        while (p != NULL){
            printf("[%d] ", cont);
            mostra(p->info);
            p = p->proximo;
            cont++;
        }
    }
}

void desaloca_fila (FilaEnc *f){
    Elemento *auxiliar = f->inicio;
    while(auxiliar != NULL){
        Elemento *prox = auxiliar->proximo;
        free(auxiliar->info);
        free(auxiliar);
        auxiliar = prox;
    }
}