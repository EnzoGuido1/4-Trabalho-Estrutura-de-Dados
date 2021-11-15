#ifndef LEITURA_H
#define LEITURA_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

char *concertaPath(char *path1, char *path2, int verificadorPath1);
char *concertaPathOutput(char *path1, char *path2);
void leituraParametros(int argc, char **argv, void *Stvar);
void *leituraGeo(Tree avl, void *Stvar);
// void leituraPm(Tree avl, Tabela pessoas, Tabela locacoes, Tabela quadrasHash, void *Stvar);
// char *leituraQry(Tree avl, Tabela pessoas, Tabela locacoes, Tabela quadrasHash, void *listaSvg, void *Stvar);

/**/
#endif