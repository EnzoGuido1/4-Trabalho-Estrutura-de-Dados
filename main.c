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

//RETIRAR ESSA MERDA DPS, SO PARA TEST CASE
void setVerticeData(void* Vertice, void* data);

int main() {
    void* Grafo_vertices = criaGrafo(9);
    void* vertice = getVertice(Grafo_vertices, 0);
    void* dados = callocDataVertice("A", 0, 0);
    setVerticeData(vertice, dados);

    vertice = getVertice(Grafo_vertices, 1);
    dados = callocDataVertice("B", 1, 1);
    setVerticeData(vertice, dados);

    vertice = getVertice(Grafo_vertices, 2);
    dados = callocDataVertice("C", 2, 2);
    setVerticeData(vertice, dados);

    vertice = getVertice(Grafo_vertices, 3);
    dados = callocDataVertice("D", 3, 3);
    setVerticeData(vertice, dados);

    vertice = getVertice(Grafo_vertices, 4);
    dados = callocDataVertice("E", 4, 4);
    setVerticeData(vertice, dados);

    vertice = getVertice(Grafo_vertices, 5);
    dados = callocDataVertice("F", 5, 5);
    setVerticeData(vertice, dados);

    vertice = getVertice(Grafo_vertices, 6);
    dados = callocDataVertice("G", 6, 6);
    setVerticeData(vertice, dados);

    vertice = getVertice(Grafo_vertices, 7);
    dados = callocDataVertice("H", 7, 7);
    setVerticeData(vertice, dados);

    vertice = getVertice(Grafo_vertices, 8);
    dados = callocDataVertice("I", 8, 8);
    setVerticeData(vertice, dados);

    // void* vertice = getVertice(Grafo_vertices, 0);
    // void* dados = callocDataVertice("S", 0, 0);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 1);
    // dados = callocDataVertice("A", 1, 1);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 2);
    // dados = callocDataVertice("B", 2, 2);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 3);
    // dados = callocDataVertice("C", 3, 3);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 4);
    // dados = callocDataVertice("D", 4, 4);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 5);
    // dados = callocDataVertice("E", 5, 5);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 6);
    // dados = callocDataVertice("F", 6, 6);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 7);
    // dados = callocDataVertice("G", 7, 7);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 8);
    // dados = callocDataVertice("H", 8, 8);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 9);
    // dados = callocDataVertice("I", 9, 9);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 10);
    // dados = callocDataVertice("J", 10, 10);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 11);
    // dados = callocDataVertice("K", 11, 11);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 12);
    // dados = callocDataVertice("L", 12, 12);
    // setVerticeData(vertice, dados);

    // vertice = getVertice(Grafo_vertices, 13);
    // dados = callocDataVertice("teste", 13, 13);
    // setVerticeData(vertice, dados);

    // dados = callocDataAresta("S-A", "dir", "esq", 7, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "S", "A", dados);

    // dados = callocDataAresta("A-B", "dir", "esq", 2, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "A", "B", dados);

    // dados = callocDataAresta("B-S", "dir", "esq", 3, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "B", "S", dados);

    // dados = callocDataAresta("C-B", "dir", "esq", 10, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "C", "B", dados);

    //TESTEEEEEEEEEEEE
    dados = callocDataAresta("A-B", "dir", "esq", 1, 1, NULL, " ");

    insere_Aresta(Grafo_vertices, "A", "B", dados);

    dados = callocDataAresta("B-C", "dir", "esq", 1, 1, NULL, " ");

    insere_Aresta(Grafo_vertices, "B", "C", dados);

    dados = callocDataAresta("D-E", "dir", "esq", 1, 1, NULL, " ");

    insere_Aresta(Grafo_vertices, "D", "E", dados);

    dados = callocDataAresta("E-F", "dir", "esq", 1, 1, NULL, " ");

    insere_Aresta(Grafo_vertices, "E", "F", dados);

    dados = callocDataAresta("G-I", "dir", "esq", 1, 1, NULL, " ");

    insere_Aresta(Grafo_vertices, "G", "I", dados);

    dados = callocDataAresta("G-H", "dir", "esq", 1, 1, NULL, " ");

    insere_Aresta(Grafo_vertices, "G", "H", dados);

    //------------------------------------------------------------------------------

    // dados = callocDataAresta("S-A", "dir", "esq", 7, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "S", "A", dados);

    // dados = callocDataAresta("S-B", "dir", "esq", 2, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "S", "B", dados);

    // dados = callocDataAresta("S-C", "dir", "esq", 3, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "S", "C", dados);

    // dados = callocDataAresta("A-B", "dir", "esq", 3, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "A", "B", dados);

    // dados = callocDataAresta("A-D", "dir", "esq", 4, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "A", "D", dados);

    // dados = callocDataAresta("B-D", "dir", "esq", 4, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "B", "D", dados);

    // dados = callocDataAresta("B-H", "dir", "esq", 1, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "B", "H", dados);

    // dados = callocDataAresta("D-F", "dir", "esq", 5, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "D", "F", dados);

    // dados = callocDataAresta("F-H", "dir", "esq", 3, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "F", "H", dados);

    // dados = callocDataAresta("H-G", "dir", "esq", 2, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "H", "G", dados);

    // dados = callocDataAresta("G-E", "dir", "esq", 2, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "G", "E", dados);

    // dados = callocDataAresta("C-L", "dir", "esq", 2, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "C", "L", dados);

    // dados = callocDataAresta("L-I", "dir", "esq", 4, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "L", "I", dados);

    // dados = callocDataAresta("L-J", "dir", "esq", 4, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "L", "J", dados);

    // dados = callocDataAresta("I-J", "dir", "esq", 6, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "I", "J", dados);

    // dados = callocDataAresta("I-K", "dir", "esq", 4, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "I", "K", dados);

    // dados = callocDataAresta("J-K", "dir", "esq", 4, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "J", "K", dados);

    // dados = callocDataAresta("K-E", "dir", "esq", 5, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "K", "E", dados);

    // dados = callocDataAresta("E-S", "dir", "esq", 15, 1, NULL, " ");

    // insere_Aresta(Grafo_vertices, "E", "S", dados);

    // void* teste = Dijkstra(Grafo_vertices, "S", "E");
    // if (teste) {
    //     void* celulaPercorreLista = getheadLista(teste);

    //     // printf("%d\n", gettamanhoLista(teste));

    //     puts("\n");
    //     printf("%s(%.2lf)", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))), getDijkstraCusto(getdataList(celulaPercorreLista)));
    //     celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     while (celulaPercorreLista) {
    //         printf("->%s(%.2lf)(%s)", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))), getDijkstraCusto(getdataList(celulaPercorreLista)), getVerticeId(getVerticeData(getDijkstraPrev(getdataList(celulaPercorreLista)))));
    //         celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     }
    //     celulaPercorreLista = getlastLista(teste);
    //     printf("\ncusto: %.2lf", getDijkstraCusto(getdataList(celulaPercorreLista)));
    //     puts("\n");
    // }

    // quickSort(getheadLista(teste), teste, compareDijkstraCusto);  //FUNCIONAAAAAAAAAAAA

    // void* celulaPercorreLista = getheadLista(teste);

    // puts("\n");
    // printf("%s(%.2lf)", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))), getDijkstraCusto(getdataList(celulaPercorreLista)));
    // celulaPercorreLista = getnextLista(celulaPercorreLista);
    // while (celulaPercorreLista) {
    //     printf("->%s(%.2lf)", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))), getDijkstraCusto(getdataList(celulaPercorreLista)));
    //     celulaPercorreLista = getnextLista(celulaPercorreLista);
    // }
    // celulaPercorreLista = getlastLista(teste);
    // printf("\ncusto: %.2lf", getDijkstraCusto(getdataList(celulaPercorreLista)));
    // puts("\n");

    puts(" ");

    void* lista_arestas_global = CriaLista();

    for (int i = 0; i < getGrafoTamanho(Grafo_vertices); i++) {
        void* verticeAtual = getVertice(Grafo_vertices, i);
        void* listaArestasVerticeAtual = getVerticeLista(verticeAtual);
        if (!listaArestasVerticeAtual)
            continue;
        void* celulaArestaAtual = getheadLista(listaArestasVerticeAtual);
        while (celulaArestaAtual) {
            InsereElementoLista(lista_arestas_global, getdataList(celulaArestaAtual));
            celulaArestaAtual = getnextLista(celulaArestaAtual);
        }
    }

    void* testeListaDeListas = KruskalMST(lista_arestas_global);
    void* celulaTesteListaDeListas = getheadLista(testeListaDeListas);
    while (celulaTesteListaDeListas) {
        void* ListaI = getheadLista(getdataList(celulaTesteListaDeListas));
        printf("Raiz %s - [", getVerticeId(getdataList(ListaI)));

        ListaI = getnextLista(ListaI);
        while (ListaI) {
            printf("(%s)", getArestaNome(getdataList(ListaI)));
            ListaI = getnextLista(ListaI);
            if (ListaI) {
                printf("-->");
            }
        }
        puts("].");

        celulaTesteListaDeListas = getnextLista(celulaTesteListaDeListas);
    }

    puts(" ");

    // void* celulaPercorreLista = getheadLista(testeLista);

    // puts("\n");
    // printf("%s", getVerticeId(getdataList(celulaPercorreLista)));
    // celulaPercorreLista = getnextLista(celulaPercorreLista);
    // while (celulaPercorreLista) {
    //     printf("->%s", getVerticeId(getdataList(celulaPercorreLista)));
    //     celulaPercorreLista = getnextLista(celulaPercorreLista);
    // }
    // celulaPercorreLista = getlastLista(testeLista);
    // puts("\n");

    // teste = Dijkstra(Grafo_vertices, "C", "B");
    // if (teste) {
    //     void* celulaPercorreLista = getheadLista(teste);

    //     puts("\n");
    //     printf("%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //     celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     while (celulaPercorreLista) {
    //         printf("->%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //         celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     }
    //     celulaPercorreLista = getlastLista(teste);
    //     printf("\ncusto: %.2lf", getDijkstraCusto(getdataList(celulaPercorreLista)));
    //     puts("\n");
    // }

    // teste = Dijkstra(Grafo_vertices, "S", "I");
    // if (teste) {
    //     void* celulaPercorreLista = getheadLista(teste);

    //     puts("\n");
    //     printf("%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //     celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     while (celulaPercorreLista) {
    //         printf("->%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //         celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     }
    //     celulaPercorreLista = getlastLista(teste);
    //     printf("\ncusto: %.2lf", getDijkstraCusto(getdataList(celulaPercorreLista)));
    //     puts("\n");
    // }

    // teste = Dijkstra(Grafo_vertices, "S", "teste");
    // if (teste) {
    //     void* celulaPercorreLista = getheadLista(teste);

    //     puts("\n");
    //     printf("%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //     celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     while (celulaPercorreLista) {
    //         printf("->%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //         celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     }
    //     celulaPercorreLista = getlastLista(teste);
    //     printf("\ncusto: %.2lf", getDijkstraCusto(getdataList(celulaPercorreLista)));
    //     puts("\n");
    // }

    // remove_Aresta(Grafo_vertices, "S", "B");

    // teste = Dijkstra(Grafo_vertices, "S", "E");
    // if (teste) {
    //     void* celulaPercorreLista = getheadLista(teste);

    //     puts("\n");
    //     printf("%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //     celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     while (celulaPercorreLista) {
    //         printf("->%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //         celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     }
    //     celulaPercorreLista = getlastLista(teste);
    //     printf("\ncusto: %.2lf", getDijkstraCusto(getdataList(celulaPercorreLista)));
    //     puts("\n");
    // }

    // remove_Aresta(Grafo_vertices, "S", "A");

    // teste = Dijkstra(Grafo_vertices, "S", "E");
    // if (teste) {
    //     void* celulaPercorreLista = getheadLista(teste);

    //     puts("\n");
    //     printf("%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //     celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     while (celulaPercorreLista) {
    //         printf("->%s", getVerticeId(getDijkstraData(getdataList(celulaPercorreLista))));
    //         celulaPercorreLista = getnextLista(celulaPercorreLista);
    //     }
    //     celulaPercorreLista = getlastLista(teste);
    //     printf("\ncusto: %.2lf", getDijkstraCusto(getdataList(celulaPercorreLista)));
    //     puts("\n");
    // }

    // teste = Dijkstra(Grafo_vertices, "S", "Y");

    // celulaAtual = getheadLista(verticeLista);

    // while (celulaAtual) {
    //     printf("%s\n", getVerticeId(getVerticeData(getArestaDestino(getdataList(celulaAtual)))));
    //     celulaAtual = getnextLista(celulaAtual);
    // }

    // void* fila = CriaFila();

    // dados = callocDataAresta("teste1", "dir", "esq", 100, 40, NULL);
    // insereFila(fila, dados, 5.5);

    // dados = callocDataAresta("teste2", "dir", "esq", 100, 40, NULL);
    // insereFila(fila, dados, 7.2);

    // dados = callocDataAresta("teste3", "dir", "esq", 100, 40, NULL);
    // insereFila(fila, dados, 7.1);

    // dados = callocDataAresta("teste4", "dir", "esq", 100, 40, NULL);
    // insereFila(fila, dados, 4.7);

    // void* teste = getHeadFila(fila);

    // while (teste) {
    //     printf("%s->", getArestaNome(getDataCelulaFila(teste)));
    //     teste = getnextFila(teste);
    // }
    // puts("\n");

    // while (filaVazia(fila)) {
    //     printf("%s\n", getArestaNome(getDataCelulaFila(getHeadFila(fila))));
    //     removeFila(fila);
    // }

    // removeFila(fila);
    // removeFila(fila);
    // removeFila(fila);
    // removeFila(fila);
    // removeFila(fila);
    // removeFila(fila);

    // puts(" ");

    return 0;
}
