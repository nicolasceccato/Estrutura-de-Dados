#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

void inicializa_lista(Lista *p, int t){
    p->tamInfo = t;
    p->cabeca = NULL;
    p->qtd = 0;
}
int lista_vazia (Lista l){
    return l.cabeca == NULL;
}
int insere_inicio (Lista *p, void *info){
    Elemento *novo = malloc(sizeof(Elemento));
    if(novo == NULL){
        return 0; //Erro, falta de memória!
    }
    novo->info = malloc (p->tamInfo);
    if(novo->info == NULL){
        free(novo);
        return 0; //Erro, falta de memória!
    }
    memcpy(novo->info, info, p->tamInfo);
    novo->proximo = p->cabeca;
    p->cabeca = novo;
    p->qtd++;
    return 1; //Sucesso!
}
int remove_inicio (Lista *p, void *info){
    if(lista_vazia(*p)){
        return ERRO_LISTA_VAZIA;
    }
    Elemento *aux = p->cabeca;
    memcpy(info, aux->info, p->tamInfo);
    p->cabeca = aux->proximo;
    free(aux->info);
    free(aux);
    p->qtd--;
    return 1; //Sucesso!
}
void mostra_lista (Lista l, void (*mostra)(void*)){
    if(lista_vazia(l)){
        printf("Lista vazia!\n");
    }else{
        printf("Dados da lista:\n");
        Elemento *p = l.cabeca;
        while(p != NULL){
            mostra (p->info);
            p = p->proximo;
        }
    }
}/*
int conta_elementos( Lista l ){
    int cont = 0;
    Elemento *aux = l.cabeca;
    while(l.cabeca != NULL){
        cont++;
        l.cabeca = aux->proximo;
        aux = aux->proximo;
    }
    return cont;
}
void desaloca_lista( Lista *l ){
    Elemento *aux = l->cabeca;
    int i;
    int quantidade = l->qtd;
    for(i = 0; i < quantidade; i++, l->cabeca = aux->proximo){
        free(aux->info);
        free(l->cabeca);
        l->qtd--;
    }

    free(l);
}*/
int conta_elementos(Lista l){
    int cont = 0;
    Elemento *aux = l.cabeca;
    while(aux != NULL){
        cont++;
        aux = aux->proximo;
    }
    return cont;
}
void limpa_lista(Lista *p){
    Elemento *aux = p->cabeca;
    while(aux != NULL){
        Elemento *prox = aux->proximo;
        free(aux->info);
        free(aux);
        aux = prox;
    }
    inicializa_lista(p, p->tamInfo);
}
	

