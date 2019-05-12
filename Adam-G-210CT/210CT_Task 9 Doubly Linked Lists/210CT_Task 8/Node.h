/*
The code to make a doubly linekd list is not my code, this code was found on the Coventry University
moodle website, 
*/

#pragma once
#include <iostream>

class Node
{
public:
	int value; //This could really be any type
	Node* next;
	Node* prev;
	Node(int val) {
		std::cout << "Node constructr!" << std::endl;
		this->value = val;
		this->next = (Node*)0; // holds memory location of next
		this->prev = (Node*)0; // holds memory location of prev
	}
	~Node() {
		std::cout << "Node destructor" << std::endl;
		std::cout << "I had the value " << this->value << std::endl;
	}
};

class List
{

public:
	Node* head;
	Node* tail;

	List() {
		std::cout << "List Constructor!" << std::endl;
		this->head = 0; //holds memory locaton of head
		this->tail = 0; //holds memory location of tail
	}
	~List() {
		std::cout << "List destructor!" << std::endl;
	}
	//Node Deletion
	void deleteNodes(Node *deletedNode)
	{
		if (head == NULL || deletedNode == NULL) return;
		//if the head node is the deleted node, then change the head node to the next node
		if (head == deletedNode) head = deletedNode->next;
		//Will only work if not last node in the list
		if (deletedNode->next != NULL) deletedNode->next->prev = deletedNode->prev;
		//Will only work if not first node in the list
		if (deletedNode->prev != NULL) deletedNode->prev->next = deletedNode->next;
		delete(deletedNode);
	}
	//Look for duplicates and then send them to be deleted.
	void removeDuplicates()
	{
		Node *firstPtr, *nextPtr;
		//Pick the numbers out by going through a for loop
		//if you sued a while a loop here, if you point to the next node but you've deleted that node
		//then it will throw a memory violation
		for (firstPtr = head; firstPtr != NULL; firstPtr = firstPtr->next)
		{
			nextPtr = firstPtr->next;
			while (nextPtr != NULL)
			{
				if (firstPtr->value == nextPtr->value)
				{
					Node* next = nextPtr->next;
					deleteNodes(nextPtr);
					nextPtr = next;
				}
				else nextPtr = nextPtr->next;
			}
		}

	}


	//node n indicates if its the start of the node, node x is the value.
	void insert(Node* n, Node* x) {
		if (n != 0) {
			x->next = n->next;
			n->next = x;
			x->prev = n;
			if (x->next != 0)
				x->next->prev = x;
		}
		if (this->head == 0) {
			this->head = x;
			this->tail = x;
			x->prev = 0;
			x->next = 0;
		}
		else if (this->tail == n) {
			this->tail = x;
		}
	}

	void display() {
		Node* i = this->head;
		std::cout << "List: ";
		while (i != 0) {
			std::cout << i->value << ",";
			i = i->next;
		}
		std::cout << std::endl;
	}
};