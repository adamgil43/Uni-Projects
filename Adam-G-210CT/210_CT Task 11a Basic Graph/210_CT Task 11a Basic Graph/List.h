/*
source of original code http://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/
Code below is an object oriented version of the original code
Comments are my own words describing what each class and function does.
*/

#pragma once
#include <iostream>

using namespace std;

/*
A class to represent an adjacency list Node
*/
class AdjNode {
public:
	int dest;
	AdjNode* next;
	AdjNode()
	{
		this->dest;
		this->next = NULL;
	}
};

/*
A class to repesent the adjacency list.
*/
class AdjList
{
public:
	AdjNode* head;	
};
/*
A class to represent the graph
Where the size of the array will be V
*/
class Graph {
public:
	int V;
	AdjList* array;
	Graph(int V)
	{
		this->V = V;
		this->array = new AdjList[V];
	}
};

Graph* createGraph(int V)
{
	Graph* graph = new Graph(V);
	for (int i = 0; i < V; i++)
	{
		graph->array[i].head = NULL;
	}
	return graph;
}

AdjNode* newAdjNode(int dest)
{
	AdjNode* newNode = new AdjNode;
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

void addEdge(Graph* graph, int src, int dest)
{
	AdjNode* newNode = newAdjNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

void printGraph(Graph* graph)
{
	//For loop goes each object that is the list, Vertice 1 would be an object
	for (int v = 0; v < graph->V; v++)
	{
		//While loop goes through the list connected to the object and prints out the results
		AdjNode* trav = graph->array[v].head;
		cout << "Adjacency list of vertex " << v;
		cout << "\n head ";
		while (trav)
		{
			cout << " -> " << trav->dest;
			trav = trav->next;
		}
		cout << endl;
	}
}

int checkGraph(Graph* graph, int vertice, int location, int length)
{
	int v = vertice;
	if (length < vertice) return -1;
	AdjNode* current = graph->array[v].head;
	int count = 1;
	while (current != NULL)
	{
		if (count == location)
		{
			return current->dest;
		}
		count++;
		current = current->next;
	}
	return -1;
}