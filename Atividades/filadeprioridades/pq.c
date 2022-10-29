#include <stdio.h>
#include <stdlib.h>
#include "pq.h"
#include <malloc.h>
#include <math.h>

pq buildpq(int m){
  pq p;
  p = (pq)malloc(sizeof(struct pq_struct));
  p -> m = m + 1;
  p -> n = 0;
  p -> v = (int *) malloc((m+1) * sizeof(int));
  return p;
}

int extractmin(pq p){
  int y = p -> v[1];
  
  p -> v[1] = p -> v[p -> n];

  p -> v[ p -> n] = y;
  p -> n = p -> n - 1;
  correctingDown(p -> v, p -> n,1);
  return y;
}

void insert(pq p, int x){
  p -> n += 1;
  p -> v [p -> n] = x;
  correctingUp(p -> v, p -> n);

}

void incq (pq p, int k, int x){
  p -> v[k] = x;
  correctingDown(p -> v, p -> n, k);
}

void decq (pq p, int k, int x){
  p -> v[k] = x;
  correctingUp(p -> v, k);
}

void dumppq(pq p){
  for (int i = 1; i <= p -> n; i++){
    printf("%d\n", p->v[i]);
  }
  printf("\n");
}

pq loadpq (){
  
  FILE *Entrada;
  
  Entrada = fopen("dados.in", "r"); 
  
  int n = 0;
  fscanf(Entrada, "%i", &n);
  
  fclose(Entrada);
  
  Entrada = fopen("dados.in", "r");
  
  int num[n];
  int r = 0;
  
  if (Entrada != NULL){ 
    while (fscanf(Entrada, "%i", &num[r]) != EOF){
      r++;
    } 
    fclose(Entrada); 
  }
  
    pq pqAdd = buildpq(n);
    for(int i = 1; i <= n; i++){
      insert(pqAdd, num[i]);
    }

    return pqAdd;
}

void savepq (pq p){

  FILE *Saida;
  
  Saida = fopen("heap.out", "w"); 

  p -> v[0] = p -> n;
  fprintf(Saida,"%d\n", p -> v[0]);
  
  for(int i = 1; i <= p -> n; i++){
      fprintf(Saida,"%d\n", p -> v[i]);
  }
  
  fclose(Saida);
}

//Funções adicionais para melhor auxiliar o código
void correctingUp(int *v,int m){
  
  int i = m;
  int y;
  int b;
    while (i >= 2 && v[i/2] > v[i]) {
        y = v[i/2];
        b = v[i];
        v[i] = y;
        v[i/2] = b;

      i = i/2;
    }
  i = floor(i/2);
}

void correctingDown(int *v, int n, int i){
    int j = i;
    int b;
    int y;
    int f;  
    while (2*j <= n){
      f =  2*j;
      if( f < n && v[f] > v[f + 1]){
        f = f + 1;
      }
      if(v[j] <= v[f]){
        j = n;
      }
      else{
        y = v[j];
        b = v[f];
        v[f] = y;
        v[j] = b;
      }
      j = f;
    }
  }