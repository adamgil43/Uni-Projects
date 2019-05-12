#pragma once
#include "../210_CT Task 11a Basic Graph/List.h"

Graph* makeGraph(int V)
{
	int v = V;
	Graph* newGraph = createGraph(v);
	addEdge(newGraph, 1, 3);
	addEdge(newGraph, 1, 4);
	addEdge(newGraph, 1, 5);
	addEdge(newGraph, 2, 3);
	addEdge(newGraph, 2, 4);
	addEdge(newGraph, 2, 5);
	addEdge(newGraph, 3, 5);
	addEdge(newGraph, 4, 5);
	return newGraph;
}
