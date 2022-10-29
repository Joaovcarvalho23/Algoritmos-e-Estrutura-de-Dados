#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

//FUNÇÕES GRUPO 1
conjunto criaconjunto(){
  conjunto C;
  return inicializa();
  return C;
}

void insere(conjunto X, int z){
  conjunto C = buscar(z, X);
  if(C == NULL) inserir(z, X);
}

void retira(conjunto X, int z){
  conjunto p;
  conjunto lixo;
  conjunto seguinte;
  p = X;
  lixo = X->prox;

  do{
    p = lixo;
    lixo = lixo->prox;
    seguinte = lixo->prox;
  }while(lixo != NULL && lixo-> conteudo != z);
  
  if(lixo != NULL){
    p->prox = lixo->prox;
    seguinte-> ant = lixo-> ant;
    free(lixo);
  }
}

bool pertence(conjunto X, int z){
  conjunto C = buscar(z, X);
  if(C != NULL) return true;
    else return false;
}

conjunto uniao(conjunto X, conjunto Y){
  conjunto C = criaconjunto();
  conjunto pt1 = X;
  conjunto pt2 = Y;
  pt1 = pt1-> prox;
  pt2 = pt2-> prox;

  do{
    inserir(X-> conteudo, C);
    pt1 = pt1-> prox;
  }while(pt1 != NULL);
  
   do{
     conjunto d = buscar(Y-> conteudo, C);
     if(d == NULL) inserir(Y-> conteudo, C);
     Y = Y-> prox;
   } while(pt2 != NULL);
  return C;
}

conjunto interseccao(conjunto X, conjunto Y){
  conjunto C = criaconjunto();
  conjunto pt1 = X-> prox;

  do{
      conjunto intersec = buscar(pt1-> conteudo, Y);
    if(intersec != NULL){
      insere(C, pt1-> conteudo);
      pt1 = pt1-> prox;
    }
  }while(pt1 != NULL);
  return C;
}

//Leitura do arquivo
conjunto leconjunto(FILE *f){
  conjunto leituraConjunto = criaconjunto();
  int tamanhoConj = 0;
  int j;
  f = fopen("dados.in", "r");

  while(fscanf(f, "%d", &j) > 0){
    if(tamanhoConj > 0) inserir(j, leituraConjunto);
    tamanhoConj++;
  }
  fclose(f);
  return leituraConjunto;
}

//Grava os valores no arquivo de saida
void salvaconjunto(FILE *f, conjunto X){
  f = fopen("dados.out", "w");
  conjunto k;
  int card = cardinalidade(X);
  fprintf(f, "%d", card);
  for(k = X-> prox; k != NULL; k = k-> prox) fprintf(f, " | %d ", k-> conteudo);
  fclose(f);
}


//FUNÇÕES GRUPO 2
bool subconjunto(conjunto X, conjunto Y){
  int tamanho = tamanhoDoConjunto(X);
  int compara = 0;
  conjunto C = X-> prox;
  do{
    conjunto buscando = buscar(C-> conteudo, Y);
    if(buscando != NULL) compara++;
    C = C-> prox;
  }while(C != NULL);
  if(compara == tamanho) return true;
  else return false;
}


int cardinalidade(conjunto X){
  conjunto C = X-> prox;
  int tamanho = 0;
  do{
    tamanho++;
    C = C-> prox;
  } while(C != NULL);
  return tamanho;
}


bool vazio(conjunto X){
  int verificaVazio = tamanhoDoConjunto(X);
  if(verificaVazio == 0) return true;
  else return false;
}


conjunto diferenca(conjunto X, conjunto Y){
  conjunto C = malloc(sizeof(conjunto));
  conjunto J = interseccao(X, Y);
  do{
    conjunto i = buscar(X-> conteudo, J);
    if(i != NULL) insere(C, X->conteudo);
    X = X-> prox;
  } while(X != NULL);
  return C;
}


conjunto diferencasim(conjunto X, conjunto Y){
  conjunto m = malloc(sizeof(conjunto));
  conjunto u = uniao(X, Y);
  conjunto i = interseccao(X, Y);
}
