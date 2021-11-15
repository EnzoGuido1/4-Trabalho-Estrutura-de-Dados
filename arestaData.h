#ifndef ARESTADATA_H
#define ARESTADATA_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

char *getArestaNome(void *Sdata);
char *getArestaLdir(void *Sdata);
char *getArestaLesq(void *Sdata);
double getArestaCmp(void *Sdata);
double getArestaVm(void *Sdata);
void *getArestaDestino(void *Sdata);
void *getArestaPartida(void *Sdata);

void *callocDataAresta(char *nome, char *ldir, char *lesq, double cmp, double vm, void *destino, void *partida);

/**/
#endif