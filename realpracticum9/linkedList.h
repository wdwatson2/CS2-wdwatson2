// Search for "WRITE YOUR CODE" to complete this program
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
  T element;  // Element contained in the node
  Node<T>* next; // Pointer to the next node

  Node(T element) : Node(element, nullptr) { } // Constructor
  Node(T element, Node<T>* next) : element(element), next(next) { } // Constructor
};

template<typename T>
class Iterator : public iterator<forward_iterator_tag, T>
{
  Node<T>* current;

public:
  Iterator(Node<T>* p) : current(p) { }

  Iterator operator++()
  {
    current = current->next;
    return *this;
  }

  T& operator*() const
  {
    return current->element;
  }

  bool operator==(const Iterator<T>& iterator) const
  {
    return current == iterator.current;
  }

  bool operator!=(const Iterator<T>& iterator) const
  {
    return current != iterator.current;
  }
};

template<typename T>
class LinkedList
{
  Node<T>* head = nullptr, * tail = nullptr;
  int size = 0;

public:
  LinkedList() = default;
  LinkedList(const LinkedList<T>& list);
  virtual ~LinkedList();
  void reverse();
  void addFirst(T element);
  void addLast(T element);
  T getFirst() const;
  T getLast() const;
  T removeFirst();
  T removeLast();
  void add(T element);
  void add(int index, T element);
  void clear();
  bool contains(T element) const;
  T get(int index) const;
  int indexOf(T element) const;
  bool isEmpty() const;
  int lastIndexOf(T element) const;
  void remove(T element);
  int getSize() const;
  T removeAt(int index);
  T set(int index, T element);

  Iterator<T> begin() const;
  Iterator<T> end() const;

  void addAll(const LinkedList<T>&);
  void removeAll(const LinkedList<T>&);
  void retainAll(const LinkedList<T>&);
  LinkedList<T>& operator=(const LinkedList<T>&);
  LinkedList<T> operator+(const LinkedList<T>&) const;
  LinkedList<T> operator-(const LinkedList<T>&) const;
  LinkedList<T> operator^(const LinkedList<T>&) const;
  T& operator[](int) const;
};

template<typename T>
void LinkedList<T>::reverse()
{
  Node<T> * previous = nullptr;
  Node<T> * current = head;
  Node<T> * next = nullptr;
  while(current != nullptr)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  head = previous;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
  for (auto iter = list.begin(); iter != list.end(); ++iter)
    add(*iter);
}

template<typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
  head = new Node<T>(element, head);
  if (isEmpty())
    tail = head;
  size++;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
  if (isEmpty())
    head = tail = new Node<T>(element);
  else
    tail = tail->next = new Node<T>(element);
  ++size;
}

template<typename T>
T LinkedList<T>::getFirst() const
{
  if (isEmpty())
    throw logic_error("No elements in the list");

  return head->element;
}

template<typename T>
T LinkedList<T>::getLast() const
{
  if (isEmpty())
    throw logic_error("No elements in the list");

  return tail->element;
}

template<typename T>
void LinkedList<T>::add(T element)
{
  addLast(element);
}

template<typename T>
void LinkedList<T>::add(int index, T element)
{
  if (index < 0 || index > size)
    throw out_of_range("Insertion index out of range");
  else if (index == size)
  {
    tail = tail->next = new Node<T>(element);
  }
  else
  {
    Node<T>** indir = &head;
    while (--index >= 0)
      indir = &(*indir)->next;
    // indir is &head iff index was 0, and &beforeNode.next otherwise.

    *indir = new Node<T>(element, *indir);
  }
  size++;
}

template<typename T>
void LinkedList<T>::clear()
{
  tail = nullptr;
  while (head != nullptr)
  {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
  }
  size = 0;
}

template<typename T>
T LinkedList<T>::get(int index) const
{
  if (index < 0 || index >= size)
    throw out_of_range("Index out of range");

  auto iter = begin();
  while (--index >= 0)
    ++iter;
  return *iter;
}

template<typename T>
int LinkedList<T>::indexOf(T element) const
{
  int idx = 0;
  for (auto iter = begin(); iter != end(); ++iter, ++idx)
  {
    if (*iter == element)
      return idx;
  }
  return -1;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
  return size == 0;
}

template<typename T>
int LinkedList<T>::getSize() const
{
  return size;
}

template<typename T>
T LinkedList<T>::removeFirst()
{
  if (isEmpty())
    throw logic_error("No elements in the list");

  Node<T>* temp = head;
  head = head->next;
  if (size == 1)
    tail = nullptr;
  --size;
  T element = move(temp->element);
  delete temp;
  return element;
}

template<typename T>
T LinkedList<T>::removeLast()
{
  if (isEmpty())
    throw logic_error("No elements in the list");

  Node<T>* temp = tail;
  if (size == 1)
    head = tail = nullptr;
  else
  {
    Node<T>* before = head;
    while (before->next != tail)
      before = before->next;
    tail = before;
    tail->next = nullptr;
  }
  --size;
  T element = move(temp->element);
  delete temp;
  return element;
}

template<typename T>
T LinkedList<T>::removeAt(int index)
{
  if (index == size - 1)
    return removeLast();
  else if (index < 0 || index >= size)
    throw out_of_range("Index out of range");
  else
  {
    Node<T>** indir = &head;
    while (--index >= 0)
      indir = &(*indir)->next;
    // indir is &head iff index was 0, and &beforeNode.next otherwise.

    Node<T>* temp = *indir;
    *indir = (*indir)->next;
    --size;
    T element = move(temp->element);
    delete temp;
    return element;
  }
}

template<typename T>
Iterator<T> LinkedList<T>::begin() const
{
  return Iterator<T>(head);
};

template<typename T>
Iterator<T> LinkedList<T>::end() const
{
  return Iterator<T>(nullptr);
};

// The functions remove(T element), lastIndexOf(T element),
// contains(T element), and set(int index, T element) are
// left as an exercise

template<typename T>
bool LinkedList<T>::contains(T element) const
{
  for (auto iter = begin(); iter != end(); ++iter)
  {
    if (*iter == element)
      return true;
  }
  return false;
}

template<typename T>
int LinkedList<T>::lastIndexOf(T element) const
{
  int idx = 0, lastIdx = -1;
  for (auto iter = begin(); iter != end(); ++idx, ++iter)
  {
    if (*iter == element)
      lastIdx = idx;
  }
  return lastIdx;
}

template<typename T>
void LinkedList<T>::remove(T element)
{
  if (isEmpty())
    ;
  else if (head->element == element)
    removeFirst();
  else if (tail->element == element)
    removeLast();
  else
  {
    Node<T>* indir = head;
    do
    {
      indir = indir->next;
      if (indir == tail)
        return; // Element not found.
    } while (indir->element != element);
    // indir is &beforeNode.next.

    Node<T>* temp = indir;
    indir = indir->next;
    --size;
    delete temp;
  }
}

template<typename T>
T LinkedList<T>::set(int index, T element)
{
  return *this[index] = element;
}

template<typename T>
void LinkedList<T>::addAll(const LinkedList<T>& other)
{
  //add each element from other to the end of current list
  for(auto iter = other.begin(); iter != other.end(); ++iter)
  {
    addLast(*iter);
  }
}

template<typename T>
void LinkedList<T>::removeAll(const LinkedList<T>& other)
{
  // WRITE YOUR CODE needs to search for each element in other and delete all occurances of that element.
  for(auto iter = other.begin(); iter != other.end(); ++iter)
  {
    //while list still contains element we want to keep removing
    while(contains(*iter))
    {
      removeAt(indexOf(*iter));
    }
  }
}

template<typename T>
void LinkedList<T>::retainAll(const LinkedList<T>& other)
{
  // WRITE YOUR CODE - remove elements not found in other
  for(auto iter = begin(); iter != end(); ++iter)
  {
    if(!(other.contains(*iter)))
    {
      removeAt(indexOf(*iter));
    }
    
  }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
  clear();
  addAll(other);
  return *this;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T>& other) const
{
  // WRITE YOUR CODE set union
  LinkedList<T> newList = *this;
  newList.addAll(other);
  return newList;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator-(const LinkedList<T>& other) const
{
  // WRITE YOUR CODE 
  LinkedList<T> newList = *this;
  newList.removeAll(other);
  return newList;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator^(const LinkedList<T>& other) const
{
  // WRITE YOUR CODE 
  LinkedList<T> newList = *this;
  newList.retainAll(other);
  return newList;
}

template<typename T>
T& LinkedList<T>::operator[](int index) const
{
  if (index < 0 || index >= size)
    throw out_of_range("Index out of range");

  auto iter = begin();
  while (--index >= 0)
    ++iter;
  return *iter;
}

#endif
