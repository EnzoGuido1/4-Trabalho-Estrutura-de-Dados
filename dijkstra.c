#include "dijkstra.h"

#include "arestaData.h"
#include "avl.h"
#include "declaracoes.h"
#include "digrafo.h"
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

typedef struct dijkstraCelula {
    void* data;
    double custo;
    void* prev;

} DijkstraCelula;

void* getDijkstraData(void* Sdata) {
    DijkstraCelula* ponteiro = Sdata;
    if (!ponteiro) {
        return NULL;
    }
    return ponteiro->data;
}

double getDijkstraCusto(void* Sdata) {
    DijkstraCelula* ponteiro = Sdata;
    if (!ponteiro) {
        return -1;
    }
    return ponteiro->custo;
}

void* getDijkstraPrev(void* Sdata) {
    DijkstraCelula* ponteiro = Sdata;
    if (!ponteiro) {
        return NULL;
    }
    return ponteiro->prev;
}

void* callocDataDijkstra(void* data, double custo, void* prev) {
    DijkstraCelula* ponteiro = calloc(1, sizeof(DijkstraCelula));
    ponteiro->data = data;
    ponteiro->custo = custo;
    ponteiro->prev = prev;

    return ponteiro;
}

void* Dijkstra(Graph grafo, char* v1, char* v2) {
    if (!grafo) {
        printf("O grafo passado na função Dijkstra consta como nulo\n");
        return NULL;
    }

    void* v1_lista = retorna_lista_arestas(grafo, v1);

    if (!v1_lista) {
        printf("Nao existem arestas no vertice de id: %s\n", v1);
        return NULL;
    }

    void* listaResultado = CriaLista();

    void* celula = callocDataDijkstra(getVerticeData(getVertice(grafo, percorre_Vertices(grafo, v1))), 0, NULL);
    InsereElementoLista(listaResultado, celula);

    void* fila = CriaFila();

    void* celulaLista = getheadLista(v1_lista);

    void* listaGeral = CriaLista();

    while (celulaLista) {
        insereFila(fila, getdataList(celulaLista), getArestaCmp(getdataList(celulaLista)) / getArestaVm(getdataList(celulaLista)));
        celulaLista = getnextLista(celulaLista);
    }

    void* celulaFila = getHeadFila(fila);

    celula = callocDataDijkstra(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila))), getArestaCmp(getDataCelulaFila(celulaFila)) / getArestaVm(getDataCelulaFila(celulaFila)), getVertice(grafo, percorre_Vertices(grafo, v1)));
    InsereElementoLista(listaResultado, celula);

    while (strcmp(getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))), v2)) {
        void* vertice_Atual_Lista = retorna_lista_arestas(grafo, getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))));
        if (vertice_Atual_Lista) {
            celulaLista = getheadLista(vertice_Atual_Lista);
            while (celulaLista) {
                if (!searchList(listaGeral, getdataList(celulaLista)))
                    insereFila(fila, getdataList(celulaLista), getArestaCmp(getdataList(celulaLista)) / getArestaVm(getdataList(celulaLista)) + getPrioridadeCelulaFila(getHeadFila(fila)));
                celulaLista = getnextLista(celulaLista);
            }
        }

        InsereElementoLista(listaGeral, getDataCelulaFila(celulaFila));

        removeFila(fila);
        celulaFila = getHeadFila(fila);

        if (!celulaFila)
            break;
        else {
            celula = callocDataDijkstra(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila))), getPrioridadeCelulaFila(celulaFila), getArestaPartida(getDataCelulaFila(celulaFila)));
            InsereElementoLista(listaResultado, celula);
        }
    }

    if (!celulaFila) {
        printf("Não é possível chegar do ponto %s ao ponto %s\n", v1, v2);
        return NULL;
    } else {
        void* celulaPercorreLista = getlastLista(listaResultado);
        char aux[100] = "";
        strcpy(aux, getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));

        while (celulaPercorreLista) {
            if (strcmp(getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))), aux) && strcmp(getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))), v2)) {
                RemoveCelulaLista(listaResultado, getdataList(celulaPercorreLista));
            } else {
                if (getDijkstraPrev(getdataList(celulaPercorreLista)))
                    strcpy(aux, getVerticeId(getVerticeData(getDijkstraPrev(getdataList(celulaPercorreLista)))));
                else
                    break;
            }

            celulaPercorreLista = getpreviousLista(listaResultado, celulaPercorreLista);
        }

        return listaResultado;
    }
}

int compareDijkstraCusto(void* A, void* B) {
    if (getDijkstraCusto(B) >= getDijkstraCusto(A)) {
        return 1;
    } else {
        return -1;
    }
}
