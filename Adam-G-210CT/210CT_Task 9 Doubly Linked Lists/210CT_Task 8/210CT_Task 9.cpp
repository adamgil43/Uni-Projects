#include "stdafx.h"
#include <iostream>
#include "Node.h"
//Nodes and lists use public data members for convenience
//This may make some software engineers froth at the mouth


/*What is a doubly linked list?

A doubly linked list is a data structure that stores items in order, accessed by index and without gaps,
it is continous but does not use continous memory, meaning you can keep on adding data to a doubly linked list.

*/


int main(int argc, char *argv[])
{
	int length;
	int number;
	List* l = new List();
	List* newList = new List();
	int myArr[7] = { 1,1,1,1,1,1,1 };
	for (int i = 0; i < 7; i++)
	{
		if (i == 0) l->insert(0, new Node(myArr[i]));
		else l->insert(l->head, new Node(myArr[i]));
	}
	l->display();
	l->head->value;
	printf("\n");
	l->display();
	l->removeDuplicates();
	l->display();
	delete l;
	return 0;
}