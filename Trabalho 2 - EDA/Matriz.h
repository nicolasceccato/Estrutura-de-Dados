#define ERRO_COORD_INVALIDA -1
#define MATRIZES_INCOMPATIVEIS -2

typedef struct{
	int **dados;
	int lin, col;
    int vertice;
} Matriz;

void inicializa_matriz( Matriz *p, int l, int c );
void mostra_matriz( Matriz m );
void libera_matriz( Matriz *p );
int set_valor( Matriz *p, int i, int j, int v );
int get_valor( Matriz m, int i, int j, int *p );
int carrega_arquivo( char *nome, Matriz *p );
int salva_arquivo( char *nome, Matriz m );
int soma_matrizes( Matriz m1, Matriz m2, Matriz *p );
//int multiplica_matrizes( Matriz m1, Matriz m2, Matriz *p );
int sao_iguais( Matriz m1, Matriz m2 );