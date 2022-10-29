#include "ll.h"
#include <stdbool.h>
#include <stdio.h>

// Aloca e devolve um conjunto vazio.
conjunto criaconjunto ();

// Cria um conjunto contendo os elementos lidos de um arquivo de inteiros representado por f.
// Esse arquivo tem na primeira linha a quantidade de inteiros a ser lida, e nas linhas seguintes,
// os inteiros, um por linha.
// Devolve um conjunto representando esses inteiros.
conjunto leconjunto (FILE *f);

// Grava o conteudo do conjunto X no arquivo f.
// O arquivo tem o formato descrito na documentação da função leconjunto.
void salvaconjunto (FILE *f, conjunto X);

// Insere o inteiro z no conjunto X. Se X já contém esse valor, nenhuma modificação é feita.
void insere (conjunto X, int z);

// Remove o inteiro z do conjunto X. Se X não contém esse valor, nenhuma modificação é feita.
void retira (conjunto X, int z);


// Testa se o inteiro z pertence ao conjunto X.
bool pertence (conjunto X, int z);

// Devolve um conjunto representando a união dos conjuntos X e Y.
conjunto uniao (conjunto X, conjunto Y);

// Devolve um conjunto representando a intersecção dos conjuntos X e Y.
conjunto interseccao (conjunto X, conjunto Y);


//GRUPO 2

// Testa se X é um subconjunto de Y.
bool subconjunto (conjunto X, conjunto Y);

// Devolve um conjunto representando a diferença de conjuntos X - Y.
conjunto diferenca (conjunto X, conjunto Y);

// Devolve um conjunto representando a diferença simétrica entre os conjuntos X - Y.
conjunto diferencasim (conjunto X, conjunto Y);

// Devolve a quantidade de elementos do conjunto X.
int cardinalidade (conjunto X);

// Testa se o conjunto X é vazio.
bool vazio (conjunto X);
