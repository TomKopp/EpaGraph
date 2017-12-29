#pragma once

#include "stdafx.h"

// A structure to represent an adjacency list node
typedef struct AdjListNode {
	int dest;
	struct AdjListNode* next;
};

// A structure to represent an adjacency list
typedef struct AdjList {
	AdjListNode * head; // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
typedef struct Graph2 {
	size_t n;
	AdjList * adj;
};

AdjListNode * createAdjListNode(int dest) {
	AdjListNode * node = (AdjListNode *)malloc(sizeof(AdjListNode));

	node->dest = dest;
	node->next = NULL;

	return node;
}

Graph2 * createGraph2(size_t nodes) {
	Graph2 * graph = (Graph2 *)malloc(sizeof(Graph2));

	graph->adj = (AdjList *)malloc(nodes * sizeof(AdjList));

	graph->n = nodes;
	for (size_t i = 0; i < nodes; ++i) {
		graph->adj[i].head = NULL;
	}

	return graph;
}

void addEdge(Graph2* g, int v1, int v2) {
	AdjListNode * node = (AdjListNode *)malloc(sizeof(AdjListNode));

	node->dest = v2;
	node->next = g->adj[v1].head;
	g->adj[v1].head = node;

	return;
}

void removeEdge(Graph2 * g, int v1, int v2) {
	if (
		v1 < g->n
		&& v2 < g->n
		) {
		AdjListNode * prev = NULL;
		AdjListNode * node = g->adj[v1].head;

		while (node != NULL) {
			if (node->dest == v2) {
				if (prev == NULL) {
					g->adj[v1].head = node->next;
				}
				else {
					prev->next = node->next;
				}

				free(node);

				return;
			}

			prev = node;
			node = node->next;
		}
	}
}

bool testEdge(Graph2 * g, int v1, int v2) {
	if (
		v1 < g->n
		&& v2 < g->n
		) {
		AdjListNode * node = g->adj[v1].head;

		while (node != NULL) {
			if (node->dest == v2)
				return true;
			node = node->next;
		}
	}

	return false;
}

void printGraph(Graph2 * g) {
	printf("\n");
	for (size_t i = 0; i < g->n; i++) {
		AdjListNode * node = g->adj[i].head;

		printf("\nv%d ", i);

		while (node != NULL) {
			printf("-> v%d", node->dest);
			node = node->next;
		}
	}
}
