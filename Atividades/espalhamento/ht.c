#include "ht.h"

HT cria_ht(int M) {
  HT newHashTable = malloc(sizeof(struct structHT));
  newHashTable->tabela = malloc(M * sizeof(struct reg));
  newHashTable->M = M;
  for (int j = 0; j < M; j++) newHashTable->tabela[j] = NULL;
  return newHashTable;
}

void put(HT t, char *ch) {
  int minhaHash = hash(ch, t->M);
  celula p = busca(ch, t->tabela[minhaHash]);
  if (p != NULL) p->ocorrencia += 1;
  else if(p == NULL){
    p = criaListaLigada(ch);
    p->prox = t->tabela[minhaHash];
    t->tabela[minhaHash] = p;
  }
}

int get(HT t, char *ch) {
  int minhaHash = hash(ch, t->M);
  celula p = busca(ch, t->tabela[minhaHash]);
  if (p != NULL) return minhaHash;
  else return -1;
}

int hash(char *ch, int M) {
  int h = 0;
  for (int indice = 0; ch[indice] != '\0'; indice++) h = (h * 256 + ch[indice]) % M;
  return h;
}

void printHT(HT t) {
  for (int k = 0; k < t->M; k++) {
    celula lista = t->tabela[k];
    do {
      printf("%s  %d  %d", lista->chave, lista->ocorrencia, get(t, lista->chave));
      printf("\n");
      lista = lista->prox;
    } while (lista != NULL);
  }
}

void imprimirNoArq(HT t, FILE *saida) {
  for (int p = 0; p < t->M; p++) {
    celula lista = t->tabela[p];
     do {
      fprintf(saida, "Bloco %s se repete %d vezes\n", lista->chave, lista->ocorrencia);
      lista = lista->prox;
    } while (lista != NULL);
  }
}