#include "digrafo.h"

#include "arestaData.h"
#include "avl.h"
#include "declaracoes.h"
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

void setVerticeId(void* Sdata, char* id);
void setVerticeX(void* Sdata, double x);
void setVerticeY(void* Sdata, double y);

void setArestaNome(void* Sdata, char* nome);
void setArestaLdir(void* Sdata, char* ldir);
void setArestaLesq(void* Sdata, char* lesq);
void setArestaCmp(void* Sdata, double cmp);
void setArestaVm(void* Sdata, double vm);
void setArestaDestino(void* Sdata, void* destino);
void setArestaPartida(void* Sdata, void* partida);

typedef struct grafo_vertice {
    void* lista;
    void* Dados;
} Grafo_vertice;

typedef struct grafo {
    Grafo_vertice* vetor;
    int tamanho;
} Grafo;

void* getVerticeData(void* Sdata) {
    Grafo_vertice* vertice = Sdata;
    if (!vertice) {
        return NULL;
    }
    return vertice->Dados;
}

void setVerticeData(void* Vertice, void* data) {
    Grafo_vertice* vertice = Vertice;
    vertice->Dados = data;
}

void* getVerticeLista(void* Sdata) {
    Grafo_vertice* vertice = Sdata;
    if (!vertice || !vertice->lista)
        return NULL;

    return vertice->lista;
}

void* getVertice(void* Sdata, int index) {
    Grafo* dados = Sdata;
    if (!dados)
        return NULL;

    return &(dados->vetor[index]);
}

int getGrafoTamanho(void* Sdata) {
    Grafo* grafo = Sdata;
    if (!grafo)
        return 0;

    return grafo->tamanho;
}

void* criaGrafo(int vertices) {
    if (vertices <= 0)
        return NULL;
    Grafo* grafo = calloc(1, sizeof(Grafo));
    grafo->tamanho = vertices;
    grafo->vetor = calloc(vertices, sizeof(Grafo_vertice));
    return grafo;
}

void insere_Aresta(Graph grafo, char* v1, char* v2, void* aresta_data) {
    //-------------------------------------------------------------------------------------------------------------------------------------------------
    //É ESTRITAMENTE NECESSÁRIO DAR CALLOC NA ARESTA_DATA COM A FUNÇÃO CALLOC_ARESTA_DATA ANTES DE INICIAR ESSA FUNÇÃO --------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------

    if (!grafo) {
        printf("O grafo passado na função insere_Aresta consta como nulo\n");
        return;
    }

    Grafo* digrafo = grafo;
    int posicao_v2 = percorre_Vertices(grafo, v2);

    void* v1_lista = retorna_lista_arestas(grafo, v1);

    int posicao_v1 = percorre_Vertices(grafo, v1);

    if (!v1_lista) {
        int posicao_v1 = percorre_Vertices(grafo, v1);
        digrafo->vetor[posicao_v1].lista = CriaLista();
        v1_lista = digrafo->vetor[posicao_v1].lista;
    }

    void* ponteiro_posicao_v1 = &(digrafo->vetor[posicao_v1]);
    setArestaPartida(aresta_data, ponteiro_posicao_v1);
    void* ponteiro_posicao_v2 = &(digrafo->vetor[posicao_v2]);
    setArestaDestino(aresta_data, ponteiro_posicao_v2);
    //(tipo void) setArestaDestino(void *aresta_data, void* exemplo); guarda a posição do vetor estático de v2 como o endereço do ponteiro, para acessar o vertice v2 deve-se apenas utilizar getArestaDestino(void *aresta_data) que funciona como digrafo->vetor[posicao_v2] descrito no exemplo acima
    InsereElementoLista(v1_lista, aresta_data);
}

void define_Info(Graph grafo, char* v1, char* v2, void* aresta_data) {
    //-------------------------------------------------------------------------------------------------------------------------------------------------
    //É ESTRITAMENTE NECESSÁRIO DAR CALLOC NA ARESTA_DATA COM A FUNÇÃO CALLOC_ARESTA_DATA ANTES DE INICIAR ESSA FUNÇÃO --------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------

    if (!grafo) {
        printf("O grafo passado na função define_Info consta como nulo\n");
        //free(aresta_data)
        return;
    }

    void* v1_lista = retorna_lista_arestas(grafo, v1);

    if (!v1_lista) {
        printf("Nao existem arestas no vertice de id: %s\n", v1);
        //free(aresta_data)
        return;
    }

    void* v2_celula = retorna_aresta_v1_para_v2(grafo, v1_lista, v2);

    if (!v2_celula) {
        printf("A aresta de v1: %s para v2: %s pela funcao define_Info nao consta nos dados do programa\n", v1, v2);
        //free(aresta_data)
        return;
    }

    //void* v2_celula_dados = getdataList(v2_celula);
    //if(v2_celula_dados)
    //  free(v2_celula_dados);
    //
    //v2_celula_dados = aresta_data;
}

void* get_Info(Graph grafo, char* v1, char* v2) {
    if (!grafo) {
        printf("O grafo passado na função define_Info consta como nulo\n");
        return NULL;
    }

    void* v1_lista = retorna_lista_arestas(grafo, v1);

    if (!v1_lista) {
        printf("Nao existem arestas no vertice de id: %s\n", v1);
        return NULL;
    }

    void* v2_celula = retorna_aresta_v1_para_v2(grafo, v1_lista, v2);

    if (!v2_celula) {
        printf("A aresta de v1: %s para v2: %s pela funcao define_Info nao consta nos dados do programa\n", v1, v2);
        return NULL;
    }

    return getdataList(v2_celula);
}

void remove_Aresta(Graph grafo, char* v1, char* v2) {
    if (!grafo) {
        printf("O grafo passado na função define_Info consta como nulo\n");
        return;
    }

    void* v1_lista = retorna_lista_arestas(grafo, v1);

    if (!v1_lista) {
        printf("Nao existem arestas no vertice de id: %s\n", v1);
        return;
    }

    void* v2_celula = retorna_aresta_v1_para_v2(grafo, v1_lista, v2);

    if (!v2_celula) {
        printf("A aresta de v1: %s para v2: %s pela funcao define_Info nao consta nos dados do programa\n", v1, v2);
        return;
    }

    RemoveCelulaLista(v1_lista, getdataList(v2_celula));
}

int v1_adjacente_v2(Graph grafo, char* v1, char* v2) {
    if (!grafo) {
        printf("O grafo passado na função define_Info consta como nulo\n");
        return 0;
    }

    void* v1_lista = retorna_lista_arestas(grafo, v1);

    if (!v1_lista) {
        printf("Nao existem arestas no vertice de id: %s\n", v1);
        return 0;
    }

    void* v2_celula = retorna_aresta_v1_para_v2(grafo, v1_lista, v2);

    if (!v2_celula) {
        printf("A aresta de v1: %s para v2: %s pela funcao define_Info nao consta nos dados do programa\n", v1, v2);
        return 0;
    }

    if (!v2_celula)
        return 0;
    else
        return 1;
}

void* v1_adjacentes(Graph grafo, char* v1) {
    if (!grafo) {
        printf("O grafo passado na função define_Info consta como nulo\n");
        return NULL;
    }

    void* v1_lista = retorna_lista_arestas(grafo, v1);

    if (!v1_lista) {
        printf("Nao existem arestas no vertice de id: %s\n", v1);
        return NULL;
    } else
        return v1_lista;
}

int percorre_Vertices(Graph grafo, char* vertice) {
    int cont = 0;
    Grafo* digrafo = grafo;
    void* digrafo_data = NULL;

    while (cont < digrafo->tamanho) {
        digrafo_data = digrafo->vetor[cont].Dados;
        // printf("%s\n", getVerticeId(digrafo_data));
        if (!strcmp(getVerticeId(digrafo_data), vertice))
            break;

        cont++;
    }

    if (cont == digrafo->tamanho || cont < 0) {
        printf("Nao foi possivel localizar o vertice de string %s na funcao percorre_Vertices\n", vertice);
        return -1;
    }

    return cont;
}

void* retorna_lista_arestas(Graph grafo, char* v1) {
    Grafo* digrafo = grafo;

    int posicao_v1 = percorre_Vertices(grafo, v1);

    if (posicao_v1 == -1) {
        return NULL;
    }

    return digrafo->vetor[posicao_v1].lista;
}

//retorna uma celula da lista
void* retorna_aresta_v1_para_v2(Graph grafo, List lista_de_arestas_v1, char* v2) {
    Grafo* digrafo = grafo;

    int posicao_v2 = percorre_Vertices(grafo, v2);

    void* celula_aresta_atual = getheadLista(lista_de_arestas_v1);

    while (celula_aresta_atual) {
        if (getArestaDestino(getdataList(celula_aresta_atual)) == &(digrafo->vetor[posicao_v2]))
            break;
        celula_aresta_atual = getnextLista(celula_aresta_atual);
    }

    return celula_aresta_atual;
}

// void* Dijkstra(Graph grafo, char* v1, char* v2) {
//     if (!grafo) {
//         printf("O grafo passado na função Dijkstra consta como nulo\n");
//         return NULL;
//     }

//     void* v1_lista = retorna_lista_arestas(grafo, v1);

//     if (!v1_lista) {
//         printf("Nao existem arestas no vertice de id: %s\n", v1);
//         return NULL;
//     }

//     void* fila = CriaFila();

//     void* celulaLista = getheadLista(v1_lista);
//     printf("%s->", v1);
//     while (celulaLista) {
//         insereFila(fila, getdataList(celulaLista), getArestaCmp(getdataList(celulaLista)) / getArestaVm(getdataList(celulaLista)));
//         celulaLista = getnextLista(celulaLista);
//     }

//     void* celulaFila = getHeadFila(fila);
//     printf("%s\n", getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))));

//     // printf("%s %s\n", getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))), v2);

//     // (getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))))

//     while (strcmp(getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))), v2)) {
//         // printf("%s %s\n", getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))), v2);

//         void* vertice_Atual_Lista = retorna_lista_arestas(grafo, getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))));
//         if (vertice_Atual_Lista) {
//             celulaLista = getheadLista(vertice_Atual_Lista);
//             while (celulaLista) {
//                 insereFila(fila, getdataList(celulaLista), getArestaCmp(getdataList(celulaLista)) / getArestaVm(getdataList(celulaLista)) + getPrioridadeCelulaFila(getHeadFila(fila)));
//                 celulaLista = getnextLista(celulaLista);
//             }

//             printf("%s->", getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))));
//         }

//         removeFila(fila);
//         celulaFila = getHeadFila(fila);

//         if (!celulaFila)
//             break;
//         if (vertice_Atual_Lista)
//             printf("%s\n", getVerticeId(getVerticeData(getArestaDestino(getDataCelulaFila(celulaFila)))));
//     }

//     if (!celulaFila) {
//         printf("Não é possível chegar do ponto %s ao ponto %s\n", v1, v2);
//         return NULL;
//     } else {
//         printf("%.2lf\n", getPrioridadeCelulaFila(celulaFila));
//         return celulaFila;
//     }
// }
