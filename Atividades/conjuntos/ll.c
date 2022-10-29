#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

conjunto 
inicializa(){
  conjunto inic = malloc(sizeof(struct minhalista));
  inic->prox = NULL;
  inic->ant = NULL;
  inic->conteudo = 0;
  return inic;
}


conjunto
buscar (int X, conjunto C){
  conjunto t1 = C;
  while(t1 != NULL && t1->conteudo != X) t1 = t1->prox;
  return t1;
}


void 
inserir (int X, conjunto C){
  conjunto novoConjunto = malloc(sizeof(conjunto));
  conjunto verificaNo = buscar(X, C);

  if(verificaNo == NULL){
    novoConjunto->prox = C->prox;
    novoConjunto->conteudo = X;
    C->prox = novoConjunto;
  }
}


void 
remover (conjunto C){
  conjunto lixo;
  conjunto seguinte;
  lixo = C->prox;
  C-> prox = lixo-> prox;
  seguinte = lixo-> prox;
  seguinte-> ant = lixo-> ant;
  free(lixo);
}


int
tamanhoDoConjunto(conjunto m){
  int tamanho = 0;
  conjunto C = m-> prox;

  while(C != NULL){
    tamanho++;
    C = C-> prox;
  }
  return tamanho;
}