#include "lista.h"

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
#include "parametrosData.h"
#include "quadrasData.h"
#include "verticeData.h"

typedef struct celulaLista {
    void *Dados;
    struct celulaLista *prox;
    struct celulaLista *ant;

} CelulaLista;

//struct lista da lista dinamica, contem o tamanho e referencias de ultimo e primeiro elemento da lista
typedef struct lista {
    int tamanho;
    CelulaLista *cabeca;
    CelulaLista *rabo;

} Lista;

void setValor(void *Sdata, void *valor) {
    CelulaLista *celula = Sdata;
    celula->Dados = valor;
}

void *callocCelulaLista() {
    CelulaLista *celula = calloc(1, sizeof(CelulaLista));
    return celula;
}

Posic getheadLista(List list) {
    Lista *lista = list;
    if (!lista->tamanho) {
        return NULL;
    }
    return lista->cabeca;
}

int gettamanhoLista(List list) {
    Lista *lista = list;
    if (!lista->tamanho) {
        return 0;
    }
    return lista->tamanho;
}

Posic getlastLista(List list) {
    Lista *lista = list;
    if (!lista->tamanho) {
        return NULL;
    }
    return lista->rabo;
}

Posic getpreviousLista(List list, Posic aux) {
    Lista *ponteiro = list;
    CelulaLista *aux1 = aux;
    if (aux1 == ponteiro->cabeca) {
        return NULL;
    }
    return aux1->ant;
}

Posic getnextLista(Posic aux) {
    CelulaLista *ponteiro = aux;
    if (ponteiro->prox == NULL) {
        return NULL;
    }
    return ponteiro->prox;
}

Posic getantLista(List list, Posic aux) {
    CelulaLista *aux1 = aux;
    return aux1->ant;
}

void *getdataList(Posic aux) {
    CelulaLista *ponteiro = aux;
    if (aux == NULL) {
        return 0;
    }
    return ponteiro->Dados;
}

void *getDataListaIndex(List list, int index) {
    if (!list) {
        return NULL;
    }

    int cont = 0;
    CelulaLista *ponteiro = getheadLista(list);
    while (ponteiro && cont < index) {
        ponteiro = getnextLista(ponteiro);
        cont++;
    }

    if (!ponteiro) {
        printf("ERRO %d\n", index);
        return NULL;
    } else
        return ponteiro->Dados;
}

List CriaLista() {
    Lista *ponteiro = malloc(sizeof(Lista));
    ponteiro->tamanho = 0;
    ponteiro->cabeca = NULL;
    ponteiro->rabo = NULL;
    return ponteiro;
}

void RemoveCelulaLista(List list, void *x) {
    Lista *lista = list;
    CelulaLista *aux3 = lista->cabeca;
    if (!lista->tamanho) {
        printf("Lista Vazia!");
        return;
    }
    while ((getdataList(aux3)) != x) {
        if (aux3->prox) {
            aux3 = aux3->prox;
        } else {
            puts("elemento com este valor nao existe");
            return;
        }
    }
    if (aux3 == lista->cabeca) {
        lista->cabeca = lista->cabeca->prox;
        lista->cabeca->ant = NULL;
    } else if (aux3 == lista->rabo) {
        lista->rabo = aux3->ant;
        lista->rabo->prox = NULL;
    } else {
        CelulaLista *aux2 = aux3->ant;
        CelulaLista *aux4 = aux3->prox;
        if (!aux3 || !aux2) {
            return;
        }
        aux4->ant = aux2;
        aux2->prox = aux3->prox;
    }
    lista->tamanho--;
    // free(aux3->Dados);
    // free(aux3);
}

void RemoveCelulaListaPorData(List list, char *cpf, char *getData(void *auxDados)) {
    Lista *lista = list;
    CelulaLista *aux3 = lista->cabeca;
    if (!lista->tamanho) {
        printf("Lista Vazia!");
        return;
    }
    while (strcmp(getData(getdataList(aux3)), cpf)) {
        if (aux3->prox) {
            aux3 = aux3->prox;
        }
        if (!strcmp(getData(getdataList(aux3)), cpf))
            break;
    }

    if (strcmp(getData(getdataList(aux3)), cpf)) {
        puts("elemento com este valor nao existe");
        return;
    }

    if (aux3 == lista->cabeca && aux3 == lista->rabo) {
        lista->cabeca = NULL;
        lista->rabo = NULL;
    } else if (aux3 == lista->cabeca) {
        lista->cabeca = lista->cabeca->prox;
        lista->cabeca->ant = NULL;
    } else if (aux3 == lista->rabo) {
        lista->rabo = aux3->ant;
        lista->rabo->prox = NULL;
    } else {
        CelulaLista *aux2 = aux3->ant;
        CelulaLista *aux4 = aux3->prox;
        if (!aux3 || !aux2) {
            return;
        }
        aux4->ant = aux2;
        aux2->prox = aux3->prox;
    }
    lista->tamanho--;
    free(aux3->Dados);
    free(aux3);
}

Posic NaPosicaoLista(List list, int index) {
    Lista *lista = list;
    CelulaLista *aux = lista->cabeca;
    if (index < 0 || index > lista->tamanho - 1) {
        puts("Index Invalido");
        return NULL;
    }
    for (int i = 0; i < index; i++) {
        aux = aux->prox;
    }
    return aux;
}

// void FreeLista(List list, int tipo) {
//     if (!list)
//         return;
//     Lista *lista = list;
//     if (!lista->tamanho || lista->tamanho == 0)
//         return;
//     CelulaLista *aux = lista->cabeca, *aux2;
//     for (int i = 0; i < lista->tamanho; i++) {
//         aux2 = aux;
//         Iten *ponteiro = aux->Dados;
//         if (tipo == 1) {
//             freeDadosPessoa(ponteiro);
//         }
//         if (tipo == -1) {
//             FreeLista(getDataPessoasLista(ponteiro), 0);
//             FreeLista(getDataLocacoesLista(ponteiro), 0);
//             free(getDataPessoasLista(ponteiro));
//             free(getDataLocacoesLista(ponteiro));
//             // FreeLista(getDataLocacoesLista(ponteiro), 0);
//             // free(getDataLocacoesLista(ponteiro));
//         }
//         free(ponteiro);

//         aux = aux->prox;
//         free(aux2);
//     }
//     // free(lista);
// }

void InsereElementoLista(List list, Iten iten) {
    Lista *lista = list;
    CelulaLista *aux = calloc(1, sizeof(CelulaLista));
    aux->Dados = iten;
    if (lista->tamanho == 0) {
        lista->cabeca = aux;
        lista->rabo = aux;
        aux->prox = NULL;
        aux->ant = NULL;
    } else {
        aux->ant = lista->rabo;
        lista->rabo->prox = aux;
        lista->rabo = aux;
        aux->prox = NULL;
    }
    lista->tamanho++;
}

void printList(List list, char *getData(void *auxDados)) {
    Lista *lista = list;
    if (!lista) {
        puts("passou");
        return;
    }
    CelulaLista *aux = getheadLista(lista);
    while (aux) {
        printf("[%s]-", getData(aux->Dados));
        aux = getnextLista(aux);
    }
    puts(" ");
}

void *searchList(List list, void *dados) {
    Lista *lista = list;

    if (!lista)
        return NULL;

    CelulaLista *celula = getheadLista(lista);

    while (celula) {
        if (celula->Dados == dados)
            break;
        celula = getnextLista(celula);
    }

    return celula;
}

void trocaDados(Posic a, Posic b) {
    CelulaLista *auxA = a;
    CelulaLista *auxB = b;
    void *t = auxA->Dados;
    auxA->Dados = auxB->Dados;
    auxB->Dados = t;
}

Posic particionaLista(Posic l, Posic h, List list, int getData(void *auxDados, void *aux2Dados)) {
    CelulaLista *aux = h;

    struct CelulaLista *i = getpreviousLista(list, l);

    int cont = 0;
    for (struct CelulaLista *aux2 = l; aux2 != h; aux2 = getnextLista(aux2)) {
        if (getData(getdataList(aux2), getdataList(aux)) == 1) {
            i = (i == NULL) ? l : getnextLista(i);

            trocaDados(i, aux2);
        }
        cont++;
    }
    i = (i == NULL) ? l : getnextLista(i);
    trocaDados(i, h);
    return i;
}

void _quickSort(Posic l, Posic h, List list, int getData(void *auxDados, void *aux2Dados)) {
    if (h != NULL && l != h && l != getnextLista(h)) {
        struct CelulaLista *aux = particionaLista(l, h, list, getData);
        _quickSort(l, getpreviousLista(list, aux), list, getData);
        _quickSort(getnextLista(aux), h, list, getData);
    }
}

void quickSort(Posic head, List list, int getData(void *auxDados, void *aux2Dados)) {
    struct CelulaLista *h = getlastLista(list);
    _quickSort(head, h, list, getData);
}

void removeElementosIguaisSortedList(List list) {
    CelulaLista *celulaAtual = getheadLista(list);

    void *dataCelulaAnterior = getdataList(celulaAtual);
    celulaAtual = getnextLista(celulaAtual);
    while (celulaAtual) {
        // printf("%s(%p) %s(%p)\n", getVerticeId(getdataList(celulaAtual)), getdataList(celulaAtual), getVerticeId(dataCelulaAnterior), dataCelulaAnterior);
        if (getdataList(celulaAtual) == dataCelulaAnterior)
            RemoveCelulaLista(list, getdataList(celulaAtual));
        else
            dataCelulaAnterior = getdataList(celulaAtual);
        celulaAtual = getnextLista(celulaAtual);
    }
}

void removeTodosElementosLista(List list) {
    CelulaLista *celulaAtual = getheadLista(list);

    while (celulaAtual) {
        RemoveCelulaLista(list, celulaAtual->Dados);
        free(celulaAtual->Dados);
        free(celulaAtual);

        celulaAtual = getnextLista(celulaAtual);
    }
}
