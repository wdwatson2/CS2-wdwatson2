// // Search for "WRITE YOUR CODE" to complete this program
// #ifndef ArrayList_H
// #define ArrayList_H
// #include <stdexcept>
// #include <iostream>
// #include <string>
// using namespace std;

// template<typename T>
// class Iterator : public std::iterator<std::forward_iterator_tag, T>
// {
// public:
//   Iterator(int index, T* list)
//   {
//     this->list = list;
//     cursor = index;
//   }

//   Iterator operator++() // Prefix ++s
//   {
//     cursor++;
//     return *this;
//   }

//   Iterator operator++(int dummy) // Postfix ++
//   {
//     Iterator temp(*this);
//     cursor++;
//     return temp;
//   }

//   T& operator*()
//   {
//     return list[cursor];
//   }

//   bool operator==(const Iterator<T>& iterator)
//   {
//     return list[cursor] == list[iterator.cursor];
//   }

//   bool operator!=(const Iterator<T>& iterator)
//   {
//     return list[cursor] != list[iterator.cursor];
//   }

// private:
//   int cursor;
//   T* list;
// };

// template<typename T>
// class ArrayList
// {
// public:
//   ArrayList();
//   ArrayList(ArrayList<T>& arr_list);
//   ~ArrayList();
//   void add(T element);
//   void add(int index, T element);
//   void clear();
//   bool contains(T element) const;
//   T get(int index) const;
//   int indexOf(T element) const;
//   bool isEmpty() const;
//   int lastIndexOf(T element) const;
//   void remove(T element);
//   int getSize() const;
//   T removeAt(int index);
//   T set(int index, T element);
//   T& operator[](int index);
//   Iterator<T> begin() const
//   {
//     return Iterator<T>(0, list);
//   }

//   Iterator<T> end() const
//   {
//     return Iterator<T>(size, list);
//   }

// private:
//   T* list;
//   int capacity;
//   int size;
//   void ensureCapacity();
// };

// template<typename T>
// ArrayList<T>::ArrayList(): size(0), capacity(4)
// {
//   list = new T[capacity];
// }

// template<typename T>
// ArrayList<T>::ArrayList(ArrayList<T>& arr_list)
// {
//   list = new T[arr_list.capacity];
//   size = arr_list.size;
//   capacity = arr_list.capacity;
//   for (int i = 0; i < size; i++)
//   {
//     list[i] = arr_list.list[i];
//   }
// }

// template<typename T>
// ArrayList<T>::~ArrayList()
// {
//   delete[] list;
// }

// template<typename T>
// void ArrayList<T>::add(T element)
// {
//   ensureCapacity();
//   list[size++] = element;
// }

// template<typename T>
// void ArrayList<T>::add(int index, T element)
// {
//   ensureCapacity();
//   if (index >= size)
//   {
//     add(element);
//   }
//   else
//   {
//     for (int i = size - 1; i >= index; i--)
//       list[i + 1] = list[i];
//     list[index] = element;
//     size++;
//   }
// }

// template<typename T>
// void ArrayList<T>::ensureCapacity()
// {
//   if (size >= capacity)
//   {
//     T* old = list;
//     capacity = 2 * size + 1;
//     list = new T[size * 2];
//     for (int i = 0; i < size; i++)
//       list[i] = old[i];

//     delete[] old;
//   }
// }

// // WRITE THE CODE HERE

// #endif

// void printList(const ArrayList<string>& list)
// {
//   for (int i = 0; i < list.getSize(); i++)
//   {
//     cout << list.get(i) << " ";
//   }
//   cout << endl;
// }

// int main()
// {
//   // Create a list for strings
//   ArrayList<string> list;

//   // Add elements to the list
//   list.add("America"); // Add it to the list

//   cout << "(1) ";
//   printList(list);

//   list.add(0, "Canada"); // Add it to the beginning of the list
//   cout << "(2) ";
//   printList(list);

//   list.add("Russia"); // Add it to the end of the list
//   cout << "(3) ";
//   printList(list);

//   list.add("France"); // Add it to the end of the list
//   cout << "(4) ";
//   printList(list);

//   list.add(2, "Germany"); // Add it to the list at index 2
//   cout << "(5) ";
//   printList(list);

//   list.add(5, "Norway"); // Add it to the list at index 5
//   cout << "(6) ";
//   printList(list);

//   list.add(0, "Netherlands"); // Same as list.addFirst("Netherlands")
//   cout << "(7) ";
//   printList(list);

//   // Remove elements from the list
//   list.removeAt(0); // Same as list.remove("Netherlands ") in this case
//   cout << "(8) ";
//   printList(list);

//   list.removeAt(2); // Remove the element at index 2
//   cout << "(9) ";
//   printList(list);

//   list.removeAt(list.getSize() - 1); // Remove the last element
//   cout << "(10) ";
//   printList(list);

//   cout << list[2] << endl;
//   list[2] = "Spain";

//   // Traverse a list using iterators
//   for (string& s : list)
//   {
//     cout << s << " ";
//   }

//   auto p = list.begin();
//   cout << endl << "The first element: " << *(p++) << endl;
//   cout << endl << "The third element: " << *(++p) << endl;

//   return 0;
// }
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#ifndef BST_H
#define BST_H

template < typename T >
class TreeNode
{
public:
  T element; // Element contained in the node
  TreeNode < T >* left; // Pointer to the left child
  TreeNode < T >* right; // Pointer to the right child

  TreeNode() // No-arg constructor
  {
    left = NULL;
    right = NULL;
  }

  TreeNode(T element) // Constructor
  {
    this->element = element;
    left = NULL;
    right = NULL;
  }
};

template < typename T >
class BST
{
public:
  BST();
  BST(T elements[], int arraySize);
  bool insert(T element);
  void inorder();
  void preorder();
  void postorder();
  int getSize();
  bool search(T element);
  void breadthFirstTraversal();
  int height();

private:
  TreeNode < T >* root;
  int size;
  void inorder(TreeNode < T >* root);
  void postorder(TreeNode < T >* root);
  void preorder(TreeNode < T >* root);
  bool search(T element, TreeNode < T >* root);
  int height(TreeNode<T>* root);
};

template < typename T >
BST < T >::BST()
{
  root = NULL;
  size = 0;
}

template < typename T >
BST < T >::BST(T elements[], int arraySize)
{
  root = NULL;
  size = 0;
  for (int i = 0; i < arraySize; i++)
  {
    insert(elements[i]);
  }
}

/* Insert element into the binary tree * Return true if the element is inserted successfully
* Return false if the element is already in the list */

template < typename T >
bool BST < T >::insert(T element)
{
  if (root == NULL)
    root = new TreeNode < T >(element); // Create a new root
  else
  {
    // Locate the parent node
    TreeNode < T >* parent = NULL;
    TreeNode < T >* current = root;
    while (current != NULL)
      if (element < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (element > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        return false; // Duplicate node not inserted

      // Create the new node and attach it to the parent node
    if (element < parent->element)
      parent->left = new TreeNode < T >(element);
    else
      parent->right = new TreeNode < T >(element);
  }

  size++;
  return true; // Element inserted
}

/* Inorder traversal */

template < typename T >
void BST < T >::inorder()
{
  inorder(root);
}

/* Inorder traversal from a subtree */

template < typename T >
void BST < T >::inorder(TreeNode < T >* root)
{
  if (root == NULL) return;
  inorder(root->left);
  cout << root->element << " ";
  inorder(root->right);
}

/* Postorder traversal */

template < typename T >
void BST < T >::postorder()
{
  postorder(root);
}

/** Inorder traversal from a subtree */

template < typename T >
void BST < T >::postorder(TreeNode < T >* root)
{
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->element << " ";
}

/* Preorder traversal */

template < typename T >
void BST < T >::preorder()
{
  preorder(root);
}

/* Preorder traversal from a subtree */

template < typename T >
void BST < T >::preorder(TreeNode < T >* root)
{
  if (root == NULL) return;
  cout << root->element << " ";
  preorder(root->left);
  preorder(root->right);
}

/* Get the number of nodes in the tree */

template < typename T >
int BST < T >::getSize()
{
  return size;
}

template < typename T >
int BST < T >::height()
{
  return height(root);
}

template < typename T >
int BST < T >::height(TreeNode<T>* root)
{
  // WRITE YOUR CODE
    if(root == nullptr)
        return -1;
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight>rightHeight)
            return leftHeight+1;
        else    
            return rightHeight+1;
    }
}

#endif

int main()
{
  BST<string> tree;
  cout << "The height of an empty tree is " << tree.height() << endl;

  cout << "Enter six strings: ";
  for (int i = 0; i < 6; i++) {
    string s;
    cin >> s;
    tree.insert(s);
  }
  cout << "\nThe height of the tree is " << tree.height() << endl;

  tree.insert("Green");
  cout << "The height of the tree is " << tree.height() << endl;

  tree.preorder(); // Traverses the tree

  string names[] = { "Tom", "George", "Jean", "Jane", "Kevin", "Peter", "Susan",
    "Jen", "Kim", "Michael", "Michelle" };
  BST<string> tree1(names, 11);
  cout << "\nThe preorder traversal of tree1 is ";
  tree1.preorder();
  cout << "\nThe height of tree1 is " << tree1.height() << endl;

  int numbers[] = { 50, 45, 35, 48, 59, 51, 58 };
  BST<int> tree2(numbers, 7);
  cout << "The preorder traversal for tree2 is ";
  tree2.preorder();
  cout << "\nThe height of tree2 is " << tree2.height() << endl;

  return 0;
}