// 210_CT Task 11a Basic Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WeightedGraph.h"
using namespace std;

/*
An Adjacency list
An array of linked lists is used
Size of array is equal to number of virticies
let array = array[]
An entry array[i] represents the linked list of verticies adjacent to the ith vertex

*/

int main()
{
	int V = 5;
	int start = 1;
	if (start == 1)
	{
		V++;
	}
	Graph* newGraph = createGraph(V);
	addEdge(newGraph, 0, 2);
	addEdge(newGraph, 0, 3);
	addEdge(newGraph, 0, 4);
	addEdge(newGraph, 1, 2);
	addEdge(newGraph, 1, 3);
	addEdge(newGraph, 1, 4);
	addEdge(newGraph, 2, 4);
	addEdge(newGraph, 3, 4);
	printGraph(newGraph);
	cin.get();
	return 0;
}

