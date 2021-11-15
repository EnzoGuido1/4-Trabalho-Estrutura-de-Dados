#include "avl.h"
#include "lista.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"

Tabela criaTabela(int nx);
void insereRegistro(Tabela tabelaEspelhamento, char *string, void *dadoLista);
Posic getRegistro(Tabela tabela, char *chave);
void *retornaRegistroLista(Tabela tabela, int index);
void removeChave(Tabela tabela, char *chave);
void freeRegistro(Tabela tabela, int tipo);

/**/
#endif