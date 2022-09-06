/*7) Escreva uma função que recebe como parâmetros uma string s e um inteiro n, e retorna
nova string nova contendo s repetida n vezes. Por exemplo, s = “Abc” e n = 4 tem como
resultado a string “AbcAbcAbcAbc”. Faça o programa principal chamando a função.
Protótipo da função:
char *repetidor( char *s, int n );*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *repetidor( char *s, int n );;
void imprime_vetor (char vet[]);
int main(int argc, char *argv[ ]) {
    char s1[30];
    char *s2;
    
    printf("Digite uma string: ");
    scanf("%s", s1);
    
    int n;
    printf("quantas vezes desejas repetir: ");
    scanf("%i", &n);

    printf("String original: \n");
    imprime_vetor(s1);

    s2 = repetidor( s1, n);

    printf("String nova: \n");
    imprime_vetor(s2);

   
    free(s2);

    return 0;
    }
void imprime_vetor (char vet[]){
    int i;

    for (i = 0; vet[i] != '\0'; i++){
        printf("%c ", vet[i]);
    }
    printf("\n");

}
char *repetidor( char *s, int n ){
    char *novaString = NULL;
    int i, j, k = 1;

    for ( i = 0; i < n; i++){
        
        for (j = 0; s[j] != '\0'; j++){
            novaString = realloc(novaString, sizeof(char)*(k+1));
            novaString[k-1] = s[j];
            k++;
        }
        
    }
    return novaString;
    
    
}
