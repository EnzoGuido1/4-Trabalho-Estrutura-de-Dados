#include "imprimeSvg.h"

#include "arestaData.h"
#include "avl.h"
#include "declaracoes.h"
#include "digrafo.h"
#include "dijkstra.h"
#include "filaPrioridade.h"
#include "funcoesQry.h"
#include "hashTable.h"
#include "kruskal.h"
#include "leitura.h"
#include "lista.h"
#include "parametrosData.h"
#include "quadrasData.h"
#include "verticeData.h"

void ImprimeRect(char* corc, char* corp, double x, double y, double w, double h, double sw, void* path) {
    fprintf(path, "\n\t<rect x=\"%.2lf\" y=\"%.2lf\" width=\"%.2lf\" height=\"%.2lf\" stroke=\"%s\" stroke-width=\"%.2lf\" fill=\"%s\" opacity=\"0.5\"/>", x, y, w, h, corc, sw, corp);
}

void ImprimeLine(char* cor, double x1, double x2, double y1, double y2, void* path) {
    fprintf(path, "\n\t<line x1=\" %.2lf \" x2=\" %.2lf \" y1=\" %.2lf \" y2=\" %.2lf \" stroke=\" %s \" />", x1, x2, y1, y2, cor);
}

void ImprimeCircle(double x, double y, double w, double h, double grossura, char* corc, char* corp, void* path) {
    fprintf(path, "\n\t<circle cx=\"%.2lf\" cy=\"%.2lf\" r=\"%.2lf\" stroke=\"%s\" stroke-width=\"%.2lf\" fill=\"%s\" opacity=\"1\"/>", x, y, (w + h) / 5, corc, grossura, corp);
}