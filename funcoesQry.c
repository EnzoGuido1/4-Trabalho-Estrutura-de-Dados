#include "funcoesQry.h"

#include "arestaData.h"
#include "avl.h"
#include "declaracoes.h"
#include "digrafo.h"
#include "dijkstra.h"
#include "filaPrioridade.h"
#include "hashTable.h"
#include "imprimeSvg.h"
#include "kruskal.h"
#include "leitura.h"
#include "lista.h"
#include "parametrosData.h"
#include "quadrasData.h"
#include "verticeData.h"

void setVerticeData(void *Vertice, void *data);

void catac(Tree avl, Tabela quadrasHash, Graph grafo, double x, double y, double w, double h, void *Stvar, char *path4, void *listaSvg) {
    void *celulaAvl = getHead(avl);
    FILE *qry = fopen(path4, "a");

    int *verificador = calloc(1, sizeof(int));
    *verificador = 0;

    fprintf(qry, "Função catac - x %.2lf y %.2lf w %.2lf h %.2lf  {\n", x, y, w, h);

    catacRec(avl, celulaAvl, quadrasHash, x, y, w, h, Stvar, qry, verificador, listaSvg);

    if (*verificador == 0)
        fprintf(qry, "\nNenhuma quadra se encaixa nos parametros passados\n");

    for (int i = 0; i < getGrafoTamanho(grafo); i++) {
        void *verticeAtual = getVertice(grafo, i);
        if (getVerticeX(getVerticeData(verticeAtual)) >= x && getVerticeX(getVerticeData(verticeAtual)) <= x + w) {
            if (getVerticeY(getVerticeData(verticeAtual)) >= y && getVerticeY(getVerticeData(verticeAtual)) <= y + h) {
                removeTodosElementosLista(getVerticeLista(verticeAtual));
                free(getVerticeData(verticeAtual));
                setVerticeData(verticeAtual, NULL);
            }
        }
    }

    fprintf(qry, "\n}\n\n");
    fclose(qry);
    free(verificador);
}

void catacRec(Tree avl, Posic celulaAtual, Tabela quadrasHash, double x, double y, double w, double h, void *Stvar, void *qry, int *verificador, void *listaSvg) {
    if (!celulaAtual) {
        return;
    }

    int verificadorCelulaRemovida = 0;

    if (getMin(celulaAtual) <= x + w && getMax(celulaAtual) >= x) {
        catacRec(avl, AvlRight(celulaAtual), quadrasHash, x, y, w, h, Stvar, qry, verificador, listaSvg);
        catacRec(avl, AvlLeft(celulaAtual), quadrasHash, x, y, w, h, Stvar, qry, verificador, listaSvg);
    }

    void *celulaListaQuadra = getheadLista(getData(celulaAtual));
    while (celulaListaQuadra) {
        void *celulaListaQuadraAux;
        if (getnextLista(celulaListaQuadra))
            celulaListaQuadraAux = getnextLista(celulaListaQuadra);
        else
            celulaListaQuadraAux = NULL;
        if (getDataX(getdataList(celulaListaQuadra)) >= x && getDataX(getdataList(celulaListaQuadra)) + getDataW(getdataList(celulaListaQuadra)) <= x + w) {
            if (getDataY(getdataList(celulaListaQuadra)) >= y && getDataY(getdataList(celulaListaQuadra)) + getDataH(getdataList(celulaListaQuadra)) <= y + h) {
                *verificador = 1;
                fprintf(qry, "\nQuadra do cep %s \n", getDataCep(getdataList(celulaListaQuadra)));

                void *celulaTree = retornaListaAvl(avl, getDataX(getdataList(celulaListaQuadra)));
                void *celulaTreeFree = retornaCelulaAvl(avl, getDataX(getdataList(celulaListaQuadra)));
                while (celulaTreeFree) {
                    if (!celulaTreeFree)
                        break;
                    if (strcmp(getDataCep(getdataList(celulaTreeFree)), getDataCep(getdataList(celulaListaQuadra))))
                        celulaTreeFree = getnextLista(celulaTreeFree);
                    else
                        break;
                }

                void *lista = getRegistro(quadrasHash, getDataCep(getdataList(celulaListaQuadra)));
                RemoveCelulaListaPorData(lista, getDataCep(getdataList(celulaListaQuadra)), getDataCep);

                char teste[1000];
                sprintf(teste, "\n\t<rect x=\"%.2lf\" y=\"%.2lf\" width=\"%.2lf\" height=\"%.2lf\" stroke=\"%s\" stroke-width=\"%.2lf\" fill=\"%s\" opacity=\"0.5\"/>", getDataX(getdataList(celulaTreeFree)), getDataY(getdataList(celulaTreeFree)), getDataW(getdataList(celulaTreeFree)), getDataH(getdataList(celulaTreeFree)), "#AA0044", getDataSw(getdataList(celulaTreeFree)), "#AB37C8");
                char *teste2 = calloc(strlen(teste) + 2, sizeof(char));
                strcpy(teste2, teste);
                InsereElementoLista(listaSvg, teste2);

                if (gettamanhoLista(celulaTree) == 1) {
                    verificadorCelulaRemovida = 1;
                    deleteNode(avl, getdataList(getheadLista(celulaTree)));
                } else
                    RemoveCelulaListaPorData(celulaTree, getDataCep(getdataList(celulaListaQuadra)), getDataCep);
            }
        }
        if (verificadorCelulaRemovida == 0)
            celulaListaQuadra = celulaListaQuadraAux;
        else
            break;
    }
}

void *PercorreLista(Tabela tabela, char *chave, char *getData(void *auxDados)) {
    void *lista = getRegistro(tabela, chave);
    if (!lista)
        return NULL;
    void *celula = getheadLista(lista);

    int verificador = 0;

    while (celula) {
        if (!strcmp(getData(getdataList(celula)), chave)) {
            verificador = 1;
            break;
        }
        celula = getnextLista(celula);
    }

    if (verificador == 0) {
        celula = NULL;
    }

    return celula;
}

double *calculaEndereco(Tree avl, Tabela quadrasHash, char *cep, char face, int numero) {
    void *celulaQuadra = PercorreLista(quadrasHash, cep, getDataCep);

    double *endereco = calloc(2, sizeof(double));
    endereco[0] = -100;
    endereco[1] = -100;

    if (celulaQuadra == NULL) {
        return endereco;

    } else {
        double x = getDataX(getdataList(celulaQuadra));
        // void *celulaTree = retornaListaAvl(avl, x);
        void *celulaTreeFree = retornaCelulaAvl(avl, x);
        while (celulaTreeFree) {
            if (!celulaTreeFree)
                break;
            if (strcmp(getDataCep(getdataList(celulaTreeFree)), cep))
                celulaTreeFree = getnextLista(celulaTreeFree);
            else
                break;
        }

        if (!celulaTreeFree)
            puts("ERRO NA CALCULA ENDERECO");
    }

    if (face == 'N') {
        endereco[0] = getDataX(getdataList(celulaQuadra)) + numero + 1;
        endereco[1] = getDataY(getdataList(celulaQuadra)) + (0.1 * getDataH(getdataList(celulaQuadra))) + 2;
    } else if (face == 'S') {
        endereco[0] = getDataX(getdataList(celulaQuadra)) + getDataW(getdataList(celulaQuadra)) - numero - 1;
        endereco[1] = getDataY(getdataList(celulaQuadra)) + getDataH(getdataList(celulaQuadra)) - (0.1 * getDataH(getdataList(celulaQuadra))) - 2;
    } else if (face == 'L') {
        endereco[1] = getDataY(getdataList(celulaQuadra)) + numero + 1;
        endereco[0] = getDataX(getdataList(celulaQuadra)) + getDataW(getdataList(celulaQuadra)) - (0.1 * getDataW(getdataList(celulaQuadra))) - 2;
    } else if (face == 'O') {
        endereco[1] = getDataY(getdataList(celulaQuadra)) + getDataH(getdataList(celulaQuadra)) - numero - 1;
        endereco[0] = getDataX(getdataList(celulaQuadra)) + (0.1 * getDataW(getdataList(celulaQuadra))) + 2;
    }

    return endereco;
}
