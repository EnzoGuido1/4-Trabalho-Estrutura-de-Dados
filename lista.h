#ifndef LISTA_H
#define LISTA_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

void setValor(void *Sdata, void *valor);
void *callocCelulaLista();
Posic getheadLista(List list);
int gettamanhoLista(List list);
Posic getlastLista(List list);
Posic getpreviousLista(List list, Posic aux);
Posic getnextLista(Posic aux);
Posic getantLista(List list, Posic aux);
void *getdataList(Posic aux);
double getValorLista(void *Sdata);
void *getDataListaIndex(List list, int index);

List CriaLista();
void RemoveCelulaLista(List list, void *x);
void RemoveCelulaListaPorData(List list, char *cpf, char *getData(void *auxDados));
Posic NaPosicaoLista(List list, int index);
void FreeLista(List list, int tipo);
void FreeListaSemDados(List list);
void InsereElementoLista(List list, Iten iten);
void printList(List list, char *getData(void *auxDados));
void *searchList(List list, void *dados);
void quickSort(Posic head, List list, int getData(void *auxDados, void *aux2Dados));
void removeElementosIguaisSortedList(List list);
void removeTodosElementosLista(List list);

/**/
#endif