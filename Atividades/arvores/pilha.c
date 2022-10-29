#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

pilha iniciaPilha(int x) {
  pilha p = (pilha) malloc (sizeof (struct s_pilha));
  p->v = (noh **) malloc (x * sizeof (int));
  p->topo = 0;
  p->Num = x;
  return p;
}

void empilha(pilha p, noh** x) {
  if(pilhaCheia(p)) exit(1);
  p->v[p->topo] = x;
  p->topo++;
}

noh* removeDaPilha(pilha p) {
  if(pilhaVazia(p)) exit(1);
  p->topo--;
  return (p->v[p->topo]);
}

int pilhaVazia (pilha p) {
  return p->topo == 0;
}

int pilhaCheia (pilha p) {
  return p->topo == p->Num;
}