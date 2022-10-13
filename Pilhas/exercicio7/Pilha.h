#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2

typedef struct{
    int *dados;
    int topo1;
    int topo2;
    int capacidade;
} PilhaDupla;

void inicializa_pilha (PilhaDupla *p, int c);

int pilha1_vazia (PilhaDupla p);

int pilha2_vazia (PilhaDupla p);

int pilhas_cheias (PilhaDupla p);

int empilha1 (PilhaDupla *p, int info);

int empilha2 (PilhaDupla *p, int info);

int desempilha1 (PilhaDupla *p, int *info);

int desempilha2 (PilhaDupla *p, int *info);

int le_topo1(PilhaDupla p, int *info);

int le_topo2(PilhaDupla p, int *info);

void mostra_pilha1(PilhaDupla p);

void mostra_pilha2(PilhaDupla p);

void mostra_pilha(PilhaDupla p);

void desaloca_pilha (PilhaDupla *p);