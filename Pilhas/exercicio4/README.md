Uma palavra é dita palíndrome se a sequência de letras que a forma é a mesma, seja ela
lida da esquerda para a direita ou vice-versa. Exemplos: arara, rairar, hanah. Escreva
uma função (definida no mesmo arquivo do programa principal) que indique se uma dada
string é ou não palíndrome. Para isso, é preciso inverter a string empilhando todos os seus
caracteres em uma pilha e, em seguida, desempilhando-os numa nova string. Por fim,
basta comparar a string invertida com a original. Protótipo da função:
int eh_palindrome( char palavra[] );
