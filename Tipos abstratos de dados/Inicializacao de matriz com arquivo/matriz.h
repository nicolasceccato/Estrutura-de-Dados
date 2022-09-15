#define ERRO_COORD_INVALIDA -1
#define ERRO_MATRIZES_INCOMPATIVEIS -2

typedef struct{
    int **dados;
    int lin, col;
} Matriz;

void inicializa_matriz(Matriz *m, int linhas, int colunas);
int carrega_arquivo(char *nome, Matriz *m);
int soma_matrizes(Matriz a, Matriz b, Matriz *c);
int salva_arquivo(char *nome, Matriz m);
void desaloca_matriz(Matriz *m);


