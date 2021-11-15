#ifndef IMPRIMESVG_H
#define IMPRIMESVG_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

void ImprimeRect(char* corc, char* corp, double x, double y, double w, double h, double sw, void* path);
void ImprimeLine(char* cor, double x1, double x2, double y1, double y2, void* path);

/**/
#endif