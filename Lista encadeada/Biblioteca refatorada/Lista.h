#define ERRO_LISTA_VAZIA -1
#define ERRO_POS_INVALIDA -2;


//elemento de lista
typedef struct ele{
    void *info;
    struct ele *proximo;
}Elemento;

//cabeçalho de lista
typedef struct{
    Elemento *cabeca;
    int tamInfo;
    int qtd;
}Lista;

void inicializa_lista(Lista *p, int t);

int lista_vazia (Lista l);

int insere_inicio (Lista *p, void *info);

int remove_inicio (Lista *p, void *info);

void mostra_lista (Lista l, void (*mostra)(void*));

int conta_elementos(Lista l);

void limpa_lista(Lista *p);

int insere_fim (Lista *p, void *info);

int remove_fim (Lista *p, void *info);

int insere_pos (Lista *p, void *info, int pos);

int remove_pos (Lista *p, void *info, int pos);

int le_valor (Lista l, void *info, int pos);

int modifica_valor (Lista l, void *info, int pos);
