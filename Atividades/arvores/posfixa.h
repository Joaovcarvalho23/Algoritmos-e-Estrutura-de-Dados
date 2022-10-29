#include "pilha.h"

// Constrói a árvore da expressão em notação posfixa exp. Devolve a raiz dessa árvore.
arvore arvoreposf (char *exp);


// Devolve o valor de uma expressão na notação posfixa exp.
int valorposf (char *exp);


// Converte a expressão exp na notação posfixa para uma nova string representando a mesma expressão na notação
// infixa. A expressão devolvida tem necessariamente um ( e ) envolvendo cada grupo de operação/operandos que
// aparece na expressão, mesmo que a precedência de operadores dispense parêntesis. Exemplo de expressão
// devolvida: ((5*3)+2)
char *posfinf (char *exp);


// Converte a expressão exp na notação posfixa para uma nova string representando a mesma expressão na notação prefixa.
char *posfpref (char *exp);


// Recebe a raiz de uma árvore representando uma expressão aritmética contendo pelo menos um operador.
// Transforma essa árvore da seguinte forma: todo nó que é pai de duas folhas é substituído por uma folha, contendo
// o resultado da operação representada por esse nó.
// Devolve a expressão na notação posfixa da árvore reduzida.
char *reduz (noh *r);


// Salva no arquivo arq a impressão da árvore v, contendo um nó por linha, e
// evidenciando o nível de cada nó com o símbolo _ (underscore; conte dois símbolos por nível).
void salva_arvore (char * arq, arvore v);


//retorna se o char ch é um número
int ehNumero(char a);

// Converte char para inteiro
int converteCharToInt(char a);