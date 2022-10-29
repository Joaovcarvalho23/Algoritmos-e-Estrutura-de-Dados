#include "ht.h"

int main(void) {
  // Entrada dos dados
  FILE *entrada;
  entrada = fopen("genomaCOVID.txt", "r");
  HT minhaTabela = cria_ht(10);
  char chave[7];
  do {
    char s[61];
    int lerArq = fscanf(entrada, "%s", s);
    
    if (lerArq != 1)  break;
    
    int contaBloco = 0;
    int i = 0;
    for (i; i < 10; i++) {
      int k = 0;
      for (k; k < 6; k++) {
        chave[k] = s[contaBloco];
        contaBloco++;
      }
      put(minhaTabela, chave);
    }
  } while (true);

  // Gravar resultado no arquivo de saída
  FILE *saida;
  saida = fopen("conta_genoma.out", "w");
  imprimirNoArq(minhaTabela, saida);
  return 0;
}