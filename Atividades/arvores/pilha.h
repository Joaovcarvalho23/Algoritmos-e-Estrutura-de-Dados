#include "arvore.h"

struct s_pilha {
noh **v; //ponteiro para ponteiro
int Num;
int topo;

};

typedef struct s_pilha *pilha;

//Função para criar a pilha com capacidade para x elementos
pilha iniciaPilha(int x);

//Função para empilhar x elementos na pilha p
void empilha(pilha p, noh** x); 

//Função para remover elementos da pilha e retorna o elemento desempilhado
noh* removeDaPilha(pilha p);

//Função para verificar se a pilha está cheia ou não
int pilhaVazia (pilha p);

//Função para verificar se a pilha está cheia ou não
int pilhaCheia (pilha p);