// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

class Node {
public:
	int data;
	Node* next;
	std::list<int> *AdjNodes;
	Node() {
		this->data = data;
		this->next = NULL;
		AdjNodes = new std::list<int>;
	}

	void addEdge(int d, int s)
	{" -> "
		AdjNodes[d].push_back(s);
		AdjNodes[s].push_back(d);
	}
};


class Graph {
public:
	int V;
	std::list<int> *Vertices;
	Graph(int V)
	{
		this->V = V;
		Vertices = new std::list<int>[V];
	}
};

int main()
{
	List* L = new List();
	L->createNode(0);
	L->createNode(1);
	L->createNode(2);
	L->createNode(3);
	L->createNode(4);
	L->displayNode();
    return 0;
}

