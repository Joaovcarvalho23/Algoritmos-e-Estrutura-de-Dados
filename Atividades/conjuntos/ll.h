struct minhalista {
int conteudo;
struct minhalista *ant, *prox; 
};
typedef struct minhalista *conjunto;
/*
Aqui, "minhalista" é seu tipo de dados (sua struct) que representa listas duplamente ligadas. Você pode dar o nome que quiser para seu tipo de dados de lista. O cliente, o usuário de suas bibliotecas, não vai se interessar em olhar para isso.
*/

//Função para inicializar o conjunto
conjunto 
inicializa();


// Esta função recebe um inteiro x e uma
// lista encadeada le de inteiros e devolve
// o endereço de uma celula que contém x.
// Se tal celula não existe, devolve NULL.
conjunto
buscar (int X, conjunto C);


// Esta função insere uma nova celula
// em uma lista encadeada. A nova celula
// tem conteudo x e é inserida entre a
// celula p e a celula seguinte.
// (Supõe-se que p != NULL.)
void 
inserir (int X, conjunto C);


// Esta função recebe o endereço p de uma 
// celula de uma lista encadeada e remove 
// da lista a celula p->prox. A função supõe
// que p != NULL e p->prox != NULL.
void 
remover (conjunto C);


// Esta função recebe uma lista encadeada le
// com cabeça e remove da lista a primeira
// celula que contiver y, se tal celula existir.
void 
buscar_e_remover (int y, conjunto C);


//Essa função determina qual o tamanho
//do conjunto de listas ligadas.
int
tamanhoDoConjunto(conjunto C);