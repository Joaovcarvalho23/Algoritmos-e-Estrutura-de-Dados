#include "ll.h"

celula criaListaLigada(char *ch){
  celula novaLista;
  novaLista=malloc(sizeof(struct reg));
  novaLista->chave=malloc(7 * sizeof(char));
  strcpy(novaLista->chave, ch);
  novaLista->ocorrencia=1;
  novaLista->prox=NULL;
  return novaLista;
}

celula busca(char *a, celula le) {  
// char str1[10];
// char str2[10];
// int comparaStrings;
// strcpy(str1, le->chave);
// strcpy(str2, a);
// comparaStrings = strcmp(str1, str2);
  
  while (le != NULL && strcmp(le->chave, a) != 0) le = le->prox;
  return le;
}

void insere(char *a, celula p) {
  celula novaLista;
  novaLista = malloc(sizeof(struct reg));
  novaLista->chave = a;
  novaLista->ocorrencia = 1;
  novaLista->prox = p -> prox;
  p->prox = novaLista;
}

void removel (celula p) {
  celula lixo;
  lixo = p -> prox;
  p -> prox = lixo -> prox;
  free(lixo);
}