#include "lista.h"

#ifndef AVL_H
#define AVL_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

void *getData(void *Sdata);
void *getHead(Tree tree);
double getMin(Posic celula);
double getMax(Posic celula);
Tree CriaArvore(int (*compare)(void *, void *), void (*freeNode)(void *));
void InsereElementoRec(Tree tree, Iten dados);
void InsereElemento(Tree list, Iten dados, Iten raizAtual, void *currentAux, int profundidadeGlobal);

void Balance(int condicional, Posic celulaDesbalanceada, Tree arvore);
void arrumaMinMaxNaRecursaoDelete(Iten aux);

void deleteNode(Tree tree, Iten aux);

int comparaRotacao(Iten aux);
int altura(Iten folha);
Iten AvlRight(Iten aux);
Iten AvlLeft(Iten aux);
int avlPrev(Iten celula);
void fixMinMax(Iten celula, Tree tree);
void rotacaoDireita(Iten celula, Tree tree);
void rotacaoEsquerda(Iten celula, Tree tree);

int getBalance(Iten aux);
int max(int a, int b);
void atualizaMinMaxSoCelula(Iten node);
Posic minValueNode(Iten node);

void freeAvl(Tree tree);
void freeAvlRec(Posic aux1_0);
void printRecursivoRec(Tree tree);
void printRecursivo(Posic galhoAtual1, int space);
int compareDouble(void *esquerda, void *direita);
void *retornaCelulaAvl(Tree tree, double x);
void *retornaListaAvl(Tree tree, double x);

void imprimeSvgAvl(Tree avl, FILE *inicializaSvgSaida, Posic celulaAtual);

/**/
#endif
