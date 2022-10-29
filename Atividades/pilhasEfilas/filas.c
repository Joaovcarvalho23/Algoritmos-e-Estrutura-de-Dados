#include "filas.h"

fila criafila (void){
  fila f;
  f = malloc(sizeof(fila));
  f-> prox = f;
}

void insere (fila f, int x) { 
   fila nova;
   nova = malloc (sizeof (fila));
   nova->prox = f->prox;
   f->prox = nova;
   f->conteudo = x;
}

int remover (fila f) {
   fila elemento;
   elemento = f->prox;
   int x = elemento->conteudo;
   f->prox = elemento->prox;
   free (elemento);
   return x;  
}

int vazia(fila f)
{
 if(f->prox == NULL) return 1;
 else return 0;
}

void imprimeLista(fila f){
  fila p;
  for(p = f-> prox; p != NULL; p = p-> prox) printf("%d\n", p->conteudo);
}