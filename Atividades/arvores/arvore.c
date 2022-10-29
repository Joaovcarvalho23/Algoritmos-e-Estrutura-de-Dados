#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


noh *aloca_noh(int valor) {
  noh *a = (noh *)malloc(sizeof(struct reg));
  a->esq = NULL;
  a->dir = NULL;
  a->conteudo = valor;
  return a;
}

void altura_nos(arvore arv) {
  if (arv->dir == NULL && arv->esq == NULL) arv->aux = 0;

  else if (arv->dir != NULL && arv->esq == NULL) {
    altura_nos(arv->dir);
    arv->aux = arv->dir->aux + 1;
  } else if (arv->dir == NULL && arv->esq != NULL) {
    altura_nos(arv->esq);
    arv->aux = arv->esq->aux + 1;
  } else {
    altura_nos(arv->dir);
    altura_nos(arv->esq);
    
    if (arv->esq->aux > arv->dir->aux) arv->aux = arv->esq->aux + 1;
    else arv->aux = arv->dir->aux + 1;
  }
}

int qtnos(arvore arv) {
  if (arv == NULL) return 0;
  int somaNos = qtnos(arv->esq) + qtnos(arv->dir) + 1;
  return somaNos;
}

int folhasDaArvore(arvore arv){
   if(arv == NULL) return 0;
   if(arv->esq == NULL && arv->dir == NULL) return 1;
   int somaFolha = folhasDaArvore(arv->esq) + folhasDaArvore(arv->dir);
   return somaFolha;
}

int totalFilhos(arvore arv){
  int totalFilhos = qtnos(arv) + folhasDaArvore(arv);
  return totalFilhos;
}

void varreInfixa(arvore arv) {
  if (arv != NULL) {
    if (arv->esq == NULL && arv->dir == NULL) printf("%d", arv->conteudo);
    else {
      printf("(");
      varreInfixa(arv->esq);
      printf("%c", arv->conteudo);
      varreInfixa(arv->dir);
      printf(")");
    }
  }
}

void varrePrefixa(arvore arv, char valorConteudo[]){
  if (arv != NULL) {   
    if (arv->esq == NULL && arv->dir == NULL) concatenaCaracter(valorConteudo, arv->conteudo);
    else {
      varrePrefixa(arv->esq, valorConteudo);     
      varrePrefixa(arv->dir, valorConteudo);
      concatenaCaracter(valorConteudo, arv->conteudo);
    }
  }
}

void varrePosfixa(arvore arv, char valorConteudo[]){
  if (arv != NULL) {   
    if (arv->esq == NULL && arv->dir == NULL) concatenaCaracter(valorConteudo, arv->conteudo);
    else {
      varrePosfixa(arv->esq, valorConteudo);     
      varrePosfixa(arv->dir, valorConteudo);
      concatenaCaracter(valorConteudo, arv->conteudo);   
    }
  }
}

void converteInfixaToChar(arvore arv, char valorConteudo[]){
  if (arv != NULL) {
    if (arv->esq == NULL && arv->dir == NULL) concatenaCaracter(valorConteudo, arv->conteudo);
    else {
      concatenaCaracter(valorConteudo, '(');
      converteInfixaToChar(arv->esq, valorConteudo);
      concatenaCaracter(valorConteudo, arv->conteudo);
      converteInfixaToChar(arv->dir, valorConteudo);
      concatenaCaracter(valorConteudo, ')');
    }
  }
}

void concatenaCaracter(char lista[], char a){
  int tamanhoLista = strlen(lista);
  lista[tamanhoLista] = a;
  lista[tamanhoLista + 1] = '\0';
}

void salvarArquivo(arvore arv, int t, FILE *arq){
  if (arv != NULL) {
    for (int k = 0; k < t; k++) fprintf(arq, "_");
    
    fprintf(arq, "%c\n", arv->conteudo);
    salvarArquivo(arv->esq, t+3, arq);
    salvarArquivo(arv->dir, t+3, arq);
  }
}

/*
testar na main
void imprime_arvore(arvore arv, int i) {
  if (arv != NULL) {
    for (int k = 0; k < i; k++) printf("_");
    printf("%c\n", arv->conteudo);
    imprime_arvore(arv->esq, i+3);
    imprime_arvore(arv->dir, i+3);
  }
}
*/