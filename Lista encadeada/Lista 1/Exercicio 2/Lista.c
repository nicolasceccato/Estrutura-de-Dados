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
void inicializa_lista(Lista *p, int t){
    p->tamInfo = t;
    p->cabeca = NULL;
    p->qtd = 0;
}
int lista_vazia (Lista l){
    return l.cabeca == NULL;
}
int insere_inicio (Lista *p, void *info){
    Elemento *novo = aloca_elemento(info, p->tamInfo);
    if(novo == NULL){
        return 0; //Erro, falta de memória!
    }
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
        printf("Dados da lista: (%d elementos)\n", l.qtd);
        Elemento *p = l.cabeca;
        int cont = 0;
        while(p != NULL){
            printf("[%d] ", cont);
            mostra (p->info);
            p = p->proximo;
            cont++;
        }
    }
    printf("--------------------------------\n");
}
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
int insere_fim (Lista *p, void *info){
    if(lista_vazia(*p)){
        return insere_inicio(p, info);
    }
    Elemento *aux = p->cabeca;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    Elemento *novo = aloca_elemento(info, p->tamInfo);
    if(novo == NULL){
        return 0; //Erro, falta de memória!
    }
    aux->proximo = novo;
    novo->proximo = NULL;
    p->qtd++;
    return 1; //Sucesso!
}
int remove_fim (Lista *p, void *info){
    if(lista_vazia(*p)){
        return ERRO_LISTA_VAZIA;
    }
    if(p->qtd == 1){ // ou p->cabeca->proximo == NULL
        return remove_inicio (p, info);
    }
    Elemento *aux = p->cabeca;
    while(aux->proximo->proximo != NULL){
        aux = aux->proximo;
    }
    Elemento *ultimo = aux->proximo;
    memcpy(info, ultimo->info, p->tamInfo);
    free(ultimo->info);
    free(ultimo);
    aux->proximo = NULL;
    p->qtd--;
    return 1;
}
int insere_pos (Lista *p, void *info, int pos){
    if (pos < 0 || pos > p->qtd){
        return ERRO_POS_INVALIDA;
    }
    if(pos == 0){
        return insere_inicio(p, info);
    }
    Elemento *aux = p->cabeca;
    int cont;
    for(cont = 0; cont < pos-1; cont++){
        aux = aux->proximo; //vai até o elemento em pos-1
    }
    Elemento *novo = aloca_elemento (info, p->tamInfo);
    if (novo == NULL){
        return 0; //Erro, falta de memória!
    }
    novo->proximo = aux->proximo;
    aux->proximo = novo;
    p->qtd++;
    return 1; //Sucesso!
}
int remove_pos (Lista *p, void *info, int pos){
    if(lista_vazia(*p)){
        return ERRO_LISTA_VAZIA;
    }
    if(pos < 0 || pos >= p->qtd){
        return ERRO_POS_INVALIDA;
    }
    if( pos == 0){
        return remove_inicio(p, info);
    }
    Elemento *aux = p->cabeca;
    int cont;
    for (cont = 0; cont < pos-1; cont ++){
        aux = aux->proximo; // Vai até pos-1
    }
    Elemento *x = aux->proximo;
    aux->proximo = x->proximo;
    memcpy(info, x->info, p->tamInfo);
    free(x->info);
    free(x);
    p->qtd--;
    return 1; // Sucesso!
}
int le_valor (Lista l, void *info, int pos){
    if(lista_vazia(l)){
        return ERRO_LISTA_VAZIA;
    }
    if (pos < 0 || pos >= l.qtd){
        return ERRO_POS_INVALIDA;
    }
    Elemento *aux = l.cabeca;
    int cont;
    for (cont = 0; cont < pos; cont++){
        aux = aux->proximo; // Vai até o elemento em pos
    }
    memcpy(info, aux->info, l.tamInfo);
    return 1; // Sucesso!
}
int modifica_valor (Lista l, void *info, int pos){
    if (lista_vazia(l)){
        return ERRO_LISTA_VAZIA;
    }
    if (pos < 0 || pos >= l.qtd){
        return ERRO_POS_INVALIDA;
    }
    Elemento *aux = l.cabeca;
    int cont;
    for (cont = 0; cont < pos; cont++){
        aux = aux->proximo; // Vai até elemento em pos
    }
    memcpy(aux->info, info, l.tamInfo);
    return 1; // Sucesso!
}
int insere_ordem( Lista *p, void *info, int (*compara)(void *, void *) ){
    Elemento *aux = p->cabeca;
    int cont = 0;

    while (aux !=NULL && compara(info, aux->info) > 0){
        aux = aux->proximo;
        cont++;
    }
    return insere_pos (p, info, cont);
}

