#ifndef DIGRAFO_H
#define DIGRAFO_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

void* getVerticeData(void* Sdata);
void* getVertice(void* Sdata, int index);
void* getVerticeLista(void* Sdata);
int getGrafoTamanho(void* Sdata);
void* criaGrafo(int vertices);
void insere_Aresta(Graph grafo, char* v1, char* v2, void* aresta_data);
void define_Info(Graph grafo, char* v1, char* v2, void* aresta_data);
void* get_Info(Graph grafo, char* v1, char* v2);
void remove_Aresta(Graph grafo, char* v1, char* v2);
int v1_adjacente_v2(Graph grafo, char* v1, char* v2);
void* v1_adjacentes(Graph grafo, char* v1);
int percorre_Vertices(Graph grafo, char* vertice);
void* retorna_lista_arestas(Graph grafo, char* v1);
void* retorna_aresta_v1_para_v2(Graph grafo, List lista_de_arestas_v1, char* v2);
void* Dijkstra(Graph grafo, char* v1, char* v2);

/**/
#endif