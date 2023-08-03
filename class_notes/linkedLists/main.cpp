// The main contents are here
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

template<typename T>
void printList(const LinkedList<T>& list)
{
  Iterator<T> current = list.begin();

  while (current != list.end())
  {
    cout << *current << " ";
    ++current;
  }

  cout << endl;
}

int main()
{
  // Create a list for strings
  LinkedList<string> list;
  cout << "Enter five lines of strings: ";
  for (unsigned i = 0; i < 5; i++)
  {
    string s;
    getline(cin, s);
    list.add(s);
  }

  // Create a list for strings
  LinkedList<string> list2;
  cout << "Enter five lines of strings: ";
  for (unsigned i = 0; i < 5; i++)
  {
    string s;
    getline(cin, s);
    list2.add(s);
  }

  LinkedList<string> list1(list);
  cout << "list1: ";
  printList(list1);
  cout << "list2: ";
  printList(list2);

  cout << "After list1.addAll(list2), list1 is ";
  list1.addAll(list2);
  printList(list1);

  cout << "list1: ";
  printList(list1);
  cout << "list2: ";
  printList(list2);

  // list1.remove("2"); remove does not work properly
  list1.removeAll(list2);
  cout << "After list1.removeAll(list2), list1 is ";
  printList(list1);

  list1 = list;
  cout << "list1: ";
  printList(list1);
  cout << "list2: ";
  printList(list2);
  list1.retainAll(list2);
  cout << "After list1.retainAll(list2), list1 is ";
  printList(list1);

  // Takes too much time. Skip this code 
  
  list1 = list;
  cout << "list1: ";
  printList(list1);
  cout << "list2: ";
  printList(list2);
  list1 = list1 + list2;
  cout << "After list1 = list1 + list2, list1 is ";
  printList(list1);

  list1 = list;
  cout << "list1: ";
  printList(list1);
  cout << "list2: ";
  printList(list2);
  list1 = list1 - list2;
  cout << "After list1 = list1 - list2, list1 is ";
  printList(list1);

  list1 = list;
  cout << "list1: ";
  printList(list1);
  cout << "list2: ";
  list1 = list1 ^ list2;
  cout << "After list1 = list1 ^ list2, list1 is ";
  printList(list1);

  list1 = list;
  cout << list1[0] << endl;
  list1[0] = list[2];
  cout << list1[0] << endl;

  return 0;
}