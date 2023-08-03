// Search for "WRITE YOUR CODE" to complete this program
#ifndef ArrayList_H
#define ArrayList_H
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

#define DEBUG

template<typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
  Iterator(int index, T* list)
  {
    this->list = list;
    cursor = index;
  }

  Iterator operator++() // Prefix ++s
  {
    cursor++;
    return *this;
  }

  Iterator operator++(int dummy) // Postfix ++
  {
    Iterator temp(*this);
    cursor++;
    return temp;
  }

  T& operator*()
  {
    return list[cursor];
  }

  bool operator==(const Iterator<T>& iterator)
  {
    return list[cursor] == list[iterator.cursor];
  }

  bool operator!=(const Iterator<T>& iterator)
  {
    return list[cursor] != list[iterator.cursor];
  }

private:
  int cursor;
  T* list;
};

template<typename T>
class ArrayList
{
public:
  ArrayList();
  ArrayList(ArrayList<T>& arr_list);
  ~ArrayList();
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
  T& operator[](int index);
  Iterator<T> begin() const
  {
    return Iterator<T>(0, list);
  }

  Iterator<T> end() const
  {
    return Iterator<T>(size, list);
  }

private:
  T* list;
  int capacity;
  int size;
  void ensureCapacity();
};

template<typename T>
ArrayList<T>::ArrayList() : size(0), capacity(4)
{
  list = new T[capacity];
}

template<typename T>
ArrayList<T>::ArrayList(ArrayList<T>& arr_list)
{
  list = new T[arr_list.capacity];
  size = arr_list.size;
  capacity = arr_list.capacity;
  for (int i = 0; i < size; i++)
  {
    list[i] = arr_list.list[i];
  }
}

template<typename T>
ArrayList<T>::~ArrayList()
{
  delete[] list;
}

template<typename T>
void ArrayList<T>::add(T element)
{
  // WRITE YOUR CODE
  ensureCapacity();
  list[size] = element;
  size++;
}

template<typename T>
void ArrayList<T>::add(int index, T element)
{
  // WRITE YOUR CODE
  T * newguy = new T[size+1];
  for(int beg = 0; beg < index; beg++)
  {
    newguy[beg] = list[beg]; //copying all elements over until index is reached
  }
  newguy[index] = element; //placing element at index 
  for(int end = index; end < size; end++)
  {
    newguy[end+1] = list[end]; //copying the rest of the elements over
  }

  ensureCapacity();
    for(int i = 0; i < size+1; i++)
    {
        list[i] = newguy[i];
    }

  size++;

  delete[] newguy;
}

template<typename T>
void ArrayList<T>::ensureCapacity()
{
  if (size >= capacity)
  {
    T* old = list;
    capacity = 2 * size + 1;
    list = new T[size * 2];
    for (int i = 0; i < size; i++)
      list[i] = old[i];

    delete[] old;
  }
}

template<typename T>
void ArrayList<T>::clear()
{
  delete[] list;
  list = new T[capacity];
  size = 0;
}

template<typename T>
bool ArrayList<T>::contains(T element) const
{
  for (int i = 0; i < size ; list++)
  {
    if (list[i].equals(element))
      return true;
  }
  return false;
}

template<typename T>
T ArrayList<T>::get(int index) const
{
  if (index < 0 || index >= size)
    throw runtime_error("Index out of range");
  else
    return list[index];
}

template<typename T>
int ArrayList<T>::indexOf(T element) const
{
  for (int i = 0; i < size; i++) {
    if (list[i].equals(element))
      return i;
  }
  return -1;
}

template<typename T>
bool ArrayList<T>::isEmpty() const
{
  return size <= 0;
}

template<typename T>
int ArrayList<T>::lastIndexOf(T element) const
{
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (list[i].equals(element))
      index = i;
  }
  return index;
}

template<typename T>
void ArrayList<T>::remove(T element)
{
  // WRITE YOUR CODE
}

template<typename T>
int ArrayList<T>::getSize() const
{
  return size;
}

template<typename T>
T ArrayList<T>::removeAt(int index) 
{
  if (index < 0 || index >= size)
    throw runtime_error("Index out of range");
  else
  {
    T temp = list[index];
    for (int i = index; i < size; i++)
      list[i] = list[i + 1];
    size--;
    return temp;
  }
}

template<typename T>
T ArrayList<T>::set(int index, T element) 
{
  // WRITE YOUR CODE
}

template<typename T>
T& ArrayList<T>::operator[](int index) 
{
  if (index < 0 || index >= size)
    throw runtime_error("Index out of range");
  else
    return list[index];
}

#endif

void printList(const ArrayList<string>& list)
{
  for (int i = 0; i < list.getSize(); i++)
  {
    cout << list.get(i) << " ";
  }
  cout << endl;
}

int main()
{
  // Create a list for strings
  ArrayList<string> list;
  cout << list.getSize() << endl;

  // Add elements to the list
  list.add("America"); // Add it to the list

  cout << "(1) ";
  printList(list);

  list.add(0, "Canada"); // Add it to the beginning of the list
  cout << "(2) ";
  printList(list);

  list.add("Russia"); // Add it to the end of the list
  cout << "(3) ";
  printList(list);

  list.add("France"); // Add it to the end of the list
  cout << "(4) ";
  printList(list);

  list.add(2, "Germany"); // Add it to the list at index 2
  cout << "(5) ";
  printList(list);

  list.add(5, "Norway"); // Add it to the list at index 5
  cout << "(6) ";
  printList(list);

  cout << "Enter a new string: ";
  string s;
  getline(cin, s);
  list.add(0, s); // Same as list.addFirst(s)
  cout << "(7) ";
  printList(list);

  // Remove elements from the list
  int index;
  cout << "Enter an index: ";
  cin >> index;
  list.removeAt(index); // Same as list.remove("Netherlands ") in this case
  cout << "(8) ";
  printList(list);

  list.removeAt(2); // Remove the element at index 2
  cout << "(9) ";
  printList(list);

  list.removeAt(list.getSize() - 1); // Remove the last element
  cout << "(10) ";
  printList(list);

  cout << list[2] << endl;
  list[2] = "Spain";

  // Traverse a list using iterators
  for (string& s : list)
  {
    cout << s << " ";
  }

  auto p = list.begin();
  cout << endl << "The first element: " << *(p++) << endl;
  cout << "The third element: " << *(++p) << endl;

  return 0;
}