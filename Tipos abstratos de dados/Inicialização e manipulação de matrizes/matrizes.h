#define ERRO_COORDENADA_INVALIDA -1

typedef struct{
    int **dados;
    int linha, coluna;
} Matriz;

void inicializa_matriz(Matriz *x);

void imprime_matriz(Matriz x);

int set_valor (Matriz *x);

int get_valor (Matriz x);

int compara_matrizes(Matriz m, Matriz y);

void soma_matrizes(Matriz m, Matriz y, Matriz *m3);

void multiplica_matrizes(Matriz m, Matriz m2, Matriz *m4);

void libera_matriz(Matriz *m);
