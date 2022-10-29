#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct minhalista {
int conteudo;
struct minhalista *prox;
};
typedef struct minhalista *fila;

//Função que cria uma fila de valores
fila criafila (void);

//Função que insere valores na fila
void insere (fila f, int x);

//Função que remove um elemento de uma fila
int remover (fila f);

//Função que retorna um valor de fila vazia
int vazia (fila f);

//Função para imprimir o conteúdo da fila
void imprimeLista(fila f);