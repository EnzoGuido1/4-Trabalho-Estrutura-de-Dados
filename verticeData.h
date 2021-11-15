#ifndef VERTICEDATA_H
#define VERTICEDATA_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

char *getVerticeId(void *Sdata);
double getVerticeX(void *Sdata);
double getVerticeY(void *Sdata);

void *callocDataVertice(char *id, double x, double y);

/**/
#endif