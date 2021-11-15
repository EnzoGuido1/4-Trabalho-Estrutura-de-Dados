#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

void* getDijkstraData(void* Sdata);
double getDijkstraCusto(void* Sdata);
void* getDijkstraPrev(void* Sdata);
void* callocDataDijkstra(void* data, double custo, void* prev);
void* Dijkstra(Graph grafo, char* v1, char* v2);
int compareDijkstraCusto(void* A, void* B);

/**/
#endif