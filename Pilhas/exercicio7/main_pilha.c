#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define MAX 5
int main(){
    PilhaDupla p;
    inicializa_pilha(&p,MAX);
    int x;
    mostra_pilha(p);
    mostra_pilha1(p);
    mostra_pilha2(p);

    empilha1(&p, 5);
    mostra_pilha1(p);
    mostra_pilha2(p);
    mostra_pilha(p);
    
    empilha2(&p, 1);
    mostra_pilha1(p);
    mostra_pilha2(p);
    mostra_pilha(p);
    
    empilha1(&p, 8);
    mostra_pilha1(p);
    mostra_pilha2(p);
    mostra_pilha(p);
    
    empilha2(&p, 33);
    mostra_pilha1(p);
    mostra_pilha2(p);
    mostra_pilha(p);

    empilha1(&p, 89);
    mostra_pilha1(p);
    mostra_pilha2(p);
    mostra_pilha(p);


    printf("\n\n**************TOPO 1 = %d\n\n***********TOPO 2 = %d\n\n", p.topo1, p.topo2);
    empilha1(&p, 4);
    mostra_pilha1(p);
    mostra_pilha2(p);
    mostra_pilha(p);
    
    empilha2(&p, 37);
    mostra_pilha1(p);
    mostra_pilha2(p);
    mostra_pilha(p);

    desempilha1(&p, &x);
    mostra_pilha1(p);
    mostra_pilha2(p);
    mostra_pilha(p);
    
    desempilha2(&p, &x);
    mostra_pilha1(p);
    mostra_pilha2(p);
    mostra_pilha(p);

    desaloca_pilha(&p);
    
    return 0;

}

