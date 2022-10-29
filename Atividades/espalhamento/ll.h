#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct reg{
char *chave;
int ocorrencia;
struct reg *prox;
};
typedef struct reg *celula;

//Função que recebe um chave de caractere 'ch ' para alocar um espaço na memória
celula criaListaLigada(char *ch);

//Função que recebe como parâmetro um inteiro 'a' em uma lista ligada 'le' e busca
//esse elemento, retornando seu endereço de memória
celula busca (char *a, celula le);

// Função que serve para inserir uma célula nova na lista ligada, e essa nova
// célula possui um elemento 'a', que é inserido entre a célula atual e a seguinte
void insere (char *a, celula p);

// Esta função recebe o endereço p de uma 
// celula de uma lista encadeada e remove 
// da lista a celula p->prox. A função supõe
// que p != NULL e p->prox != NULL.
void removel (celula p);