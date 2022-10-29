#include "simpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------------Definição das
// funções-----------------------------------------------

// O algoritmo de Knuth–Morris–Pratt procura a ocorrência de uma "palavra" W
// dentro de um "texto" S empregando a simples técnica de que quando aparece uma
// diferença, a palavra tem em si a informação necessária para determinar onde
// começar a próxima comparação.
void KMP(char *x, int m, char *y, int n);

// O algoritmo de força bruta consiste em verificar, em todas as posições do
// texto entre 0 e n-m, se uma ocorrência do padrão começa ali ou não. Então,
// após cada tentativa, ele muda o padrão exatamente uma posição para a direita.
void BF(char *x, int m, char *y, int n);

// Função para ler o arquivo de entrada
char *lerArquivo(FILE *f);

//---------------------------------Implementação das
// funções-----------------------------------------------
void preKmp(char *x, int m, int kmpNext[]) {
  int i, j;

  i = 0;
  j = kmpNext[0] = -1;
  while (i < m) {
    while (j > -1 && x[i] != x[j])
      j = kmpNext[j];
    i++;
    j++;
    if (x[i] == x[j])
      kmpNext[i] = kmpNext[j];
    else
      kmpNext[i] = j;
  }
}

/*FUNÇÕES COM CONTADOR*/

// Função 'BF' modificada para fazer busca com wildcard (#) e adicionando
// um contador da quantidade de comparações de caracteres.
void BF(char *x, int m, char *y, int n) {
  int i, j;
  char varAuxiliar = '#';
  long long contadorBF = 0;

  /* Searching */
  for (j = 0; j <= n - m; ++j) {
    for (i = 0; i < m && (x[i] == y[i + j] || x[i] == varAuxiliar); ++i)
      ;
    contadorBF++;
    if (i >= m)
      printf("%i\n", j);
  }
  printf("\n\nContador BF: %i\n", contadorBF);
}

// Função KMP modificada para adicionar um contador da quantidade de comparações
// de caracteres.
void KMP(char *x, int m, char *y, int n) {
  int i, j, kmpNext[m];
  long long contadorKMP = 0;

  /* Preprocessing */
  preKmp(x, m, kmpNext);

  /* Searching */
  i = j = 0;
  while (j < n) {
    while (i > -1 && x[i] != y[j]) {
      i = kmpNext[i];
      contadorKMP++;
    }
    i++;
    j++;
    if (i >= m) {
      printf("%d ", j - i);
      i = kmpNext[i];
    }
  }
  printf("\n\nContador KMP: %ld\n", contadorKMP);
}

char *lerArquivo(FILE *f) {
  char *linhasArquivo;
  fseek(f, 0, SEEK_END);
  int size = ftell(f);
  fseek(f, 0, SEEK_SET);
  printf("%d\n", size);

  char *livro = (char *)malloc((size + 1) * sizeof(char));
  do {
    linhasArquivo = ReadLine(f);
    if (linhasArquivo)
      strcat(livro, linhasArquivo);
  } while (!feof(f));
  return livro;
}

//---------------------------------------Main--------------------------------------------------------------
int main(void) {
  char *a =
      "Desejo que você Não tenha medo da vida, tenha medo de não vivê-la. Não há céu sem tempestades, nem caminhos sem acidentes. Só é digno do pódio quem usa as derrotas para alcançá-lo. Só é digno da sabedoria quem usa as lágrimas para irrigá-la. Os frágeis usam a força; os fortes, a inteligência. Seja um sonhador, mas una seus sonhos com disciplina, Pois sonhos sem disciplina produzem pessoas frustradas. Seja um debatedor de ideias. Lute pelo que você ama.";
  char *b = "strength";

  FILE *entrada = fopen("montanha_magica.txt", "r");
  char *meuLivro = lerArquivo(entrada);
  a = meuLivro;
  KMP(b, strlen(b), a, strlen(a));
  BF(b, strlen(b), a, strlen(a));
}