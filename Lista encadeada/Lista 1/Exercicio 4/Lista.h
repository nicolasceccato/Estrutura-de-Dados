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

//fila encadeada
typedef struct {
    Elemento *inicio, *fim;
    int tamInfo, qtd;
} FilaEnc;

void inicializa_fila (FilaEnc *f, int c);

int fila_vazia (FilaEnc f);

//int fila_cheia (FilaEnc f);

int inserir (FilaEnc *f, void *info);

int remover (FilaEnc *f, void *info);

void mostra_fila (FilaEnc f, void (*mostra)(void*));

void desaloca_fila (FilaEnc *f);