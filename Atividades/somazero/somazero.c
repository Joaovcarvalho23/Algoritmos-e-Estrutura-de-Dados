#include <stdio.h>
#include "simpio.h"

int main (void){

  int NOP = 0;
  
  FILE *entrada;
  FILE *saida;
  FILE *nop; 

  entrada = fopen("somazero.in", "r");
  saida = fopen("somazero.out", "w");
  //nop = fopen("somazero.out", "w");
  
  if(entrada == NULL){
    printf("\nO arquivo de entrada de dados não foi encontrado");
    exit(EXIT_FAILURE);
  } else {
    FILE *saida;
    saida = fopen("somazero.out", "w");

    char a;
    char letra = '\n';
    int linhasArquivo = 1;

    while(fread(&a, sizeof(char), 1, entrada))
      if(a == letra)
        linhasArquivo++;

    int num1;
    int num2;
    int i;
    int j;
    int casoNao = 1;
    
    for(int i = 1; i <= linhasArquivo; i++){

      FILE *input1;
      input1 = fopen("somazero.in", "r");

      int contador1 = 0;

      do{
        fscanf(input1, "%d", &num1);
        contador1++;
      } while (contador1 != i);
      fclose(input1);
    
      
      for(j = 1; j <= linhasArquivo; j++){
        FILE *input2;
        input2 = fopen("somazero.in", "r");

        int contador2 = 0;
        
        do{
          fscanf(input2, "%d", &num2);
          contador2++;
        }while (contador2 != j);

        if(num1 + num2 == 0 && j != i){
          fprintf(saida, "%s", "SIM");
          casoNao = 0;
          break;
        }
        fclose(input2);
      }
      if(num1 + num2 == 0 && i != j)
        break;
    }
    
    if(casoNao == 1)
      fprintf(saida, "%s", "NÃO");
    
    fclose(entrada);
    fclose(saida);
    return 0;
  }
}