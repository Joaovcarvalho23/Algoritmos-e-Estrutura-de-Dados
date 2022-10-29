#include <stdio.h> 

//converter de int para char!
//devemos imprimir os operadores da árvore
typedef struct reg {
  int conteudo;
  int aux;
  struct reg *esq;
  struct reg *dir;
} noh; // nó da árvore

typedef noh *arvore;

//Função que aloca o nó na árvore
noh *aloca_noh (int);

//Função para determinar a altura dos nós que uma árvore possui
void altura_nos (arvore);

//Função que determina a quantidade de nós de uma árvore
int qtnos (arvore);

//Função que serve para determinar as folhas de uma árvore, ou seja, quantos
//nós dessa árvore não possui filho à direita e à esquerda
int folhasDaArvore(arvore arv);

//Função para determinar o total de filhos de uma árvore, ou seja, o somatório de todos os nós com todas as folhas
int totalFilhos(arvore arv);

//Função que varre/percorre a árvore na esquência esquerda-raiz-direita, ou e-r-d, também //conhecida como inorder traversal, ou varredura infixa, ou varredura central.
void varreInfixa (arvore arv);

//Função que varre/percorre a árvore na esquência raiz-esquerda-direita, ou r-e-d, também //conhecida como varredura prefixa
void varrePrefixa(arvore arv, char valorConteudo[]);

//Função que varre/percorre a árvore na esquência esquerda-direita-raiz, ou edr, também conhecida como varredura posfixa
void varrePosfixa(arvore r, char valorConteudo[]);

//Função que transforma a varredura da árvore na sequência esquerda-raiz-direita e representa na forma de caracter
void converteInfixaToChar(arvore a, char valorConteudo[]);

//Função para poder concatenar o conjunto de caracteres para poder desenhas a árvore na saída
void concatenaCaracter(char lista[], char a); //juntarChar

//Função que serve unicamente para salvar a árvore em um arquivo de saída
void salvarArquivo(arvore arv, int x, FILE *arq);

//Função para imprimir a árvore como um todo
void imprime_arvore (arvore, int);