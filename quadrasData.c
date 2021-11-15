#include "quadrasData.h"

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
#include "verticeData.h"

typedef struct quadra {
    char* cep;
    char* corC;
    char* corP;

    double x;
    double y;
    double w;
    double h;
    double sw;

    void* pessoasLista;
    void* locacoesLista;
} Quadra;

char* getDataCep(void* Sdata) {
    Quadra* quadra = Sdata;
    return quadra->cep;
}

char* getDataCorC(void* Sdata) {
    Quadra* quadra = Sdata;
    return quadra->corC;
}

char* getDataCorP(void* Sdata) {
    Quadra* quadra = Sdata;
    return quadra->corP;
}

double getDataX(void* Sdata) {
    Quadra* quadra = Sdata;
    return quadra->x;
}

double getDataY(void* Sdata) {
    Quadra* quadra = Sdata;
    return quadra->y;
}

double getDataW(void* Sdata) {
    Quadra* quadra = Sdata;
    return quadra->w;
}

double getDataH(void* Sdata) {
    Quadra* quadra = Sdata;
    return quadra->h;
}

double getDataSw(void* Sdata) {
    Quadra* quadra = Sdata;
    return quadra->sw;
}

//set
void setDataCep(void* Sdata, char* Scep) {
    Quadra* ponteiro = Sdata;
    ponteiro->cep = realloc(ponteiro->cep, strlen(Scep) + 1);
    strcpy(ponteiro->cep, Scep);
}

void setDataCorC(void* Sdata, char* ScorC) {
    Quadra* ponteiro = Sdata;
    ponteiro->corC = realloc(ponteiro->corC, strlen(ScorC) + 1);
    strcpy(ponteiro->corC, ScorC);
}

void setDataCorP(void* Sdata, char* ScorP) {
    Quadra* ponteiro = Sdata;
    ponteiro->corP = realloc(ponteiro->corP, strlen(ScorP) + 1);
    strcpy(ponteiro->corP, ScorP);
}

void setDataX(void* Sdata, double Sx) {
    Quadra* quadra = Sdata;
    quadra->x = Sx;
}

void setDataY(void* Sdata, double Sy) {
    Quadra* quadra = Sdata;
    quadra->y = Sy;
}

void setDataW(void* Sdata, double Sw) {
    Quadra* quadra = Sdata;
    quadra->w = Sw;
}

void setDataH(void* Sdata, double Sh) {
    Quadra* quadra = Sdata;
    quadra->h = Sh;
}

void setDataSw(void* Sdata, double Ssw) {
    Quadra* quadra = Sdata;
    quadra->sw = Ssw;
}

void* callocDataQuadra(char* cep, char* corc, char* corp, double x, double y, double w, double h, double sw) {
    Quadra* quadra = calloc(1, sizeof(Quadra));
    setDataCep(quadra, cep);
    setDataCorC(quadra, corc);
    setDataCorP(quadra, corp);
    setDataX(quadra, x);
    setDataY(quadra, y);
    setDataW(quadra, w);
    setDataH(quadra, h);
    setDataSw(quadra, sw);
    return quadra;
}
