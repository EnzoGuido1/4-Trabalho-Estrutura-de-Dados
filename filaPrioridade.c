#include "filaPrioridade.h"

#include "arestaData.h"
#include "avl.h"
#include "declaracoes.h"
#include "digrafo.h"
#include "dijkstra.h"
#include "funcoesQry.h"
#include "hashTable.h"
#include "imprimeSvg.h"
#include "kruskal.h"
#include "leitura.h"
#include "lista.h"
#include "parametrosData.h"
#include "quadrasData.h"
#include "verticeData.h"

typedef struct celulaFila {
    void *data;
    double prioridade;
    struct celulaFila *prox;

} CelulaFila;

typedef struct fila {
    int tamanho;
    CelulaFila *cabeca;

} Fila;

void setDataCelulaFila(void *Sdata, void *valor) {
    CelulaFila *celula = Sdata;
    celula->data = valor;
}

void *getDataCelulaFila(void *Sdata) {
    CelulaFila *celula = Sdata;
    return celula->data;
}

double getPrioridadeCelulaFila(void *Sdata) {
    CelulaFila *celula = Sdata;
    return celula->prioridade;
}

void *getnextFila(void *Sdata) {
    CelulaFila *celula = Sdata;
    return celula->prox;
}

void *CriaFila() {
    Fila *ponteiro = malloc(sizeof(Fila));
    ponteiro->tamanho = 0;
    ponteiro->cabeca = NULL;
    return ponteiro;
}

void *criaCelulaFila(void *dados, double priori) {
    CelulaFila *celula = calloc(1, sizeof(CelulaFila));
    celula->data = dados;
    celula->prioridade = priori;
    celula->prox = NULL;

    return celula;
}

void *getHeadFila(void *fila) {
    Fila *ponteiro = fila;
    return ponteiro->cabeca;
}

void removeFila(void *filaPrioridade) {
    Fila *fila = filaPrioridade;
    if (!fila->cabeca)
        return;

    CelulaFila *temporario = fila->cabeca;
    fila->cabeca = temporario->prox;
    temporario->prox = NULL;
    // free(temporario->data);
    // free(temporario);
}

void insereFila(void *filaPrioridade, void *dados, double priori) {
    Fila *fila = filaPrioridade;
    CelulaFila *celulaInicial = fila->cabeca;

    if (!celulaInicial) {
        celulaInicial = criaCelulaFila(dados, priori);
        fila->cabeca = celulaInicial;
        return;
    }

    CelulaFila *celulaNova = criaCelulaFila(dados, priori);
    if (celulaInicial->prioridade > priori) {
        celulaNova->prox = celulaInicial;
        fila->cabeca = celulaNova;
    } else {
        while (celulaInicial->prox != NULL && celulaInicial->prox->prioridade < priori) {
            celulaInicial = celulaInicial->prox;
        }

        celulaNova->prox = celulaInicial->prox;
        celulaInicial->prox = celulaNova;
    }
}

int filaVazia(void *filaPrioridade) {
    Fila *fila = filaPrioridade;

    if (!fila->cabeca)
        return 0;
    else
        return 1;
}
