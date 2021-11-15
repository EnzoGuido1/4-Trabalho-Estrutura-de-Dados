CC = gcc
TS = -Wall -g -fstack-protector-all -std=c99

all: t2
	rm *.o

t2: main.o arestaData.o avl.o digrafo.o dijkstra.o filaPrioridade.o funcoesQry.o hashTable.o imprimeSvg.o kruskal.o leitura.o lista.o parametrosData.o quadrasData.o verticeData.o
	$(CC) $(TS) main.o arestaData.o avl.o digrafo.o dijkstra.o filaPrioridade.o funcoesQry.o hashTable.o imprimeSvg.o kruskal.o leitura.o lista.o parametrosData.o quadrasData.o verticeData.o -o t2 -lm

main1.o: main.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c main.c

arestaData.o: arestaData.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c arestaData.c

avl.o: avl.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c avl.c

digrafo.o: digrafo.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c digrafo.c

dijkstra.o: dijkstra.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c dijkstra.c

filaPrioridade.o: filaPrioridade.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c filaPrioridade.c
	
funcoesQry.o: funcoesQry.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c funcoesQry.c

hashTable.o: hashTable.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c hashTable.c

imprimeSvg.o: imprimeSvg.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c imprimeSvg.c

kruskal.o: kruskal.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c kruskal.c

leitura.o: leitura.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c leitura.c

lista.o: lista.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c lista.c

parametrosData.o: parametrosData.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c parametrosData.c

quadrasData.o: quadrasData.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c quadrasData.c

verticeData.o: verticeData.c arestaData.h avl.h declaracoes.h digrafo.h dijkstra.h filaPrioridade.h funcoesQry.h hashTable.h imprimeSvg.h kruskal.h leitura.h lista.h parametrosData.h quadrasData.h verticeData.h
	$(CC) $(TS) -c verticeData.c