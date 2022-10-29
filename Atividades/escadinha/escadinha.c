#include <stdio.h>
#include "simpio.h"

int verificarEscada(FILE *);

int main (void){

  FILE *entrada;
  FILE *saida;

  entrada = fopen("escadinha.in", "r");
  saida = fopen("escadinha.out", "w");

  if(entrada == NULL){
    printf("\n O arquivo de entrada de dados não foi encontrado");
    exit(EXIT_FAILURE);
  
  } else{
    FILE *saida;
    saida = fopen("escadinha.out", "w");

    int num1 = 0;
    string s;
    fscanf(entrada, "%d", &num1);

    while(!feof(entrada)){
     int num2;
      fscanf(entrada, "%d", &num2);

      if(num2 > num1){
        fprintf(saida, "%s", "1\n");
      } else if (num2 < num1){
        fprintf(saida, "%s", "-1\n");
      } else if(num2 = num1){
        fprintf(saida, "%s", "0\n");
      }

      num1 = num2;
    }

    fclose(entrada);
    fclose(saida);

    return 0;
  } 
}