// Linked Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* prev;
	Node* head;
	
public:



	void insert(int x)
	{
		Node* temp = new Node;
		temp->data = x;
		temp->next = head;
		head = temp;
	}
	void deleteDubs(struct Node *start)
	{
		struct Node *temp1, *temp2, *dup;
		temp1 = start;
		while (temp1 != NULL & )
	}
};

int main()
{
	Node* head = new Node();
	cout << "How many numbers?\n";
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter a number\n";
		cin >> x;
		head->Insert(x);
	}
	head->print();
	std::cin.get();
    return 0;
}

