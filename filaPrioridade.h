#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

void *getDataCelulaFila(void *Sdata);
double getPrioridadeCelulaFila(void *Sdata);
void *CriaFila();
void *getnextFila(void *Sdata);
void *criaCelulaFila(void *dados, double priori);
void *getHeadFila(void *fila);
void removeFila(void *filaPrioridade);
void insereFila(void *filaPrioridade, void *dados, double priori);
int filaVazia(void *filaPrioridade);

/**/
#endif