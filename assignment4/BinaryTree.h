#ifndef BINARYTREE_H
#define BINARYTREE_H
/*
• Determine whether the binary tree is empty. DONE
• Search the binary tree for a particular item. DONE
• Insert an item in the binary tree. Inserts as a leaf node. DONE
• Delete an item from the binary tree. DONE
• Find the height of the binary tree. DONE
• Find the number of nodes in the binary tree. DONE
• Find the number of leaves in the binary tree. DONE
• Traverse the binary tree. 3 ways DONE 
• Copy the binary tree. DONE
*/
#include <iostream>
#include <random>
#include <fstream>
using namespace std;


template<class T>
struct nodeType
{
    T data;
    nodeType<T>* left;
    nodeType<T>* right;
    nodeType<T>* parent;
};

template<class T>
class BinaryTree
{
public:    
    bool isEmpty() const;

    int treeHeight(); //still needs to be done

    int treeNodeCount(); //inorder traversal simply counting nodes

    int leafCount(); //inorder traversal until node does not have left or right node 

//deletes a node with the given data
    bool remove(const T & data);

//search. calls private findNode
    bool locate(const T & data, T & fdata);

//insertion. calls private insertNode
    void insert(const T & data); 
    
//constructors
    BinaryTree();
    BinaryTree(const BinaryTree<T> & otherTree);
    ~BinaryTree(); //calls private postOrderDelete

//public traversal functions that print elements
    void inOrderTraverse(fstream & fout);
    void preOrderTraverse(fstream & fout);
    void postOrderTraverse(fstream & fout);

protected:
//root of the tree
    nodeType<T>* root;

private:
//copy
    void copy(const nodeType<T> * root);

//postOrderDelete to delete whole tree
    void postOrderDelete(nodeType<T>* curr);

//locates node with given data
    nodeType<T> * findNode(const T & data, nodeType<T>* root);

//inserts node with data into binary tree
    void insertNode(const T & data, nodeType<T>*& root);

//deletes node with given data
    int deleteNode(const T & data, nodeType<T>*& root);
    void swapDelete(nodeType<T>* & root);

//traverse the binary tree 3 traversals
	void inOrderTraverseWORKER(fstream & fout, nodeType<T> * root, int & counter);
	void preOrderTraverseWORKER(fstream & fout, nodeType<T> * root, int & counter);
	void postOrderTraverseWORKER(fstream & fout, nodeType<T> * root, int & counter);

//inorder traverse for leaf count
    void leafCountTraverse(nodeType<T> * curr, int & leafCount);

//inorder traverse for node count
    void elementCount(nodeType<T> * curr, int & elementCount);

//tree height
    int btHeight(nodeType<T> * root);

};

template<class T>
void BinaryTree<T>::swapDelete(nodeType<T> * & root)
{
    //swap with a child 
    if(root->left == nullptr && root->right == nullptr)
    {
        //delete the root which must be a leaf node
        cout << "About to free node" << endl;
        // root->parent->left = nullptr;
        if(root->parent->left == root)
            root->parent->left =  nullptr;
        else
            root->parent->right = nullptr;
        
    }
    else
    {
        //swap data with one of the childs
        T temp = root->data;
        if(root->left != nullptr)
        {
            root->data = root->left->data;
            root->left->data = temp;
            swapDelete(root->left);
        }
        else
        {
            root->data = root->right->data;
            root->right->data = temp;
            swapDelete(root->right);
        }
    }
}

template<class T>
bool BinaryTree<T>::isEmpty() const
{
    return (root == nullptr);
}
template<class T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template<class T>
void BinaryTree<T>::copy(const nodeType<T> * root)
{
    if(root != nullptr)
    {
        insert(root->data);
        copy(root->left); //preorder traversal
        copy(root->right);
    }
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> & otherTree)
{
    root = nullptr;
    copy(otherTree.root);
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    postOrderDelete(root);
}

template<typename T>
void BinaryTree<T>::inOrderTraverseWORKER(fstream & fout, nodeType<T> * root, int & counter)
{
	if(root == nullptr)
		return;
	inOrderTraverseWORKER(fout, root->left,counter);
	if(counter == 0)
		fout << "In-order Elements:";
	if(counter%5 == 0)
		fout << '\n';
	fout << root->data << '\t';
	counter++;
	inOrderTraverseWORKER(fout, root->right, counter);
}

template<typename T>
void BinaryTree<T>::preOrderTraverseWORKER(fstream & fout, nodeType<T> * root, int & counter)
{
	if(root == nullptr)
		return;
	if(counter == 0)
		fout << "Pre-order Elements:";
	if(counter%5 == 0)
		fout << '\n';
	fout << root->data << '\t';
	counter++;
	preOrderTraverseWORKER(fout, root->left,counter);
	preOrderTraverseWORKER(fout, root->right, counter);
}

template<typename T>
void BinaryTree<T>::postOrderTraverseWORKER(fstream & fout, nodeType<T> * root, int & counter)
{
	if(root == nullptr)
		return;

	postOrderTraverseWORKER(fout, root->left,counter);
	postOrderTraverseWORKER(fout, root->right, counter);
	if(counter == 0)
		fout << "Post-order Elements:";
	if(counter%5 == 0)
		fout << '\n';
	fout << root->data << '\t';
	counter++;
}


template<class T>
void BinaryTree<T>::inOrderTraverse(fstream & fout)
{
    int counter = 0;
    inOrderTraverseWORKER(fout, root, counter);
}

template<class T>
void BinaryTree<T>::preOrderTraverse(fstream & fout)
{
    int counter = 0;
    preOrderTraverseWORKER(fout, root, counter);
}

template<class T>
void BinaryTree<T>::postOrderTraverse(fstream & fout)
{
    int counter = 0;
    postOrderTraverseWORKER(fout, root, counter);
}


template<class T>
nodeType<T>* BinaryTree<T>::findNode(const T & data, nodeType<T>* root)
{
    //data is not sorted so expect O(n) time.
    if(root != nullptr)
    {
        if(data == root->data)
            return root;
        else
        {
            nodeType<T> * foundNode = findNode(data, root->left);
            if(foundNode == nullptr)
            {
                foundNode = findNode(data, root->right);
            }
            return foundNode;
        }
    }
    else    
        return 0;
}

template<class T>
bool BinaryTree<T>::locate(const T & data, T & fdata)
{
    nodeType<T>* foundNode = findNode(data, root);
    if (foundNode != 0)
    {
        fdata = foundNode->data;
        return true;
    }
    else
        return false;
}

template<class T>
int BinaryTree<T>::deleteNode(const T & data, nodeType<T>*& root)
{
    //locating the node we want to delete
    if(root == nullptr )
        return -1;
    else
    {
        if(root->data == data)
        {
            //swap this nodes data with a child below it and continue this process until data is swapped with a leaf
            //node. Then we delete this leaf node.
            swapDelete(root);
        }
        else
        {
            deleteNode(data, root->left);
            deleteNode(data, root->right);
        }
    }
    return 1;

}
template<class T>
bool BinaryTree<T>::remove(const T & data)
{
    if(deleteNode(data, root) == -1)
        return false;
    else return true;
}



template<class T>
void BinaryTree<T>::postOrderDelete(nodeType<T>* curr)
{
    if (curr != nullptr)
    {
        postOrderDelete(curr->left);
        postOrderDelete(curr->right);
        if(curr->parent == nullptr)
            curr = nullptr;
        else if(curr->parent->left == curr)
            curr->parent->left = nullptr;
        else
            curr->parent->right = nullptr;
    }
}

template<class T>
void BinaryTree<T>::insertNode(const T & data, nodeType<T>*& root)
{
    // looks for the first available open leaf starting from root. Does not put in order.
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uid(0,314159);
    if (root == nullptr)
    {
        root = new nodeType<T>;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
    }
    else if(root->left == nullptr)
    {
        root->left = new nodeType<T>;
        root->left->data = data;
        root->left->left = nullptr;
        root->left->right = nullptr;
        root->left->parent = root;
    }
    else if(root->right == nullptr)//open slot to the right
    {
        root->right = new nodeType<T>;
        root->right->data = data;
        root->right->left = nullptr;
        root->right->right = nullptr;
        root->right->parent = root;
    }
    else if(uid(rng)%2 == 0)
        insertNode(data, root->left);
    else   
        insertNode(data, root->right);
}

template<class T>
void BinaryTree<T>::insert(const T & data)
{
    insertNode(data, root);
}

template<class T>
void BinaryTree<T>::leafCountTraverse(nodeType<T> * curr, int & leafCount)
{
    if(curr == nullptr)
        return;
    leafCountTraverse(curr->left, leafCount);
    if(curr->left == nullptr && curr->right == nullptr)
        leafCount++;
    leafCountTraverse(curr->right, leafCount);
}



template<class T>
int BinaryTree<T>::leafCount()
{
    int leafCount = 0;
    leafCountTraverse(root, leafCount);
    return leafCount;
}


template<class T>
void BinaryTree<T>::elementCount(nodeType<T> * curr, int & counter)
{
    if(curr == nullptr)
        return;
    elementCount(curr->left, counter);
    counter++;
    elementCount(curr->right, counter);
}


template<class T>
int BinaryTree<T>::treeNodeCount()
{
    int counter = 0;
    elementCount(root, counter);
    return counter;
}

template<class T>
int BinaryTree<T>::btHeight(nodeType<T> * root)
{
    if(root == nullptr)
        return 0;
    else
    {
        int leftHeight = btHeight(root->left);
        int rightHeight = btHeight(root->right);
        if(leftHeight>rightHeight)
            return leftHeight+1;
        else    
            return rightHeight+1;
    }
}

template<class T>
int BinaryTree<T>::treeHeight()
{
    return btHeight(root);
}

















#endif