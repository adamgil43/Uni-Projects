// Stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>

void dfs(Graph* graph, int V)
{
	int u = 0;
	stack<int> stack;
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	stack.push(V);
	while (!stack.empty())
	{
		u = stack.top();
		stack.pop();
		if (!visited[u])
		{

			for (int v = u; v < graph->V; v++)
			{

			}
		}
	}
}

int main()
{
	int u = 0;
    return 0;
}

