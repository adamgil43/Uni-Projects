#pragma once

#include "stdafx.h"
#include <iostream>
bool destroyed = false;

bool checkifTrue(bool nodeDest)
{
	if (nodeDest == true) return true;
	else return false;
}

/*
Class that will give a node a value, a left pointer and a right pointer; pointers
point to the location of the next node and the value is the data inside that node.
*/

class BinTreeNode {
public:
	BinTreeNode(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	int value;
	BinTreeNode* left;
	BinTreeNode* right;
	~BinTreeNode()
	{
		bool destroyed = true;
		checkifTrue(destroyed);
	}

};


/*
Inserting a value in a tree by seeing if its larger or smaller than the
parent and then decides whether to put it to the left or right.

The way you insert into a binary tree will affect its structure.
*/
BinTreeNode* tree_insert(BinTreeNode* tree, int item) {
	if (tree == NULL)
		tree = new BinTreeNode(item);
	else
		if (tree->value > item)
			if (tree->left == NULL)
				tree->left = new BinTreeNode(item);
			else
				tree_insert(tree->left, item);
		else
			if (tree->right == NULL)
				tree->right = new BinTreeNode(item);
			else
				tree_insert(tree->right, item);
	return tree;

}
/*
Traverse through the tree recursivley to find
if a node is the tree.
*/

int countChild(BinTreeNode* tree)
{
	int count = 0;

	if (tree->left != 0)
	{
		count++;
	}
	if (tree->right != 0)
	{
		count++;
	}
	return count;
}
/*
Funcion to find the lowest value node on the right hand side of the tree
*/
BinTreeNode* minimumNode(BinTreeNode* tree)
{
	while (tree->left != NULL)
	{
		tree = tree->left;
	}
	return tree;
}
/*
Function that deletes nodes from the tree
*/
BinTreeNode* deleteNode(BinTreeNode* tree, int target)
{
	//finds out where the target is in the tree, if its in the tree.
	if (tree == NULL)
	{
		return tree;
	}
	//if the target is less than the current tree value then move down to the left of the tree.
	else if (target < tree->value)
	{
		tree->left = deleteNode(tree->left, target);
	}
	//if the target is greater than the current value then move down the tree on the right.
	else if (target > tree->value)
	{
		tree->right = deleteNode(tree->right, target);
	}
	//Delete node once value is found
	else
	{
		int children = countChild(tree);
		if (children == 0) // If node has no children just delete.
		{
			delete tree;
			tree = NULL; //Tree stille exists in memory so set that location to NULL;
			return tree;
		}
		//if node has 1 child change the pointer and then delete the temp
		else if (children == 1)
		{
			if (tree->left == NULL)
			{
				BinTreeNode* temp = tree;
				tree = tree->right;
				delete temp;
				return tree;
			}
			else if (tree->right == NULL)
			{
				BinTreeNode* temp = tree;
				tree = tree->left;
				delete temp;
				return tree;
			}
		}
		//if tree has 2 children, swap the values round with highest or lowest and then delete the replaced node
		else
		{
			BinTreeNode* temp = minimumNode(tree->right);
			tree->value = temp->value;
			tree->right = deleteNode(tree->right, temp->value);
		}
	}
	return tree;
}


void postorder(BinTreeNode* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	std::cout << tree->value << std::endl;

}

void in_order(BinTreeNode* tree) {
	if (tree->left != NULL)
		in_order(tree->left);
	std::cout << tree->value << std::endl;
	if (tree->right != NULL)
		in_order(tree->right);
}