#include <stdio.h>
#include <stdlib.h>

void intercala (int p, int q, int r, int v[]){
    int *w;
    w = malloc((r-p) * sizeof(int));
    int i = p;       
    int j = q;     
    int k = 0;
    
    while (i < q && j < r){
        if (v[i] <= v[j]) w[k++] = v[i++];
         else w[k++] = v[j++];
    }
    while (i < q)
      w[k++] = v[i++];
  
    while (j < r)
      w[k++] = v[j++];

    for(i = p; i < r; i++)
      v[i] = w[i-p];
    free (w);
  }

void mergeSort(int p, int r, int v[]){
  if (p < r-1){
    int q = (p+r)/2;
    mergeSort(p, q, v);
    mergeSort(q, r, v);
    intercala(p, q, r, v);
  }
}

int buscaBinaria(int p, int r, int numero, int v[]){
    int q = (p + r) / 2;
    if (p > r) 
      return -1;

    if (v[q] == numero)
        return q;

    if (v[q] < numero) return buscaBinaria(q+1, r, numero, v);  
    else return buscaBinaria(p, q-1, numero, v);
}

int somazero(int p, int r, int v[]){
    int t = p;
    int numeroSelecionado = v[t] + (2*(-(v[t])));
    if (t > r) 
      return 1;
  
    if(buscaBinaria(0, r, numeroSelecionado, v) != -1 && buscaBinaria(0, r, numeroSelecionado, v) != t) 
      return 0;
    else{
       somazero(t, r, v);
      t+=1; 
    }
}

int main (void) {
  FILE *entrada;
  FILE *saida;

  entrada = fopen("somazero.in", "r");
  saida = fopen("somazero.out", "w");

  if(entrada == NULL){
    printf("\nO arquivo não foi encontrado");
    exit(EXIT_FAILURE);
  }

  char letra = '\n';
  char a;
  int linhasArquivo = 1;

  do{
    if(a == letra) linhasArquivo++;
  } while (fread(&a, sizeof(char), 1, entrada));

  fseek(entrada, 0, SEEK_SET);
  int v[linhasArquivo];
  for(int i = 0; i < linhasArquivo; i++) fscanf(entrada, "%d", &v[i]);

  mergeSort(0, linhasArquivo-1, v);

  if(somazero(0, linhasArquivo - 1, v) == 0){
    fprintf(saida, "%s", "Sim");
  } else{
    fprintf(saida, "%s", "Não");
  }
  fclose(entrada);
  fclose(saida);
  return  EXIT_SUCCESS;
}