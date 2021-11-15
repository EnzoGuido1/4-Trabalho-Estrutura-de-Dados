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
#include "verticeData.h"

typedef struct aresta {
    char *nome;
    char *ldir;
    char *lesq;
    double cmp;
    double vm;
    void *destino;
    void *partida;

} Aresta;

//bloco de get, retorna o valor de um dado expecifico da struct quando chamada indicado no nome da função
char *getArestaNome(void *Sdata) {
    Aresta *ponteiro = Sdata;
    return ponteiro->nome;
}

char *getArestaLdir(void *Sdata) {
    Aresta *ponteiro = Sdata;
    return ponteiro->ldir;
}

char *getArestaLesq(void *Sdata) {
    Aresta *ponteiro = Sdata;
    return ponteiro->lesq;
}

double getArestaCmp(void *Sdata) {
    Aresta *ponteiro = Sdata;
    return ponteiro->cmp;
}

double getArestaVm(void *Sdata) {
    Aresta *ponteiro = Sdata;
    return ponteiro->vm;
}

void *getArestaDestino(void *Sdata) {
    Aresta *ponteiro = Sdata;
    return ponteiro->destino;
}

void *getArestaPartida(void *Sdata) {
    Aresta *ponteiro = Sdata;
    return ponteiro->partida;
}

//bloco de set, quando chamada a função. um dado expecifico da struct recebe o valor passado no argumento
void setArestaNome(void *Sdata, char *nome) {
    Aresta *ponteiro = Sdata;
    ponteiro->nome = realloc(ponteiro->nome, strlen(nome) + 1);
    strcpy(ponteiro->nome, nome);
}

void setArestaLdir(void *Sdata, char *ldir) {
    Aresta *ponteiro = Sdata;
    ponteiro->ldir = realloc(ponteiro->ldir, strlen(ldir) + 1);
    strcpy(ponteiro->ldir, ldir);
}

void setArestaLesq(void *Sdata, char *lesq) {
    Aresta *ponteiro = Sdata;
    ponteiro->lesq = realloc(ponteiro->lesq, strlen(lesq) + 1);
    strcpy(ponteiro->lesq, lesq);
}

void setArestaCmp(void *Sdata, double cmp) {
    Aresta *ponteiro = Sdata;
    ponteiro->cmp = cmp;
}

void setArestaVm(void *Sdata, double vm) {
    Aresta *ponteiro = Sdata;
    ponteiro->vm = vm;
}

void setArestaDestino(void *Sdata, void *destino) {
    Aresta *ponteiro = Sdata;
    ponteiro->destino = destino;
}

void setArestaPartida(void *Sdata, void *partida) {
    Aresta *ponteiro = Sdata;
    ponteiro->partida = partida;
}

void *callocDataAresta(char *nome, char *ldir, char *lesq, double cmp, double vm, void *destino, void *partida) {
    Aresta *ponteiro = calloc(1, sizeof(Aresta));
    setArestaNome(ponteiro, nome);
    setArestaLdir(ponteiro, ldir);
    setArestaLesq(ponteiro, lesq);
    setArestaCmp(ponteiro, cmp);
    setArestaVm(ponteiro, vm);
    setArestaDestino(ponteiro, destino);
    setArestaPartida(ponteiro, partida);

    return ponteiro;
}