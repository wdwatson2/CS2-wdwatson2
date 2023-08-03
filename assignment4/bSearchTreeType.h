#ifndef H_binarySearchTree
#define H_binarySearchTree

#include <iostream>
#include <cassert>
#include <fstream>
#include "BinaryTree.h"
using namespace std;
template<class elemType>
class bSearchTreeType: public BinaryTree<elemType>
{
public:
    bool locate(const elemType& searchItem) const;
    void insert(const elemType& insertItem);
    void remove(const elemType& deleteItem);
};

template<typename elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
	if(this->root == nullptr)
	{
		this->root = new nodeType<elemType>;
        this->root->data = insertItem;
        this->root->left = nullptr;
        this->root->right = nullptr;
        this->root->parent = nullptr;
	}
	else
	{
		// Locate the parent node
		nodeType<elemType>* parentguy = nullptr;
		nodeType<elemType>* current = this->root;
		while (current != nullptr)
		if (insertItem <= current->data)
		{
			parentguy = current;
			current = current->left;
		}
		else if (insertItem >= current->data)
		{
			parentguy = current;
			current = current->right;
		}

		// Create the new node and attach it to the parent node
		if (insertItem < parentguy->data)
		{
			parentguy->left = new nodeType<elemType>;
			parentguy->left->data = insertItem;
			parentguy->left->left = nullptr;
			parentguy->left->right = nullptr;
			parentguy->left->parent = parentguy;
		}
		else
		{
			parentguy->right = new nodeType<elemType>;
			parentguy->right->data = insertItem;
			parentguy->right->left = nullptr;
			parentguy->right->right = nullptr;
			parentguy->right->parent = parentguy;
		}
	}
}

//almost line to line from Revel
template<typename elemType>
bool bSearchTreeType<elemType>::locate(const elemType& searchItem) const
{  
    nodeType<elemType> * current = this->root; // Start from the root

    while (current != nullptr)
        if (searchItem < current->data)
        {
            current = current->left; // Go left
        }
        else if (searchItem > current->data)
        {
            current = current->right; // Go right
        }
        else 
            return true;

    return false; 
}

template<typename elemType>
void bSearchTreeType<elemType>::remove(const elemType& deleteItem)
{
	// Locate the node to be deleted and also locate its parent node
	nodeType<elemType>* parentguy = nullptr;
	nodeType<elemType>* current = this->root;
	while (current != nullptr)
	{
		if (deleteItem < current->data)
		{
			parentguy = current;
			current = current->left;
		}
		else if (deleteItem > current->data)
		{
			parentguy = current;
			current = current->right;
		}
		else
			break; 
	}

	if (current == nullptr)
		return; 

	// Case 1: current has no left children
	if(current->left == nullptr)
	{
		// Connect the parent with the right child of the current node
		if (parentguy == nullptr)
		{
			this->root = current->right;
		}
		else
		{
		if (deleteItem < parentguy->data)
			parentguy->left = current->right;
		else
			parentguy->right = current->right;
		}

		delete current; // Delete current
	}
	else
	{
		// Case 2: The current node has a left child
		// Locate the rightmost node in the left subtree of
		// the current node and also its parent
		nodeType<elemType>* parentOfRightMost = current;
		nodeType<elemType>* rightMost = current->left;

		while (rightMost->right != nullptr)
		{
			parentOfRightMost = rightMost;
			rightMost = rightMost->right; // Keep going to the right
		}

		// Replace the element in current by the element in rightMost
		current->data = rightMost->data;

		// Eliminate rightmost node
		if (parentOfRightMost->right == rightMost)
			parentOfRightMost->right = rightMost->left;
		else
		// Special case: parentOfRightMost->right == current
		parentOfRightMost->left = rightMost->left;

		delete rightMost; // Delete rightMost
	}

}


#endif