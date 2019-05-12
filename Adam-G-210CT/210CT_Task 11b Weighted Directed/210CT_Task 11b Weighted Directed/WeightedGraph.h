#pragma once

#include "stdafx.h"
#include <iostream>

/*
Class that will give a node a value, a left pointer and a right pointer; pointers
point to the location of the next node and the value is the data inside that node.
*/

class Node {
public:
	int dest;
	Node* next;
	Node(int dest) {
		this->dest = dest;
		this->next = NULL;
	}
};

class List {
public:
	Node* head;
};

class Graph {
public:
	int V;
	List* array;
	Graph(int V)
	{
		this->V = V;
		this->array = new List[V];
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

Node* newNode(int dest)
{
	Node* newNode = new Node(dest);
	return newNode;
}

void addEdge(Graph* graph, int src, int dest)
{
	Node* newNode = new Node(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = new Node(src);
	newNode->next = graph->array[dest].head;
	graph->array[src].head = newNode;
}

void printGraph(Graph* graph)
{
	for (int v = 0; v < graph->V; v++)
	{
		Node* traverse = graph->array[v].head;
		std::cout << "\n Adjacency List  of vertex " << v << "\nhead ";
		while (traverse)
		{
			std::cout << "-> " << traverse->dest;
			traverse = traverse->next;
		}
		std::cout << "\n";
	}
}