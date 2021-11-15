#include "verticeData.h"

#include "arestaData.h"
#include "avl.h"
#include "declaracoes.h"
#include "digrafo.h"
#include "dijkstra.h"
#include "filaPrioridade.h"
#include "funcoesQry.h"
#include "hashTable.h"
#include "imprimeSvg.h"
#include "kruskal.h"
#include "leitura.h"
#include "lista.h"
#include "parametrosData.h"
#include "quadrasData.h"

typedef struct vertice {
    char *id;
    double x;
    double y;

} Vertice;

//bloco de get, retorna o valor de um dado expecifico da struct quando chamada indicado no nome da função
char *getVerticeId(void *Sdata) {
    Vertice *ponteiro = Sdata;
    return ponteiro->id;
}

double getVerticeX(void *Sdata) {
    Vertice *ponteiro = Sdata;
    return ponteiro->x;
}

double getVerticeY(void *Sdata) {
    Vertice *ponteiro = Sdata;
    return ponteiro->y;
}

//bloco de set, quando chamada a função. um dado expecifico da struct recebe o valor passado no argumento
void setVerticeId(void *Sdata, char *id) {
    Vertice *ponteiro = Sdata;
    ponteiro->id = realloc(ponteiro->id, strlen(id) + 1);
    strcpy(ponteiro->id, id);
}

void setVerticeX(void *Sdata, double x) {
    Vertice *ponteiro = Sdata;
    ponteiro->x = x;
}

void setVerticeY(void *Sdata, double y) {
    Vertice *ponteiro = Sdata;
    ponteiro->y = y;
}

void *callocDataVertice(char *id, double x, double y) {
    Vertice *ponteiro = calloc(1, sizeof(Vertice));
    setVerticeId(ponteiro, id);
    setVerticeX(ponteiro, x);
    setVerticeY(ponteiro, y);

    return ponteiro;
}
