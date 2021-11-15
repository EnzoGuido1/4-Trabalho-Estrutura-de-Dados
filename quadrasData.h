#ifndef QUADRASTADA_H
#define QUADRASTADA_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

char* getDataCep(void* Sdata);
char* getDataCorC(void* Sdata);
char* getDataCorP(void* Sdata);
double getDataX(void* Sdata);
double getDataY(void* Sdata);
double getDataW(void* Sdata);
double getDataH(void* Sdata);
double getDataSw(void* Sdata);
void* getDataPessoasLista(void* Sdata);
void* getDataLocacoesLista(void* Sdata);
void* callocDataQuadra(char* cep, char* corc, char* corp, double x, double y, double w, double h, double sw);

/**/
#endif