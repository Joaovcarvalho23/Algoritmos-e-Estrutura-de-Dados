#include "posfixa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valorposf(char *exp) {
  int tamanho = strlen(exp);
  pilha p = iniciaPilha(tamanho);
  noh *noArvore;

  for(int i = 0; i<tamanho; i++){
    if(ehNumero(exp[i])){ 
      noArvore = aloca_noh(exp[i] - '0');
      empilha(p, noArvore);
    }
    else{
      switch (exp[i]) { 
        case '+':
          noArvore = aloca_noh(exp[i]);
          noArvore->dir = removeDaPilha(p);
          noArvore->esq = removeDaPilha(p);            
          noArvore->conteudo = noArvore->esq->conteudo + noArvore->dir->conteudo;
          empilha(p, noArvore); 
          break;

        case '*':
          noArvore = aloca_noh(exp[i]);
          noArvore->dir = removeDaPilha(p);
          noArvore->esq = removeDaPilha(p);            
          noArvore->conteudo = noArvore->esq->conteudo * noArvore->dir->conteudo;
          empilha(p, noArvore);
          break;

        case '/':
          noArvore = aloca_noh(exp[i]);
          noArvore->dir = removeDaPilha(p);
          noArvore->esq = removeDaPilha(p);            
          noArvore->conteudo = noArvore->esq->conteudo / noArvore->dir->conteudo;
          empilha(p, noArvore);
          break;
        
        case '-':
          noArvore = aloca_noh(exp[i]);
          noArvore->dir = removeDaPilha(p);
          noArvore->esq = removeDaPilha(p);            
          noArvore->conteudo = noArvore->esq->conteudo - noArvore->dir->conteudo;
          empilha(p, noArvore);
          break;
      }
    }      
  } return noArvore->conteudo;
}

arvore arvoreposf(char *exp) {
  int a = 0;
  noh *noArvore;
  noh *raizArvore = NULL;
  int tamanho = strlen(exp);
  pilha p = iniciaPilha(tamanho);

  do{
    if (ehNumero(exp[a])) {
      noArvore = aloca_noh(exp[a]);
      empilha(p, noArvore);
    } else {
      noArvore = aloca_noh(exp[a]);
      noArvore->dir = removeDaPilha(p);
      noArvore->esq = removeDaPilha(p);
      empilha(p, noArvore);
    }
    a++;
  } while (a < tamanho);
  raizArvore = removeDaPilha(p);
  return raizArvore;
}


char *posfinf(char *exp) {
  char *t = malloc(sizeof(char) * 100);
  arvore arv = arvoreposf(exp);
  converteInfixaToChar(arv, t);
  return t;
}

char *posfpref(char *exp) {
  char *t = malloc(sizeof(char) * 100);
  arvore arv = arvoreposf(exp);
  varrePrefixa(arv, t);
  return t;
}

char *reduz(noh *r) {
  int varAux;
  char *arvoreReduzida = malloc(sizeof(char*) * (qtnos(r)+1));
  noh *noArv = r;

  if (noArv->esq != NULL && noArv->dir != NULL && ehNumero(noArv->esq->conteudo) && ehNumero(noArv->dir->conteudo)){    
    
    switch (noArv->conteudo) { 
      case '+':
        varAux = converteCharToInt(noArv->esq->conteudo) + converteCharToInt(noArv->dir->conteudo);
        break;
      case '*':
        varAux = converteCharToInt(noArv->esq->conteudo) * converteCharToInt(noArv->dir->conteudo);
        break;
      case '/':
        varAux = converteCharToInt(noArv->esq->conteudo) / converteCharToInt(noArv->dir->conteudo);
        break;
      case '-':
        varAux = converteCharToInt(noArv->esq->conteudo) - converteCharToInt(noArv->dir->conteudo);
        break;
      }
    noArv->conteudo = varAux + '0'; 
    noArv->esq = NULL;
    free(noArv->esq); 
    noArv->dir = NULL;
    free(noArv->dir);

    } else{
        if (!ehNumero(noArv->esq->conteudo)) reduz(noArv->esq);
        if (!ehNumero(noArv->dir->conteudo)) reduz(noArv->dir);
    }
  varrePosfixa(noArv, arvoreReduzida);
  return arvoreReduzida;
}

void salva_arvore(char *arq, arvore v) {
  arvore a = v;
  FILE *f;
  f = fopen(arq, "w");
  salvarArquivo(a, 1, f);
  fclose(f);
}

int ehNumero(char ch) {
  return (ch >= '0' && ch <= '9');
}

int converteCharToInt(char c){
  int num = c - '0';
  return num;
}