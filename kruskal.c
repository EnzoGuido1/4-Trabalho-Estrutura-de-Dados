#include "kruskal.h"

#include "arestaData.h"
#include "avl.h"
#include "declaracoes.h"
#include "digrafo.h"
#include "dijkstra.h"
#include "filaPrioridade.h"
#include "funcoesQry.h"
#include "hashTable.h"
#include "imprimeSvg.h"
#include "leitura.h"
#include "lista.h"
#include "parametrosData.h"
#include "quadrasData.h"
#include "verticeData.h"

struct subset {
    void* id;
    int parent;
    int rank;
};

int retornaIndexPorId(void* vertice_posicao, struct subset* subsets, int v);
int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
int compareKruskalId(void* A, void* B);
int compareKruskalCmp(void* A, void* B);
int retornaIndexPorId(void* vertice_posicao, struct subset* subsets, int v);

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void* KruskalMST(List arestas_globais) {
    void* celula_arestas_globais = getheadLista(arestas_globais);
    void* lista_vertices_totais = CriaLista();
    while (celula_arestas_globais) {
        InsereElementoLista(lista_vertices_totais, getVerticeData(getArestaPartida(getdataList(celula_arestas_globais))));
        InsereElementoLista(lista_vertices_totais, getVerticeData(getArestaDestino(getdataList(celula_arestas_globais))));
        celula_arestas_globais = getnextLista(celula_arestas_globais);
    }

    quickSort(getheadLista(lista_vertices_totais), lista_vertices_totais, compareKruskalId);

    removeElementosIguaisSortedList(lista_vertices_totais);

    int V = gettamanhoLista(lista_vertices_totais);
    void* result = CriaLista();

    quickSort(getheadLista(arestas_globais), arestas_globais, compareKruskalCmp);

    struct subset* subsets = calloc(V, sizeof(struct subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
        subsets[v].id = getDataListaIndex(lista_vertices_totais, v);
    }

    celula_arestas_globais = getheadLista(arestas_globais);
    while (celula_arestas_globais) {
        int x_index = retornaIndexPorId(getArestaDestino(getdataList(celula_arestas_globais)), subsets, V);
        int y_index = retornaIndexPorId(getArestaPartida(getdataList(celula_arestas_globais)), subsets, V);

        int x = find(subsets, x_index);
        int y = find(subsets, y_index);

        if (x != y) {
            Union(subsets, x, y);
            InsereElementoLista(result, getdataList(celula_arestas_globais));
        }

        celula_arestas_globais = getnextLista(celula_arestas_globais);
    }

    void* listaDeListas = CriaLista();

    for (int i = 0; i < V; i++) {
        int index = find(subsets, i);
        int verify = 1;

        if (!getheadLista(result))
            break;

        if (!getheadLista(listaDeListas)) {
            InsereElementoLista(listaDeListas, CriaLista());
            void* aux = getlastLista(listaDeListas);
            InsereElementoLista(getdataList(aux), subsets[index].id);

        } else {
            void* listaAtual = getheadLista(listaDeListas);
            while (listaAtual) {
                if (subsets[index].id == getdataList(getheadLista(getdataList(listaAtual))))
                    verify = 0;

                listaAtual = getnextLista(listaAtual);
            }

            if (verify == 1) {
                InsereElementoLista(listaDeListas, CriaLista());
                void* aux = getlastLista(listaDeListas);
                InsereElementoLista(getdataList(aux), subsets[index].id);
            }
        }

        void* arestaAtual = getheadLista(result);
        while (arestaAtual) {
            void* verticeDestino = getVerticeData(getArestaDestino(getdataList(arestaAtual)));

            index = -1;
            void* verticeAtual = subsets[i].id;
            if (verticeAtual == verticeDestino) {
                index = find(subsets, i);
            }

            if (index != -1) {
                void* listaAtual = getheadLista(listaDeListas);
                while (listaAtual) {
                    if (subsets[index].id == getdataList(getheadLista(getdataList(listaAtual)))) {
                        InsereElementoLista(getdataList(listaAtual), getdataList(arestaAtual));
                        break;
                    }

                    listaAtual = getnextLista(listaAtual);
                }
            }

            arestaAtual = getnextLista(arestaAtual);
        }
    }

    return listaDeListas;
}

int compareKruskalId(void* A, void* B) {
    if (strcmp(getVerticeId(A), getVerticeId(B)) <= 0)
        return 1;
    else
        return -1;
}

int compareKruskalCmp(void* A, void* B) {
    if (getArestaCmp(A) <= getArestaCmp(B))
        return 1;
    else
        return -1;
}

int retornaIndexPorId(void* vertice_posicao, struct subset* subsets, int v) {
    char* id = getVerticeId(getVerticeData(vertice_posicao));
    for (int i = 0; i < v; i++) {
        if (!strcmp(getVerticeId(subsets[i].id), id))
            return i;
    }

    puts("DEU MERDA MENOH");

    return -1;
}
