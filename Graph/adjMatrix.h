#pragma once

#include "stdafx.h"

typedef struct graph {
	int** adj; /**< Adjacency matrix. */
	int n; /**< Number of nodes in graph. */
} Graph;

Graph *createGraph(int nodes) {
	int r = nodes, c = nodes, i, j, count;
	Graph * tmp = (Graph*)malloc(sizeof(Graph));

	tmp->adj = (int **)malloc(sizeof(int *) * r);
	tmp->adj[0] = (int *)malloc(sizeof(int) * c * r);

	for (i = 0; i < r; i++) {
		tmp->adj[i] = (*tmp->adj + c * i);
	}

	tmp->n = nodes;
	//count = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			//tmp->adj[i][j] = ++count;
			tmp->adj[i][j] = 0;
		}
	}

	return tmp;
}

void printAdjMatrix(Graph * g) {
	int r = g->n, c = g->n, i, j;

	for (i = 0; i < r; i++) {
		printf("\n");
		for (j = 0; j < c; j++) {
			printf("%d\t", g->adj[i][j]);
		}
	}
	printf("\n");
}

void addEdge(Graph * g, int v1, int v2) {
	if (v1 < g->n && v2 < g->n)
		g->adj[v1][v2] = 1;

	return;
}

void removeEdge(Graph * g, int v1, int v2) {
	if (v1 < g->n && v2 < g->n)
		g->adj[v1][v2] = 0;

	return;
}

bool testEdge(Graph * g, int v1, int v2) {
	if (g->adj[v1][v2] > 0)
		return true;

	return false;
}
