#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ll.h"

typedef struct structHT{
celula *tabela; //hash table
int M; //tamanho
}noh;

typedef noh *HT;

// Cria uma nova tabeg com colisões
// tratadas por encadeamento; M é o tamanho da tabela
HT cria_ht(int M);

// Insere uma chave ch na tabela de hashing t.
// Se ch não pertence à tabela, o valor da nova
// célula criada é 1.
// Se já pertence, incrementa o valor.
void put(HT t, char *ch);

// Devolve o valor associado à chave ch na tabela t.
// Se ch não está na tabela, devolve -1.
int get(HT t, char *ch);

// Função de espalhamento usada na tabela
int hash(char *ch, int M);

// Imprime o conteúdo de uma tabela de espalhamento t
void printHT(HT t);

//Função para imprimir no arquivo de saída a quantidade de vezes
//que um bloco de tamanho 6 se repete no arquivo de entrada
void imprimirNoArq(HT t,FILE *saida);
