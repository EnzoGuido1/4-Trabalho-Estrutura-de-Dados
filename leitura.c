#include "leitura.h"

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
#include "lista.h"
#include "parametrosData.h"
#include "quadrasData.h"
#include "verticeData.h"

//set para os parametros passados
void setVarEntrada(void *Svar, char *Entrada);
void setVarSaida(void *Svar, char *Saida);
void setVarGeo(void *Svar, char *Geo);
void setVarQry(void *Svar, char *Qry);
void setVarVia(void *Svar, char *Via);
void setVarEntradaVerifica(void *Svar, int cont);
void setVarSaidaVerifica(void *Svar, int cont);
void setVarGeoVerifica(void *Svar, int cont);
void setVarQryVerifica(void *Svar, int cont);
void setVarViaVerifica(void *Svar, int cont);
void setVarNx(void *Svar, int cont);

//set para as structs de dados quadras
void setDataCep(void *Sdata, char *Scep);
void setDataCorC(void *Sdata, char *ScorC);
void setDataCorP(void *Sdata, char *ScorP);
void setDataX(void *Sdata, double Sx);
void setDataY(void *Sdata, double Sy);
void setDataW(void *Sdata, double Sw);
void setDataH(void *Sdata, double Sh);
void setDataSw(void *Sdata, double Ssw);

void setVerticeData(void *Vertice, void *data);

char *concertaPath(char *path1, char *path2, int verificadorPath1) {
    char *path;
    if (verificadorPath1 == 1) {  //faz o ajuste do path de leitura
        path = calloc(strlen(path1) + strlen(path2) + 2, sizeof(char));
        strcpy(path, path1);
        strcat(path, "/");
        strcat(path, path2);
    } else {
        path = calloc(strlen(path2) + 1, sizeof(char));
        strcpy(path, path2);
    }
    return path;
}

char *concertaPathOutput(char *path1, char *path2) {
    char *path;
    path = calloc(strlen(path1) + strlen(path2) + 2, sizeof(char));
    strcpy(path, path1);
    strcat(path, "/");
    int verificador = 0;
    for (int i = 0; i < strlen(path2); i++) {
        if (path2[i] == '/')
            verificador = 1;
    }
    char path5[500] = " ";
    int cont = 0;
    for (int j = 0; j < strlen(path2); j++) {
        if (path2[j] == '.')
            break;
        if (verificador == 0) {
            path5[cont] = path2[j];
            cont++;
        }
        if (path2[j] == '/')
            verificador = 0;
    }
    strcat(path, path5);
    return path;
}

void leituraParametros(int argc, char **argv, void *Stvar) {
    setVarEntradaVerifica(Stvar, 0);
    setVarGeoVerifica(Stvar, 0);
    setVarQryVerifica(Stvar, 0);
    setVarSaidaVerifica(Stvar, 0);
    setVarViaVerifica(Stvar, 0);

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-e")) {
            setVarEntrada(Stvar, argv[i + 1]);
            setVarEntradaVerifica(Stvar, 1);
        }
        if (!strcmp(argv[i], "-f")) {
            setVarGeo(Stvar, argv[i + 1]);
            setVarGeoVerifica(Stvar, 1);
        }
        if (!strcmp(argv[i], "-o")) {
            setVarSaida(Stvar, argv[i + 1]);
            setVarSaidaVerifica(Stvar, 1);
        }
        if (!strcmp(argv[i], "-q")) {
            setVarQry(Stvar, argv[i + 1]);
            setVarQryVerifica(Stvar, 1);
        }
        if (!strcmp(argv[i], "-v")) {
            setVarVia(Stvar, argv[i + 1]);
            setVarViaVerifica(Stvar, 1);
        }
    }
}

void *leituraGeo(Tree avl, void *Stvar) {
    void *dados;
    void *quadrasHash;
    int contNx = 0;
    char funcao[100], cep[100], corc[30], corp[30];
    double x, y, w, h, sw;

    char *svgGeo = concertaPathOutput(getVarSaida(Stvar), getVarGeo(Stvar));
    strcat(svgGeo, ".svg");
    FILE *inicializaSvg = fopen(svgGeo, "w");
    fprintf(inicializaSvg, "<svg xmlns=\"http://www.w3.org/2000/svg\">  <!--ENZO GUIDO-->");

    char *path2 = concertaPath(getVarEntrada(Stvar), getVarGeo(Stvar), getVarEntradaVerifica(Stvar));

    FILE *geo = fopen(path2, "r");
    while (fscanf(geo, "%s", funcao) != -1) {
        if (!strcmp(funcao, "q"))
            contNx++;
    }
    fclose(geo);

    quadrasHash = criaTabela(contNx / 3);

    geo = fopen(path2, "r");
    while (fscanf(geo, "%s", funcao) != -1) {
        if (!strcmp(funcao, "cq")) {  //leitura comando cq
            fscanf(geo, "%lf", &sw);  // seta a grossura da borda da quadra

            fscanf(geo, "%s", funcao);  //leitura cor de preenchimento
            if (!strcmp(funcao, "@")) {
                strcpy(corp, "none");
            } else {
                strcpy(corp, funcao);
            }

            fscanf(geo, "%s", funcao);  //leitura cor de contorno
            if (!strcmp(funcao, "@")) {
                strcpy(corc, "none");
            } else {
                strcpy(corc, funcao);
            }

        } else if (!strcmp(funcao, "q")) {
            fscanf(geo, "%s", funcao);
            strcpy(cep, funcao);

            fscanf(geo, "%lf", &x);
            fscanf(geo, "%lf", &y);
            fscanf(geo, "%lf", &w);
            fscanf(geo, "%lf", &h);

            dados = callocDataQuadra(cep, corc, corp, x, y, w, h, sw);

            InsereElementoRec(avl, dados);

            insereRegistro(quadrasHash, cep, dados);

            ImprimeRect(corc, corp, x, y, w, h, sw, inicializaSvg);
        }
    }
    fprintf(inicializaSvg, "\n</svg>");

    fclose(geo);
    fclose(inicializaSvg);

    free(path2);
    free(svgGeo);

    return quadrasHash;
}

void leituraVia(Graph grafo, void *Stvar) {
    if (getVarViaVerifica(Stvar) == 0)
        return;

    char funcao[100], id[100], nome[100], ldir[100], lesq[100], i[100], j[100];
    double cmp, vm, x, y;
    int nv;
    int contVerticeAtual = 0;

    char *path2 = concertaPath(getVarEntrada(Stvar), getVarVia(Stvar), getVarEntradaVerifica(Stvar));

    FILE *via = fopen(path2, "r");

    fscanf(via, "%d", &nv);
    criaGrafo(nv);

    while (fscanf(via, "%s", funcao) != -1) {
        if (!strcmp(funcao, "v")) {
            fscanf(via, "%s", funcao);
            strcpy(id, funcao);
            fscanf(via, "%lf", &x);
            fscanf(via, "%lf", &y);

            void *vertice = getVertice(grafo, contVerticeAtual);
            void *dados = callocDataVertice(id, x, y);
            setVerticeData(vertice, dados);
            contVerticeAtual++;

        } else if (!strcmp(funcao, "e")) {  //leitura comando cq
            fscanf(via, "%s", funcao);
            strcpy(i, funcao);
            fscanf(via, "%s", funcao);
            strcpy(j, funcao);
            fscanf(via, "%s", funcao);
            strcpy(ldir, funcao);
            fscanf(via, "%s", funcao);
            strcpy(lesq, funcao);
            fscanf(via, "%lf", &cmp);
            fscanf(via, "%lf", &vm);
            fscanf(via, "%s", funcao);
            strcpy(nome, funcao);

            void *dados = callocDataAresta(nome, ldir, lesq, cmp, vm, getVertice(grafo, percorre_Vertices(grafo, j)), getVertice(grafo, percorre_Vertices(grafo, i)));
            insere_Aresta(grafo, i, j, dados);
        }
    }
    fclose(via);

    free(path2);
}

char *leituraQry(Tree avl, Tabela pessoas, Tabela locacoes, Tabela quadrasHash, void *listaSvg, void *Stvar) {
    if (getVarQryVerifica(Stvar) == 0)
        return "NULL";

    char funcao[100];
    // char funcao[100], cpf[100], complexo[100], cep[100], id[100], face, sfx[200];
    // int numero;
    // double area, vMensais, x, y, w, h;

    char *path2 = concertaPath(getVarEntrada(Stvar), getVarQry(Stvar), getVarEntradaVerifica(Stvar));
    char *path3 = concertaPathOutput(getVarSaida(Stvar), getVarGeo(Stvar));
    char path4[500] = " ";  //path com o nome correto da saída do txt do qry
    strcpy(path4, path3);
    free(path3);
    strcat(path4, "-");
    path3 = getVarQry(Stvar);
    int verificador = 0;
    for (int i = 0; i < strlen(getVarQry(Stvar)); i++) {
        if (path3[i] == '/')
            verificador = 1;
    }
    char path5[500] = " ";
    int cont = 0;
    for (int j = 0; j < strlen(path3); j++) {
        if (path3[j] == '.')
            break;
        if (verificador == 0) {
            path5[cont] = path3[j];
            cont++;
        }
        if (path3[j] == '/')
            verificador = 0;
    }
    strcat(path4, path5);
    char *saidaGeo = calloc(strlen(path4) + 10, sizeof(char));
    strcpy(saidaGeo, path4);
    strcat(saidaGeo, ".svg");
    strcat(path4, ".txt");

    FILE *inicializaTxt = fopen(path4, "w");
    fclose(inicializaTxt);

    FILE *qry = fopen(path2, "r");

    while (fscanf(qry, "%s", funcao) != -1) {
        if (!strcmp(funcao, "@o?")) {
            //comentario
        } else if (!strcmp(funcao, "catac")) {
            //comentario
        } else if (!strcmp(funcao, "rv")) {
            //comentario
        } else if (!strcmp(funcao, "cx")) {
            //comentario
        } else if (!strcmp(funcao, "p?")) {
            //comentario
        }
    }
    fclose(qry);

    free(path2);

    return saidaGeo;
}
