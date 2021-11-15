#ifndef FUNCOESQRY_H
#define FUNCOESQRY_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

void catac(Tree avl, Tabela quadrasHash, Graph grafo, double x, double y, double w, double h, void *Stvar, char *path4, void *listaSvg);
void catacRec(Tree avl, Posic celulaAtual, Tabela quadrasHash, double x, double y, double w, double h, void *Stvar, void *qry, int *verificador, void *listaSvg);
void *PercorreLista(Tabela tabela, char *chave, char *getData(void *auxDados));
double *calculaEndereco(Tree avl, Tabela quadrasHash, char *cep, char face, int numero);

/**/
#endif