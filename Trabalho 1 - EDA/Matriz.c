#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

void inicializa_matriz( Matriz *p, int l, int c ){
	p->lin = l;
	p->col = c;
	p->dados = malloc( sizeof( int* ) * l );
	int i, j;
	for( i = 0 ; i < l ; i++ ){
		p->dados[i] = malloc( sizeof( int ) * c );
		for( j = 0 ; j < c ; j++ )
			p->dados[i][j] = 0;
	}
}

void mostra_matriz( Matriz m ){
	int i, j;
	printf("Dados da matriz (%dx%d):\n", m.lin, m.col);
	for( i = 0 ; i < m.lin ; i++ ){
		for( j = 0 ; j < m.col ; j++ ){
			printf("%4d ", m.dados[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void libera_matriz( Matriz *p ){
	int i;
	for( i = 0 ; i < p->lin ; i++ )
		free( p->dados[i] );
	free( p->dados );
}

int set_valor( Matriz *p, int i, int j, int v ){
	if( i >= p->lin || j >= p->col )
		return ERRO_COORD_INVALIDA;
	
	p->dados[i][j] = v;
	return 1; // Sucesso;
}

int get_valor( Matriz m, int i, int j, int *p ){
	if( i >= m.lin || j >= m.col )
		return ERRO_COORD_INVALIDA;
	
	*p = m.dados[i][j];
	return 1; // Sucesso;	
}

int carrega_arquivo( char *nome, Matriz *p ){
	FILE *f = fopen( nome, "rt" );
	if( f == NULL )
		return 0;
	
	int l, c, i, j, vert;
	fscanf( f, "%d", &l);
    c = l;
	inicializa_matriz( p, l, c );
	for( i = 0 ; i < l ; i++ ){
		for( j = 0 ; j < c ; j++ ){
			fscanf( f , "%d", &p->dados[i][j] );
        }   
    }
    /*fscanf(f, "%d", &vert);
    p->vertice = (vert - 1)*/;
	fclose( f );
	return 1;
}

int salva_arquivo( char *nome, Matriz m ){
	FILE *f = fopen( nome, "wt" );
	if( f == NULL )
		return 0;

	int i, j;
	fprintf( f, "%d %d\n", m.lin, m.col);
	for( i = 0 ; i < m.lin ; i++ ){
		for( j = 0 ; j < m.col ; j++ ){
			fprintf( f, "%4d ", m.dados[i][j]);
		}
		fprintf( f, "\n");
	}

	fclose( f );
	return 1;	
}


int soma_matrizes( Matriz m1, Matriz m2, Matriz *p ){
	if( m1.lin != m2.lin || m1.col != m2.col )
		return MATRIZES_INCOMPATIVEIS;
	
	inicializa_matriz( p, m1.lin, m1.col );
	int i, j;
	for( i = 0 ; i < m1.lin ; i++ )
		for( j = 0 ; j < m1.col ; j++ )
			p->dados[i][j] = m1.dados[i][j] + m2.dados[i][j];
	
	return 1; // Sucesso
}


int sao_iguais( Matriz m1, Matriz m2 ){
	if( m1.lin != m2.lin || m1.col != m2.col )
		return 0;
		
	int i, j;
	for( i = 0 ; i < m1.lin ; i++ )
		for( j = 0 ; j < m1.col ; j++ )
			if( m1.dados[i][j] != m2.dados[i][j] )
				return 0;
	
	return 1;
}